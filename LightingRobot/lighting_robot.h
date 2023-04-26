#ifndef Lighting_robot_h
#define Lighting_robot_h

#include "gear.h"

#include <robo_receptor.h>
#include <robo_communication.h>
#include <bpm_values.h>

#include <Adafruit_GFX.h>
#include <FastLED.h>
#include <FastLED_NeoMatrix.h>

#include <math.h>

#define MS_PER_MIN 60000
#define SEMIQUAVERS_PER_BEAT 4

#define NB_BLINKING_INTERVALS 5

#define SEMIQUAVERS_PER_WHOLE_NOTE 16
#define SEMIQUAVERS_PER_HALF_NOTE 8
#define SEMIQUAVERS_PER_QUARTER_NOTE 4
#define SEMIQUAVERS_PER_QUAVER 2

#define NB_SPOTLIGHTS 6
#define NB_BOTTOM_SPOTLIGHTS 3
#define NB_METERS 2

#define NB_PRIMARY_COLORS 3
#define NB_PALETTE_COLORS 4

#define BAR_WIDTH 2

#define MAX_METER_OUTPUT 15

class LightingRobot : public RoboReceptor {
public:
  LightingRobot(int matrixWidth, int matrixHeight, int nbMatricesHor, int nbMatricesVert, FastLED_NeoMatrix *fastLedMatrix,
                int spotlightPins[NB_SPOTLIGHTS], int meterPins[NB_METERS], int brightness, int address);

  void setBpm(uint8_t bpm);
  void setBpm(float bpm);

  void doLighting(unsigned long currTime);

  void processStartMsg();
  void processStopMsg();
  void processResyncMsg();
  void processBpmChangeMsg(uint8_t messageContent);
  void processBpmIdxChangeMsg(uint8_t messageContent);
  void processMtxModeChangeMsg(uint8_t messageContent);
  void processSplModeChangeMsg(uint8_t messageContent);
  void processMtxBlinkChangeMsg(uint8_t messageContent);
  void processSplBlinkChangeMsg(uint8_t messageContent);
  void processBrightnessChangeMsg(uint8_t messageContent);
  void processSetResyncTimeMsg(uint16_t messageContent);

private:
  void doMatrixName();
  void doMatrixBlinking();
  void doMatrixLogo();
  void doMatrixRectangles();
  void doMatrixBars();

  void doSpotlightBlinking();
  void doSpotlightSequence();

  void doMeterMovement(unsigned long currTime);

  void initializeMatrixMode();
  void initializeSpotlightMode();
  void initializeSpotlightSequence();
  void initializeSpotlightBlinking();

  void printMatrixName();
  void printMatrixLogo();
  void printMatrixRectangles();
  void printMatrixBars();

  void clearAllLights();
  void clearMeters();
  void clearMatrix();
  void turnOnMatrix();

  void switchSpotlights(byte onOrOff);
  void switchSpotlightsTop(byte onOrOff);
  void switchSpotlightsBottom(byte onOrOff);

  void checkNoteChanges(unsigned long currTime);

  uint8_t matrixMode_;
  float bpm_;
  unsigned int w_, h_, nbMtxHor_;
  FastLED_NeoMatrix *fastLedMatrix_;

  int spotlightPins_[NB_SPOTLIGHTS], meterPins_[NB_METERS];
  uint8_t currSpotlight_;

  uint16_t primaryColors_[NB_PRIMARY_COLORS], paletteColors_[NB_PALETTE_COLORS];
  int x_, currColorIndex_, currBitmap_;
  bool hasStarted_, isFirstAfterStart_, isFirstAfterStop_, isFirstAfterMatrixModeChange_, isFirstAfterSpotlightModeChange_, isFirstAfterMatrixBlinkChange_, isFirstAfterSpotlightBlinkChange_;
  bool isMatrixOn_, areSpotlightsOn_;
  bool isBpmChangePending_, isBrightnessChangePending_;
  float pendingBpm_, pendingBrightness_;

  unsigned long lastSemiquaverChange_, semiquaverInterval_;
  unsigned long lastQuarterNoteChange_, quarterNoteInterval_;
  unsigned int semiquaverCount_;

  bool hasIntervalChanged_[NB_BLINKING_INTERVALS];
  uint8_t currMtxBlinkInterval_, currSplBlinkInterval_;
  uint8_t mtxOrderCount_;

  bool isSplBlinkOn_, isSplSeqOn_, isSplTopOn_, isSplBottomOn_;

  unsigned int halfSize_;
  bool isMatrixPending_;
};

#endif