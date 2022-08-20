// **** Include libraries here ****
// Standard libraries
#include <stdio.h>
#include <string.h>

//CMPE13 Support Library
#include "BOARD.h"
#include "Buttons.h"

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
    T1CONbits.TCKPS = 2; // 1:64 prescaler
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
    
    ButtonsInit();
    printf("Welcome to bkhadka's lab4 part4 (ButtonsTest).  Compiled on %s %s.\n", __TIME__, __DATE__);

    
    printf("Please press some buttons!\n");
    while(1){
        if(ButtonResult != prevButtonResult)
        {
        
            char b1[6];
            char b2[6];
            char b3[6];
            char b4[6];
            //printf("%d",ButtonResult);
        if(ButtonResult & BUTTON_EVENT_1UP){
            strcpy(b1, "UP");//button one up
            //printf("\nBUTTON 1 has been pressed %s",b1);
        }
        else if(ButtonResult & BUTTON_EVENT_1DOWN) {
            strcpy(b1, "DOWN");//button one down
            
            //printf("\nBUTTON 1 has been pressed %s",b1);
        }
        else{
            strcpy(b1, "----");
        }
        if(ButtonResult & BUTTON_EVENT_2UP){
            strcpy(b2, "UP");//button two up
            
            //printf("\nBUTTON 2 has been pressed %s",b2);
        }
        else if(ButtonResult & BUTTON_EVENT_2DOWN) {
            strcpy(b2, "DOWN");//button two down
            
            //printf("\nBUTTON 2 has been pressed %s",b2);
        }
            else{
            strcpy(b2, "----");
        }
        if(ButtonResult & BUTTON_EVENT_3UP){
            strcpy(b3, "UP");//button three up
            
            //printf("\nBUTTON 3 has been pressed %s",b3);
        }
        else if(ButtonResult & BUTTON_EVENT_3DOWN) {
            strcpy(b3, "DOWN");//button three down
            
            //printf("\nBUTTON 3 has been pressed %s",b3);
        }
            else{
            strcpy(b3, "----");
        }
        if(ButtonResult & BUTTON_EVENT_4UP){
           strcpy(b4, "UP"); //button four up
           
            //printf("\nBUTTON 4 has been pressed %s",b4);
        }
        else if(ButtonResult & BUTTON_EVENT_4DOWN) {
            strcpy(b4, "DOWN");//button four down
            
            //printf("\nBUTTON 3 has been pressed %s",b4);
        }
        else{
            strcpy(b4, "----");
        }
        
        printf("\nEVENT: 4: %s 3: %s 2: %s 1: %s\n",b4,b3,b2,b1);
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