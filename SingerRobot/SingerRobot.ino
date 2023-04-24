#include <percu_controller.h>
#include <robo_communication.h>

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

bool hasOutput = false;
bool isSimulation = false;
bool hasVibrato = true;

const byte openPos1 = 150;
const byte openPos2 = 140;
const byte openPos3 = 140;
const byte closedPos1 = 180;
const byte closedPos2 = 180;
const byte closedPos3 = 180;

const byte vibratoAmp = 0;

byte closedPositions[NB_SINGERS] = {closedPos1, closedPos2, closedPos3};
byte openPositions[NB_SINGERS] = {openPos1, openPos2, openPos3};

bool isNoteOn[NB_SINGERS] = { 0, 0, 0 };
bool isPeak[NB_SINGERS] = { 0, 0, 0 };

int count[NB_SINGERS] = { 0, 0, 0 };
int count2toggle[NB_SINGERS] = { 0, 0, 0 };

const int ts = 64;  // sampling period in us

/* Timer reload value, globally available */
unsigned int tcnt2;

byte buzzPins[NB_SINGERS] = { BUZZ_PIN_SINGER1, BUZZ_PIN_SINGER2, BUZZ_PIN_SINGER3 };
byte vibratoPins[NB_SINGERS] = { SERVO_PIN_SINGER1, SERVO_PIN_SINGER2, SERVO_PIN_SINGER3 };

SingerRobot *robot;
SingerSong *song;
PercuController<NB_SINGERS, NB_POS_JOINTS_SG, BITS_FOR_POS_SG> *roboController;

void setup() {
  Serial.begin(9600);

  // -------------------------------------------------------- Pattern setting ----------------------------------------------------------
  song = new SingerSong();
  song->createPredefinedPatterns(C_SCALE, false);

  // -------------------------------------------------------- Servo attaching ----------------------------------------------------------
  robot = new SingerRobot(vibratoPins);
  robot->setVibrato(hasVibrato);
  robot->setVibratoParams(closedPositions, openPositions, vibratoAmp);
  robot->setServoSpeed(0.2);

  // Configure buzzPins for output and the timer
  for (unsigned int ii = 0; ii < NB_SINGERS; ii++) {
    pinMode(buzzPins[ii], OUTPUT);
  }

  configureTimer2();

  // -------------------------------------------------------- Creation of the controller ------------------------------------------------
  roboController = new PercuController<NB_SINGERS, NB_POS_JOINTS_SG, BITS_FOR_POS_SG>(robot, song, SINGER_ADDRESS, isSimulation, hasOutput);
  roboController->setReceptor();
}

/* Install the Interrupt Service Routine (ISR) for Timer2. */
ISR(TIMER2_OVF_vect) {
  /* Reload the timer */
  TCNT2 = tcnt2;

  for (unsigned int ii = 0; ii < NB_SINGERS; ii++) {
    count[ii]++;
    if (isNoteOn[ii] && count[ii] == count2toggle[ii]) {
      isPeak[ii] = !isPeak[ii];
      digitalWrite(buzzPins[ii], isPeak[ii]);
      count[ii] = 0;
    }
  }
}

void loop() {
  unsigned int currTime = millis();
  roboController->goToTime(currTime, hasOutput);
  for (unsigned int singerIdx = 0; singerIdx < NB_SINGERS; singerIdx++) {
    if (robot->isNoteOn(singerIdx)) {
      if (robot->isNoteOnPending(singerIdx)) {        
        makeNoteOn(singerIdx, robot->getFrequency(singerIdx));
        robot->startVibrato(singerIdx, currTime);
        robot->unsetNoteOnPending(singerIdx);
      }
      robot->checkVibrato(singerIdx, currTime);
    } else if (robot->isNoteOffPending(singerIdx)) {
      makeNoteOff(singerIdx);
      robot->stopVibrato(singerIdx);
      robot->unsetNoteOffPending(singerIdx);
    }
  }
}

void makeNoteOn(int idx, int freq) {  //(int idx, unsigned long currTime) {
                                      //  int freq= song.getFreqNextHit(idx);
  isNoteOn[idx] = true;
  count[idx] = 0;
  count2toggle[idx] = 1e6 / (2.0 * freq * ts);

  isPeak[idx] = true;
  digitalWrite(buzzPins[idx], HIGH);
}

void makeNoteOff(int idx) {
  digitalWrite(buzzPins[idx], LOW);
  isNoteOn[idx] = false;
}

void configureTimer2() {
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
}