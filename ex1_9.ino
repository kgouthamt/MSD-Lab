int red_pin = 3;
int val = 0;
int intensity = 0;

void setup(){
  pinMode(red_pin,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  val = analogRead(A0);
  intensity = map(val,0,1023,0,255);
  analogWrite(red_pin, intensity);
  Serial.print("INPUT:");
  Serial.println(val);
  delay(20);int ldrValue = analogRead(ldrPin); // Read analog value from A3
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("LDR Value:");     // Print label on first row
  
  lcd.setCursor(0, 1);
  lcd.print(ldrValue);         // Print sensor reading on second row
  
  delay(200);  
}
