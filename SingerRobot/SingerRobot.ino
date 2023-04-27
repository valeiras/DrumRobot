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
bool hasAutomaticStart = true;
Songs automaticSong = HOUND_DOG;

const byte openPos1 = 140;
const byte openPos2 = 140;
const byte openPos3 = 160;
const byte closedPos1 = 180;
const byte closedPos2 = 180;
const byte closedPos3 = 180;

const byte vibratoAmp = 0;

byte closedPositions[NB_SINGERS] = { closedPos1, closedPos2, closedPos3 };
byte openPositions[NB_SINGERS] = { openPos1, openPos2, openPos3 };

// A variable should be declared volatile whenever its value can be changed by something beyond
// the control of the code section in which it appears, such as a concurrently executing thread.
volatile bool isNoteOn[NB_SINGERS] = { 0, 0, 0 };
volatile bool isPeak[NB_SINGERS] = { 0, 0, 0 };
volatile uint8_t count[NB_SINGERS] = { 0, 0, 0 };
volatile uint8_t count2toggle[NB_SINGERS] = { 0, 0, 0 };

//This is the period of the timer. It will depend on its configuration, which is now set as 40kHz
const int ts = 25;  // sampling period in us

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
  song->createPredefinedPatterns(HOUND_DOG, false);

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
  if (hasAutomaticStart) {
    roboController->processStartSongMsg(automaticSong);
  }
}

/* Install the Interrupt Service Routine (ISR) for Timer2. */
ISR(TIMER2_COMPA_vect) {
  for (unsigned int ii = 0; ii < NB_SINGERS; ii++) {
    if (isNoteOn[ii]) {
      //count[ii]++;
      if (++count[ii] == count2toggle[ii]) {
        isPeak[ii] = !isPeak[ii];
        digitalWrite(buzzPins[ii], isPeak[ii]);
        count[ii] = 0;
      }
    }
  }
}

void loop() {
  unsigned long currTime = millis();
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
  // This code was modified from the one in https://www.instructables.com/Arduino-Timer-Interrupts/
  cli();  // stop interrupts

  TCCR2A = 0;  // set entire TCCR2A register to 0
  TCCR2B = 0;  // same for TCCR2B
  TCNT2 = 0;   //initialize counter value to 0
  // set compare match register for 40000kHz increments
  // I am using half the theoretical sampling period, obtaining lower notes. I have read somewhere that
  // we actually only had acces to this 8MHz sampling frequency. I don't know if this is accurate, but I like the sound better
  OCR2A = 24;  // = (8*10^6) / (40000*8) - 1 (must be <256)
  // OCR2A = 49;  // = (16*10^6) / (40000*8) - 1 (must be <256)
  // turn on CTC mode
  TCCR2A |= (1 << WGM21);
  // Set CS21 bit for 8 prescaler
  TCCR2B |= (1 << CS21);
  // enable timer compare interrupt
  TIMSK2 |= (1 << OCIE2A);

  sei();  //allow interrupts
}