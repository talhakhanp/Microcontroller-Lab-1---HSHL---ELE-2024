/// code for the tinkercad simulation

// BY TALHA KHAN ONLY FOR EDUCATIONAL PURPOSES

void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop()
{
  digitalWrite(3, LOW);  
  digitalWrite(2, HIGH);  // red only
  delay(5000);
  
  digitalWrite(3, HIGH); // // red + yellow
  delay(2000);
  
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
   digitalWrite(4, HIGH); // green
  delay(5000); 
  
  digitalWrite(4, LOW);
  digitalWrite(3, HIGH); // // yellow
  delay(2000);
  
}
