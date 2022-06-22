
// Declare variables
const int BUTTON_PIN = 53;
const int LED_UP = 51;
const int LED_DOWN = 49;
const int LED_LEFT = 47;
const int LED_RIGHT = 45;

void setup() {
  Serial.begin(9600);
  pinMode(LED_UP, OUTPUT);
  pinMode(LED_DOWN, OUTPUT);
  pinMode(LED_LEFT, OUTPUT);
  pinMode(LED_RIGHT, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  int buttonStatus = digitalRead(BUTTON_PIN);
  if (buttonStatus == LOW) { 
    // Check for serial connection
    if (Serial.available() > 0) {
      // Read serial string
      String data = Serial.readStringUntil('n');
  
      // Parse the data
      int firstline = data.indexOf('|');
      int secondline = data.indexOf('|', firstline + 1);
      int thirdline = data.indexOf('|', secondline + 1);
      int x = data.substring(0, firstline).toInt();
      int y = data.substring(firstline + 1, secondline - 1).toInt();
      //Serial.println(x);
  
      // Output to LEDs
      if (x > 0 && y > 0) {
        digitalWrite(LED_UP, HIGH);
        digitalWrite(LED_RIGHT, HIGH);
        digitalWrite(LED_DOWN, LOW);
        digitalWrite(LED_LEFT, LOW);
      }
      else if (x > 0 && y < 0) {
        digitalWrite(LED_DOWN, HIGH);
        digitalWrite(LED_RIGHT, HIGH);
        digitalWrite(LED_UP, LOW);
        digitalWrite(LED_LEFT, LOW);
      }  
      else if (x < 0 && y > 0) {
        digitalWrite(LED_UP, HIGH);
        digitalWrite(LED_LEFT, HIGH);
        digitalWrite(LED_DOWN, LOW);
        digitalWrite(LED_RIGHT, LOW);
      }  
      else if (x < 0 && y < 0) {
        digitalWrite(LED_DOWN, HIGH);
        digitalWrite(LED_LEFT, HIGH);
        digitalWrite(LED_UP, LOW);
        digitalWrite(LED_RIGHT, LOW);
      }  
    }
  //Serial.println("Button is LOW");  // For debugging push button
  }
  else {
    digitalWrite(LED_UP, LOW);
    digitalWrite(LED_RIGHT, LOW);
    digitalWrite(LED_DOWN, LOW);
    digitalWrite(LED_LEFT, LOW);
  }
  // Quick delay
  delay(10);
}
