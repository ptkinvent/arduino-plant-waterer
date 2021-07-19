/**
 * @author Prateek Sahay
 * @date 7/19/21
 */

class AbstractMotor
{
public:
    /**
     * Motor channel can be either A or B
     */
    AbstractMotor(int directionPin, int speedPin, int brakePin, int currSensingPin) :
        _directionPin(directionPin),
        _speedPin(speedPin),
        _brakePin(brakePin),
        _currSensingPin(currSensingPin)
    {
        pinMode(_directionPin, OUTPUT); // Initiate direction pin
        pinMode(_brakePin, OUTPUT);     // Initiate brake pin
    };

    /**
     * Spin the motor clockwise
     */
    void spinForward(int speed)
    {
        digitalWrite(_directionPin, HIGH); // Establish forward direction
        digitalWrite(_brakePin, LOW);      // Disengage brake
        analogWrite(_speedPin, speed);     // Spin motor
    };

    /**
     * Spin the motor counterclockwise
     */
    void spinBackward(int speed)
    {
        digitalWrite(_directionPin, LOW);  // Establish backward direction
        digitalWrite(_brakePin, LOW);      // Disengage brake
        analogWrite(_speedPin, speed);     // Spin motor
    };

    /**
     * Brake the motor
     */
    void brake()
    {
        digitalWrite(_brakePin, HIGH); // Engage brake
    };

private:
    int _directionPin;
    int _speedPin;
    int _brakePin;
    int _currSensingPin;
};



class MotorA : public AbstractMotor
{
public:
    MotorA() : AbstractMotor(12, 3, 9, A0) {};
};



class MotorB : public AbstractMotor
{
public:
    MotorB() : AbstractMotor(13, 11, 8, A1) {};
};
