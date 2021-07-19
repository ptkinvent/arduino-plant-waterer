/**
 * Plant Waterer
 * Attach motor to motor shield channel A.
 * Attach soil capacitive sensor to A5.
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
    // Desired moisture level is 0.28
    float val = moistureSensor.sense();
    Serial.println(val);

    if (val > 0.28)
    {
        motor.spinForward(255);
        delay(1500);
        motor.brake();
        delay(10000);
    }
}
