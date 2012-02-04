#include "WProgram.h"
#include "AnalogIn.h"

AnalogIn::AnalogIn(byte pin): Pin(pin) {
  pinMode(m_pin, INPUT);
}
    
unsigned int AnalogIn::read() {
  return analogRead(m_pin);
}

