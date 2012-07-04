#include "Arduino.h"
#include "PwmOut.h"

PwmOut::PwmOut(byte pin): Pin(pin) {
  pinMode(m_pin, OUTPUT);
}

void PwmOut::write(byte value) {
  analogWrite(m_pin, value);
}


