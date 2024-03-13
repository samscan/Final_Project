//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "speed_control.h"
#include "motor.h"

//=====[Declaration and initialization of public global objects]===============

AnalogIn gasPedal(A0);

//=====[Declaration and initialization of public global variables]=============

float speedPercentage = 0.0;

//=====[Implementations of public functions]===================================

void speedControlUpdate() {
    //sets the speed of the motor based off of the potentiometer reading 
    speedPercentage = gasPedal.read();
    setMotorSpeed(speedPercentage);
}

float getSpeedPercentage() {
    //determines the speed percentage from the potentiometer reading 
    speedPercentage = gasPedal.read();
    return speedPercentage;
}
