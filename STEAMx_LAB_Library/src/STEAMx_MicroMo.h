#ifndef STEAMx_MicroMo_h
#define STEAMx_MicroMo_h
#include <Arduino.h>
#include <Wire.h>
#include <math.h>



////////////////////////////////////////////////////////////////////////////////// LED
class button {
  public:

    button();          // Constructor
    int readButton();          
  private:
};

////////////////////////////////////////////////////////////////////////////////// LED
class LED {
  public:
  long last_time;
  int state_blink = 0;
    LED();          // Constructor
    void on();             // Turn LED on
    void off();            // Turn LED off
    void blink(int delayMs); // Blink LED
  private:
    int LEDpin;              // Pin connected to the LED
};
//////////////////////////////////////////////////////////////////////////////////
class Vibration {
  public:
    Vibration();          // Constructor
    void on();             // Turn LED on
    void off();            // Turn LED off
  private:
};
//////////////////////////////////////////////////////////////////////////////////
// MPU6050 I2C address
#define MPU6050_ADDR 0x68

// MPU6050 register addresses
#define ACCEL_XOUT_H 0x3B
#define PWR_MGMT_1   0x6B
#define ACCEL_CONFIG 0x1C
#define GYRO_CONFIG  0x1B
#define CONFIG       0x1A

class Gyroscope {
public:
    Gyroscope();
    void begin();
    void getData(int data[2]);
    // void writeMPU6050(uint8_t reg, uint8_t value);
    // void readMPU6050(uint8_t startReg, int16_t &x, int16_t &y, int16_t &z);

private:
void writeMPU6050(uint8_t reg, uint8_t value) {
    Wire.beginTransmission(MPU6050_ADDR);
    Wire.write(reg);
    Wire.write(value);
    Wire.endTransmission();
}
void readMPU6050(uint8_t startReg, int16_t &x, int16_t &y, int16_t &z) {
    Wire.beginTransmission(MPU6050_ADDR);
    Wire.write(startReg);
    Wire.endTransmission(false);
    Wire.requestFrom(MPU6050_ADDR, 6);

    x = (Wire.read() << 8) | Wire.read();
    y = (Wire.read() << 8) | Wire.read();
    z = (Wire.read() << 8) | Wire.read();
}
};









//////////////////////////////////////////////////////////////////////////////////

#endif

