#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4, 8, 12, 13);

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  Serial.begin(9600);
}

void loop() {
  int ldrValue = analogRead(A3); 
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("LDR Value:");     
  
  lcd.setCursor(0, 1);
  lcd.print(ldrValue);   

  Serial.print("LDR Value:");
  Serial.println(ldrValue);
  
  delay(200);  
}
