#include <Servo.h>

#define SERVO_PIN 6
#define SENSOR_PIN A0
#define BUTTON_PIN 2

#define ORDER_STOP 90
#define ORDER_V_MIN 87
#define ORDER_V_MAX 59

Servo servo;
bool pressed, lastPressed;

unsigned long count = 0;
unsigned long sum = 0;

bool hasStarted = false;

void setup() {
  Serial.begin(9600);
  pinMode(SENSOR_PIN, INPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  lastPressed = false;

  servo.attach(SERVO_PIN);
  servo.write(ORDER_STOP);
  //servo.write((ORDER_V_MIN + ORDER_V_MAX)/2);
}

void loop() {
  if (!hasStarted) {
    pressed = digitalRead(BUTTON_PIN) == LOW;
    if (!pressed && lastPressed) {
      Serial.print("Start!");
      hasStarted = true;
    }
    lastPressed = pressed;
  } else {
    int currRead = analogRead(SENSOR_PIN);
    sum += currRead;
    Serial.print("Current value: ");
    Serial.println(currRead);

    Serial.print("Current mean value: ");
    Serial.println(sum / ++count);
    Serial.println("--------------");
  }
}