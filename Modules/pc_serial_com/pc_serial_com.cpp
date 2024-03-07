//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"
#include "speedometer.h"
#include "pc_serial_com.h"

//=====[Declaration and initialization of public global objects]===============

UnbufferedSerial uartUsb(USBTX, USBRX, 115200);

//=====[Declaration and initialization of public global variables]=============
//=====[Declarations (prototypes) of public functions]=========================

//=====[Implementations of public functions]===================================

void PC_SerialUpdate()
{
    char RPMString[30] = "";
    sprintf(RPMString, "!%d\r\n", getSpeed());
    uartUsb.write( RPMString , 35 );
    
}

