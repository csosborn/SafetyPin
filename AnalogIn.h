#ifndef analog_in_h
#define analog_in_h

#include "Arduino.h"
#include "Pin.h"

/**
 * AnalogIn
 *
 * Pin subclass representing a specific input pin that when read produces analog values [0-1023].
 */
class AnalogIn : public Pin {
  public:
    AnalogIn(byte pin);
    
    unsigned int read();
};

#endif
