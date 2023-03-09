#include "lighting_robot.h"

#define SPOTLIGHT_PIN1 2
#define SPOTLIGHT_PIN2 3
#define SPOTLIGHT_PIN3 4
#define SPOTLIGHT_PIN4 5
#define SPOTLIGHT_PIN5 6
#define SPOTLIGHT_PIN6 7
#define LED_MATRIX_PIN 9

const int BRIGHTNESS = 64;
const int MATRIX_WIDTH = 16;
const int MATRIX_HEIGHT = 16;

LightingRobot lightRobot;

int bpm = 120;

int spotlightPins[NB_SPOTLIGHTS] = {SPOTLIGHT_PIN1, SPOTLIGHT_PIN2, SPOTLIGHT_PIN3, SPOTLIGHT_PIN4, SPOTLIGHT_PIN5, SPOTLIGHT_PIN6};

void setup() {
  Serial.begin(9600);
  lightRobot = LightingRobot(MATRIX_WIDTH, MATRIX_HEIGHT, LED_MATRIX_PIN, spotlightPins, BRIGHTNESS, LIGHTING_ADDRESS, bpm);
  lightRobot.setReceptor();
}

void loop() {
  lightRobot.doLighting(millis());
}
