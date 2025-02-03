#include "STEAMx_MicroMo.h"
Vibration vibration;

void setup() {
  // put your setup code here, to run once:
}
void loop() {
  // put your main code here, to run repeatedly:
  vibration.on();
  delay(2000);
  vibration.off();
  delay(2000);
}
