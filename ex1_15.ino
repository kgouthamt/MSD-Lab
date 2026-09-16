#include <Servo.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4, 8, 12, 13);
Servo myServo;
int servo_pin = 5;
int angle = 0;
int val= 0;

void setup(){
  lcd.begin(16, 2);
  lcd.clear();
  myServo.attach(servo_pin);
  Serial.begin(9600);
}

void loop() {
  val = analogRead(A0);
  angle = map(val,0,1023,0,180);
  myServo.write(angle);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Angle:");     
  
  lcd.setCursor(0, 1);
  lcd.print(angle);   


  Serial.print("Angle:");
  Serial.println(angle);
  //Serial.print("INPUT:");
  //Serial.println(val);
  delay(20);
}
