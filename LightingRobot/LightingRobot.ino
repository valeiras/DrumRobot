#include "lighting_robot.h"

#define MATRIX_PIN 6
#define LIGHT_PIN1 4

const int BRIGHTNESS = 32;
const int MATRIX_WIDTH = 16;
const int MATRIX_HEIGHT = 16;

LightingRobot lightRobot;

int bpm = 120;

void setup() {
  Serial.begin(9600);
  lightRobot = LightingRobot(MATRIX_WIDTH, MATRIX_HEIGHT, MATRIX_PIN, LIGHT_PIN1, BRIGHTNESS, LIGHTING_ADDRESS, bpm);
  lightRobot.setReceptor();
}

void loop() {
  lightRobot.doLighting(millis());
}
