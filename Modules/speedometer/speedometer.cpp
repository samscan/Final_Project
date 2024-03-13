//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "speedometer.h"
#include "speed_control.h"
#include "motor.h"

//=====[Declaration of private defines]========================================

#define TIME_INCREMENT_MS 10
#define RADIUS .667

//=====[Declaration and initialization of public global variables]=============

float accumulatedDistance = 0.0;

//=====[Declarations (prototypes) of private functions]========================

void distanceUpdate();

//=====[Implementations of public functions]===================================

void speedometerInit() {
    //initializes the speedometer
    motorInit();
}

void speedometerUpdate() {
    //updates the speedometer
    speedControlUpdate();
    distanceUpdate();
}

float getSpeed() {
    //returns the speed in inches per hour after recieveing it in rotations per second 
    float rps = getMotorSpeed();
    float rpm = rps * 60.0;
    float rph = rpm * 60.0;
    float iph = rpm * 2.0 * 3.14159 * RADIUS;
    return iph;
}

float getDistance() {
    //returns the accumulated distance travelled by the vehicle 
    return accumulatedDistance;
}

//=====[Implementations of private functions]==================================

void distanceUpdate() {
    //updates the distance travelled based on the current speed during each time increments 
    float reps = getMotorSpeed() * TIME_INCREMENT_MS / 1000.0;
    float distanceTravelled = reps * 2.0 * 3.14159 * RADIUS;
    accumulatedDistance = accumulatedDistance + distanceTravelled;
}
