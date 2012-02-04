#include "WProgram.h"
#include "DigitalOut.h"

DigitalOut::DigitalOut(byte pin): Pin(pin) {
  pinMode(m_pin, OUTPUT);
}

void DigitalOut::low() {
  digitalWrite(m_pin, LOW);
}
  
void DigitalOut::high() {
  digitalWrite(m_pin, HIGH);
}

