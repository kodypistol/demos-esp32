#pragma once

#include <Arduino.h>

class Led {
public:
  Led(int pin);
  void begin();
  void on();
  void off();

private:
  int pin;
};
