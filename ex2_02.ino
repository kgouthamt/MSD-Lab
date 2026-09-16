const int IRpin = A0;
const int ledPin = 12; 

int threshold = 400;
void setup() { 
  pinMode(IRpin,INPUT); 
  pinMode(ledPin,OUTPUT); 
} 
void loop() { 
	int IRread = analogRead(IRpin); 
  if (IRread < threshold) { 
    digitalWrite(ledPin, HIGH); // Object detected -> Turn LED ON
  } else {
    digitalWrite(ledPin, LOW);  // No object detected -> Turn LED OFF
  }
} 
