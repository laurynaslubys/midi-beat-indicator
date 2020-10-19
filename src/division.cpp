#include <division.hpp>
#include <Arduino.h>
#include <display.hpp>
#include <Arduino_FreeRTOS.h>
#include <queue.h>
#include <timers.h>

#define encoderPinA 2
#define encoderPinB 3

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

int current_division_idx = 6;
int current_division = division_values[current_division_idx];
boolean enc_A_value = false;
boolean enc_B_value = false;
QueueHandle_t changeQueue;
TimerHandle_t restoreDisplayTimer;

#define LOW_TICKS (-42)
#define HIGH_TICKS 30

void handleEncoder(void *pvParam)
{
  int potValue = 0;
  int8_t change = 0;
  for (;;)
  {
    xQueueReceive(changeQueue, &change, portMAX_DELAY);
    potValue += change;
    potValue = constrain(potValue, LOW_TICKS, HIGH_TICKS);
    int current_division_idx = map(potValue, LOW_TICKS, HIGH_TICKS, 0, 11);
    int new_division = division_values[current_division_idx];

    activate_channel(CLOCK_DIV);

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
    current_division = new_division;

    xTimerReset(restoreDisplayTimer, 0);
  }
}

void restoreDisplay(TimerHandle_t timer)
{
  activate_channel(BEAT);
}

void doEncoderA()
{
  enc_A_value = digitalRead(encoderPinA) == HIGH;
  int8_t change = (enc_A_value == enc_B_value) ? +1 : -1;
  xQueueSendToBackFromISR(changeQueue, &change, NULL);
}

void doEncoderB()
{
  enc_B_value = digitalRead(encoderPinB) == HIGH;
  int8_t change = (enc_A_value != enc_B_value) ? +1 : -1;
  xQueueSendToBackFromISR(changeQueue, &change, NULL);
}

void setup_divisions()
{
  changeQueue = xQueueCreate(5, sizeof(int8_t));

  pinMode(encoderPinA, INPUT_PULLUP);
  pinMode(encoderPinB, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(encoderPinA), doEncoderA, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encoderPinB), doEncoderB, CHANGE);

  restoreDisplayTimer = xTimerCreate("RestoreDisplay",
                                     1000 / portTICK_PERIOD_MS,
                                     false,
                                     NULL,
                                     restoreDisplay);

  xTaskCreate(handleEncoder,
              "HandleEncoder",
              128,
              NULL,
              3,
              NULL);

  start_blink(CLOCK_DIV, 50, 30);
}