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

#define SEMIQUAVERS_PER_WHOLE_NOTE 16
#define SEMIQUAVERS_PER_HALF_NOTE 8
#define SEMIQUAVERS_PER_QUARTER_NOTE 4
#define SEMIQUAVERS_PER_QUAVER 2

#define NB_SPOTLIGHTS 6
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

  void treatStartMsg();
  void treatStopMsg();
  void treatResyncMsg();
  void treatBpmChangeMsg(uint8_t messageContent);
  void treatBpmIdxChangeMsg(uint8_t messageContent);
  void treatModeChangeMsg(uint8_t messageContent);
  void treatBrightnessChangeMsg(uint8_t messageContent);
  void treatSetResyncTimeMsg(uint16_t messageContent);

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

  void printMatrixName();
  void printMatrixLogo();
  void printMatrixRectangles();
  void printMatrixBars();

  void clearAllLights();
  void clearMeters();
  void clearMatrix();
  void turnOnMatrix();
  void turnOffSpotlights();
  void turnOnSpotlights();

  void checkNoteChanges(unsigned long currTime);

  uint8_t matrixMode_, spotlightMode_;
  float bpm_;
  unsigned int w_, h_, nbMtxHor_;
  FastLED_NeoMatrix *fastLedMatrix_;

  int spotlightPins_[NB_SPOTLIGHTS], meterPins_[NB_METERS];
  int currSpotlight_;

  uint16_t primaryColors_[NB_PRIMARY_COLORS], paletteColors_[NB_PALETTE_COLORS];
  int x_, currColorIndex_, currBitmap_;
  bool hasStarted_, firstAfterStart_, firstAfterStop_, firstAfterMatrixModeChange_, firstAfterSpotlightModeChange_, matrixOn_, spotlightsOn_;
  bool isBpmChangePending_, isBrightnessChangePending_;
  float pendingBpm_, pendingBrightness_;

  unsigned long lastSemiquaverChange_, semiquaverInterval_;
  unsigned long lastQuarterNoteChange_, quarterNoteInterval_;
  unsigned int semiquaverCount_;

  bool wholeNoteChange_, halfNoteChange_, quarterNoteChange_, quaverChange_, semiquaverChange_;
  unsigned int halfSize_;
  bool matrixPending_;
};

#endif