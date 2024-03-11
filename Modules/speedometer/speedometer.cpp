#include "mbed.h"
#include "arm_book_lib.h"

#include "speedometer.h"
#include "speed_control.h"
#include "motor.h"

#define TIME_INCREMENT_MS                       10
#define WHEEL_DIAMETER 0.5

int accumulatedTime = 0;
float speed;

float accumulatedDistance = 0.0;

void distanceUpdate();

void speedometerInit() {
    speedControlInit();
    motorInit();
}

void speedometerUpdate() {
    speedControlUpdate();
    motorUpdate();
    distanceUpdate();
    accumulatedTime = accumulatedTime + TIME_INCREMENT_MS;
}

float getSpeed() {
    float rps = getMotorSpeed();
    float rpm = rps * 60.0;
    float rph = rpm * 60.0;
    float iph = rpm * 2.0 * 3.14159 * .667;
    return iph;
}

void distanceUpdate() {
    float reps = getMotorSpeed() * TIME_INCREMENT_MS / 1000.0;
    float distanceTravelled = reps * 2.0 * 3.14159 * .667;
    accumulatedDistance = accumulatedDistance + distanceTravelled;
}

float getDistance() {
    return accumulatedDistance;
}
