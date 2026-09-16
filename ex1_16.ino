const int BUTTON_PIN = 7;
const int LED_LSB = 11;
const int LED_MID = 12;
const int LED_MSB = 13;


int counter = 0;
int buttonState = 0;
int lastButtonState = 0;

void setup() {

  pinMode(LED_LSB, OUTPUT);
  pinMode(LED_MID, OUTPUT);
  pinMode(LED_MSB, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  buttonState = digitalRead(BUTTON_PIN);
  if (buttonState != lastButtonState) {
    if (buttonState == LOW) {
      counter = (counter + 1) % 8;
      updateLEDs(counter);
    }
    delay(50);
  }
  lastButtonState = buttonState;
}

void updateLEDs(int val) {
  digitalWrite(LED_LSB, (val >> 0) & 1); 
  digitalWrite(LED_MID, (val >> 1) & 1);
  digitalWrite(LED_MSB, (val >> 2) & 1);
}
