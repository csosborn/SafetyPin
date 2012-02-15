#include "WProgram.h"
#include "DigitalOut.h"

DigitalOut::DigitalOut(byte pin): Pin(pin) {
  pinMode(m_pin, OUTPUT);
  write(false);
}

void DigitalOut::low() {
  write(false);
}
  
void DigitalOut::high() {
  write(true);
}

void DigitalOut::write(bool value) {
  digitalWrite(m_pin, value);
}

bool DigitalOut::read() {
	return digitalRead(m_pin);
}