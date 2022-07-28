/*
 * Every file you submit should start with a header like this
 *  
 * File:   part0.c
 * Author: Bijaya Khadka (bkhadka@ucsc.edu)
 *
 * Created on July 27, 2022, 11:02 PM
 */

#include <stdio.h>
#include <stdlib.h>

#include "BOARD.h"

/*
 * 
 */
int main(void) {

    BOARD_Init();
    printf("Hello World\n");
    
    
    BOARD_End(); // handles cleanup of the system
    while(1); // if embedded we should never exit
}

