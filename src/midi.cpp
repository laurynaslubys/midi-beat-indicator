#include "MIDIUSB.h"
#include <Arduino_FreeRTOS.h>
#include <shared.hpp>
#include <display.hpp>
#include <division.hpp>

#define MSG_CLOCK 0xF8
#define MSG_START 0xFA
#define MSG_CONTINUE 0xFB
#define MSG_STOP 0xFC
#define MSG_SPP 0xF2

#define TRIG_PIN 7

int song_pos = 0;
bool playing = false;

TaskHandle_t blink;
TaskHandle_t endTrig;

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
      vTaskResume(endTrig);
    }
  }
}

void EndTrig(void *pvParameters)
{
  for (;;)
  {
    vTaskSuspend(NULL);
    vTaskDelay(50 / portTICK_PERIOD_MS);
    digitalWrite(TRIG_PIN, LOW);
  }
}

void continue_play()
{
  playing = true;
  vTaskSuspend(blink);
}

void pause_play()
{
  playing = false;
  vTaskResume(blink);
}

void TaskRcvMidi(void *pvParameters)
{
  midiEventPacket_t rx;
  for (;;)
  {
    rx = MidiUSB.read();

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
    taskYIELD();
  };
}

void Blink(void *pvParameters)
{
  for (;;)
  {
    display_num(BEAT, 0, 0);
    vTaskDelay(100 / portTICK_PERIOD_MS);
    indicate_current();
    vTaskDelay(900 / portTICK_PERIOD_MS);
  }
}

void setup_midi()
{
  pinMode(TRIG_PIN, OUTPUT);

  xTaskCreate(TaskRcvMidi,
              "RcvMidi",
              128,
              NULL,
              3,
              NULL);

  xTaskCreate(Blink,
              "Blink",
              128,
              NULL,
              3,
              &blink);

  xTaskCreate(EndTrig,
              "EndTrig",
              128,
              NULL,
              3,
              &endTrig);
}