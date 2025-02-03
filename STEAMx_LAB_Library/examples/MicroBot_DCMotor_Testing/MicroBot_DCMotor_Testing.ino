#include "STEAMx_MicroBot.h"

motor myMotor;

void setup() {
  // put your setup code here, to run once:
  // Wire.begin();
  myMotor.begin();
}
void loop() {
  // put your main code here, to run repeatedly:
  myMotor.motor1(1, 250);
  myMotor.motor2(1, 250);
  myMotor.motor3(1, 250);
  myMotor.motor4(1, 250);
  delay(1500);
  myMotor.motorStopAll();
  delay(1500);
  myMotor.motor1(0, 250);
  myMotor.motor2(0, 250);
  myMotor.motor3(0, 250);
  myMotor.motor4(0, 250);
  delay(1500);
  myMotor.motorStopAll();
  delay(1500);
}
