#include <Servo.h>


const int SWITCH_CW = 7;
const int SWITCH_CCW = 8;
const int SERVO_PIN = 5;

Servo myServo;


int servoPos = 90;


int cwState = HIGH;
int lastCwState = HIGH;

int ccwState = HIGH;
int lastCcwState = HIGH;

void setup() {
  myServo.attach(SERVO_PIN);
  myServo.write(servoPos);
  pinMode(SWITCH_CW, INPUT_PULLUP);
  pinMode(SWITCH_CCW, INPUT_PULLUP);
}

void loop() {
  cwState = digitalRead(SWITCH_CW);
  ccwState = digitalRead(SWITCH_CCW);
  if (cwState != lastCwState) {
    if (cwState == HIGH && lastCwState == LOW) { 
      servoPos = servoPos+10;
      if (servoPos > 180) servoPos = 180;
      myServo.write(servoPos);
    }
    delay(20);
  }
  lastCwState = cwState;
  if (ccwState != lastCcwState) {
    if (ccwState == HIGH && lastCcwState == LOW) { 
      servoPos = servoPos-10;
      if (servoPos < 0) servoPos = 0; 
      myServo.write(servoPos);
    }
    delay(20);
  }
  lastCcwState = ccwState;
}
