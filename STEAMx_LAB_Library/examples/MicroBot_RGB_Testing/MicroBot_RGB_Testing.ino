#include "STEAMx_MicroBot.h"

rgbPin myRGB;
void setup() {
  // put your setup code here, to run once:
  myRGB.begin();
}
void loop() {
  // put your main code here, to run repeatedly:

  myRGB.brightness(10);
  myRGB.rgbColor(0, 255, 0, 0);
  myRGB.rgbColor(1, 0, 255, 0);
  delay(500);
  myRGB.brightness(20);
  myRGB.rgbColor(0, 0, 255, 0);
  myRGB.rgbColor(1, 255, 0, 0);
  delay(500);
}
