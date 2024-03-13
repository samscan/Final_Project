//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"
#include "speedometer.h"
#include "pc_serial_com.h"

//=====[Declaration and initialization of public global objects]===============

UnbufferedSerial uartUsb(USBTX, USBRX, 115200);

//=====[Implementations of public functions]===================================

void PC_SerialUpdate()
{
    //sends the current speed to the pc
    char RPMString[30] = "";
    sprintf(RPMString, "!%.0f\r\n", getSpeed());
    uartUsb.write( RPMString , 35 );
    
}
