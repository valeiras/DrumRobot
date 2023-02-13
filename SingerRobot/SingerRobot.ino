#include <Servo.h>

#include "singer_robot.h"
#include "singer_song.h"
#include "singer_robot_config.h"

// Since the tone() library uses timer2, which also controls PWM in pins 3 and 11, these cannot be used
#define SERVO_PIN_SINGER1 6
#define SERVO_PIN_SINGER2 9
#define SERVO_PIN_SINGER3 10
#define BUZZ_PIN_SINGER1 2
#define BUZZ_PIN_SINGER2 4
#define BUZZ_PIN_SINGER3 5

unsigned int initialDelay = 1000;
unsigned long currTime, initTime;

bool printOutput = false;
bool simulation = true;

SingerRobot singer;
SingerSong song;

const byte openPos = 160;
const byte closedPos = 180;
const byte vibratoAmp = 10;

unsigned long timeCurrSemiquaver, timePerSemiquaver, timeNextInstruction[NB_SINGERS];
bool nextInstruction[NB_SINGERS];
unsigned short bpm = 120;

bool toggle[NB_SINGERS] = { 0, 0, 0 };
bool noteOn[NB_SINGERS] = { 0, 0, 0 };
int count[NB_SINGERS] = { 0, 0, 0 };
int count2toggle[NB_SINGERS] = { 0, 0, 0 };

byte buzzPins[NB_SINGERS] = { BUZZ_PIN_SINGER1, BUZZ_PIN_SINGER2, BUZZ_PIN_SINGER3 };

const int ts = 64;  // sampling period in us

/* Timer reload value, globally available */
unsigned int tcnt2;

void setup() {
  Serial.begin(9600);

  // -------------------------------------------------------- Pattern setting ----------------------------------------------------------
  song.createPredefinedPatterns(C_SCALE, false);

  unsigned long timeQuarter = int(60000.0 / bpm);  // us per quarter note
  timePerSemiquaver = int(timeQuarter / 4.0);

  byte vibratoPins[NB_SINGERS] = { SERVO_PIN_SINGER1, SERVO_PIN_SINGER2, SERVO_PIN_SINGER3 };
  singer.attachServos(vibratoPins);
  singer.setVibratoParams(closedPos, openPos, vibratoAmp);
  singer.setServoSpeed(0.2);

  initTime = millis();

  /* First disable the timer overflow interrupt*/
  TIMSK2 &= ~(1 << TOIE2);

  /* Configure timer2 in normal mode (no PWM) */
  TCCR2A &= ~((1 << WGM21) | (1 << WGM20));
  TCCR2B &= ~(1 << WGM22);

  /* Select clock source: internal I/O clock */
  ASSR &= ~(1 << AS2);

  /* Disable Compare Match A interrupt (only overflow) */
  TIMSK2 &= ~(1 << OCIE2A);

  /* Configure the prescaler to CPU clock divided by 128 */
  TCCR2B |= (1 << CS22) | (1 << CS20);  // Set bits
  TCCR2B &= ~(1 << CS21);               // Clear bit

  /* We need to calculate a proper value to load the counter.
  * The following loads the value 248 into the Timer 2 counter
  * The math behind this is:
  * (Desired period) = 64us.
  * (CPU frequency) / (prescaler value) = 125000 Hz -> 8us.
  * (desired period) / 8us = 8.
  * MAX(uint8) – 8 = 248;
  */
  /* Save value globally for later reload in ISR */
  tcnt2 = 248;

  /* Finally load end enable the timer */
  TCNT2 = tcnt2;
  TIMSK2 |= (1 << TOIE2);

  //Configure I/O Pin Directions
  for (unsigned int ii = 0; ii < NB_SINGERS; ii++) {
    pinMode(buzzPins[ii], OUTPUT);
  }

  // makeNoteOn(0, currTime);
  makeNoteOn(0, FREQ_C04);
  delay(500);
  makeNoteOn(1, FREQ_E04);
  makeNoteOn(2, FREQ_G04);
  //makeNoteOn(1, currTime);
}

/* Install the Interrupt Service Routine (ISR) for Timer2. */
ISR(TIMER2_OVF_vect) {
  /* Reload the timer */
  TCNT2 = tcnt2;

  for (unsigned int ii = 0; ii < NB_SINGERS; ii++) {
    count[ii]++;
    if (noteOn[ii] && count[ii] == count2toggle[ii]) {
      digitalWrite(buzzPins[ii], toggle[ii] == 0 ? HIGH : LOW);
      toggle[ii] = !toggle[ii];
      count[ii] = 0;
    }
  }
}

void loop() {
  currTime = millis() - initTime;

  // for (unsigned int singerIdx = 0; singerIdx < NB_SINGERS; singerIdx++) {
  //   if (currTime >= timeNextInstruction[singerIdx]) {
  //     if (nextInstruction[singerIdx] == NOTE_ON) {
  //       makeNoteOn(singerIdx, currTime);
  //     } else {
  //       makeNoteOff(singerIdx);
  //     }
  //     getNextNote(singerIdx);
  //   }
  // }
  singer.checkVibrato(currTime, printOutput);

  // if (currTime >= timeCurrSemiquaver) {
  //   timeCurrSemiquaver += timePerSemiquaver;
  //   song.goToNextSemiquaver();
  // }
  // for (int ii = 0; ii < NB_NOTES_SG; ii++) {
  //   makeNoteOn(1, _freqs[ii]);
  //   delay(200);
  // }
}

void getNextNote(unsigned int singerIdx) {
  song.computeNextHit(singerIdx, printOutput);
  nextInstruction[singerIdx] = song.getVelNextHit(singerIdx);
  timeNextInstruction[singerIdx] = timeCurrSemiquaver + song.getSemiquaversToNextHit(singerIdx) * timePerSemiquaver;
}

void setBpm(unsigned short newBpm) {
  // bpm = newBpm;
  // unsigned long timeQuarter = int(60000.0 / bpm);  // us per quarter note
  // timePerSemiquaver = int(timeQuarter / 4.0);      // us per semiquaver note

  // // We update the Sing instructions
  // for (unsigned int singerIdx = 0; singerIdx < NB_SINGERS; singerIdx++) {
  //   timeNextInstruction[singerIdx] = timeCurrSemiquaver + song.getSemiquaversToNextHit(singerIdx) * timePerSemiquaver;
  // }
}

void makeNoteOn(int idx, int freq) {  //(int idx, unsigned long currTime) {
                                      //  int freq= song.getFreqNextHit(idx);

  singer.noteOn(idx, currTime);

  noteOn[idx] = true;
  count[idx] = 0;
  count2toggle[idx] = 1e6 / (2.0 * freq * ts);
}

void makeNoteOff(int idx) {
  digitalWrite(buzzPins[idx], LOW);
  noteOn[idx] = false;
}