#include "mbed.h"
#include "arm_book_lib.h"

#include "speed_control.h"

#define TIME_INCREMENT_MS                       10
#define DUTY_MIN 0
#define DUTY_MAX 1
#define PERIOD 0.000102

PwmOut motor(PF_8);
InterruptIn motorHallSensor(D11);

float motorSpeed;
int accumulatedTime = 0;

static void motorHallSensorCallback();

void motorInit() {
    motor.period(PERIOD);
    motor.write(DUTY_MIN);
    motorHallSensor.mode(PullDown);
    motorHallSensor.rise(&motorHallSensorCallback);
    motorSpeed = 0;
}

void motorUpdate() {
    accumulatedTime = accumulatedTime + TIME_INCREMENT_MS;
}

void setMotorSpeed(float speedPercentage) {
    motor.write(speedPercentage);
}

int getMotorSpeed() {
    return motorSpeed;
}

static void motorHallSensorCallback() {
    motorSpeed = 1.0 / accumulatedTime; 
    accumulatedTime = 0;
}
