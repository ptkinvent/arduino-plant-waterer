/**
 * Plant Waterer
 * Attach motor to motor shield channel A.
 * Attach soil capacitive sensor to A5.
 */

#include <avr/interrupt.h>
#include <LiquidCrystal.h>
#include "Motor.h"
#include "MoistureSensor.h"

MotorA motor;
MoistureSensor moistureSensor(A5);
float desiredVal = 0.31;
float currentVal = desiredVal;


void setup()
{
    Serial.begin(9600);

    // Interrupt every 1s
    unsigned int reload = 0xF424;
    cli();
    TCCR1A = 0;
    TCCR1B = 0;
    OCR1A = reload;
    TCCR1B = (1<<WGM12) | (1<<CS11);
    TIMSK1 = (1<<OCIE1A);
    sei();
}



void loop()
{
    noInterrupts();

    Serial.print("Current: ");
    Serial.print((1 - currentVal) * 100);
    Serial.print(" | ");
    Serial.print("Desired: ");
    Serial.print((1 - desiredVal) * 100);
    Serial.print(" | ");

    interrupts();

    if (currentVal > desiredVal)
    {
        Serial.println("Pumping...");
        motor.spinForward(255);
        delay(1500);
        motor.brake();
        delay(10000);
    }
    else
    {
        Serial.println("No pump");
        delay(1000);
    }
}



ISR(TIMER1_COMPA_vect)
{
    currentVal = moistureSensor.sense();
    Serial.print("Sensing: ");
    Serial.println((1 - currentVal)*100);
}
