#ifndef digital_out_h
#define digital_out_h

#include "Arduino.h"
#include "Pin.h"

/**
 * DigitalOut
 *
 * Pin subclass representing a specific output pin that may be driven either high or low.
 */
class DigitalOut : public Pin {	
  public:
    
    DigitalOut(byte pin);

    void low();
    void high();
	void write(bool value);
	bool read();
};

#endif


