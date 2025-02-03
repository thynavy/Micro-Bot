
#include "STEAMx_MicroBot.h"
#include "PCA9557.h"
#include "Wire.h"
#include "Adafruit_NeoPixel.h"
#include "Adafruit_PWMServoDriver.h"
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
//////////////////////////////////////////////////////////////////////////////////

Button::Button() {
  pinMode(6, INPUT_PULLUP);
}
int Button::readButton(){
  return digitalRead(6);
}

////////////////////////////////////////////////////////////////////////////////// LED

buzzerPin::buzzerPin(int pin) {
  LEDpin = pin;
  pinMode(LEDpin, OUTPUT);
}

void buzzerPin::on() {
  digitalWrite(LEDpin, HIGH);
}

void buzzerPin::off() {
  digitalWrite(LEDpin, LOW);
}

void buzzerPin::blink(int delayMs) {
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

PCA9557 io(0x18, &Wire);

motor::motor() {
}
void motor::begin() {
  Wire.begin();
  io.pinMode(INA_M1, OUTPUT);  //Motor 1
  io.pinMode(INB_M1, OUTPUT);
  pinMode(PWM_M1, OUTPUT);

  io.pinMode(INA_M2, OUTPUT);  //Motor 2
  io.pinMode(INB_M2, OUTPUT);
  pinMode(PWM_M2, OUTPUT);

  io.pinMode(INA_M3, OUTPUT);  //Motor 3
  io.pinMode(INB_M3, OUTPUT);
  pinMode(PWM_M3, OUTPUT);

  io.pinMode(INA_M4, OUTPUT);  //Motor 4
  io.pinMode(INB_M4, OUTPUT);
  pinMode(PWM_M4, OUTPUT);
}

void motor::motor1(bool direction, int speed) {
  if (direction == 0) {
    io.digitalWrite(INA_M1, 1);
    io.digitalWrite(INB_M1, 0);
    analogWrite(PWM_M1, speed);
  } else {
    io.digitalWrite(INA_M1, 0);
    io.digitalWrite(INB_M1, 1);
    analogWrite(PWM_M1, speed);
  }
}

void motor::motor2(bool direction, int speed) {
  if (direction == 0) {
    io.digitalWrite(INA_M2, 1);
    io.digitalWrite(INB_M2, 0);
    analogWrite(PWM_M2, speed);
  } else {
    io.digitalWrite(INA_M2, 0);
    io.digitalWrite(INB_M2, 1);
    analogWrite(PWM_M2, speed);
  }
}

void motor::motor3(bool direction, int speed) {
  if (direction == 0) {
    io.digitalWrite(INA_M3, 1);
    io.digitalWrite(INB_M3, 0);
    analogWrite(PWM_M3, speed);
  } else {
    io.digitalWrite(INA_M3, 0);
    io.digitalWrite(INB_M3, 1);
    analogWrite(PWM_M3, speed);
  }
}

void motor::motor4(bool direction, int speed) {
  if (direction == 0) {
    io.digitalWrite(INA_M4, 1);
    io.digitalWrite(INB_M4, 0);
    analogWrite(PWM_M4, speed);
  } else {
    io.digitalWrite(INA_M4, 0);
    io.digitalWrite(INB_M4, 1);
    analogWrite(PWM_M4, speed);
  }
}

void motor::motorStop(int motorNum) {
  if (motorNum == 1) {
    io.digitalWrite(INA_M1, 0);
    io.digitalWrite(INB_M1, 0);
    analogWrite(PWM_M1, 0);
  } else if (motorNum == 2) {
    io.digitalWrite(INA_M2, 0);
    io.digitalWrite(INB_M2, 0);
    analogWrite(PWM_M2, 0);
  } else if (motorNum == 3) {
    io.digitalWrite(INA_M3, 0);
    io.digitalWrite(INB_M3, 0);
    analogWrite(PWM_M3, 0);
  } else if (motorNum == 4) {
    io.digitalWrite(INA_M4, 0);
    io.digitalWrite(INB_M4, 0);
    analogWrite(PWM_M4, 0);
  }
}
void motor::motorStopAll() {
  io.digitalWrite(INA_M1, 0);
  io.digitalWrite(INB_M1, 0);
  analogWrite(PWM_M1, 0);

  io.digitalWrite(INA_M2, 0);
  io.digitalWrite(INB_M2, 0);
  analogWrite(PWM_M2, 0);

  io.digitalWrite(INA_M3, 0);
  io.digitalWrite(INB_M3, 0);
  analogWrite(PWM_M3, 0);

  io.digitalWrite(INA_M4, 0);
  io.digitalWrite(INB_M4, 0);
  analogWrite(PWM_M4, 0);
}
//////////////////////////////////////////////////////////////////////////////////
PCA9557 ioOut(0x19, &Wire);
ioPin::ioPin(){

}
void ioPin::ioMode(int pin, int mode){
  ioOut.pinMode(pin, mode);

}
void ioPin::ioWrite(int pin, int state){
  ioOut.digitalWrite(pin,state);
}
int ioPin::ioRead(int pin){
  return ioOut.digitalRead(pin);
}
//////////////////////////////////////////////////////////////////////////////////
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

rgbPin::rgbPin() {
}
void rgbPin::begin() {
  strip.begin();  // Initialize NeoPixel object
}
void rgbPin::brightness(int Brightness) {
  strip.setBrightness(Brightness);  // Set BRIGHTNESS to about 4% (max = 255)
}
void rgbPin::rgbColor(int num, int Red, int Green, int Blue) {
  N = num;
  R = Red;
  G = Green;
  B = Blue;

  strip.setPixelColor(num, R, G, B);
  strip.show();
}


//////////////////////////////////////////////////////////////////////////////////
// Create PCA9685 object
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// Define pulse range for 180-degree servo
#define SERVOMIN 102  // Minimum pulse length count (~500µs)
#define SERVOMAX 512  // Maximum pulse length count (~2500µs)

// Function to convert angle (0-180) to pulse width
int angleToPulse(int angle) {
  return map(angle, 0, 180, SERVOMIN, SERVOMAX);
}

// Function to control a specific servo
void controlServo(int servoChannel, int angle) {
  if (servoChannel < 0 || servoChannel > 15) {
    Serial.println("Error: Servo channel out of range (0-15).");
    return;
  }
  if (angle < 0 || angle > 180) {
    Serial.println("Error: Angle out of range (0-180 degrees).");
    return;
  }

  int pulse = angleToPulse(angle);     // Convert angle to pulse width
  pwm.setPWM(servoChannel, 0, pulse);  // Send PWM signal
  Serial.print("Servo ");
  Serial.print(servoChannel);
  Serial.print(" set to ");
  Serial.print(angle);
  Serial.println(" degrees.");
}

servoMotor::servoMotor() {
}
void servoMotor::begin() {
  // Initialize PCA9685
  pwm.begin();
  pwm.setPWMFreq(50);  // Set frequency to 50Hz
}
void servoMotor::servoAngle(int N, int A) {

  controlServo(N, A);
}

//////////////////////////////////////////////////////////////////////////////////
//NRF_Transmit

RF24 radio(7, 8);  // CE, CSN

struct DataPackage {
  int data[8];
};

DataPackage dataToSend;
nrfTransmit::nrfTransmit() {
}
void nrfTransmit::address(const byte ad[6]) {
  radio.begin();
  radio.openWritingPipe(ad);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void nrfTransmit::nrfdataTransmit(int data0, int data1, int data2, int data3, int data4, int data5, int data6, int data7) {
  if (millis() - last_time_nRFtransmit > 100){
    last_time_nRFtransmit = millis();

    dataToSend.data[0] = data0;
    dataToSend.data[1] = data1;
    dataToSend.data[2] = data2;
    dataToSend.data[3] = data3;
    dataToSend.data[4] = data4;
    dataToSend.data[5] = data5;
    dataToSend.data[6] = data6;
    dataToSend.data[7] = data7;
    if (radio.write(&dataToSend, sizeof(dataToSend))) {
      Serial.print("Data sent successfully");
    } else {
      Serial.print("Data transmission failed");
    }
  }


}

//////////////////////////////////////////////////////////////////////////////////
//NRF_Receiver
DataPackage dataReceived;

nrfReceiver::nrfReceiver() {
}

void nrfReceiver::address(const byte ad[6]) {
  radio.begin();
  radio.openReadingPipe(1, ad);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}
void nrfReceiver::getData(int data[8]) {
  if (millis() - last_time_nRFreceive > 50){
    last_time_nRFreceive = millis();
    if (radio.available()) {
      radio.read(&dataReceived, sizeof(dataReceived));
      // Serial.print("Received data: ");
      for (int i = 0; i < 8; i++) {
        data[i] = dataReceived.data[i];
      }
    }
  }

}