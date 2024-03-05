#include "mbed.h"
#include "arm_book_lib.h"

#include "speedometer.h"
#include "speed_control.h"
#include "motor.h"

#define TIME_INCREMENT_MS                       10

int accumulatedTime = 0;
float speed;

void speedometerInit() {
    speedControlInit();
    motorInit();
}

void speedometerUpdate() {
    speedControlUpdate();

}

float getSpeed() {
    if (accumulatedTime >= 100) {
        float rps = getMotorRotCount() / 0.1;
        float rpm = rps * 60.0;
        speed = rpm;
    }
    else {
        accumulatedTime = accumulatedTime + TIME_INCREMENT_MS;
    }
    return speed;
}
