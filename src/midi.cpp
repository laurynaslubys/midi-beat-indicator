#include <usbmidi.h>
#include <FastGPIO.h>
#include <Arduino_FreeRTOS.h>
#include <Arduino.h>
#include <shared.hpp>
#include <display.hpp>
#include <division.hpp>
#include <queue.h>
#include <timers.h>
#include <wiring.h>

//https://www.midi.org/specifications-old/item/table-1-summary-of-midi-message
#define MSG_CLOCK 0b11111000
#define MSG_START 0b11111010
#define MSG_CONTINUE 0b11111011
#define MSG_STOP 0b11111100
#define MSG_SPP 0b11110010

struct MidiMessage
{
  int status = 0;
  int data1 = 0;
  int data2 = 0;
};

int song_pos = 0;
bool playing = false;

QueueHandle_t midiQueue;
TimerHandle_t endTriggerTimer;
volatile int sync_pulses_remaining = 0;

void endTrigger(TimerHandle_t timer)
{
  FastGPIO::Pin<TRIG_PIN>::setOutputValueLow();
}

void indicate_beat(int note)
{
  int beatNote = note % N_QS;
  int beat = note / N_BEATS;

  display_num(BEAT, beat, beatNote);
}

void indicate_current()
{
  indicate_beat(song_pos / (PPQN / DIVISION));
}

void trigger_current()
{
  if (current_division > 0)
  {
    if (song_pos % current_division == 0 && sync_pulses_remaining > 0)
    {
      FastGPIO::Pin<TRIG_PIN>::setOutputValueHigh();
      xTimerReset(endTriggerTimer, 1000 / portTICK_PERIOD_MS);
      sync_pulses_remaining--;
    }
  }
}

void continue_play()
{
  playing = true;
  stop_blink(BEAT);
}

void pause_play()
{
  playing = false;
  start_blink(BEAT, 600, 300);
}

void TaskHandleMidi(void *pvParameters)
{
  MidiMessage rx;
  for (;;)
  {
    xQueueReceive(midiQueue, &rx, portMAX_DELAY);

    switch (rx.status)
    {
    case MSG_CLOCK:
      if (playing)
        song_pos++;
      break;
    case MSG_START:
      song_pos = 0;
      continue_play();
      break;
    case MSG_CONTINUE:
      continue_play();
      break;
    case MSG_STOP:
      pause_play();
      break;
    case MSG_SPP:
      song_pos = (rx.data1 | (rx.data2 << 7)) * PPQN / 4;
      break;
    }

    if (song_pos >= PPBN)
      song_pos %= PPBN;
    if (playing)
    {
      indicate_current();
      trigger_current();
    }
  }
}

void TaskRcvMidi(void *pvParameters)
{
  int data = 0;
  int pending_bytes = 0;
  MidiMessage current_message = {};
  for (;;)
  {
    USBMIDI.poll();

    while (USBMIDI.available())
    {
      data = USBMIDI.read();
      Serial1.write(data);
      bool is_command = data & 0b10000000;

      if (is_command)
      {
        pending_bytes = 0;
      }

      switch (pending_bytes)
      {
      case 2:
        pending_bytes = 1;
        current_message.data1 = data;
        break;
      case 1:
        pending_bytes = 0;
        current_message.data2 = data;
        xQueueSendToBack(midiQueue, (void *)&current_message, 0);
        break;
      case 0:
      {
        switch (data)
        {
        case MSG_CLOCK:
        case MSG_CONTINUE:
        case MSG_START:
        case MSG_STOP:
          current_message.status = data;
          xQueueSendToBack(midiQueue, (void *)&current_message, 0);
          break;
        case MSG_SPP:
          current_message.status = data;
          pending_bytes = 2;
          break;
        }
        break;
      }
      }
    }

    taskYIELD();
  };
}

void onSyncButton()
{
  sync_pulses_remaining = 4;
}

void setup_midi()
{
  pinMode(SYNC_BUTTON_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(SYNC_BUTTON_PIN), onSyncButton, FALLING);

  midiQueue = xQueueCreate(16, sizeof(MidiMessage));
  endTriggerTimer = xTimerCreate("Stop trigger",
                                 50 / portTICK_PERIOD_MS,
                                 false,
                                 NULL,
                                 endTrigger);

  FastGPIO::Pin<TRIG_PIN>::setOutputLow();

  xTaskCreate(TaskRcvMidi,
              "RcvMidi",
              128,
              NULL,
              1,
              NULL);

  xTaskCreate(TaskHandleMidi,
              "HandleMidi",
              128,
              NULL,
              1,
              NULL);
}