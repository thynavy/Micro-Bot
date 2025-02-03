#include "STEAMx_MicroMo.h"
Gyroscope Gyro;
int data[2];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Gyro.begin();
}
void loop() {
  // put your main code here, to run repeatedly:
  Gyro.getData(data);

  Serial.print(" Roll = ");
  Serial.print(data[0]);
  Serial.print("°");

  Serial.print(" Pitch = ");
  Serial.print(data[1]);
  Serial.println("°");
  delay(1000);
}
