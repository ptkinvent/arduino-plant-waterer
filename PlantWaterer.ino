/**
 * Plant Waterer
 * Attach motor to motor shield channel A.
 * Attach soil capacitive sensor to A0.
 */

// the setup function runs once when you press reset or power the board
void setup() {
  //Setup Channel A
  pinMode(12, OUTPUT); //Initiates Motor Channel A pin
  pinMode(9, OUTPUT); //Initiates Brake Channel A pin

  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  // forward @ full speed
  digitalWrite(12, HIGH); //Establishes forward direction of Channel A
  digitalWrite(9, LOW);   //Disengage the Brake for Channel A
  analogWrite(3, 0);   //Spins the motor on Channel A at full speed

  delay(1500);
  
  digitalWrite(9, HIGH); //Eengage the Brake for Channel A

  delay(3000);

  int val = analogRead(A0);
  Serial.println(val);
}
