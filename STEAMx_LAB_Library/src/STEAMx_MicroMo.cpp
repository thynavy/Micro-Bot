#include "STEAMx_MicroMo.h"


////////////////////////////////////////////////////////////////////////////////// LED

button::button() {
  pinMode(6, INPUT_PULLUP);
}
int button::readButton(){
  return digitalRead(6);
}
////////////////////////////////////////////////////////////////////////////////// LED

LED::LED (){
  LEDpin = 2;
  pinMode(LEDpin, OUTPUT);
}

void LED::on() {
  digitalWrite(LEDpin, HIGH);
}

void LED::off() {
  digitalWrite(LEDpin, LOW);
}

void LED::blink(int delayMs) {
  if (millis() - last_time > delayMs) {
    last_time = millis();
    if (state_blink == 0) {
      on();
      state_blink = 1;
    } else if (state_blink == 1) {
      off();
      state_blink = 0;
    }
  }
}

//////////////////////////////////////////////////////////////////////////////////

Vibration::Vibration (){
  pinMode(4, OUTPUT);
}

void Vibration::on() {
  digitalWrite(4, HIGH);
}

void Vibration::off() {
  digitalWrite(4, LOW);
}

//////////////////////////////////////////////////////////////////////////////////
Gyroscope::Gyroscope(){

}

void Gyroscope::begin(){
      Wire.begin();

    // Wake up MPU6050
    writeMPU6050(PWR_MGMT_1, 0x00);

    // Set accelerometer range to ±8G (0x10 = ±8G)
    writeMPU6050(ACCEL_CONFIG, 0x10);

    // Set gyro range to ±500 degrees/sec (0x08 = ±500 deg/s)
    writeMPU6050(GYRO_CONFIG, 0x08);

    // Set filter bandwidth to 21 Hz (0x04 = 21Hz)
    writeMPU6050(CONFIG, 0x04);

    delay(100);
}

void Gyroscope::getData(int data[2]){
   int16_t accX, accY, accZ;
    readMPU6050(ACCEL_XOUT_H, accX, accY, accZ);

    // Convert raw accelerometer data to g (assuming ±8G range)
    float accX_g = accX / 4096.0;
    float accY_g = accY / 4096.0;
    float accZ_g = accZ / 4096.0;

    // Calculate roll (X-axis rotation) from -180 to 180 degrees
    float roll = atan2(accY_g, accZ_g) * 180.0 / M_PI;

    // Calculate pitch (Y-axis rotation) from -180 to 180 degrees
    float pitch = atan2(-accX_g, sqrt(accY_g * accY_g + accZ_g * accZ_g)) * 180.0 / M_PI;

    // Extend pitch to -180 to 180 by checking Z-axis direction
    if (accZ_g < 0) {
        pitch = (pitch > 0) ? (180 - pitch) : (-180 - pitch);
    }

    // Normalize roll values to -180 to 180
    if (roll > 180) roll -= 360;
    if (roll < -180) roll += 360;
    data[0] = roll;
    data[1] = pitch;
    // // Print the results
    // Serial.print("Roll: ");
    // Serial.print(roll);
    // Serial.print("°, Pitch: ");
    // Serial.println(pitch);

    // delay(100);
}