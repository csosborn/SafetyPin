#ifndef digital_in_h
#define digital_in_h

#include "Arduino.h"
#include "Pin.h"

/**
 * DigitalIn
 *
 * Pin subclass representing a specific input pin that may be read either high or low.
 */
class DigitalIn : public Pin {	
  public:
    
    DigitalIn(byte pin);
    DigitalIn(byte pin, bool enablePullUp);

    bool read() const;
};

#endif


