#include "mbed.h"
#include "arm_book_lib.h"

#include "dashboard_system.h"
#include "system_state.h"
#include "speedometer.h"
#include "user_interface.h"
#include "pc_serial_com.h"

#define TIME_INCREMENT_MS                       10

void dashboardSystemInit() {
    systemStateInit();
    speedometerInit();
    userInterfaceDisplayInit();
}
void dashboardSystemUpdate() {
    systemStateUpdate();
    bool systemState = getSystemState();
    if (systemState == ON) {
        speedometerUpdate();
        userInterfaceDisplayUpdate();
        PC_SerialUpdate();
    }
}

