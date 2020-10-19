#include "MIDIUSB.h"
#include <Arduino_FreeRTOS.h>
#include <shared.hpp>
#include <display.hpp>
#include <division.hpp>
#include <queue.h>
#include <timers.h>

#define MSG_CLOCK 0xF8
#define MSG_START 0xFA
#define MSG_CONTINUE 0xFB
#define MSG_STOP 0xFC
#define MSG_SPP 0xF2

#define TRIG_PIN 7

int song_pos = 0;
bool playing = false;

QueueHandle_t midiQueue;
TimerHandle_t endTriggerTimer;

void endTrigger(TimerHandle_t timer)
{
  digitalWrite(TRIG_PIN, LOW);
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
    if (song_pos % current_division == 0)
    {
      digitalWrite(TRIG_PIN, HIGH);
      xTimerReset(endTriggerTimer, 1000 / portTICK_PERIOD_MS);
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
  midiEventPacket_t rx;
  for (;;)
  {
    xQueueReceive(midiQueue, &rx, portMAX_DELAY);

    if (rx.header == 0xF)
    {
      switch (rx.byte1)
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
      }
    }
    else if (rx.header == 0x3)
    {
      switch (rx.byte1)
      {
      case 0xF2:
        song_pos = (rx.byte2 | (rx.byte3 << 7)) * PPQN / 4;
        break;
      }
    }

    if (song_pos >= PPBN)
      song_pos %= PPBN;

    if (playing)
    {
      indicate_current();
      trigger_current();
    }
  };
}

void TaskRcvMidi(void *pvParameters)
{
  midiEventPacket_t rx;
  for (;;)
  {
    rx = MidiUSB.read();
    if (rx.header != 0)
    {
      xQueueSendToBack(midiQueue, (void *)&rx, 0);
    }
    taskYIELD();
  };
}

void setup_midi()
{
  midiQueue = xQueueCreate(16, sizeof(midiEventPacket_t));
  endTriggerTimer = xTimerCreate("Stop trigger",
                                 50 / portTICK_PERIOD_MS,
                                 false,
                                 NULL,
                                 endTrigger);

  pinMode(TRIG_PIN, OUTPUT);

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