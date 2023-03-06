#include <Arduino.h>
#include <robo_communication.h>

#include "music_box_controller.h"
#include "music_box_robot.h"

#define SERVO_PIN 6
#define SENSOR_PIN A0

MusicBoxRobot *robot = new MusicBoxRobot(SERVO_PIN, SENSOR_PIN);
MusicBoxSong *song = new MusicBoxSong();

MusicBoxController controller(MUSIC_BOX_ADDRESS, robot, song);

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
