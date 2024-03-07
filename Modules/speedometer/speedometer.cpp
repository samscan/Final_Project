#include "mbed.h"
#include "arm_book_lib.h"

#include "speedometer.h"
#include "speed_control.h"
#include "motor.h"

#define TIME_INCREMENT_MS                       10
#define WHEEL_DIAMETER 0.5

int accumulatedTime = 0;
float speed;
float distance;

void speedometerInit() {
    speedControlInit();
    motorInit();
}

void speedometerUpdate() {
    speedControlUpdate();
    motorUpdate();

}

float getSpeed() {
    float rps = getMotorSpeed();
    float rpm = rps * 60.0;
    return rpm;
}

float getDistance() {
    //function to calculate distance traveled 
}
