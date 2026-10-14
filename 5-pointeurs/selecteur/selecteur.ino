#include "Led.h"
#include "Color.h"

Led bigLed(23);
Led smallLed(2);

Led *current = &bigLed;

void setup() {
  Serial.begin(115200);
  bigLed.begin();
  smallLed.begin();

  int red = 0;
  int green = 0;
  int blue = 0;
  hexToRgb("#6f56a3", &red, &green, &blue);

  Serial.println(red);
  Serial.println(green);
  Serial.println(blue);
}

void loop() {
  current->on();
  delay(500);
  current->off();
  delay(500);

  if (current == &bigLed) {
    current = &smallLed;
  } else {
    current = &bigLed;
  }
}
