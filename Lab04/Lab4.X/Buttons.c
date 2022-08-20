

/**
 * @file
 * This library implements the interface Buttons.h to the 4 pushbuttons on the Digilent Basic IO shield for their
 * Uno32 development board platform..
 *
 */

#include <stdint.h>
#include <genericTypeDefs.h>

// We rely on this file to define various macros for working with the hardware buttons.
#include "BOARD.h"
#include "Buttons.h"

static int lastState = 0x00; //preserve last state of BUTTON_STATES())
static uint8_t lastButtonState = 0x00; //preserve last button state of 8 bit ButtonFlag
static int debounce = BUTTONS_DEBOUNCE_PERIOD; //debounce time limit
static int currentState = 0x00; //preserve current state
/**
 * This function initializes the proper pins such that the buttons 1-4 may be used by modifying
 * the necessary bits in TRISD/TRISF. Only the bits necessary to enable the 1-4 buttons are
 * modified, so that this library does not interfere with other libraries.
 */
void ButtonsInit(void){
    TRISD |= 0x00E0;
    TRISF |= 0x0002;
}

/**
 * ButtonsCheckEvents function checks the current button states and returns
 * any events that have occured since its last
 * call.  This function should be called repeatedly in a Timer ISR, though it can
 * be called in main() during testing.
 *
 * In normal use, this function should only be used after ButtonsInit().
 * 
 * This function should assume that the buttons start in an off state with 
 * value 0. Therefore if no buttons are
 * pressed when ButtonsCheckEvents() is first called, 
 * BUTTONS_EVENT_NONE should be returned. 
 * 
 * @return  Each bit of the return value corresponds to one ButtonEvent flag,
 *          as described in Buttons.h.  If no events are detected, BUTTONS_EVENT_NONE is returned.
 * 
 * Note that more than one event can occur simultaneously, though this situation is rare.
 * To handle this, the output should be a bitwise OR of all applicable event flags. 
 * For example, if button 1 was released at the same time that button 2 was pressed,
 * this function should return (BUTTON_EVENT_1UP | BUTTON_EVENT_2DOWN) 
 * 
 */
uint8_t ButtonsCheckEvents(void){
    
    uint8_t buttonState = 0x00; //variable to hold button state that will be compiled
    if(debounce > 0)
    {
        debounce--; //decrement debounce
        return lastButtonState; //return last button state
    }
    else{
        currentState = BUTTON_STATES(); //get current state
        debounce = BUTTONS_DEBOUNCE_PERIOD; // reset debounce
            
            if((currentState & BUTTON_STATE_1) ^ (lastState & BUTTON_STATE_1)){ // if button 1 has changed it's state
                if(currentState & BUTTON_STATE_1){ // if button is pressed currently 
                  buttonState |= BUTTON_EVENT_1DOWN; //add button event down
                }
                else if(lastState & BUTTON_STATE_1){ // if button was pressed previously 
                    buttonState |= BUTTON_EVENT_1UP; //add button event up
                }
            }
            else {
                if (currentState & BUTTON_STATE_1){  // if button 1 has not changed it's state in being pressed
                    buttonState |= BUTTON_EVENT_1DOWN; //add button event down
                }
                
            }
        
        
        if((currentState & BUTTON_STATE_2) ^ (lastState & BUTTON_STATE_2)){ //button 2 has changed it's state
                if(currentState & BUTTON_STATE_2){ // if button is pressed currently 
                  buttonState |= BUTTON_EVENT_2DOWN; //add button event down
                }
                else if(lastState & BUTTON_STATE_2){ // if button was pressed previously
                    buttonState |= BUTTON_EVENT_2UP; //add button event up
                }
            }
            else {
                if (currentState & BUTTON_STATE_2){ // if button 1 has not changed it's state in being pressed
                    buttonState |= BUTTON_EVENT_2DOWN; //add button event down
                }
                
            }
        
        
        if((currentState & BUTTON_STATE_3) ^ (lastState & BUTTON_STATE_3)){ //button 3 has changed it's state
                if(currentState & BUTTON_STATE_3){ // if button is pressed currently
                  buttonState |= BUTTON_EVENT_3DOWN; //add button event down
                }
                else if(lastState & BUTTON_STATE_3){ // if button was pressed previously
                    buttonState |= BUTTON_EVENT_3UP; //add button event up
                }
            }
            else {
                if (currentState & BUTTON_STATE_3){ // if button 1 has not changed it's state in being pressed
                    buttonState |= BUTTON_EVENT_3DOWN; //add button event down
                }
                
            }
        
        
        if((currentState & BUTTON_STATE_4) ^ (lastState & BUTTON_STATE_4)){ //button 4 has changed it's state
                if(currentState & BUTTON_STATE_4){ // if button is pressed currently
                  buttonState |= BUTTON_EVENT_4DOWN; //add button event down
                }
                else if(lastState & BUTTON_STATE_4){ // if button was pressed previously
                   buttonState |= BUTTON_EVENT_4UP; //add button event up
                }
            }
            else {
                if (currentState & BUTTON_STATE_4){ // if button 1 has not changed it's state in being pressed
                    buttonState |= BUTTON_EVENT_4DOWN; //add button event down
                }
                
            }
        
        
       
            
           
        
        
        lastState = currentState; //update last state for next time 
        lastButtonState = buttonState;  //update last button state
        
        return buttonState; //return final Button event Flag
        }
    }
    
    
        
   


