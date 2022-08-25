// **** Include libraries here ****
// Standard libraries
#include <stdio.h>
#include <string.h>

//CSE13E Support Library
#include "BOARD.h"
#include "Oled.h"
#include "Buttons.h"
#include "Adc.h"

// Microchip libraries
#include <xc.h>
#include <sys/attribs.h>



// **** Set any macros or preprocessor directives here ****
// Set a macro for resetting the timer, makes the code a little clearer.
#define TIMER_2HZ_RESET() (TMR1 = 0)

#define LONG_PRESS 3

#define START_TEMP 300

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c" /// macros for printing binary numbers
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0') 


// **** Set any local typedefs here ****
typedef enum {
    SETUP, SELECTOR_CHANGE_PENDING, COOKING, RESET_PENDING
} OvenState;

typedef struct {
    OvenState state; //Oven State
    int temperature; //Oven temperature
    char cm[5]; //string holding cooking mode
    int bpt; //Button Press Time
    int cst; //Cooking Start Time
    int inS; //Input Selector
    //add more members to this struct
} OvenData;

// **** Declare any datatypes here ****
enum MODE{
    bake, toast, broil,
};
// **** Define any module-level, global, or external variables here ****
static uint8_t ButtonResult;
static OvenData od;
static int sp = 12;
static uint8_t adcC;
static uint32_t adcV;
static int TIMER_TICK;

static int st; // start time
static int cft; //current free running time
static int et; //elapsed time
static int m; //mode setting
static int min;//minute
static int seconds;//seconds
static int temp = START_TEMP; //temperature

static char mo[5] = "Mode:"; //char to hold mode string for display
static char ti[5] = "Time:"; // char to hold time string for display
static char ati[4]; // char to hold minute/seconds input for display
static char atp[4]; // char to hold temp input for display
static char tp[5] = "Temp:"; // char to hold temp string for display

static const char *MODE_LIST[] = {"Bake","Toast","Broil"} ;

// **** Put any helper functions here ****


/*This function will update your OLED to reflect the state .*/
void updateOvenOLED(OvenData ovenData){
    //update OLED here
    // create starting screen
          //heading
          OledClear(0);
          
          OledDrawChar(62,1,mo[0]);     //write out to OLED with each character in mode
          OledDrawChar(68,1,mo[1]);
          OledDrawChar(74,1,mo[2]);
          OledDrawChar(80,1,mo[3]);
          OledDrawChar(86,1,mo[4]);
          OledDrawChar(92,1,mo[5]);
          
          OledDrawChar(96,1,od.cm[0]);     //write out to OLED with each character in Oven Data mode
          OledDrawChar(102,1,od.cm[1]);
          OledDrawChar(108,1,od.cm[2]);
          OledDrawChar(114,1,od.cm[3]);
          OledDrawChar(120,1,od.cm[4]);
          OledDrawChar(126,1,od.cm[5]);
          
          
          
          
          //percent = ((float) raw)/1023 * 100; //percent of raw voltage
          //sprintf(p, "%3.0f", percent); //set percent value to char string
          
          OledDrawChar(62,12,ti[0]);    // write out to OLED with each character in time
          OledDrawChar(68,12,ti[1]);
          OledDrawChar(74,12,ti[2]);
          OledDrawChar(80,12,ti[3]);
          OledDrawChar(86,12,ti[4]);
          OledDrawChar(92,12,ti[5]);
          
          
                                        // write out to OLED dynamic cooking time char
          
          sprintf(ati, "%d", min); //set minute value to char string
          sprintf(ati+strlen(ati),"%d",seconds); //set seconds value to char string
          printf("ati:%s",ati);
          if(seconds < 10){
          OledDrawChar(100,12,ati[0]);
          OledDrawChar(106,12,':');
          OledDrawChar(112,12,'0');
          OledDrawChar(118,12,ati[1]);
          }
          else{
          OledDrawChar(100,12,ati[0]);
          OledDrawChar(106,12,':');
          OledDrawChar(112,12,ati[1]);
          OledDrawChar(118,12,ati[2]);
          }
          
          if(strcmp(od.cm, MODE_LIST[1]) != 0){
          OledDrawChar(62,24,tp[0]);    // write out to OLED with each character in temperature
          OledDrawChar(68,24,tp[1]);
          OledDrawChar(74,24,tp[2]);
          OledDrawChar(80,24,tp[3]);
          OledDrawChar(86,24,tp[4]);
          
          sprintf(atp, "%d", temp); //set temperature value to char string
          //printf("atp:%s",atp);
          OledDrawChar(100,24,atp[0]);
          OledDrawChar(106,24,atp[1]);
          OledDrawChar(112,24,atp[2]);
          
          }
          
          //printf("sp(draw):%d\n",sp);
          OledDrawChar(54,sp,'>');
          OledUpdate();                 //update OLED
          
          
          
      
    
}

