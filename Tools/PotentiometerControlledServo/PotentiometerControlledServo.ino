#include <Servo.h>

Servo servo1;
const int SERVOPIN = 9;
const int POTPIN = A0;

int potVal;
int ang;

void setup() {
  servo1.attach(SERVOPIN);
  Serial.begin(9600);
}

void loop() {
  potVal = analogRead(POTPIN);
  ang = map(potVal, 0, 1023, 0, 180);
  servo1.write(ang);
  delay(100);
  Serial.print("Lectura: ");
  Serial.print(potVal);
  Serial.print(", angulo: ");
  Serial.println(ang);
}
