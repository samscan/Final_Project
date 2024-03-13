//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "system_state.h"

//=====[Declaration of private defines]========================================

#define TIME_INCREMENT_MS                       10
#define DEBOUNCE_BUTTON_TIME_MS                 40

//=====[Declaration of private data types]=====================================

typedef enum {
    BUTTON_UP,
    BUTTON_DOWN,
    BUTTON_FALLING,
    BUTTON_RISING
} buttonState_t;

//=====[Declaration and initialization of public global objects]===============

DigitalIn ignition(D10);
DigitalOut engine(LED2);

//=====[Declaration and initialization of public global variables]=============

buttonState_t ignitionButtonState;
int accumulatedDebounceButtonTime = 0;
int ignitionPressedDebounceTime = 0;

//=====[Declarations (prototypes) of private functions]========================

void checkStartEngine();
void checkStopEngine();
void debounceButtonInit();
bool debounceButtonUpdate();

//=====[Implementations of public functions]===================================

void systemStateInit()
{
    //initializes the ignition button 
    ignition.mode(PullUp);
    debounceButtonInit();
}

void systemStateUpdate()
{
    //updates the engine based on the ignition button 
    if(!engine) {
        checkStartEngine();
    }
    else {
        checkStopEngine();
    }
    ignitionPressedDebounceTime = ignitionPressedDebounceTime + TIME_INCREMENT_MS;
}

bool getSystemState()
{
    //returns whether the engine is on or off 
    if (engine == ON) {
        return ON;
    }
    else {
        return OFF;
    }
}

//=====[Implementations of private functions]==================================

void checkStartEngine(){
    //checks whether the engine is being started 
    bool ignitionButtonReleasedEvent = debounceButtonUpdate();
    if(ignitionButtonReleasedEvent){
        engine = ON;
        ignitionPressedDebounceTime = 0;
    }
    
}

void checkStopEngine(){
    //checks whether the engine is being stopped 
    bool ignitionButtonReleasedEvent = debounceButtonUpdate();
    if(ignitionButtonReleasedEvent){
        engine = OFF;
        ignitionPressedDebounceTime = 0;
    }
}

bool debounceButtonUpdate()
{
    //debounces the ignition button and returns whether the button is being released 
    bool ignitionReleasedEvent = false;
    switch( ignitionButtonState ) {
    
    case BUTTON_UP:
        if( ignition == 1 ) {
            ignitionButtonState = BUTTON_FALLING;
            accumulatedDebounceButtonTime = 0;
        }
        break;

    case BUTTON_FALLING:
        if( accumulatedDebounceButtonTime >= DEBOUNCE_BUTTON_TIME_MS ) {
            if( ignition == 1 ) {
                ignitionButtonState = BUTTON_DOWN;
            } else {
                ignitionButtonState = BUTTON_UP;
            }
        }
        accumulatedDebounceButtonTime = accumulatedDebounceButtonTime +
                                        TIME_INCREMENT_MS;
        break;

    case BUTTON_DOWN:
        if( ignition == 0 ) {
            ignitionButtonState = BUTTON_RISING;
            accumulatedDebounceButtonTime = 0;
        }
        break;

    case BUTTON_RISING:
        if( accumulatedDebounceButtonTime >= DEBOUNCE_BUTTON_TIME_MS ) {
            if( ignition == 0 ) {
                ignitionButtonState = BUTTON_UP;
                ignitionReleasedEvent = true;
            }
            else {
                ignitionButtonState = BUTTON_DOWN;
            }
        }
        accumulatedDebounceButtonTime = accumulatedDebounceButtonTime +
                                        TIME_INCREMENT_MS;
        break;

    default:
        debounceButtonInit();
        break;
    }
    return ignitionReleasedEvent;
}

void debounceButtonInit()
{
    //determines the initial state of the ignition button 
    if( ignition == 1) {
        ignitionButtonState = BUTTON_UP;
    } else {
        ignitionButtonState = BUTTON_DOWN;
    }
}
