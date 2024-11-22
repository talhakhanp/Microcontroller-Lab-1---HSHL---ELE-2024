/// code for the tinkercad simulation

// BY TALHA KHAN ONLY FOR EDUCATIONAL PURPOSES

// // **MASTER**

// Pin Definitions
int buttonPin = 8;  // pin connected to the button

void setup() {
  Serial.begin(9600);               // initialize serial communication
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  // // check if the button is pressed
  if (digitalRead(buttonPin) == LOW) {
    delay(50); // // debounce delay
    if (digitalRead(buttonPin) == LOW) {  // check again to confirm press
      Serial.println(1);  // // send signal to slave
      delay(1000);            // // prevent multiple signals for one press
    }
  }
}
