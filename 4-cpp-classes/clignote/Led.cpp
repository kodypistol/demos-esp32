#include "Led.h"

Led::Led(int pin, unsigned long intervalMs) {
  this->pin = pin;
  this->intervalMs = intervalMs;
  lastToggleAt = 0;
  isOn = false;
}

void Led::begin() {
  pinMode(pin, OUTPUT);
}

void Led::update() {
  unsigned long now = millis();

  if (now - lastToggleAt < intervalMs) {
    return;
  }

  lastToggleAt = now;
  isOn = !isOn;
  digitalWrite(pin, isOn);
}
