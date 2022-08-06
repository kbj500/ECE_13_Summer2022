

Name: Bijaya Khadka
CruzID: bkhadka

Summer Session 2, 2022

ECE 13

Lab 2: Matrix Math

--------------
DESCRIPTION


This lab will develop a program for 3x3 Matrix Calculation and output Tested results for sample calculations.


--------------
FILES


- Lab2.X
    - BOARD.h
    - BOARD.c
    - MatrixMath.h
    - MatrixMath.c
    - mml_test.c

This file includes a MPLAB project folder for the lab. Within the MPLAB project folder, BOARD.h and BOARD.c are files for setting up and writing out the program to a Arduino. MatrixMath.h is a header files that declares the Matrix functions which will are coded in MatrixMath.c. And mml_test.c is the file with main() where those Matrix functions are tested and writes output evaluating tests passed.


INSTRUCTIONS

This program is intended to be run using the MPLAB IDE and the PIC32 kit but doesn't require a PIC32 kit and can be compiled, built and executed using the Simulator.


--------------
THOUGHTS

Provide a summary of the lab in your own words. Highlight what
you thought were the important aspects of the lab. If these differ
from how the lab manual presents things, make a note of that.

This lab basically exibhited functions, expressions, assignment, loops, printing, arrays and types within C through the implementation of a program that manipulates 3x3 matrices. I think it was important to understand the nuances and minute details of these general programming language operations within C because it increases confidence, comfortablility, familiarity and actual experience with coding in C, which was something that I still feel I am gradually marinating into. Especially understanding basic compilation problems, syntactical issues and output handling were significant for moving past a minimum understanding of the language. Doing this lab made me very much more comfortable coding in C in general. I have already taken Linear Algebra so I didn't find the matrix content that important but moreso the different kinds of tools in C to represent data and types of constructs and how we can use them was more important to me. The lab manual presented the method of passing by reference in this lab but I never had to use it for any part of the lab except when I made a void local function in mml_test, testPassed() inorder to automate the printing process for each unit test that had succeeded or failed. 


What mistakes did you make, and how did you identify and solve
them?

My primary mistake that took the most time solving was the calculation of the matrix inverse which required a formula that had a negative one to a certain power according to the position of the row or column that was iterated over in the matrix. I didn't realize that C does not treat the operator ^ in the same way as other programming languages as a built in "to the power of" operation but instead it is a bitwise AND operation. I tried to find a neat workaround that didn't require including other libraries like the math library in C or writing out a full function or if else statement so that I could get the operation on the negative one correct but I couldn't think of any workaround on time so I just ended up using an if else statement testing for an even modulo. I also encountered some values in my matrices during function tests to have negative zero and I didn't realize that in C -0 and 0 are equivalently seen as 0. So I again implemented a fix with an if else statement that converted all negative signed zeros to just regular zeros. 

Describe your approach to the lab. What went wrong as you worked
through it? What worked well? What limitations are present in your
code regarding matrix sizes, etc? How would you approach this lab
differently if you were to do it again?

The biggest issue I faced this lab was that the day after the lab released, my MPLAB IDE kept freezing and crashing at startup. I tried fixing this for a whole day to no avail and ended up writing my code in another IDE temporarily but even throughout the week after seeing and getting help from TAs Navid and Andrew, I could not get my MPLAB IDE fixed. I tried uninstall reinstalls, restatring cpu, deleting caches, updating compiliers, and changing a plethora of project properties and settings still nothing worked so I coded in a different IDE and check the compilation on Andrew's CPU. My approach was centered around gradually building upon the validity of each function as I coded them. First I got the MatrixPrint() function correct because it was basically just printing out an array of numbers which I had done before in other languages. Then I got the MatrixEquals() function correct because it had the same loop structure as MatrixPrint(), but instead of assigning values it within the loop, you compare them between two matrices. So getting these functions right I used them in verifying that all the other more complicated operations were correct. Additionally, I added a ton of printf() statements throughout my loops in the functions when I was writing them so I could clear up any discrepancies if something was not working correctly and this approach to debugging really helped prevent and resolve minute and possibly overlooked things.

The clear limitation in my code is that the size of the matrices must be 3x3 as defined by DIM. As a result my functions and this library, are not dynamic to different size matrices. They are fixed to 3x3 and will produce errors if the input is not fixed as such. Also, there is no straightforward way to test the expected output for a non-invertible matrix when the MatrixInverse() function is called as the print() output of that function must match the expected output but that function is void so I'm not sure how the printf() output could be accessed. Maybe there is some workaround.

If I were to do this lab again, I would purchase a windows computer but Navid told me that MACs are problematic for MPLAB IDEs and if I didn't have MPLAB IDE issues I probably wouldn't have had initial troubles and more time to refine my code. 

Do you have any feedback for us about this lab?

I think it's a really good lab for implementing and practicing many different basic parts for C but the criteria on the dcoumentation is not clear. There's multiple sections with headings that give requirements that don't always apply when I ask the TAs and then there's some sections where a certain aspect is left unclear.  

Did you work with anyone else in the class? How did you work with them and what did you find
helpful/unhelpful?

I didn't work with anyone in the class. I mostly got my questions and issues with code answered by TAs Navid and Andrew. They were super helpful and cooperative.

Give us some feedback. How many hours did you end up spending
on it? What'd you like about it? 

I probably spent somewhere around 35-40 hours. I probly would have spent like 25 hours but my MPLAB issues exacerabated the time constraints. I liked the rewarding feeling that occurs when you have spent the last 3 hours on a particular snippet of code competely oblivious to the core issue of some incorrect output and then all of a sudden you connect the dots and hypothesize another source where the issue is coming from and attempt resolving it from there and you succeed! I also liked seeing the matrices retain their properties amidst the calculations. It was fascinating. 

What did you dislike? Was this a worthwhile lab? Do you have any suggestions for altering it to make
it better? What were the hardest parts of it?   

This was definitely a worthwile lab. Implementing any general program that does calculations seems productive and insightful as to how calculations are actually written for all kinds of computational calculators. I disliked the fact that I had setup my lab folder through MPLAB IDE but then I couldn't use MPLAB IDE because it froze and crashed on my CPU so this made me worry about manipulating C files and replacing them to compile and build successfully in MPLAB. I think the most difficult part was writing the code for the MatrixInverse() function because that required a number of different computations. No suggesstions aside from clearing up instructions and requirements on documentation a little better.

Did the points distribution for the grading seem appropriate? 

Yes and the extra point seemed appropiate given there's many different parts of the lab and leaving cushion for a 1 point deduction seemed reasonable.

Did the lab manual cover the material in enough detail to start you off? Did examples
or discussions during class help you understand this lab or would
more teaching on the concepts in this lab help?

Yes for the most part the lab manual definitely helped to start off the initial steps of the writing the program but the lab manual fell short in specifying what kinds of cases would not be checked for and would be checked for as well as particularly what kinds of unit tests should be run. The manual only elaborated that the tests should be non trivial and 2 or more for each function but it didn't say anything about the trickiness of floating point numbers and digit representation in C ie. -0, rounding. This was left up to the coder to resolve. Additionally, not all matrix computations were possible such as finding the inverse of a matrix with zero detereminant, this was not really mentioned in the lab in terms of handling. Lectures helped understand what I was conceptually doing while coding but it didn't really help the debugging process or fixing malfunctioning code. 

