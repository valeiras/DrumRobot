#include <Servo.h>

#define SERVO_PIN 6
#define SENSOR_PIN A0
#define BUTTON_PIN 2

#define ORDER_STOP 90

#define ORDER_T_MAX 87
#define ORDER_T_MIN 59
#define ORDER_V_MIN 87
#define ORDER_V_MAX 59
#define T_MIN 1542
#define T_MAX 19000

#define SENSOR_MIN 0
#define SENSOR_MAX 683

Servo servo;
int currRead;
int maxRead = 0;
bool pressed, lastPressed;
unsigned long timeEllapsed, timeStart;

void setup() {
  Serial.begin(9600);
  servo.attach(SERVO_PIN);
  pinMode(SENSOR_PIN, INPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  lastPressed = false;

  servo.write(ORDER_V_MIN);
  maxRead = analogRead(SENSOR_PIN);
}

void loop() {
  currRead = analogRead(SENSOR_PIN);
  if(currRead > maxRead){
    maxRead = currRead;
  }
  pressed = digitalRead(BUTTON_PIN) == LOW;
  if(!pressed && lastPressed){
    Serial.print("Max sensor value: ");
    Serial.println(maxRead);
  }
  lastPressed = pressed;
}