/*This function will execute your state machine.  
 * It should ONLY run if an event flag has been set.*/
void runOvenSM(void)
{
    //write your SM logic here.
    //check timer ticks
    if(od.state == RESET_PENDING){
        od.state = SETUP;
        
        adcV = (((uint32_t)AdcRead())>>2)+1;
        min = adcV/60;
        seconds = adcV % 60;
    }
    if(sp == 12){
        if(adcC){
           
            
            //printf("\nAdcRead() int:%d\n",AdcRead());
            //printf("AdcRead() binary:\n "BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(AdcRead()));
            adcV = (((uint32_t)AdcRead())>>2)+1;
            min = adcV/60;
            printf("Minutes:%d\n",min);
            seconds = adcV % 60;
            
            printf("Seconds:%d\n",seconds);
            //printf("\nadcV:%d\n",adcV);
            //printf("adcV binary:\n "BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(adcV));
            
        }
    }
    else{
        if(adcC){
        adcV = (((uint32_t)AdcRead())>>2)+300;
        printf("\nadcV:%d\n",adcV);
        temp = adcV;
        }
        
    }
    if(TIMER_TICK){
        cft++;
        et = cft-st;
        TIMER_TICK = 0;
        if(od.state == COOKING){
            printf("Seconds(cook):%d\n",seconds);
            if(seconds != 0 || min != 0){
                if(seconds == 0){
                    min--;
                    seconds = 59;
                }
                seconds--;
            }
            else{
                od.state = RESET_PENDING;
            }
            updateOvenOLED(od);
            /*
            if(seconds != 0 || min != 0){
                if(seconds = 0){
                    printf("Minutes(cs):%d\n",min);
                    min--;
                    seconds = 59;
                }
            printf("Minutes(c):%d\n",min);
                
            printf("Seconds(c1b):%d\n",seconds);
               seconds--; 
            printf("Seconds(c1a):%d\n",seconds);
               updateOvenOLED(od);
               
            }
            else{
                od.state == RESET_PENDING; 
            }*/
            printf("Seconds(c):%d\n",seconds);
        }
    }
    if(ButtonResult & BUTTON_EVENT_3DOWN) {
        st = cft;
        et = cft-st;
        od.state = SELECTOR_CHANGE_PENDING;
        printf("\nst:%d\n", st);
        
       printf("\ncft(down):%d\n", cft);
    }
    if(ButtonResult & BUTTON_EVENT_3UP){ 
        
            printf("\ncft(Up):%d\n", cft);
             printf("\net:%d\n", et);
                 if(et < LONG_PRESS){
                 //printf("\nswitch next mode\n");
                    sp = 12;
                    if(m < 2){
                        m++;
                        strcpy(od.cm,MODE_LIST[m]);
                        updateOvenOLED(od);
                    }
                    else{
                        m = 0;
                        strcpy(od.cm,MODE_LIST[m]);
                        updateOvenOLED(od);
                    }
                 }
                 else{
                     if(strcmp(od.cm, MODE_LIST[1]) != 0){
                     if(sp>12){
                           sp = 12;
                           updateOvenOLED(od);
                           //printf("sp(12):%d\n",sp);

                       }
                       else{
                           sp = 24;
                           updateOvenOLED(od);
                           //printf("sp(24):%d\n",sp);

                       }
                     }

                 }
             od.state = SETUP;
    }
    
    if(ButtonResult & BUTTON_EVENT_4DOWN){
        od.state = COOKING; 
    }
    
    updateOvenOLED(od);
    
}


