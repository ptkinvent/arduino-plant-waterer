/**
 * Plant Waterer
 * Attach motor to motor shield channel A.
 * Attach soil capacitive sensor to A5.
 */

#include <LiquidCrystal.h>
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
    // Desired moisture level is 0.31
    float desiredVal = 0.31;
    float currentVal = moistureSensor.sense();
    Serial.print("Current: ");
    Serial.print((1 - currentVal) * 100);
    Serial.print(" | ");
    Serial.print("Desired: ");
    Serial.print((1 - desiredVal) * 100);
    Serial.print(" | ");
    motor.brake();

    delay(500);
    if (currentVal > desiredVal)
    {
        Serial.println("Pumping...");
//        motor.spinForward(255);
//        delay(1500);
//        motor.brake();
//        delay(10000);
    }
    else
    {
        Serial.println("No pump");
    }
}
