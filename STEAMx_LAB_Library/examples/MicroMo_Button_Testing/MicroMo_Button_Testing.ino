#include "STEAMx_MicroMo.h"
button value;
int Button_value;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Button_value = value.readButton();

  if (Button_value == 0) {
    Serial.print("Button Pressed = ");
    Serial.println(Button_value);
  } else {
    Serial.print("Button Released = ");
    Serial.println(Button_value);
  }
}
