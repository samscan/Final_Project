//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "motor.h"
#include "speed_control.h"

//=====[Declaration of private defines]========================================

#define DUTY_MIN 0
#define DUTY_MAX 1
#define PERIOD 0.000102
#define MAX_SPEED 0.7776

//=====[Declaration and initialization of public global objects]===============

PwmOut motor(PF_8);

//=====[Implementations of public functions]===================================

void motorInit() {
    //initializes the motor output 
    motor.period(PERIOD);
    motor.write(DUTY_MIN);
}

void setMotorSpeed(float speedPercentage) {
    //sets the speed of the motor based on the percentage recieved 
    motor.write(speedPercentage);
}

float getMotorSpeed() {
    //returns the speed of the motor based on the speed percentage updating the motor 
    float speedPercentage = getSpeedPercentage();
    float rps = speedPercentage * MAX_SPEED;
    return rps;
}
