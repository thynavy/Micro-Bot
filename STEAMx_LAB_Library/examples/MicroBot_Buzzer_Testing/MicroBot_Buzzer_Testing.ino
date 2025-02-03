#include "STEAMx_MicroBot.h"
buzzerPin mybuzzer(4);

void setup() {
  // put your setup code here, to run once:

}
void loop() {
  // put your main code here, to run repeatedly:
  mybuzzer.blink(100);  
}
