
#include "mbed.h"
#include "arm_book_lib.h"
#include "dashboard_system.h"

#define TIME_INCREMENT_MS 10

int main()
{
    dashboardSystemInit();
    while (true) {
        dashboardSystemUpdate();
        delay(TIME_INCREMENT_MS);
    }
}
