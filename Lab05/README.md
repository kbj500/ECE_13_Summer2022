Name: Bijaya Khadka
CruzID: bkhadka

Summer Session 2, 2022

ECE 13

Lab 5: Toaster Oven

--------------
DESCRIPTION


This lab will develop a program for simulating a Toaster Oven on the PIC32 Arduino board.


--------------
FILES


- Lab5.X
    - Pre-written Files
        - Adc.h
        - Ascii.h
        - BOARD.c
        - BOARD.h
        - Buttons.h
        - Lab5SupportLib.a
        - Oled.h
        - OledDriver.h
    - Edited Files
        - Lab05_main.c
        - Leds.h


This file includes a MPLAB project folder for the lab. Within the MPLAB project folder the Pre-written files are all files to support constants and functions that manipulate pins on the Board, Potentiometer, Buttons, OLED screen and LEDs. Leds_Lab04.c and Buttons.c implement the functions in their respective header files, the former for LED manipulation and the latter for Button checking.  


INSTRUCTIONS

This program is intended to be run using the MPLAB IDE and the PIC32 kit but doesn't require a PIC32 kit and can be compiled, built and executed using the Simulator.

--------------
Collaboration

For this lab I did not collaborate with anyone. I did the lab by myself and got support from TA's Andrew and Navid.


--------------
Lab Summary:

In this lab, I think the important aspects concerned assembling and executing the logic that goes into a state maching and making sure it functioned as intended. The finite state machine is a closed system where every outcome is deterministic in that it follows some pre-prepared path within the system to a halting point till it is again iterated through the system based on an event check. In the case of the toaster oven this was in terms of the states of setting up, reseting, cooking and selecting which all were changed and shifted based on the events of the adc reading, button 3 press, button 4 press and timer ticks. Thus the system manipulated states depending on events that occured and adjusted the states and actions within the program in accordance with those events to simulate the activity of a toaster oven. I think another important aspect was the free running counter and keeping track of time that occurs between two events because this allows the finite state machine to have more options based on the times set for each event. I see this applied directly on everyday PC use where depending on the time that a power button is pressed, you can restart the PC in regular or safemode. Thus free running counters, I think are important because they allow useful applications through increasing the options within a finite state machine.

--------------
Approach to Lab:

My approach to this lab was initially diving into setting up specific actions of the program but shifted to stepping back and implementing the generic actions before the specific ones. Initially, after setting up the OLED screen with the appropiate characters and formatting, I tried to make the selection change with the less than symbol work correctly and the potentiometer and temperature change accordingly as well. I hit a roadblock when I had difficultly with converting the hertz rate to a time from 0:01 to 4:15 because the lab manual instructed to use only the top 8 bits and add one to the hertz rate. I tried to do this by casting the hertz rate input as an unsigned 8 bit integer but this did not give the correct 8 bit value. So I abandoned this approach and instead tried to setup the state machine generically first and check if it can switch from screen to screen correctly. In this I read the lab manual 4 times over and then I configured the timer ISR and timer ticks to read in button input to differentiate between long button presses and short button presses to correctly react to either changing selection or switching screens. From there I went back to setting up the cooking time and temperature and figured that I could bitshift to the right to get the top eight bits and then add one to get a hertz value that is within 0 to 255 and converts to 0:01 to 4:15. I then fixed the temperature manipulation as well and then moved on to counting down the cooking time. I encountered some issues with the cooking time decrementing too quickly because my timer isr was not adjusted to the 5 hertz per seconds constant. Navid clarified this to me and I fixed this issue by adding an if statement that only decremented if the free running time had no remainder with 5. Finally, finishing the led portion of the lab was the least difficult as the math seemed very intuitive to me of taking the difference of the total time cooking and subtracting it from the current time and seeing if that difference was equal to the value total time cooking split among each LED. 

If I were to start this lab again, I would first start with generically implementing the transitions between modes instead of trying to configure the potentiometer and buttons first. After tracing my steps back and doing this starting from general states implementation instead of specific features, I also got a better grasp of the flow of the program and state machine within the lab so this was definitely something I should have done to begin with at the start of the lab.

I didn't really work with other students in the class. StackOverflow and the TA's were the primary source of knowledge and support.

--------------
Results of Lab:

I think all things considered the finite state machine program I made for this lab was a success. I spent close to 20-25 hours working on this lab. I liked seeing the results of the program on the PIC32 board and also seeing that everything functioned well as it rewarding to see the program work as intended. I didn't dislike anything about the lab except for some unclear parts of the lab manual but TA's Andrew and Navid helped clarify things so wasn't that big of an issue. The most difficult part was probably understanding the flow of the program and the function of runOvenSM() because I understood in large part how to implement all the other parts of the lab but it wasn't initially clear from seeing the main() file where the switch statement was supposed to go and how and when updateOLED() is supposed to be called. After understanding the main() is only called by event flags and that all the logic checks are in runOvenSM() the lab program flow was much easier to implement. 

There are a number of drawbacks with the current implementation of the Oven finite state machine on the board. First during any event, it is not clear and not established how a state will react to unfamiliar actions or readings for manipulation of potentiometer or buttons on the board because those readings have not been anticipated in those states. Furthermore, the LEDS do not evenly light down in cooking times that are not evenly divisible by 8 and if the cooking time is less than 8 seconds then the Oven simply resets because it cannot be divided into 8 parts in terms of integers. These are some limitations that I would have liked to correct but didn't have enough time to do. 

The points distribution for this lab seems fair. The lab manual had a lot of crucial information that was detailed enough and was helpful in implementing this lab. Additionally, concepts convered in class like structs, macros, constants were absolutely relevant to this lab and helped implementing it in realtime. 




