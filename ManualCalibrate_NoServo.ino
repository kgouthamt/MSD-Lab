/*
  Manual calibration of the LDR + tri-colour LED colour sensor (no servo / base motor).
  Place the sensor over the white patch by hand before running.

  ASSUMED WIRING (change the pins below to match your kit):
    Tri-colour LED  : R -> D7, G -> D8, B -> D9  (each colour in series with its own potentiometer)
    LDR (divider)   : A0
    Stop push button: D10 to GND (INPUT_PULLUP, pressed = LOW)
    16x2 LCD        : RS=12, E=11, D4=5, D5=4, D6=3, D7=2
*/
#include <LiquidCrystal.h>

// ---------- pins ----------
const int LED_R = 9;
const int LED_G = 11;
const int LED_B = 10;
const int LDR_PIN = A2;
const int STOP_BTN = 7;

// ---------- settings ----------
const int LDR_SETTLE_MS = 500;   // 50-100 ms delay before every LDR read
const int LOOP_DELAY_MS = 600;   // small delay at the end of each iteration

LiquidCrystal lcd(2, 3, 4, 8, 12, 13);

// Shine ONE colour, wait, read the LDR, switch the colour off again
int readColour(int ledPin) {
  digitalWrite(LED_R, LOW);
  digitalWrite(LED_G, LOW);
  digitalWrite(LED_B, LOW);
  digitalWrite(ledPin, HIGH);
  delay(LDR_SETTLE_MS);            // LDR needs time to settle
  int value = analogRead(LDR_PIN);
  digitalWrite(ledPin, LOW);
  return value;
}

// Waits for ms milliseconds; returns true if the stop button was pressed meanwhile
bool waitForStop(int ms) {
  unsigned long start = millis();
  while (millis() - start < (unsigned long)ms) {
    if (digitalRead(STOP_BTN) == LOW) {
      delay(30);                   // debounce
      if (digitalRead(STOP_BTN) == LOW) return true;
    }
  }
  return false;
}

void ManualCalibrate() {
  lcd.clear();
  lcd.print("Sensor on WHITE");
  lcd.setCursor(0, 1);
  lcd.print("Press BTN = done");
  delay(2000);

  while (true) {
    // i. read reflected intensity for R, G, B
    int r = readColour(LED_R);
    int g = readColour(LED_G);
    int b = readColour(LED_B);

    // ii. show on LCD (16x2: R,G on line 1; B and max colour on line 2)
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("R:");  lcd.print(r);
    lcd.print(" G:"); lcd.print(g);

    // iii. maximum reading = minimum intensity -> this is the reference
    int maxVal = min(r, min(g, b));
    char maxCol = (maxVal == r) ? 'R' : (maxVal == g) ? 'G' : 'B';
    lcd.setCursor(0, 1);
    lcd.print("B:");  lcd.print(b);
    lcd.setCursor(8, 1);
    lcd.print("Max:");
    lcd.print(maxCol);

    Serial.print("R:"); Serial.print(r);
    Serial.print("  G:"); Serial.print(g);
    Serial.print("  B:"); Serial.print(b);
    Serial.print("  Max="); Serial.println(maxCol);

    // iv. small delay; stop command exits the loop
    if (waitForStop(LOOP_DELAY_MS)) break;
  }

  lcd.clear();
  lcd.print("Calibration done");
  delay(1500);
}

void setup() {
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
  pinMode(STOP_BTN, INPUT_PULLUP);
  Serial.begin(9600);
  lcd.begin(16, 2);

  ManualCalibrate();
}

void loop() {
  // rest of your program
}
