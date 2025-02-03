#ifndef STEAMx_MicroBot_h
#define STEAMx_MicroBot_h
#include <Arduino.h>
#include "Adafruit_NeoPixel.h"
#include "Adafruit_PWMServoDriver.h"
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
////////////////////////////////////////////////////////////////////////////////// LED
class Button {
  public:

    Button();          // Constructor
    int readButton();          
  private:
};

////////////////////////////////////////////////////////////////////////////////// LED
class buzzerPin {
  public:
  long last_time;
  int state_blink = 0;
    buzzerPin(int pin);          // Constructor
    void on();             // Turn LED on
    void off();            // Turn LED off
    void blink(int delayMs); // Blink LED
  private:
    int LEDpin;              // Pin connected to the LED
};
//////////////////////////////////////////////////////////////////////////////////

#define INA_M1 0
#define INB_M1 1
#define PWM_M1 3

#define INA_M2 2
#define INB_M2 3
#define PWM_M2 5

#define INA_M3 4
#define INB_M3 5
#define PWM_M3 9

#define INA_M4 6
#define INB_M4 7
#define PWM_M4 10

class motor {
public:
  motor();
  void begin();
  void motor1(bool direction, int speed);
  void motor2(bool direction, int speed);
  void motor3(bool direction, int speed);
  void motor4(bool direction, int speed);
  void motorStop(int motorNum);
  void motorStopAll();
// private:
};
//////////////////////////////////////////////////////////////////////////////////
class ioPin {
public:
  ioPin();
  void ioMode(int pin, int mode);
  void ioWrite(int pin, int state);
  int ioRead(int pin);

// private:
};
//////////////////////////////////////////////////////////////////////////////////

#define LED_PIN 2
#define LED_COUNT 8

class rgbPin {

  int R;
  int G;
  int B;
  int N;
  public:
    rgbPin();          // Constructor
    void begin();
    void rgbColor(int num, int Red, int Green, int Blue);             // Turn LED on
    void brightness(int Brightness);            // Turn LED off
    void blink(int delayMs); // Blink LED
  private:
    int rgbpin;              // Pin connected to the LED
};

//////////////////////////////////////////////////////////////////////////////////

class servoMotor {
  public:
    servoMotor();          // Constructor
    void begin();
    void servoAngle(int N, int A);
  private:
};
//////////////////////////////////////////////////////////////////////////////////

class nrfTransmit {
  long last_time_nRFtransmit;
  public:

    nrfTransmit();          // Constructor
    void nrfdataTransmit(int data0, int data1, int data2, int data3, int data4, int data5, int data6, int data7);
    void address(const byte ad[6]);
  private:
  
};
//////////////////////////////////////////////////////////////////////////////////
class nrfReceiver {
  long last_time_nRFreceive;
public:
    nrfReceiver();
    void address(const byte ad[6]);
    void getData(int data[8]);

private:
    // RF24 radio;
    // const byte address[6] = "00003";
    // struct DataPackage {
    //     int data[8];
    // } dataReceived;
};

//////////////////////////////////////////////////////////////////////////////////
#endif

