/**
 * Plant Waterer
 * Attach motor to motor shield channel A.
 * Attach soil capacitive sensor to A0.
 */

#include "Motor.h"

MotorA motor;


void setup()
{
  Serial.begin(9600);
}



void loop()
{
  motor.spinForward(255);

  delay(1500);
  
  motor.brake();

  delay(3000);

  int val = analogRead(A0);
  Serial.println(val);
}
