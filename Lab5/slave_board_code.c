/// code for the tinkercad simulation

// BY TALHA KHAN ONLY FOR EDUCATIONAL PURPOSES

// // **SLAVE**

// Pin Definitions
int trafficRedPin = 2;
int trafficYellowPin = 3;
int trafficGreenPin = 4;
int pedRedPin = 12;
int pedGreenPin = 13;


// Traffic Light States
int state = 0;  // 0 = red, 1 = red + yellow, 2 = green, 3 = yellow
bool pedestrianRequest = false;

void setup() {
  pinMode(trafficRedPin, OUTPUT);
  pinMode(trafficYellowPin, OUTPUT);
  pinMode(trafficGreenPin, OUTPUT);
  pinMode(pedRedPin, OUTPUT);
  pinMode(pedGreenPin, OUTPUT);

  // starting serial communication
  Serial.begin(9600);

  // // start with the traffic light + ped light both on red 
  digitalWrite(trafficRedPin, HIGH);
  digitalWrite(pedRedPin, HIGH);
}

void loop() {
  // check for incoming data from the master
  if (Serial.available() > 0) {
    char incomingData = Serial.read();
    if (incomingData == '1') {
      pedestrianRequest = true;  // set the pedestrian request flag
    }
  }

  switch (state) {
    case 0:  // // red light phase
      digitalWrite(trafficRedPin, HIGH);
      digitalWrite(trafficYellowPin, LOW);
      digitalWrite(trafficGreenPin, LOW);
      digitalWrite(pedRedPin, HIGH);
      digitalWrite(pedGreenPin, LOW);
      
      delay(10000);  // // wait for 10 seconds on red
      if (pedestrianRequest) {
        // // pedestrian walk phase
        digitalWrite(pedRedPin, LOW);
        digitalWrite(pedGreenPin, HIGH);
        delay(10000);  // // let pedestrians walk for 10 seconds
        pedestrianRequest = false;  // // reset the button press
      }
      state = 1;  // // go to the next phase
      break;
      
    case 1:  // // red + yellow light phase
      digitalWrite(trafficRedPin, HIGH);
      digitalWrite(trafficYellowPin, HIGH);
      digitalWrite(trafficGreenPin, LOW);
      delay(5000);  // // stay here for 5 seconds
      state = 2;  // // move to green
      break;
      
    case 2:  // // green light phase
      digitalWrite(trafficRedPin, LOW);
      digitalWrite(trafficYellowPin, LOW);
      digitalWrite(trafficGreenPin, HIGH);
      digitalWrite(pedRedPin, HIGH);
      digitalWrite(pedGreenPin, LOW);
      
      delay(10000);  // // green light stays for 10 seconds
      state = 3;  // // move to yellow light
      break;
      
    case 3:  // // yellow light phase
      digitalWrite(trafficRedPin, LOW);
      digitalWrite(trafficYellowPin, HIGH);
      digitalWrite(trafficGreenPin, LOW);
      delay(5000);  // // yellow light stays for 5 seconds
      state = 0;  // // go back to red light
      break;
  }
}
