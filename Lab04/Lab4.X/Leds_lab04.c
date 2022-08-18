
#include "Leds_Lab04.h"
//CMPE13 Support Library
#include "BOARD.h"
/**
 * @file
 * This library implements an interface for controlling the LEDs on the 
 * chipKit Basic I/O Shield development board.
 *
 * 
 */
/*
int main(void){
    
    LEDS_INIT();
    while(1){
    LEDS_SET(0xFF);
    LEDS_SET(0x00);
  
    LEDS_SET(0x40);
    
    LEDS_SET(0x20);
    
    LEDS_SET(0x10);
   
    LEDS_SET(0x8);
    
    LEDS_SET(0x4);
   
    LEDS_SET(0x2);
    
    LEDS_SET(0x1);
    }

    
    
    /*
    int i; 
    for(i = 0; i <5; i++){
        LEDS_SET(0xDD);
    }
    for(i = 0; i <5; i++){
        LEDS_SET(0);
    }
    for(i = 0; i <5; i++){
        LEDS_SET(0xFF);
    }
    
}*/

/**
 * LEDS_INIT() initializes the LED bar by doing two things:
 *      1) Use the appropriate SFRs to set each LED pin to "output" mode.
 *      2) Use the appropriate SFRs to set each LED pin's output value to 0 (low voltage).
 * 
 * After calling LEDS_INIT(), the other functions in this file can be used to manipulate the LED bar.
 */
void LEDS_INIT(void){
    TRISE = 0x0; // 0000 0000
    LATE = 0x0; // 0000 0000
    
}


/**
 * LEDS_SET() controls the output on the LED bar.  Input values are 8-bit patterns, where each bit 
 * describes the desired state of the corresponding LED.  So, for example, LEDS_SET(0x80) should 
 * leave the first LED on, and the last 7 LEDs off.  LEDS_SET(0x1F) should turn off the first three
 * LEDs and turn on the remaining five LEDs.
 * 
 * @param newPattern:  An 8-bit value describing the desired output on the LED bar.  
 * 
 * LEDS_SET should not change any LED pins to inputs.
 */
void LEDS_SET(char newPattern){
    
    LATE = newPattern;
}


/**
 * LEDS_GET() returns the current state of the LED bar.  Return values are 8-bit patterns,
 * where each bit describes the current state of the corresponding LED So, for example, if the 
 * led bar's led's are [ON OFF ON OFF   OFF ON OFF ON], LEDS_GET() should return 0xA5.
 * 
 * @return char:  An 8-bit value describing the current output on the LED bar.  
 * 
 * LEDS_GET() should not change the state of the LEDS, or any SFRs.
 */
char LEDS_GET(void){
    return LATE; 
}
