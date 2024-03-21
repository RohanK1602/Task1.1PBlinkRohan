const int buttonPin = 2;    
const int ledPin = LED_BUILTIN; 
bool ledStatus = false;  // Checking LED state

// Morse code translation of Rohan
const String morseCode[] = {".-.", "---", "....", ".-", "-."};

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Check state of the button
  int buttonState = digitalRead(buttonPin);

  // Check if button is pressed, if it low, toggle LED on
  if (buttonState == LOW) {
    // Toggle the LED state
    ledStatus = !ledStatus;
    digitalWrite(ledPin, ledStatus ? HIGH : LOW);

    // Start morse code blink
    for (const String& code : morseCode) {
      blinkMorseCode(code);
    }

    // Wait for button release
    while (digitalRead(buttonPin) == LOW) {
      delay(10); // Wait for button release
    }
    delay(50); 
  }
}

void blinkMorseCode(String code) {
  for (char c : code) {
    if (c == '.') {
      digitalWrite(ledPin, HIGH);  // Turn LED on for a dot
      delay(250);  // Dot duration
    } else if (c == '-') {
      digitalWrite(ledPin, HIGH);  // Turn LED on for a dash
      delay(750);  // Dash duration
    }
    digitalWrite(ledPin, LOW);  // Turn LED off
    delay(250);  // Delay between dots and dashes
  }
}
