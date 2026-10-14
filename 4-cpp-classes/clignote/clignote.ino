#include "Led.h"

Led slowLed(23, 1000);
Led fastLed(2, 200);

void setup() {
  slowLed.begin();
  fastLed.begin();
}

void loop() {
  slowLed.update();
  fastLed.update();
}
