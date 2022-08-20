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
static uint8_t ButtonResult;
static uint8_t prevButtonResult;
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
    int b1counter;
    int b2counter;
    int b3counter;
    int b4counter;
    while(1){
        if(ButtonResult != prevButtonResult)
        {
        if(SWITCH_STATES() &  SWITCH_STATE_SW1 || SWITCH_STATES() &  SWITCH_STATE_SW2 || SWITCH_STATES() &  SWITCH_STATE_SW3 || SWITCH_STATES() &  SWITCH_STATE_SW4){ //switch 1 is 
           if(ButtonResult & BUTTON_EVENT_1UP) {
                if(b1counter % 2 == 0){
                    LEDS_SET(LEDS_GET()^0x3);
                }
                else{

                LEDS_SET(LEDS_GET()|0x3);
                }
                b1counter++;
            }
            if(ButtonResult & BUTTON_EVENT_2UP) {

                if(b2counter % 2 == 0){
                    LEDS_SET(LEDS_GET()^0xC);
                }

                else{
                LEDS_SET(LEDS_GET()|0xC);
                }
                b2counter++;
            }
            if(ButtonResult & BUTTON_EVENT_3UP) {
                if(b3counter % 2 == 0){
                    LEDS_SET(LEDS_GET()^0x30);
                }
                else{
                LEDS_SET(LEDS_GET()|0x30);
                }
                b3counter++;
            }
            if(ButtonResult & BUTTON_EVENT_4UP) {
                if(b4counter % 2 == 0){
                    LEDS_SET(LEDS_GET()^0xC0);
                }
                else{
                LEDS_SET(LEDS_GET()|0xC0);
                }
                b4counter++;
            } 
           
        } 
        else{
            if(ButtonResult & BUTTON_EVENT_1DOWN) {
                if(b1counter % 2 == 0){
                    LEDS_SET(LEDS_GET()^0x3);
                }
                else{

                LEDS_SET(LEDS_GET()|0x3);
                }
                b1counter++;
            }
            if(ButtonResult & BUTTON_EVENT_2DOWN) {

                if(b2counter % 2 == 0){
                    LEDS_SET(LEDS_GET()^0xC);
                }

                else{
                LEDS_SET(LEDS_GET()|0xC);
                }
                b2counter++;
            }
            if(ButtonResult & BUTTON_EVENT_3DOWN) {
                if(b3counter % 2 == 0){
                    LEDS_SET(LEDS_GET()^0x30);
                }
                else{
                LEDS_SET(LEDS_GET()|0x30);
                }
                b3counter++;
            }
            if(ButtonResult & BUTTON_EVENT_4DOWN) {
                if(b4counter % 2 == 0){
                    LEDS_SET(LEDS_GET()^0xC0);
                }
                else{
                LEDS_SET(LEDS_GET()|0xC0);
                }
                b4counter++;
            }
            
        
            
        }
        prevButtonResult = ButtonResult;
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
    ButtonResult = ButtonsCheckEvents();

    /***************************************************************************************************
     * Your code goes in between this comment and the preceding one with asterisks
     **************************************************************************************************/

}