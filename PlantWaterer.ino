/**
 * Plant Waterer
 * Attach motor to motor shield channel A.
 * Attach soil capacitive sensor to A5.
 */

#define PLOT 1

#include <avr/interrupt.h>
#include "Motor.h"
#include "MoistureSensor.h"

MotorA motor;
MoistureSensor moistureSensor(A5);
float desiredVal = 0.63;
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

#if PLOT == 0
    Serial.print("Current: ");
    Serial.print(currentVal);
    Serial.print(" | ");
    Serial.print("Desired: ");
    Serial.print(desiredVal);
    Serial.print(" | ");
#endif
    interrupts();

    if (currentVal < desiredVal)
    {
#if PLOT == 0
        Serial.println("Pumping...");
#endif
        motor.spinForward(255);
        delay(1500);
        motor.brake();
        delay(10000);
    }
    else
    {
#if PLOT == 0
        Serial.println("No pump");
#endif
        delay(1000);
    }
}



ISR(TIMER1_COMPA_vect)
{
    currentVal = moistureSensor.sense();
#if PLOT == 0
    Serial.print("Sensing: ");
    Serial.println(currentVal);
#else
    Serial.print(currentVal*100);
    Serial.print(",");
    Serial.println(desiredVal*100);
#endif
}
