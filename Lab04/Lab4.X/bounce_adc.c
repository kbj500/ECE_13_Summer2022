// **** Include libraries here ****
// Standard libraries
#include <stdio.h>

//CMPE13 Support Library
#include "BOARD.h"



// Microchip libraries
#include <xc.h>
#include <sys/attribs.h>

// User libraries
#include "Oled.h"

// **** Set macros and preprocessor directives ****
#define WINDOW_SIZE 5   //macro for window size

// **** Declare any datatypes here ****
typedef struct AdcResult{
    uint8_t event;
    int16_t voltage;
}AdcResult;                 //struct for seeing voltage

// **** Define global, module-level, or external variables here ****
static AdcResult AR;
static int prev = 0;        // previous voltage value
// **** Declare function prototypes ****

int main(void)
{
    BOARD_Init();

// Enable interrupts for the ADC
    IPC6bits.AD1IP = 2;
    IPC6bits.AD1IS = 0;
    IEC1bits.AD1IE = 1;

    // Set B2 to an input so AN2 can be used by the ADC.
    TRISBbits.TRISB2 = 1;

    // Configure and start the ADC
    AD1CHSbits.CH0SA = 2; // add B2 to the mux
    AD1PCFGbits.PCFG2 = 0; // add b2 to the ADC
     AD1CSSLbits.CSSL2 = 1; // and add b2 to the scanner

    AD1CON1 = 0; // start with 0
    AD1CON1bits.SSRC = 0b111; // auto conversion
    AD1CON1bits.ASAM = 1; // auto sample

    AD1CON2 = 0; // start with 0
    AD1CON2bits.SMPI = 7; // one interrupt per 8 samples

    AD1CON3 = 0; // start with 0
    AD1CON3bits.SAMC = 29; // long sample time
    AD1CON3bits.ADCS = 50; // long conversion time
    
    AD1CON1bits.ADON = 1; // and finally turn it on

    /***************************************************************************************************
     * Your code goes in between this comment and the following one with asterisks.
     **************************************************************************************************/
    OledInit(); //initialize board
    int raw = 0; // raw voltage value
    float percent = 0; // percent of total voltage
    char r[3]; //char to hold raw value for print
    char p[2]; // char to hold percent value for print
  printf("Welcome to bkhadka's lab4 part3 (bounce_adc).  Compiled on %s %s.\n",__TIME__,__DATE__);

  while(1){
      if(AR.event ==TRUE){
          OledDrawString("Potentiometer Value"); //heading
          
          raw = (ADC1BUF0+ADC1BUF1+ADC1BUF2+ADC1BUF3+ADC1BUF4+ADC1BUF5+ADC1BUF6+ADC1BUF7) / 8; //raw value
          sprintf(r, "%d", raw);        //set raw value to char string
          
          OledDrawChar(16,15,r[0]);     //write out to OLED with each character in raw value
          OledDrawChar(22,15,r[1]);
          OledDrawChar(27,15,r[2]);
          OledDrawChar(32,15,r[3]);
          
          percent = ((float) raw)/1023 * 100; //percent of raw voltage
          sprintf(p, "%3.0f", percent); //set percent value to char string
          
          OledDrawChar(48,15,p[0]);    // write out to OLED with each character in percentage 
          OledDrawChar(54,15,p[1]);
          OledDrawChar(60,15,p[2]);
          OledDrawChar(66,15,'%');
          
          OledUpdate();                 //update OLED
          AR.event == FALSE; //clear ADC event flag
      }
  }
    /***************************************************************************************************
     * Your code goes in between this comment and the preceding one with asterisks
     **************************************************************************************************/

    while (1);
}

/**
 * This is the interrupt for the ADC1 peripheral. It will trigger whenever a new ADC reading is available
 * in the ADC buffer SFRs, ADC1BUF0 - ADC1BUF7.
 * 
 * It should not be called, and should communicate with main code only by using module-level variables.
 */
void __ISR(_ADC_VECTOR, ipl2auto) AdcHandler(void)
{
    
    IFS1bits.AD1IF = 0;
    int current = (ADC1BUF0+ADC1BUF1+ADC1BUF2+ADC1BUF3+ADC1BUF4+ADC1BUF5+ADC1BUF6+ADC1BUF7) / 8; //read 8 buffered ADC values in ADC1BUF0 and average them

    if (current-prev > WINDOW_SIZE || current-prev < WINDOW_SIZE ){ //if window size has been exceeded 
        prev = current;         // set new previous value
        AR.event = TRUE;        // event activate
    }
    
    // if ADC reading exits window,generate ADC event and update window center

}