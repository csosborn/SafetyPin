#include "Arduino.h"
#include "DigitalIn.h"

DigitalIn::DigitalIn(byte pin): Pin(pin) {
  pinMode(m_pin, INPUT);
}

DigitalIn::DigitalIn(byte pin, bool enablePullUp): Pin(pin) {
	if (enablePullUp) {
		pinMode(m_pin, INPUT_PULLUP);
		digitalWrite(m_pin, HIGH);
	} else {
		pinMode(m_pin, INPUT);
	}
}

bool DigitalIn::read() const {
  return digitalRead(m_pin);
}
