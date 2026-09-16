#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4, 8, 12, 13);

void setup() {

  lcd.begin(16, 2);
  

  lcd.setCursor(0, 0);
  lcd.print("Meowww!");
  

}

void loop() {

}
