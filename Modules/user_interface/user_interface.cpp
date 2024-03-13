//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "display.h"
#include "motor.h"
#include "user_interface.h"
#include "speedometer.h"

//=====[Declaration of private defines]========================================

#define DISPLAY_REFRESH_TIME_MS         1000
#define SYSTEM_TIME_INCREMENT_MS        10

//=====[Implementations of public functions]===================================

void userInterfaceDisplayInit()
{
    //initializes the display 
    displayInit();
     
    displayCharPositionWrite ( 0,0 );
    displayStringWrite( "Spd:" );

    displayCharPositionWrite ( 0,1 );
    displayStringWrite( "Dis:" );
    
}

void userInterfaceDisplayUpdate()
{
    //updates the display to show the current speed and distacne traveled 
    static int accumulatedDisplayTime = 0;
    char speedString[2] = "";
    char distanceString[4] = "";
    
    if( accumulatedDisplayTime >=DISPLAY_REFRESH_TIME_MS ) {

        accumulatedDisplayTime = 0;

        sprintf(speedString, "%.0f", getSpeed());
        displayCharPositionWrite (  4,0 );
        displayStringWrite( speedString );
        displayStringWrite( "  IN   " );

        sprintf(distanceString, "%.0f", getDistance());
        
        displayCharPositionWrite ( 5,1 );
        displayStringWrite( distanceString );
        displayStringWrite( "  IN    " );

    }
    else {
        accumulatedDisplayTime =
            accumulatedDisplayTime + SYSTEM_TIME_INCREMENT_MS;        
    } 
}
