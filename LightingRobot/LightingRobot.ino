#include "lighting_robot.h"

#define MATRIX_PIN 6

const int BRIGHTNESS = 32;
const int MATRIX_WIDTH = 16;
const int MATRIX_HEIGHT = 16;

LightingRobot lightRobot;

void setup() {
  Serial.begin(9600);
  lightRobot = LightingRobot(MATRIX_WIDTH, MATRIX_HEIGHT, MATRIX_PIN, BRIGHTNESS, LIGHTING_ADDRESS);
  lightRobot.setReceptor();
}

void loop() {
  lightRobot.doLighting();
  delay(100);
}
