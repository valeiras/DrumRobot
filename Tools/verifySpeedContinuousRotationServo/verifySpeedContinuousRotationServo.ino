#include <Servo.h>

#define SERVO_PIN 6
#define SENSOR_PIN A0
#define LED_PIN 13

#define ORDER_STOP 90

#define ORDER_T_MAX 87
#define ORDER_T_MIN 59
#define T_MIN 1542
#define T_MAX 19000

#define SENSOR_MIN 0
#define SENSOR_MAX 683

Servo servo;
int currRead, lastRead;
bool firstLoop;
int loopCount, securityCount;
unsigned long timeEllapsed, timeStart;

int currOrder = 76;

const int nbLoops = 100;

void setup() {
  Serial.begin(9600);
  servo.attach(SERVO_PIN);
  pinMode(SENSOR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  servo.write(currOrder);
  firstLoop = true;
  lastRead = analogRead(SENSOR_PIN);
  loopCount = 0;
  securityCount = 0;
}

void loop() {
  currRead = analogRead(SENSOR_PIN);
  if (currRead > 600 && lastRead < 100) {
    if (firstLoop) {
      firstLoop = false;
      timeStart = millis();
    } else {
      loopCount++;
      if (loopCount == nbLoops) {
        timeEllapsed = millis() - timeStart;
        servo.write(ORDER_STOP);
        Serial.println("-----------");
        Serial.print("Order: ");
        Serial.println(currOrder);
        Serial.print("Nb of loops: ");
        Serial.println(nbLoops);
        Serial.print("Time ellapsed: ");
        Serial.println(timeEllapsed);
        Serial.print("Ms per loop: ");
        Serial.println(float(timeEllapsed) / nbLoops);
        Serial.print("Expected time: ");
        float expectedTime = T_MIN + (T_MAX - T_MIN) / (ORDER_T_MAX - ORDER_T_MIN) * (currOrder - ORDER_T_MIN);
        Serial.println(expectedTime);
      }
    }
    digitalWrite(LED_PIN, HIGH);
    delay(100);
    digitalWrite(LED_PIN, LOW);
  }
  lastRead = currRead;
  delay(100);
}
