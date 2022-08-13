Name: Bijaya Khadka
CruzID: bkhadka

Summer Session 2, 2022

ECE 13

Lab 3: Double Linked List

--------------
DESCRIPTION


This lab will develop a program for Double Linked List and utilize for sorting.


--------------
FILES


- Lab3.X
    - BOARD.h
    - BOARD.c
    - LinkedList.h
    - LinkedList.c
    - LinkedListTest.c
    - sort.c

This file includes a MPLAB project folder for the lab. Within the MPLAB project folder, BOARD.h and BOARD.c are files for setting up and writing out the program to a Arduino. LinkedList.h is a header files that declares the LinkedList functions which will are coded in LinkedList.c. And LinkedListtest.c is the file with main() where those functions are tested and writes output evaluating tests passed. sort.c is the file that displays the sorting algorithms.


INSTRUCTIONS

This program is intended to be run using the MPLAB IDE and the PIC32 kit but doesn't require a PIC32 kit and can be compiled, built and executed using the Simulator.
--------------

STOP WATCH TIMES
Target halted. Stopwatch cycle count = 198925 (198.925 ms)
Target halted. Stopwatch cycle count = 48886 (48.886 ms)
Target halted. Stopwatch cycle count = 597461 (597.461 ms)
Target halted. Stopwatch cycle count = 31513 (31.513 ms)




--------------
THOUGHTS

Did you collaborate with anyone?

No I did the lab by myself and got support from TA's Andrew and Navid.

o Which was faster, SelectionSort() or InsertionSort()? Explain why. Was this what you expected?

Insertion sort was faster because it had less iterations about the list than Selection Sort. Selection Sort goes through the list all the way through mulitple times for each iteration. This is why it takes longer. Insertion sort on the otherhand takes less time because it doesn't need to iterate through all elements everytime it checks through the list in so far as a certain number of elements are less or greater than the element scanner's compared item.

o In the next section you should provide a summary of the lab in your own words. Highlight what you thought were the important aspects of the lab. If these differ from how the lab manual presents things, make a note of that.

I think it was important to understand data structures like Linked LIsts and the usage of structs as well. I think linked lists are imporant in regard to the C langauge because unlike other languages where you immediately change and save the values to an int or other type, in C you cannot do this without declaring a pointer. So managing the memory and taking the intricacies of the pointer into account was important I think. Furthermore, Data structures in general seem very important to real world applications in terms of how data is stored transported and how data manipulation is conducted with regard to the memory handling. Especially in terms of seeing the process of a Linked List at the level of the compiler and RAM memory it gave a better picture of how the hardware handles data structures creation and manipulation. I also think understanding the different sorting algorithms and their benefits and disadvantages was significant. I did not entirely know that some algorithms were better for sorting than others in that the second differences that were made were actually really crucial. 

o The following section should describe your approach to the lab. What was your general approach to the lab? Did you read the manual first or what were your first steps? What went wrong as you worked through it? What worked well? How would you approach this lab differently if you were to do it again? How did you work with other students in the class and what did you find helpful/unhelpful?

My approach was getting the functions working first of all. Getting the first function of LinkedListNew working was a burden because I wasn't sure how to handle random memory allocation. I also was not confident in malloc and memory management as they were not used in any other programming language I was familiar with. So I got the three primary functions working first which were also including LinkedListCreateAfter and LinkedListRemove which basically madeup the crux of the Item manipulation in the lab. After getting these done, the other functions were easier to implement mostly because you were not trying to create an abstract data type but just returning information or some point of reference to something already created. This was definitely an easier task than the other ones. The Test harness was difficult to work out because it wasn't clear which edge cases would be tested like if some functions would be called on items that had been removed and deallocated and this might still return some garbage memory. I fixed this by reverting the address to nulls when removing.

o The final section should describe the results of you implementing the lab. How did it end up finally? How many hours did you end up spending on it? What did you like about it? What did you dislike? Was this a worthwhile lab? Do you have any suggestions for altering it to make it better? What were the hardest parts of it? Did the points distribution for the grading seem appropriate? Did the lab manual cover the material in enough detail to start you off? Did examples or discussions during class help your understand this lab or would more teaching on the concepts in this lab help?

I spent virtually the entire week working on it. Probably over 45 hours working on. Firstly because MPLab IDE was not working and that was an annoynance from the get go. So I worked on the lab mostly from the source of another IDE and got everything working well. But when I transferred onto MPLab IDE when I got it work again, there were a number of compile errors and syntactical as well as memory weird issues. This was an even bigger hassle and drove me away from fully completing this lab. Furthermore, I live about an hour away from Santa Cruz and driving to and fro to attend lab sections really took away some time and considering all the other technical issues, I wasn't able to fully complete the lab to my liking. Primarily, the test harness did not fully come out the way I wanted it to but other than that everything else worked. TA's Andrew and Navid were crucially supportive in this lab.

