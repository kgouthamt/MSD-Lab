#include <Servo.h>
Servo myServo;
int servo_pin = 5;


void setup(){
  myServo.attach(servo_pin);
}

void loop() {
  for (int pos = 0; pos <= 180; pos += 1) { 
    myServo.write(pos);
    delay(15);
  }
  

  for (int pos = 180; pos >= 0; pos -= 1) { 
    myServo.write(pos);
    delay(15);
  }
}
