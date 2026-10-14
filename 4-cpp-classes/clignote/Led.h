#pragma once

#include <Arduino.h>

class Led {
public:
  Led(int pin, unsigned long intervalMs);
  void begin();
  void update();

private:
  int pin;
  unsigned long intervalMs;
  unsigned long lastToggleAt;
  bool isOn;
};
