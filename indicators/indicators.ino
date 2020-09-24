#include "MIDIUSB.h"


#define MSG_CLOCK 0xF8
#define MSG_START 0xFA
#define MSG_CONTINUE 0xFB
#define MSG_STOP 0xFC
#define MSG_SPP 0xF2

const int PPQN = 24;
const int N_BEATS = 4;
const int N_QS = 4;
const int PPBN = PPQN * N_BEATS * N_QS;

#define BEAT_1 8
#define BEAT_2 9
#define BEAT_3 10

#define NOTE_1 11
#define NOTE_2 12
#define NOTE_3 13

void setup() {
  pinMode(BEAT_1, OUTPUT);
  pinMode(BEAT_2, OUTPUT);
  pinMode(BEAT_3, OUTPUT);

  pinMode(NOTE_1, OUTPUT);
  pinMode(NOTE_2, OUTPUT);
  pinMode(NOTE_3, OUTPUT);
}

void step(int step_idx) {
  indicate(step_idx);
  delay(250);
}

void setTo(int led, bool on) {
  digitalWrite(led, on ? HIGH : LOW);
}


void indicate(int note) {
  int beatNote = note % N_QS;
  int beat = note / N_BEATS;

  setTo(NOTE_1, beatNote >= 1);
  setTo(NOTE_2, beatNote >= 2);
  setTo(NOTE_3, beatNote >= 3);

  setTo(BEAT_1, beat >= 1);
  setTo(BEAT_2, beat >= 2);
  setTo(BEAT_3, beat >= 3);
}


int song_pos = 0;
bool playing = false;

void loop() {
  midiEventPacket_t rx;
  do {
    rx = MidiUSB.read();

    if (rx.header == 0xF) {
      switch (rx.byte1) {
        case MSG_CLOCK:
          if (playing) song_pos++;
          break;
        case MSG_START:
          song_pos = 0;
          playing = true;
          break;
        case MSG_CONTINUE:
          playing = true; 
          break;
        case MSG_STOP:
          playing = false;
          break;
      }
    } else if (rx.header == 0x3) {
      switch (rx.byte1) {
        case 0xF2:
          song_pos = (rx.byte2 | (rx.byte3 << 7)) * PPQN / 4;
          break;
      }
    }

    if (song_pos >= PPBN) song_pos %= PPBN;
  } while (rx.header != 0);

  indicate(song_pos / PPQN);
}
