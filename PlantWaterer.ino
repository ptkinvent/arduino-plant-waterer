/**
 * Plant Waterer
 * Attach motor to motor shield channel A.
 * Attach soil capacitive sensor to A0.
 */

#include "Motor.h"
#include "MoistureSensor.h"

MotorA motor;
MoistureSensor moistureSensor(A5);


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

    float val = moistureSensor.sense();
    Serial.println(val);
}
