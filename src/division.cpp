#include <division.hpp>
#include <Arduino.h>
#include <display.hpp>
#include <Arduino_FreeRTOS.h>

const int division_values[] = {
    24, //QUARTER,
    16, //QUARTER_TRIP,
    12, //EIGHT,
    8,  //EIGHT_TRIP,
    6,  //SIXTEENTH,
    4,  //SIXTEENTH_TRIP,
};

int current_division = -1;
int same_value_count = 0;

void SamplePotentiometer(void *pvParam)
{
  for (;;)
  {
    int potValue = analogRead(A0);
    int current_division_idx = map(potValue, 0, 1023, 0, 5);
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
    display_num(CLOCK_DIV, current_division_idx + 1, current_division_idx - 2);
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
}