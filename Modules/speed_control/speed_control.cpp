#include "mbed.h"
#include "arm_book_lib.h"

#include "speed_control.h"
#include "motor.h"

#define TIME_INCREMENT_MS                       10

AnalogIn gasPedal(A0);

float speedPercentage = 0.0;

void speedControlInit() {

}

void speedControlUpdate() {
    speedPercentage = gasPedal.read();
    setMotorSpeed(speedPercentage);
}

float getSpeedPercentage() {
    speedPercentage = gasPedal.read();
    return speedPercentage;
}
