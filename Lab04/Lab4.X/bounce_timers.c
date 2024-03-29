// **** Include libraries here ****
// old bounce
// Standard libraries
#include <stdio.h>
#include <GenericTypeDefs.h>

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
static Timer TimerA;        
static Timer TimerB;
static Timer TimerC;


#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c" //macros prints BINARY 
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0') 

#define TWO_SECONDS 76      //macros for each second value based on hertz value
#define THREE_SECONDS 114
#define FIVE_SECONDS 190
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
    printf("Welcome to bkhadka's lab4 part1 (timers).  Compiled on %s %s.\n", __TIME__, __DATE__); 
    
    TimerA.timeRemaining = TWO_SECONDS;     //initialize starting times
    TimerB.timeRemaining = THREE_SECONDS;
    TimerC.timeRemaining = FIVE_SECONDS; 
    
    LEDS_INIT(); // initialize board
    
    while (1) {
        //poll timer A
            //react to timer A events
            //clear timer A event flag
        if(TimerA.event == TRUE){           //poll timer A
            TimerA.event = FALSE;           //clear timer A event flag
            printf("A\n"); 
            LEDS_SET(LEDS_GET()^0x01);      //react to timer A events
            
        }
        if(TimerB.event == TRUE){           //poll timer B 
            TimerB.event = FALSE;           //clear timer B event flag
            printf("B\n");
            LEDS_SET(LEDS_GET()^0x02);      //react to timer B events
        }
        if(TimerC.event == TRUE){           //poll timer C
            TimerC.event = FALSE;           //clear timer C event flag
            printf("C\n");
            LEDS_SET(LEDS_GET()^0x04);      //react to timer C events
        }

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
    
    
    TimerA.timeRemaining--;     //update timerA
    TimerB.timeRemaining--;     //update timerB
    TimerC.timeRemaining--;     //update timerC
    if(TimerA.timeRemaining ==0){   //if timerA has counted down,
        TimerA.event = TRUE;        //generate timerA event
        TimerA.timeRemaining = TWO_SECONDS;           //reset timerA
    }
    if(TimerB.timeRemaining ==0){   //if timerB has counted down,
        TimerB.event = TRUE;        //generate timerB event
        TimerB.timeRemaining = THREE_SECONDS;           //reset timerB
    }
    if(TimerC.timeRemaining ==0){   //if timerC has counted down,
        TimerC.event = TRUE;        //generate timerC event
        TimerC.timeRemaining = FIVE_SECONDS;          //reset timerC

    }
    
    
    
    
    /***************************************************************************************************
     * Your code goes in between this comment and the preceding one with asterisks
     **************************************************************************************************/

}