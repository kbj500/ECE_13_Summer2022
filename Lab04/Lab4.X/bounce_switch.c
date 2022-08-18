
// **** Include libraries here ****
// old bounce
// Standard libraries
#include <stdio.h>
					


//CMPE13 Support Library
#include "BOARD.h"

// Microchip libraries
#include <xc.h>
#include <sys/attribs.h>

// User libraries
#include "Leds_Lab04.h"

// **** Declare any datatypes here ****
typedef struct Timer {
    uint8_t event;
    int16_t timeRemaining;
}Timer;	

// **** Define global, module-level, or external variables here ****
static Timer TimerS;
static int state;
#define LEFT 1
#define RIGHT 0
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
    LEDS_INIT(); // initialize board
    LEDS_SET(0x1); //set initial LED
    TimerS.timeRemaining = 76;
    printf("0x80:%d\n", 0x80);
    printf("LED START:%d\n",LEDS_GET());
    //LEDS_SET(LEDS_GET()<<1);
    //printf("LED START SHIFT LEFT:%d\n",LEDS_GET());
    int counter = 0;
    printf("Welcome to CRUZID's lab4 part2 (bounce_switch).  Compiled on %s %s.\n",__TIME__,__DATE__);				 
	while(counter < 16){
        //poll timer events and react if any occur 
        if(LEDS_GET() == 0x1){
            state = LEFT;// Reverse direction
            printf("State set Left");
        }
        else if(LEDS_GET() == 0x80){
            state = RIGHT;// Reverse direction
            printf("State set Right");
        }
        if(state == LEFT){
            printf("LED:%d\n",LEDS_GET());            
            LEDS_SET(LEDS_GET()<<1);
            
             printf("LED SHIFTED LEFT:%d\n",LEDS_GET());
        }
        else{
            printf("LED:%d\n",LEDS_GET());            
            printf("LED SHIFTED RIGHT:%d\n",LEDS_GET()>>1);
            LEDS_SET(LEDS_GET()>>1);
        }
        counter++;
        //TimerS.event = FALSE;//clear timer event flag
        
    }
        
    			


    /***************************************************************************************************
     * Your code goes in between this comment and the preceding one with asterisks
     **************************************************************************************************/

}


/**
 * This is the interrupt for the Timer1 peripheral. It will trigger at the frequency of the peripheral
 * clock, divided by the timer 1 prescaler and the interrupt interval.
 * 
 * It should not be called, and should communicate with main code only by using module-level variables.
 */
void __ISR(_TIMER_1_VECTOR, ipl4auto) Timer1Handler(void)
{
    // Clear the interrupt flag.
    IFS0bits.T1IF = 0;

    /***************************************************************************************************
     * Your code goes in between this comment and the following one with asterisks.
     **************************************************************************************************/
    
    if(SWITCH_STATES() &  SWITCH_STATE_SW1 || SWITCH_STATES() &  SWITCH_STATE_SW2 || SWITCH_STATES() &  SWITCH_STATE_SW3 || SWITCH_STATES() &  SWITCH_STATE_SW4){   //any switches up
        TimerS.event = TRUE; 
        TimerS.timeRemaining +=  8;   //decrement slower        
    }
    else{
        TimerS.event = TRUE;
        TimerS.timeRemaining -=  8; //decrement fast
    }
    /***************************************************************************************************
     * Your code goes in between this comment and the preceding one with asterisks
     **************************************************************************************************/									
	 
}