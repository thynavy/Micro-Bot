#include "STEAMx_MicroBot.h"
nrfReceiver nRF;  
int data[8];

void setup() {
  Serial.begin(9600);
  nRF.address("00003");
}

void loop() {
  nRF.getData(data);
  Serial.print(" Data0 = ");
  Serial.print(data[0]);
  Serial.print(" Data1 = ");
  Serial.print(data[1]);
  Serial.print(" Data2 = ");
  Serial.print(data[2]);
  Serial.print(" Data3 = ");
  Serial.print(data[3]);
  Serial.print(" Data4 = ");
  Serial.print(data[4]);
  Serial.print(" Data5 = ");
  Serial.print(data[5]);
  Serial.print(" Data6 = ");
  Serial.print(data[6]);
  Serial.print(" Data7 = ");
  Serial.println(data[7]);

}
