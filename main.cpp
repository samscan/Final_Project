
#include "mbed.h"
#include "arm_book_lib.h"
#include "dashboard_system.h"

int main()
{
    dashboardSystemInit();
    while (true) {
        dashboardSystemUpdate();
    }
}
