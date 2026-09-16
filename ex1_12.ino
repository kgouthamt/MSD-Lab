#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4, 8, 12, 13);
int ledPin = 13;

int threshold = 400;

void setup() {
  pinMode(ledPin, OUTPUT);
  lcd.begin(16, 2);
  lcd.clear();
  Serial.begin(9600);
}

void loop() {
  int ldrValue = analogRead(A3); 
  String ledStatus = "";

  if (ldrValue < threshold) {
    digitalWrite(ledPin, HIGH);
    ledStatus = "ON ";
  } else {
    digitalWrite(ledPin, LOW);
    ledStatus = "OFF";
  }


  lcd.setCursor(0, 0);       
  lcd.print("LDR Value: ");
  lcd.print(ldrValue);
  lcd.print("    ");         

  lcd.setCursor(0, 1);       
  lcd.print("LED Status: ");
  lcd.print(ledStatus);

 
  Serial.print("LDR Value: ");
  Serial.print(ldrValue);
  Serial.print(" | LED Status: ");
  Serial.println(ledStatus);

  delay(300);  
}
