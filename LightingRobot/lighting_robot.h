#ifndef Lighting_robot_h
#define Lighting_robot_h

#include "gear.h"

#include <robo_receptor.h>
#include <robo_communication.h>

#include <Adafruit_GFX.h>
#include <FastLED.h>
#include <FastLED_NeoMatrix.h>

#include <math.h>

#define MS_PER_MIN 60000
#define SEMIQUAVERS_PER_BEAT 2

#define SEMIQUAVERS_PER_WHOLE_NOTE 16
#define SEMIQUAVERS_PER_HALF_NOTE 8
#define SEMIQUAVERS_PER_QUARTER_NOTE 4
#define SEMIQUAVERS_PER_QUAVER 2

#define NB_SPOTLIGHTS 6

#define NB_PRIMARY_COLORS 3
#define NB_PALETTE_COLORS 4

#define BAR_WIDTH 2

class LightingRobot : public RoboReceptor {
public:
  LightingRobot();
  LightingRobot(int matrixWidth, int matrixHeight, int nbMatricesHor, int nbMatricesVert, FastLED_NeoMatrix *fastLedMatrix,
                int spotlightPin[NB_SPOTLIGHTS], int brightness, int address);

  void setBpm(uint8_t bpm);

  void doLighting(unsigned long currTime);

  void treatStartMsg();
  void treatResyncMsg();
  void treatBpmChangeMsg(uint8_t messageContent);
  void treatModeChangeMsg(uint8_t messageContent);
  void treatSetResyncTimeMsg(uint16_t messageContent);

private:
  void doMatrixName(unsigned long ellapsedTime);
  void doMatrixBlinking(unsigned long ellapsedTime);
  void doMatrixLogo(unsigned long ellapsedTime);
  void doMatrixRectangles(unsigned long ellapsedTime);
  void doMatrixBars(unsigned long ellapsedTime);

  void doSpotlightBlinking(unsigned long ellapsedTime);
  void doSpotlightSequence(unsigned long ellapsedTime);

  void initializeMatrixMode();
  void initializeSpotlightMode();

  void printMatrixName();
  void printMatrixLogo();
  void printMatrixRectangles();
  void printMatrixBars();

  void clearAllLights();
  void clearMatrix();
  void turnOffSpotlights();
  void turnOnSpotlights();

  void checkNoteChanges(unsigned long currTime);

  uint8_t matrixMode_, spotlightMode_, bpm_;
  unsigned int w_, h_, nbMtxHor_;
  FastLED_NeoMatrix *fastLedMatrix_;

  int spotlightPins_[NB_SPOTLIGHTS];
  int currSpotlight_;

  uint16_t primaryColors_[NB_PRIMARY_COLORS], paletteColors_[NB_PALETTE_COLORS];
  int x_, currColorIndex_, currBitmap_;
  bool hasStarted_, matrixOn_, spotlightsOn_;

  unsigned long lastSemiquaverChange_, semiquaverInterval_;
  unsigned int semiquaverCount_;

  bool wholeNoteChange_, halfNoteChange_, quarterNoteChange_, quaverChange_, semiquaverChange_;
  unsigned int halfSize_;
};

#endif