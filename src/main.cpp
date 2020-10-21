#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <shared.hpp>
#include <display.hpp>
#include <midi.hpp>
#include <division.hpp>

void setup()
{
  delay(1000); // prevents usb driver crash on startup, do not omit this

  setup_display();
  setup_divisions();
  setup_midi();
}

void loop()
{
}
