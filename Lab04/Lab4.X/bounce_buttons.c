// **** Include libraries here ****
// Standard libraries
#include <stdio.h>

//CMPE13 Support Library
#include "BOARD.h"
#include "Buttons.h"
#include "Leds_Lab04.h"

// Microchip libraries
#include <xc.h>
#include <sys/attribs.h>

// User libraries

// **** Set macros and preprocessor directives ****

// **** Declare any datatypes here ****

// **** Define global, module-level, or external variables here ****
static uint8_t ButtonResult; //get Button Event Flag activity
static uint8_t prevButtonResult; //preserve previous Button activity
// **** Declare function prototypes ****

int main(void)
{
    BOARD_Init();

    // Configure Timer 1 using PBCLK as input. This default period will make the LEDs blink at a
    // pretty reasonable rate to start.
    T1CON = 0; // everything should be off
    T1CONbits.TCKPS = 1; // 1:8 prescaler
    PR1 = 0xFFFF; // interrupt at max interval
    T1CONbits.ON = 1; // turn the timer on

    // Set up the timer interrupt with a priority of 4.
    IFS0bits.T1IF = 0; //clear the interrupt flag before configuring
    IPC1bits.T1IP = 4; // priority of  4
    IPC1bits.T1IS = 0; // subpriority of 0 arbitrarily 
    IEC0bits.T1IE = 1; // turn the interrupt on

    /***************************************************************************************************
     * Your code goes in between this comment and the following one with asterisks.
     **************************************************************************************************/
    printf("Welcome to bkhadka's lab4 part5 (bounce_buttons).  Compiled on %s %s.\n", __TIME__, __DATE__);
    LEDS_INIT(); // initialize board
    int b1counter; //initialize counters to record if button pressed twice to turn off and on
    int b2counter;
    int b3counter;
    int b4counter;
    while(1){
        if(ButtonResult != prevButtonResult) //if Button status has changed
        {
        if(SWITCH_STATES() &  SWITCH_STATE_SW1 || SWITCH_STATES() &  SWITCH_STATE_SW2 || SWITCH_STATES() &  SWITCH_STATE_SW3 || SWITCH_STATES() &  SWITCH_STATE_SW4){ //any switch is on 
           if(ButtonResult & BUTTON_EVENT_1UP) { // if button up event occurred
                if(b1counter % 2 == 0){         // if button has already been pressed 
                    LEDS_SET(LEDS_GET()^0x3); //clear button
                }
                else{                           //if button has not already been pressed 

                LEDS_SET(LEDS_GET()|0x3);    //activate button
                }
                b1counter++;                //increment counter for tracking button pressing
            }
            if(ButtonResult & BUTTON_EVENT_2UP) { // if button up event occurred

                if(b2counter % 2 == 0){             // if button has already been pressed 
                    LEDS_SET(LEDS_GET()^0xC);   //clear button
                }

                else{                       //if button has not already been pressed 
                LEDS_SET(LEDS_GET()|0xC);   //activate button
                }
                b2counter++;                //increment counter for tracking button pressing
            }
            if(ButtonResult & BUTTON_EVENT_3UP) { //same as above if statement
                if(b3counter % 2 == 0){
                    LEDS_SET(LEDS_GET()^0x30);
                }
                else{
                LEDS_SET(LEDS_GET()|0x30);
                }
                b3counter++;
            }
            if(ButtonResult & BUTTON_EVENT_4UP) { //same as above if statement
                if(b4counter % 2 == 0){
                    LEDS_SET(LEDS_GET()^0xC0);
                }
                else{
                LEDS_SET(LEDS_GET()|0xC0);
                }
                b4counter++;
            } 
           
        } 
        else{                                       //if no switch is on
            if(ButtonResult & BUTTON_EVENT_1DOWN) {     // if button down event occurred
                if(b1counter % 2 == 0){                  // if button has already been pressed 
                    LEDS_SET(LEDS_GET()^0x3);           //clear button
                }
                else{                               //if button has not already been pressed

                LEDS_SET(LEDS_GET()|0x3);           //activate button
                }
                b1counter++;                        //increment counter for tracking button pressing
            }
            if(ButtonResult & BUTTON_EVENT_2DOWN) { //same as above if statement

                if(b2counter % 2 == 0){
                    LEDS_SET(LEDS_GET()^0xC);
                }

                else{
                LEDS_SET(LEDS_GET()|0xC);
                }
                b2counter++;
            }
            if(ButtonResult & BUTTON_EVENT_3DOWN) { //same as above if statement
                if(b3counter % 2 == 0){
                    LEDS_SET(LEDS_GET()^0x30);
                }
                else{
                LEDS_SET(LEDS_GET()|0x30);
                }
                b3counter++;
            }
            if(ButtonResult & BUTTON_EVENT_4DOWN) { //same as above if statement
                if(b4counter % 2 == 0){
                    LEDS_SET(LEDS_GET()^0xC0);
                }
                else{
                LEDS_SET(LEDS_GET()|0xC0);
                }
                b4counter++;
            }
            
        
            
        }
        prevButtonResult = ButtonResult; //update previousButton result
    }
    }
    

    /***************************************************************************************************
     * Your code goes in between this comment and the preceding one with asterisks
     **************************************************************************************************/

    while (1);
}

/**
 * This is the interrupt for the Timer1 peripheral. It should check for button events and stores them in a
 * module-level variable.
 * 
 * You should not modify this function for ButtonsTest.c or bounce_buttons.c!
 */
void __ISR(_TIMER_1_VECTOR, ipl4auto) Timer1Handler(void)
{
    // Clear the interrupt flag.
    IFS0bits.T1IF = 0;

    /***************************************************************************************************
     * Your code goes in between this comment and the following one with asterisks.
     **************************************************************************************************/
    ButtonResult = ButtonsCheckEvents(); //collect new button activity

    /***************************************************************************************************
     * Your code goes in between this comment and the preceding one with asterisks
     **************************************************************************************************/

}