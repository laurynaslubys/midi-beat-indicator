#include <display.hpp>
#include <shared.hpp>
#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <FastGPIO.h>
#include <wiring.h>

struct DisplayValue // TODO store in one byte
{
  boolean low_1 = false;
  boolean low_2 = false;
  boolean low_3 = false;
  boolean high_1 = false;
  boolean high_2 = false;
  boolean high_3 = false;
  boolean blinking = false;
  int on_millis = -1;
  int off_millis = -1;
};

Channel active_channel = BEAT;
const DisplayValue dv_off = {};
DisplayValue channels[CHANNEL_COUNT];

TaskHandle_t blink;

void set_leds(const DisplayValue value)
{
  FastGPIO::Pin<HIGH_1>::setOutputValue(value.high_1);
  FastGPIO::Pin<HIGH_2>::setOutputValue(value.high_2);
  FastGPIO::Pin<HIGH_3>::setOutputValue(value.high_3);
  FastGPIO::Pin<LOW_1>::setOutputValue(value.low_1);
  FastGPIO::Pin<LOW_2>::setOutputValue(value.low_2);
  FastGPIO::Pin<LOW_3>::setOutputValue(value.low_3);
}

void display_num(Channel channel, int low, int high)
{
  display_bits(channel,
               low >= 1,
               low >= 2,
               low >= 3,
               high >= 1,
               high >= 2,
               high >= 3);
}

void display_bits(Channel channel, bool low_1, bool low_2, bool low_3, bool high_1, bool high_2, bool high_3)
{
  DisplayValue &dv = channels[channel];

  if ((low_1 != dv.low_1) ||
      (low_2 != dv.low_2) ||
      (low_3 != dv.low_3) ||
      (high_1 != dv.high_1) ||
      (high_2 != dv.high_2) ||
      (high_3 != dv.high_3))
  {

    dv.high_1 = high_1;
    dv.high_2 = high_2;
    dv.high_3 = high_3;
    dv.low_1 = low_1;
    dv.low_2 = low_2;
    dv.low_3 = low_3;

    if (channel == active_channel && !dv.blinking)
    {
      set_leds(dv);
    }
  }
}

void activate_channel(Channel channel)
{
  if (active_channel != channel)
  {
    active_channel = channel;
    DisplayValue &dv = channels[active_channel];
    set_leds(channels[active_channel]);
    if (dv.blinking)
    {
      xTaskAbortDelay(blink);
      vTaskResume(blink);
    }
    else
    {
      vTaskSuspend(blink);
    }
  }
}

void start_blink(Channel channel, int on_millis, int off_millis)
{
  DisplayValue &dv = channels[channel];
  dv.blinking = true;
  dv.on_millis = on_millis;
  dv.off_millis = off_millis;
  if (channel == active_channel)
  {
    vTaskResume(blink);
  }
}

void stop_blink(Channel channel)
{
  DisplayValue &dv = channels[channel];
  dv.blinking = false;
  if (channel == active_channel)
  {
    set_leds(dv);
    vTaskSuspend(blink);
  }
}

void Blink(void *pvParameters)
{
  DisplayValue *dv = &channels[active_channel];
  TickType_t lastWakeTime;

  for (;;)
  {
    dv = &channels[active_channel];
    if (dv->blinking)
    {
      lastWakeTime = xTaskGetTickCount();
      set_leds(dv_off);

      vTaskDelayUntil(&lastWakeTime, dv->off_millis / portTICK_PERIOD_MS);

      dv = &channels[active_channel];
      set_leds(*dv);
      vTaskDelayUntil(&lastWakeTime, dv->on_millis / portTICK_PERIOD_MS);
    }
    else
    {
      vTaskSuspend(NULL);
    }
  }
}

void setup_display()
{
  FastGPIO::Pin<LOW_1>::setOutput(LOW);
  FastGPIO::Pin<LOW_2>::setOutput(LOW);
  FastGPIO::Pin<LOW_3>::setOutput(LOW);
  FastGPIO::Pin<HIGH_1>::setOutput(LOW);
  FastGPIO::Pin<HIGH_2>::setOutput(LOW);
  FastGPIO::Pin<HIGH_3>::setOutput(LOW);

  xTaskCreate(Blink,
              "Blink",
              128,
              NULL,
              3,
              &blink);

  vTaskSuspend(blink);
}
