#include "STEAMx_MicroBot.h"
servoMotor Servo;
void setup() {
  // put your setup code here, to run once:
  Servo.begin();
}
void loop() {
  // put your main code here, to run repeatedly:
Servo.servoAngle(0, 0);
delay(3000);
Servo.servoAngle(0, 180);
delay(3000);

}
