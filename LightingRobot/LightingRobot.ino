#include "lighting_robot.h"

#include <FastLED.h>
#include <FastLED_NeoMatrix.h>

// #define SPOTLIGHT_PIN1 2
// #define SPOTLIGHT_PIN2 3
// #define SPOTLIGHT_PIN3 8 // Pin 4 is not working
// #define SPOTLIGHT_PIN4 5
// #define SPOTLIGHT_PIN5 6
// #define SPOTLIGHT_PIN6 7

#define SPOTLIGHT_PIN1 2
#define SPOTLIGHT_PIN2 3
#define SPOTLIGHT_PIN3 4
#define SPOTLIGHT_PIN4 5
#define SPOTLIGHT_PIN5 7
#define SPOTLIGHT_PIN6 8

#define LED_MATRIX_PIN 9
#define METER_PIN1 11
#define METER_PIN2 12

// const int BRIGHTNESS = 64;
// const int MATRIX_WIDTH = 16;
// const int MATRIX_HEIGHT = 16;
// const int NB_MATRICES_HOR = 3;
// const int NB_MATRICES_VERT = 1;

const int BRIGHTNESS = 64;
const int MATRIX_WIDTH = 8;
const int MATRIX_HEIGHT = 8;
const int NB_MATRICES_HOR = 1;
const int NB_MATRICES_VERT = 1;

const int NUM_LEDS = MATRIX_WIDTH * MATRIX_HEIGHT * NB_MATRICES_HOR * NB_MATRICES_VERT;
CRGB leds[NUM_LEDS];

LightingRobot *lightRobot;

int spotlightPins[NB_SPOTLIGHTS] = { SPOTLIGHT_PIN1, SPOTLIGHT_PIN2, SPOTLIGHT_PIN3, SPOTLIGHT_PIN4, SPOTLIGHT_PIN5, SPOTLIGHT_PIN6 };
int meterPins[NB_METERS] = { METER_PIN1, METER_PIN2 };

void setup() {
  Serial.begin(9600);
  Serial.println("Setup");

  FastLED.addLeds<NEOPIXEL, LED_MATRIX_PIN>(leds, NUM_LEDS);
  FastLED_NeoMatrix *matrix = new FastLED_NeoMatrix(leds, MATRIX_WIDTH, MATRIX_HEIGHT, NB_MATRICES_HOR, NB_MATRICES_VERT,
                                                    NEO_MATRIX_TOP + NEO_MATRIX_LEFT + NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG);


  lightRobot = new LightingRobot(MATRIX_WIDTH, MATRIX_HEIGHT, NB_MATRICES_HOR, NB_MATRICES_VERT, matrix, spotlightPins, meterPins, BRIGHTNESS, LIGHTING_ADDRESS);
  lightRobot->setReceptor();
}

void loop() {
  lightRobot->doLighting(millis());
}
