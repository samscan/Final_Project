#include "mbed.h"
#include "arm_book_lib.h"

#include "dashboard_system.h"
#include "system_state.h"
#include "speedometer.h"
#include "user_interface.h"

#define TIME_INCREMENT_MS                       10

void dashboardSystemInit() {
    systemStateInit();
    speedometerInit();
    userInterfaceDisplayInit();
}
void dashboardSystemUpdate() {
    systemStateUpdate();
    speedometerUpdate();
    userInterfaceDisplayUpdate();
}

