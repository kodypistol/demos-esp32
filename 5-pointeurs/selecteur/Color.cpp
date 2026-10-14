#include "Color.h"

const String HEX_DIGITS = "0123456789abcdef";

int hexPairToNumber(String pair) {
  int tens = HEX_DIGITS.indexOf(pair[0]);
  int units = HEX_DIGITS.indexOf(pair[1]);
  return tens * 16 + units;
}

void hexToRgb(String hex, int *red, int *green, int *blue) {
  hex.replace("#", "");
  hex.toLowerCase();

  *red = hexPairToNumber(hex.substring(0, 2));
  *green = hexPairToNumber(hex.substring(2, 4));
  *blue = hexPairToNumber(hex.substring(4, 6));
}
