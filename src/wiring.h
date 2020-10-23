#ifndef WIRING_H
#define WIRING_H

#ifdef WIRING_LEONARDO

#define LOW_1 8
#define LOW_2 11
#define LOW_3 13
#define HIGH_1 9
#define HIGH_2 10
#define HIGH_3 12
#define SYNC_BUTTON_PIN 3
#define TRIG_PIN 7
#define POT_PIN A0

#elif WIRING_PRO_MICRO

#define LOW_1 4
#define LOW_2 7
#define LOW_3 9
#define HIGH_1 5
#define HIGH_2 6
#define HIGH_3 8
#define SYNC_BUTTON_PIN 3
#define TRIG_PIN 10
#define POT_PIN A0

#endif

#endif