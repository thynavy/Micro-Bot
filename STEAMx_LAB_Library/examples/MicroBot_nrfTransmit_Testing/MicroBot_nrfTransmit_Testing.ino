#include "STEAMx_MicroBot.h"

rgbPin myRGB(3, 8);
nrfTransmit nRF;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  nRF.address("00003");
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
  nRF.nrfdataTransmit(1, 2, 3, 4, 5, 6, 7, 8);
  delay(500);
  nRF.nrfdataTransmit(10, 20, 30, 40, 50, 60, 70, 80);
  delay(500);
  nRF.nrfdataTransmit(10, 20, 30, 40, 50, 60, 70, 80);
  delay(500);
  nRF.nrfdataTransmit(110, 120, 130, 140, 150, 160, 170, 180);
  delay(500);
  Serial.println("   ");
}
