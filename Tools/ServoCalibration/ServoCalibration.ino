#include <Servo.h>

#define SERVO_PIN 6

Servo servo1;

void setup() {
  servo1.attach(SERVO_PIN);
}

void loop() {
  // put your main code here, to run repeatedly:
  servo1.write(180);
  delay(100);
  servo1.write(180);
  delay(100);
}
