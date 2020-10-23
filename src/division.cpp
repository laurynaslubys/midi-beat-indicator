#include <division.hpp>
#include <Arduino.h>
#include <display.hpp>
#include <Arduino_FreeRTOS.h>
#include <wiring.h>

const int division_values[] = {
    192, //TWO_BAR
    128, //TWO_BAR_TRIP
    96,  //BAR
    64,  //BAR_TRIP
    48,  //HALF
    32,  //HALF_TRIP
    24,  //QUARTER,
    16,  //QUARTER_TRIP,
    12,  //EIGHT,
    8,   //EIGHT_TRIP,
    6,   //SIXTEENTH,
    4,   //SIXTEENTH_TRIP,
};

int current_division = -1;
int same_value_count = 0;

void SamplePotentiometer(void *pvParam)
{
  for (;;)
  {
    int potValue = analogRead(POT_PIN);
    int current_division_idx = map(potValue, 0, 1023, 0, 11);
    int new_division = division_values[current_division_idx];
    if (current_division == new_division)
    {
      same_value_count++;
      if (same_value_count > 20)
      {
        activate_channel(BEAT);
      }
    }
    else
    {
      same_value_count = 0;
      activate_channel(CLOCK_DIV);
    }
    if (current_division_idx >= 6)
    {
      display_bits(CLOCK_DIV,
                   current_division_idx >= 6,
                   current_division_idx >= 7,
                   current_division_idx >= 8,
                   current_division_idx >= 9,
                   current_division_idx >= 10,
                   current_division_idx >= 11);
    }
    else
    {
      display_bits(CLOCK_DIV,
                   current_division_idx <= 0,
                   current_division_idx <= 1,
                   current_division_idx <= 2,
                   current_division_idx <= 3,
                   current_division_idx <= 4,
                   current_division_idx <= 5);
    }
    vTaskDelay(50 / portTICK_PERIOD_MS);
    current_division = new_division;
  }
}

void setup_divisions()
{
  xTaskCreate(SamplePotentiometer,
              "SamplePot",
              128,
              NULL,
              3,
              NULL);

  start_blink(CLOCK_DIV, 50, 30);
}