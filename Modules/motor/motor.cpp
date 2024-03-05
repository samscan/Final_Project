#include "mbed.h"
#include "arm_book_lib.h"

#include "speed_control.h"

#define TIME_INCREMENT_MS                       10
#define DUTY_MIN 0
#define DUTY_MAX 1
#define PERIOD 0.000102

PwmOut motor(PF_8);

int motorRotCount = 0;

void motorInit() {
    motor.period(PERIOD);
    motor.write(DUTY_MIN);
    motorRotCount = 0;
}

void motorUpdate() {

}

void setMotorSpeed(float speedPercentage) {
    motor.write(speedPercentage);
}

int getMotorRotCount() {
    int value = motorRotCount; 
    motorRotCount = 0;
    return value;
}


//interupt - motorRotCount += 1