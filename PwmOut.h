#ifndef pwm_out_h
#define pwm_out_h

#include "Arduino.h"
#include "Pin.h"

/**
 * PwmOut
 *
 * Pin subclass representing a specific output pin that encodes an analog value
 * using pulse width modulation.
 *
 * You may reasonably ask why this isn't called "AnalogOut", since it wraps the 
 * Arduino's analogWrite method. The answer is that it isn't an analog voltage 
 * output, which is what people normally think of when they think analog, and 
 * cannot be used in the same fashion: one could drive a motor with PWM or bias 
 * an amplifier with an analog voltage, but not vice versa. It is entirely 
 * possible that future Arduino hardware might include true steady-state analog 
 * voltage output pins for which the name AnalogOut would be much more appropriate.
 */
class PwmOut : public Pin {
  public:
    
    PwmOut(byte pin);

    void write(byte value);
};

#endif


