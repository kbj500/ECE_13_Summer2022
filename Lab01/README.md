

Name: Bijaya Khadka
CruzID: bkhadka

Summer Session 2, 2022

ECE 13

Lab 1: Compiling, Running, and Debugging

--------------
DESCRIPTION


This lab will develop a "Hello World" program and simulate a temperature conversion table


--------------
FILES


- Lab1_part0.X
- Lab2_part0.X
- Lab3_part0.X

These files includes the MPE folders for each part of the lab. Part 0 writes "Hello World" onto the from the simulator to the Arduino board and the terminal. Part 1 shows formatting of code and the use of breakpoints and seeing variable changes during debugging. Part 2 simulates a temperature conversion table. 


INSTRUCTIONS

This program is intended to be run using the MPLAB IDE and the PIC32 kit.


--------------
RECORDED RESULTS

Recorded values of valsToBeSorted(6 iterations of debug cycle with breakpoint):

- 48,28,249,23,189
- 48,28,249,23,189
- 28,48,249,23,189
- 28,48,249,23,189
- 23,28,48,249,189
- 23,28,48,249,189

Changes made to following lines of part1.c:

- 15,17,19,20,22,30,35

--------------
THOUGHTS

What did you do in this lab? 

I learned the workarounds and environment of MPLAB IDE, how to setup projects, establish serial communication with PICkit3 through CoolTerm, compilation and debugging guidelines and steps,  tools and settings for checking code history and variables, and printf() specifications and use in C. Also used Git for saving and uploading work within MPLAB IDE.

What mistakes did you make, and how did you identify and solve
them?

I had a lot of technical difficulties with the project setup of the MPLAB IDE and the Arduino connection. I tinkered for quite some time to reset settings, try different options within the actions in the tool bar and hardware selection. Terminal issues and git issues were common but minor since I was familiar with using both. TA's Navid and Andrew were a great help in clarifying parts of the lab. Since I am using Mac OS many of the specific steps on the lab documentation did not apply and I had to use other means within the MPLAB IDE as it is within the Mac OS system. Also a prevalent problem that I spent many hours on was checking why my hardware wasn't detected or caused errors when compiling or make and program execution and it was because the lab documentation had provided the incorrect Pickit3 number for settings. TA's clarified this and am eternally grateful.

Do you have any feedback for us about this lab?

Please make sure the documentation is as ERROR FREE and CLEAR as it can be. Some vital parts of the documentation were incorrect such as the Pic3 hardware number for settings as well as loading a byte count for the HEAP when making new project and many other parts were unclear and lacked specification such as what to expect with the hardware setup ie. it will light up or not, and copy pasting sections of modified code. Many times it is significant that small details affect large parts of the lab and therefore it is important to make sure those small aspects of the documentation are as clear or as implied clear as can be so that extra time is not spent on miscellaneous questions or errors that could be used on furthering the actual content in the lab. 