int main()
{
    BOARD_Init();
     //initalize timers and timer ISRs:
    // <editor-fold defaultstate="collapsed" desc="TIMER SETUP">
    
    // Configure Timer 2 using PBCLK as input. We configure it using a 1:16 prescalar, so each timer
    // tick is actually at F_PB / 16 Hz, so setting PR2 to F_PB / 16 / 100 yields a .01s timer.

    T2CON = 0; // everything should be off
    T2CONbits.TCKPS = 0b100; // 1:16 prescaler
    PR2 = BOARD_GetPBClock() / 16 / 100; // interrupt at .5s intervals
    T2CONbits.ON = 1; // turn the timer on

    // Set up the timer interrupt with a priority of 4.
    IFS0bits.T2IF = 0; //clear the interrupt flag before configuring
    IPC2bits.T2IP = 4; // priority of  4
    IPC2bits.T2IS = 0; // subpriority of 0 arbitrarily 
    IEC0bits.T2IE = 1; // turn the interrupt on

    // Configure Timer 3 using PBCLK as input. We configure it using a 1:256 prescaler, so each timer
    // tick is actually at F_PB / 256 Hz, so setting PR3 to F_PB / 256 / 5 yields a .2s timer.

    T3CON = 0; // everything should be off
    T3CONbits.TCKPS = 0b111; // 1:256 prescaler
    PR3 = BOARD_GetPBClock() / 256 / 5; // interrupt at .5s intervals
    T3CONbits.ON = 1; // turn the timer on

    // Set up the timer interrupt with a priority of 4.
    IFS0bits.T3IF = 0; //clear the interrupt flag before configuring
    IPC3bits.T3IP = 4; // priority of  4
    IPC3bits.T3IS = 0; // subpriority of 0 arbitrarily 
    IEC0bits.T3IE = 1; // turn the interrupt on;

    // </editor-fold>
   
    printf("Welcome to CRUZID's Lab05 (Toaster Oven).  Compiled on %s %s.", __TIME__, __DATE__);

    //initialize state machine (and anything else you need to init) here
    OledInit();
    AdcInit();
    od.state = SETUP;
    strcpy(od.cm,MODE_LIST[m]);
    while (1){
        // Add main loop code here:
        
                        //check for events
    if(ButtonResult || adcC){   //check for events: button, adc, state
        runOvenSM();                                // on event, run runOvenSM()
    }   
    if(od.state == SELECTOR_CHANGE_PENDING){// if state is selector change pending 
        runOvenSM(); 
    }
    if(od.state == SETUP || od.state == COOKING || od.state == RESET_PENDING){ // if state is setup, cooking, reset pending
        runOvenSM(); 
    }
    //ButtonResult = 0;   // clear event flags
    //adcC = 0;
    
        
        
    };
}


/*The 5hz timer is used to update the free-running timer and to generate TIMER_TICK events*/
void __ISR(_TIMER_3_VECTOR, ipl4auto) TimerInterrupt5Hz(void)
{
    // Clear the interrupt flag.
    IFS0CLR = 1 << 12;

    //add event-checking code here
    TIMER_TICK = 1;
    
    
    
}


/*The 100hz timer is used to check for button and ADC events*/
void __ISR(_TIMER_2_VECTOR, ipl4auto) TimerInterrupt100Hz(void)
{
    // Clear the interrupt flag.
    IFS0CLR = 1 << 8;

    //add event-checking code here
    
    ButtonResult = ButtonsCheckEvents(); //collect new button activity
    adcC = AdcChanged(); //collect adc activity 
}