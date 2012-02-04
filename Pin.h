#ifndef pin_h
#define pin_h

#include "WProgram.h"

/**
 * Pin
 *
 * Abstract base for classes representing specific numbered Arduino pins. 
 */
class Pin {
  protected:
    byte m_pin;
    Pin(byte pin): m_pin(pin) {}

  public:
  
    // Overloaded byte cast for compatibility with libraries expecting raw pin numbers.
    operator byte() { 
      return m_pin; 
    }
    
  private:
    // Copy constructor and assignment operator are private, ensuring that each Pin is explicitly constructed
    // just once at the beginning of a program, and only passed by reference thereafter.
    Pin(const Pin& rhs);
    Pin& operator=(const Pin& pin);
};


#endif
