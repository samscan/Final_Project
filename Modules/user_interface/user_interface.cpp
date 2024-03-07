#include "mbed.h"
#include "arm_book_lib.h"

#include "display.h"
#include "motor.h"
#include "user_interface.h"

#define DISPLAY_REFRESH_TIME_MS         1000
#define SYSTEM_TIME_INCREMENT_MS        10

static void userInterfaceDisplayInit()
{
    displayInit();
     
    displayCharPositionWrite ( 0,0 );
    displayStringWrite( "Spd:" );

    displayCharPositionWrite ( 0,1 );
    displayStringWrite( "Dis:" );
    
}

static void userInterfaceDisplayUpdate()
{
    static int accumulatedDisplayTime = 0;
    char speedString[2] = "";
    char distanceString[4] = ""
    
    if( accumulatedDisplayTime >=DISPLAY_REFRESH_TIME_MS ) {

        accumulatedDisplayTime = 0;

        sprintf(speedString, "%.0f", getSpeed());
        //12
        displayCharPositionWrite (  4,0 );
        displayStringWrite( speedString );
        displayCharPositionWrite ( 7,0 );
        displayStringWrite( "MPH" );

       

        sprintf(distanceString, "%.0f", getDistance());
        
        displayCharPositionWrite ( 5,1 );
        displayStringWrite( speedString );
        displayCharPositionWrite ( 9,1 );
        displayStringWrite( "MI." );

    }
    else {
        accumulatedDisplayTime =
            accumulatedDisplayTime + SYSTEM_TIME_INCREMENT_MS;        
    } 
}