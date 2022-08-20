Name: Bijaya Khadka
CruzID: bkhadka

Summer Session 2, 2022

ECE 13

Lab 4: Basic IO on a Microcontroller

--------------
DESCRIPTION


This lab will develop a program for reading sensors and developing output for the buttons, LEDS, OLED and Potentiometer of the PIC32 Arduino board.


--------------
FILES


- Lab4.X
    - Pre-written Files
        - Ascii.h
        - Ascii.c
        - BOARD.c
        - BOARD.h
        - Buttons.h
        - Oled.c
        - Oled.h
        - OledDriver.c
        - OledDriver.h
        - Leds_Lab04.h
    - Created Files
        - Leds_Lab04.c
        - Buttons.c
    - Edited Files
        - bounce_timers.c
        - bounce_switch.c
        - bounce_adc.c
        - ButtonsTest.c
        - bounce_buttons.c
        - bounce_ec.c


This file includes a MPLAB project folder for the lab. Within the MPLAB project folder the Pre-written files are all files to support constants and functions that manipulate pins on the Board. Leds_Lab04.c and Buttons.c implement the functions in their respective header files, the former for LED manipulation and the latter for Button checking.  


INSTRUCTIONS

This program is intended to be run using the MPLAB IDE and the PIC32 kit but doesn't require a PIC32 kit and can be compiled, built and executed using the Simulator.

--------------
Collaboration

For this lab I did not collaborate with anyone. I did the lab by myself and got support from TA's Andrew and Navid.


--------------
Lab Summary:

In this lab, I think the important aspects concerned the intricacies of handling sensitive external responses in an embedded system. For different concurrent parts of the lab, there were different components on the PIC32 Arduino board which were made to change in line with the output produced from a program. In doing this, the program has to handle specific kinds of sensitive external responses that the user does onto the component like turning the potentiometer or pressing a button or flipping a switch, where the input could be erratic because the shifting, turning or pressing action from the user did not follow a strictly binary form. It took on fluctuating value and that value had to be interpreted and handled in a way where it could be read and inline with an appropriate output like characters displayed on the OLED. It think this porcess is the most significant thing that I learned in this lab about embedded systems because handling external responses in a program seems like the fundamental aspect of the function of an embedded system. So event-driven programming, interruptive service routines and windows to detect sharp changes were critical things in this lab concerning the handling of external responses that a program has to function in line with. 

--------------
Approach to Lab:

My approach to this lab was in first trying to get a solid conceptual understanding of what the objective of each part was. So in this, I printed out the lab manual and reread it several times over and annotated different parts. I did this also because this lab had more parts compared to previous labs and I noticed that crucial bits of information were only mentioned once or twice in some parts. 

From reading the lab manual I got a good grasp of the concepts but on starting the implementation of the programs, I encountered a number of technical difficulties but reading the header and .c files that were provided, helped clear things up. Retrospectively, part 1 and part 2 were relatively easy to implement and writing the functions of reach library for LEDs and OLED was also pretty self evident. The one major issue that I encountered that took up almost a whole day to resolve was an issue with the signed default value of char in the LEDS_GET() function. In my bounce_switch.c file, the LEDS were not bouncing correctly. In my main() the LED input would bitwise shift left to 64 but then in the next iteration of bitwise shifting it would result in -128 when LED_GET() was called after the shift. This was because the function, LED_GET() returns a char value that has a default signed type. And I tried many things to workaround this including casting the value but it did not work because I was always calling LED_GET() and if LED_GET() had been previously set to 128 then it would output -128. I fixed this after getting help from Navid by basically not using LED_GET() at all and replacing it with a integer variable. This worked like a charm but it was frustrating that such an eas fix eluded me for a large amount of time. Other than that there were not other major functional issues in terms of the files or components given.

If I were to start this lab again, I would just dive start into creating and editing the programs. Looking back, I probly was too focused on reading the lab manual and if I had just started coding first then I would understand what the objective was better because by observing the program and it's components and what they do in realtime, I definitely would have gotten a better understanding of what was desired. 

I didn't really work with other students in the class. I talked with some of my peers and gave and got minor clarifications on things but that was it. StackOverflow and the TA's were the primary source of knowledge and support.

--------------
Results of Lab:

All in all the lab was sufficiently completed. I spent approximately 30-35 hours working on it. I liked the fact that after completing a program, I could actually manipulate components on the board to something of my liking like seeing the voltage on the OLED change with the potentiometer turning. That was cool to see work out. The one thing I disliked about the lab werer the trivial solutions to time consuming issues that I had that I just did not see early enough. I think this was defnitely a worthwhile lab that gave a great grasp of what embedded systems do and how they actually function in realtime in response to external stimuli. I think the most difficult part of the lab was setting up the Button.c file in part 4. It was not clear to me exactly what the function ButtonCheckEvents() was supposed to return as a Button flag. I originally thought that it was supposed to be a 4 bit value similar to BUTTON_STATES() until a peer clarified to me that it was acutally an 8 bit value encoding the status of each action of each button. The points distribution seems a little bit tough because this lab has many parts and there's great chance for trivial errors that could mess core components up. The lab manual was a bit unclear but I could understand that it's objective was to get the readerto implement everything with minimal initial information and the class discussions definitely madeup for any and all discrepancies in the lab manual.




