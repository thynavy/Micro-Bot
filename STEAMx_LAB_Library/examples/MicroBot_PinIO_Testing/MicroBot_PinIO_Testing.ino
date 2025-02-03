#include "STEAMx_MicroBot.h"
ioPin IO;

void setup() {
  // put your setup code here, to run once:
  IO.ioMode(0, INPUT);
  IO.ioMode(1, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(IO.ioRead(0));

  IO.ioWrite(1, 0);
  delay(1000);
  IO.ioWrite(1, 1);
  delay(1000);
  
}
