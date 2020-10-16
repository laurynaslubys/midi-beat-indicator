#include <display.hpp>
#include <shared.hpp>
#include <Arduino.h>

#define LOW_1 8
#define LOW_2 11
#define LOW_3 13

#define HIGH_1 9
#define HIGH_2 10
#define HIGH_3 12

struct DisplayValue // TODO store in one byte
{
  boolean low_1 = 0;
  boolean low_2 = 0;
  boolean low_3 = 0;
  boolean high_1 = 0;
  boolean high_2 = 0;
  boolean high_3 = 0;
};

Channel active_channel = BEAT;
DisplayValue channels[CHANNEL_COUNT];

void setTo(int led, bool on)
{
  digitalWrite(led, on ? HIGH : LOW);
}

void set_leds(const DisplayValue value)
{
  setTo(HIGH_1, value.high_1);
  setTo(HIGH_2, value.high_2);
  setTo(HIGH_3, value.high_3);

  setTo(LOW_1, value.low_1);
  setTo(LOW_2, value.low_2);
  setTo(LOW_3, value.low_3);
}

void display_num(Channel channel, int low, int high)
{
  DisplayValue &dv = channels[channel];

  dv.high_1 = high >= 1;
  dv.high_2 = high >= 2;
  dv.high_3 = high >= 3;
  dv.low_1 = low >= 1;
  dv.low_2 = low >= 2;
  dv.low_3 = low >= 3;

  if (channel == active_channel)
  {
    set_leds(dv);
  }
}

void activate_channel(Channel channel)
{
  active_channel = channel;
  set_leds(channels[active_channel]);
}

void setup_display()
{
  pinMode(LOW_1, OUTPUT);
  pinMode(LOW_2, OUTPUT);
  pinMode(LOW_3, OUTPUT);

  pinMode(HIGH_1, OUTPUT);
  pinMode(HIGH_2, OUTPUT);
  pinMode(HIGH_3, OUTPUT);
}
