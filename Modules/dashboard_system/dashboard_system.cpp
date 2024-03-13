//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "dashboard_system.h"
#include "system_state.h"
#include "speedometer.h"
#include "user_interface.h"
#include "pc_serial_com.h"

//=====[Implementations of public functions]===================================

void dashboardSystemInit() {
    //initializes all of the systems involved in the dashboard 
    systemStateInit();
    speedometerInit();
    userInterfaceDisplayInit();
}

void dashboardSystemUpdate() {
    //updates all of the systems involved in the dashboard
    systemStateUpdate();
    bool systemState = getSystemState();
    if (systemState == ON) {
        speedometerUpdate();
        userInterfaceDisplayUpdate();
        PC_SerialUpdate();
    }
}
