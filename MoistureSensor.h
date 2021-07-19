/**
 * @author Prateek Sahay
 * @date 7/19/21
 */

class MoistureSensor
{
public:
    /**
     * Plug moisture sensor into an analog pin of Grove shield.
     */
    MoistureSensor(int pin) : _pin(pin) {};

    /**
     * Returns moisture level 0-1
     */
    float sense()
    {
        int val = analogRead(_pin);
        float ratio = (float) val / 1024.0;
        return ratio;
    }

private:
    int _pin;
};
