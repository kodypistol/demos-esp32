#include "Led.h"

Led::Led(int pin) {
  this->pin = pin;
}

void Led::begin() {
  pinMode(pin, OUTPUT);
}

void Led::on() {
  digitalWrite(pin, HIGH);
}

void Led::off() {
  digitalWrite(pin, LOW);
}
