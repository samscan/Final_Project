//=====[#include guards - begin]===============================================

#ifndef _USER_INTERFACE_H_
#define _USER_INTERFACE_H_

//=====[Declaration of public defines]=========================================

//=====[Declaration of public data types]======================================

//=====[Declarations (prototypes) of public functions]=========================

void userInterfaceInit();
void userInterfaceUpdate();
bool userInterfaceCodeCompleteRead();
void userInterfaceCodeCompleteWrite( bool state );

void userInterfaceDisplayInit();
void userInterfaceDisplayUpdate();


//=====[#include guards - end]=================================================

#endif // _USER_INTERFACE_H_