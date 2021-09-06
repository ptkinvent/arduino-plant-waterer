/**
 * Plant Waterer
 * Attach motor to motor shield channel A.
 * Attach soil capacitive sensor to A5.
 */

#include <LiquidCrystal.h>
#include "Motor.h"
#include "MoistureSensor.h"

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
MotorA motor;
MoistureSensor moistureSensor(A5);


void setup()
{
    Serial.begin(9600);
    lcd.begin(16, 2);
}



void loop()
{
    // Desired moisture level is 0.31
    float desiredVal = 0.31;
    float currentVal = moistureSensor.sense();
    Serial.println(currentVal);
    lcd.setCursor(0, 0);
    lcd.print("Current: ");
    lcd.print(100 * (1 - currentVal));
    lcd.print("%");
    lcd.setCursor(0, 1);
    lcd.print("Desired: ");
    lcd.print(100 * (1 - desiredVal));
    lcd.print("%");
    motor.brake();

    delay(500);
    if (currentVal < desiredVal)
    {
        motor.spinForward(255);
        delay(1500);
        motor.brake();
        delay(10000);
    }
}
