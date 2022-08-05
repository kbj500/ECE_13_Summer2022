/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include "MatrixMath.h"

int main()
{
    /* Initialize example matrices used for testing*/
    
    float zero_matrix[3][3] = {{},{},{}};
    float sample1_matrix[3][3] = {{3,4,5},{7,8,2},{0,9,1}};
    float sample2_matrix[3][3] = {{-7,-4,3},{6,-7,-3},{-2,5,-2}};
    float identity_matrix[3][3] = {{1,0,0},{0,1,0},{0,0,1}};
    float out_matrix[3][3];
    
    
    /* test pass function to print frequency of tests passed if output equaled expected output */
    void testPassed(float m[3][3],float e[3][3],int pass)
    {
        if(MatrixEquals(m,e))
        {
            pass++;
        }
    }
    
    
/******************************************************************************
 * Matrix Print Check:
 *****************************************************************************/
/**/ 

printf("************************** \n");
printf("** MATRIX PRINT CHECK **\n");
printf("**************************\n");


 /* Check print on zero_matrix*/
 printf("Operation: print zero matrix\n");
 printf("Output:\n");
 MatrixPrint(zero_matrix);
 printf("Expected output:\n%f %f %f\n%f %f %f\n%f %f %f\n",0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000);
 printf("\n");
 printf("\n");
 
 
 /* Check print on identity_matrix */
 printf("Operation: print identity matrix\n");
 printf("Output:\n");
 MatrixPrint(identity_matrix);
 printf("Expected output:\n%f %f %f\n%f %f %f\n%f %f %f\n",1.000000,0.000000,0.000000,0.00000,1.00000,0.00000,0.000000,0.000000,1.000000);
 printf("\n");
 printf("\n");
 
 
 /* Check print on sample1_matrix */
 printf("Operation: print sample1 matrix\n");
 printf("Output:\n");
 MatrixPrint(sample1_matrix);
 printf("Expected output:\n%f %f %f\n%f %f %f\n%f %f %f\n",3.000000,4.000000,5.000000,7.000000,8.000000,2.000000,0.000000,9.000000,1.000000);
 printf("\n");
 printf("\n");
 
 
 /* Check print on sample2_matrix */ 
 printf("Operation: print sample2 matrix\n");
 printf("Output:\n");
 MatrixPrint(sample2_matrix);
 printf("Expected output:\n%f %f %f\n%f %f %f\n%f %f %f\n",-7.000000,-4.000000,3.000000,6.000000,-7.000000,-3.000000,-2.000000,5.000000,-2.000000);
 printf("\n");
 printf("\n");
 
 
 /******************************************************************************
 * Matrix Equals Check:
 *****************************************************************************/
/**/

int eqPass = 0;

printf("************************** \n");
printf("** MATRIX EQUALS CHECK **\n");
printf("**************************\n");


 /* Check equals on zero_matrix*/
 printf("Operation: Check zero matrix = zero matrix\n");
 printf("Output:%d\n",MatrixEquals(zero_matrix,zero_matrix));
 printf("Expected output:%d", 1);
 
if(MatrixEquals(zero_matrix,zero_matrix) == 1)
{
    eqPass++;
}
 
 printf("\n");
 printf("\n");
 

 
 
 /* Check equals on identity_matrix */
 printf("Operation: Check zero matrix = identity matrix\n");
 printf("Output:%d\n",MatrixEquals(zero_matrix,identity_matrix));
 printf("Expected output:%d", 0);
 
 if(MatrixEquals(zero_matrix,identity_matrix) == 0)
{
    eqPass++;
}
 
 printf("\n");
 printf("\n");
 
 
 /* Check equals on sample1_matrix */
 printf("Operation: Check sample1 matrix = sample1 matrix\n");
 printf("Output:%d\n",MatrixEquals(sample1_matrix,sample1_matrix));
 printf("Expected output:%d", 1);
 
 if(MatrixEquals(sample1_matrix,sample1_matrix) == 1)
{
    eqPass++;
}
 
 printf("\n");
 printf("\n");
 
 
 /* Check equals on sample2_matrix */ 
 printf("Operation: Check sample2 matrix = sample1 matrix\n");
 printf("Output:%d\n",MatrixEquals(sample2_matrix,sample1_matrix));
 printf("Expected output:%d", 0);
 
 if(MatrixEquals(sample2_matrix,sample1_matrix) == 0)
{
    eqPass++;
}
 
 
 printf("\n");
 printf("\n");
 
 
 /******************************************************************************
 * Matrix Multiply Check:
 *****************************************************************************/
/**/

int mulPass;

printf("************************** \n");
printf("** MATRIX MULTPLY CHECK **\n");
printf("**************************\n");


 /* Check matrix multply on zero_matrix*/
 printf("Operation: Check matrix product of zero matrix and zero matrix\n");
 MatrixMultiply(zero_matrix,zero_matrix,out_matrix);
 printf("Output:\n");
 MatrixPrint(out_matrix);
 printf("Expected output:\n%f %f %f\n%f %f %f\n%f %f %f\n",0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000);
 
testPassed(out_matrix,zero_matrix,mulPass);
 
 
 printf("\n");
 printf("\n");
 
 
 /* Check matrix multply on identity_matrix */
 printf("Operation: Check matrix product of identity matrix and identity matrix\n");
 MatrixMultiply(identity_matrix,identity_matrix,out_matrix);
 printf("Output:\n");
 MatrixPrint(out_matrix);
 printf("Expected output:\n%f %f %f\n%f %f %f\n%f %f %f\n",1.000000,0.000000,0.000000,0.00000,1.00000,0.00000,0.000000,0.000000,1.000000);
 
 testPassed(out_matrix,identity_matrix,mulPass);
 
 printf("\n");
 printf("\n");
 
 
 /* Check matrix multply on sample1_matrix */
 printf("Operation: Check matrix product of sample1 matrix and identity matrix\n");
 MatrixMultiply(sample1_matrix,identity_matrix,out_matrix);
 printf("Output:\n");
 MatrixPrint(out_matrix);
 printf("Expected output:\n%f %f %f\n%f %f %f\n%f %f %f\n", 3.000000, 4.000000,5.000000,7.000000,8.000000,2.000000,0.000000,9.000000,1.000000);
 
 testPassed(out_matrix,sample1_matrix,mulPass);
 
 printf("\n");
 printf("\n");
 
 
 /* Check matrix multiply on sample2_matrix */ 
 printf("Operation: Check matrix product of sample2 matrix and sample1 matrix\n");
 MatrixMultiply(sample2_matrix,sample1_matrix,out_matrix);
 printf("Output:\n");
 MatrixPrint(out_matrix);
 printf("Expected output:\n");
 float eo_mulsample2sample1_matrix[3][3] ={{-49.000000,-33.000000,-40.000000},{-31.000000,-59.000000,13.000000},{29.000000,14.000000,-2.000000}};
 
 testPassed(out_matrix,eo_mulsample2sample1_matrix,mulPass);
 
 printf("\n");
 printf("\n");
 
/******************************************************************************
 * Matrix Scalar Add Check:
 *****************************************************************************/
/**/


printf("*****************************\n");
printf("** MATRIX SCALAR ADD CHECK **\n");
printf("*****************************\n");


/* Check scalar add on zero_matrix */ 
 printf("Operation: add scalar 1 to zero matrix\n");
 printf("Output:\n");
 MatrixScalarAdd(1,zero_matrix,out_matrix);
 MatrixPrint(out_matrix);
 printf("Expected output:\n%f %f %f\n%f %f %f\n%f %f %f\n",1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000,1.000000);
 printf("\n");
 printf("\n");
 
 
 /* Check scalar add on identity_matrix */ 
 printf("Operation: add scalar 95 to identity matrix\n");
 printf("Output:\n");
 MatrixScalarAdd(95,identity_matrix,out_matrix);
 MatrixPrint(out_matrix);
 printf("Expected output:\n%f %f %f\n%f %f %f\n%f %f %f\n",96.000000,95.000000,95.000000,95.000000,96.000000,95.000000,95.000000,95.000000,96.000000);
 printf("\n");
 printf("\n");
 
 /* Check scalar add on sample1_matrix */ 
 printf("Operation: add scalar -86 to sample1 matrix\n");
 printf("Output:\n");
 MatrixScalarAdd(-86,sample1_matrix,out_matrix);
 MatrixPrint(out_matrix);
 printf("Expected output:\n%f %f %f\n%f %f %f\n%f %f %f\n",-83.000000,-82.000000,-81.000000,-79.000000,-78.000000,-84.000000,-86.000000,-77.000000,-85.000000);
 printf("\n");
 printf("\n");
 
 
 /* Check scalar add on sample2_matrix */ 
 printf("Operation: add scalar -6.5783 to sample2 matrix\n");
 printf("Output:\n");
 MatrixScalarAdd(-6.5783,sample2_matrix,out_matrix);
 MatrixPrint(out_matrix);
 printf("Expected output:\n%f %f %f\n%f %f %f\n%f %f %f\n",-13.578300,-10.578300,-3.578300,-0.578300,-13.578300,-9.578300,-8.578300,-1.578300,-8.578300 );
 printf("\n");
 printf("\n");
 
 
/******************************************************************************
 * Matrix Scalar Multiply Check:
 *****************************************************************************/
/**/

printf("*********************************\n");
printf("** MATRIX SCALAR MULTPLY CHECK **\n");
printf("*********************************\n");


/* Check scalar multiply on zero_matrix */ 
 printf("Operation: multiply scalar 1 to zero matrix\n");
 printf("Output:\n");
 MatrixScalarMultiply(1,zero_matrix,out_matrix);
 MatrixPrint(out_matrix);
 printf("Expected output:\n%f %f %f\n%f %f %f\n%f %f %f\n",0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000,0.000000);
 printf("\n");
 printf("\n");
 
 
 /* Check scalar multiply on identity_matrix */ 
 printf("Operation: multiply scalar 95 to identity matrix\n");
 printf("Output:\n");
 MatrixScalarMultiply(95,identity_matrix,out_matrix);
 MatrixPrint(out_matrix);
 printf("Expected output:\n%f %f %f\n%f %f %f\n%f %f %f\n",95.000000,0.000000,0.000000,0.000000,95.000000,0.000000,0.000000,0.000000,95.000000);
 printf("\n");
 printf("\n");
 
 /* Check scalar multiply on sample1_matrix */ 
 printf("Operation: multiply scalar -86 to sample1 matrix\n");
 printf("Output:\n");
 MatrixScalarMultiply(-86,sample1_matrix,out_matrix);
 MatrixPrint(out_matrix);
 printf("Expected output:\n%f %f %f\n%f %f %f\n%f %f %f\n",-258.000000,-344.000000,-430.000000,-602.000000,-688.000000,-172.000000,0.000000,-774.000000,-86.000000);
 printf("\n");
 printf("\n");
 
 
 /* Check scalar multiply on sample2_matrix */ 
 printf("Operation: multiply scalar -6.5783 to sample2 matrix\n");
 printf("Output:\n");
 MatrixScalarMultiply(-6.5783,sample2_matrix,out_matrix);
 MatrixPrint(out_matrix);
 printf("Expected output:\n%f %f %f\n%f %f %f\n%f %f %f\n",-13.578300,-10.578300,-3.578300,-0.578300,-13.578300,-9.578300,-8.578300,-1.578300,-8.578300 );
 printf("\n");
 printf("\n");
 
/******************************************************************************
 * Matrix Trace Check:
 *****************************************************************************/
/**/

printf("************************\n");
printf("** MATRIX TRACE CHECK **\n");
printf("************************\n");


/* Check trace on zero_matrix */ 
 printf("Operation: compute trace of zero matrix\n");
 printf("Output:%f\n",MatrixTrace(zero_matrix));
 printf("Expected output:%f\n",0.000000);
 printf("\n");
 printf("\n");
 
 
 /* Check trace on identity_matrix */ 
 printf("Operation: compute trace of identity matrix\n");
 printf("Output:%f\n",MatrixTrace(identity_matrix));
 printf("Expected output:%f\n",3.000000);
 printf("\n");
 printf("\n");
 
 
 /* Check trace on zero_matrix */ 
 printf("Operation: compute trace of sample1 matrix\n");
 printf("Output:%f\n",MatrixTrace(sample1_matrix));
 printf("Expected output:%f\n",12.000000);
 printf("\n");
 printf("\n");
 
 
 /* Check trace on zero_matrix */ 
 printf("Operation: compute trace of sample2 matrix\n");
 printf("Output:%f\n",MatrixTrace(sample2_matrix));
 printf("Expected output:%f\n",-16.000000);
 printf("\n");
 printf("\n");
 
/******************************************************************************
 * Matrix Transpose Check:
 *****************************************************************************/
/**/

printf("****************************\n");
printf("** MATRIX TRANSPOSE CHECK **\n");
printf("****************************\n");


/* Check transpose on zero_matrix */ 
 printf("Operation: compute transpose of zero matrix\n");
 printf("Output:\n");
 MatrixTranspose(zero_matrix,out_matrix);
 MatrixPrint(out_matrix);
 printf("Expected output:\n");
 MatrixPrint(zero_matrix);
 printf("\n");
 printf("\n");
 
 
 /* Check transpose on identity_matrix */ 
 printf("Operation: compute transpose of identity matrix\n");
 printf("Output:\n");
 MatrixTranspose(identity_matrix,out_matrix);
 MatrixPrint(out_matrix);
 printf("Expected output:\n");
 MatrixPrint(identity_matrix);
 printf("\n");
 printf("\n");
 
 
 /* Check transpose on sample1_matrix */ 
 printf("Operation: compute transpose of sample1 matrix\n");
 printf("Output:\n");
 MatrixTranspose(sample1_matrix,out_matrix);
 MatrixPrint(out_matrix);
 printf("Expected output:\n");
 float eotrans_sample1_matrix[3][3] = {{3,7,0},{4,8,9},{5,2,1}};
 MatrixPrint(eotrans_sample1_matrix);
 printf("\n");
 printf("\n");
 
 
 /* Check transpose on sample2_matrix */ 
 printf("Operation: compute transpose of sample1 matrix\n");
 printf("Output:\n");
 MatrixTranspose(sample2_matrix,out_matrix);
 MatrixPrint(out_matrix);
 printf("Expected output:\n");
 float eotrans_sample2_matrix[3][3] = {{-7,6,-2},{-4,-7,5},{3,-3,-2}};
 MatrixPrint(eotrans_sample2_matrix);
 printf("\n");
 printf("\n");


/******************************************************************************
 * Matrix Inverse Check:
 *****************************************************************************/
/**/

printf("****************************\n");
printf("** MATRIX INVERSE CHECK **\n");
printf("****************************\n");


/* Check inverse on zero_matrix */ 
 printf("Operation: compute matrix inverse of zero matrix\n");
 printf("Output:\n");
 MatrixInverse(zero_matrix,out_matrix);
 printf("Expected output:\nThe matrix is not invertible.\n");
 printf("\n");
 printf("\n");
 
 
 /* Check inverse on identity_matrix */ 
 printf("Operation: compute matrix inverse of identity matrix\n");
 printf("Output:\n");
 MatrixInverse(identity_matrix,out_matrix);
 MatrixPrint(out_matrix);
 printf("Expected output:\n");
 MatrixPrint(identity_matrix);
 printf("\n");
 printf("\n");


/* Check inverse on sample1_matrix */ 
 printf("Operation: compute matrix inverse of sample1 matrix\n");
 printf("Output:\n");
 MatrixInverse(sample1_matrix,out_matrix);
 MatrixPrint(out_matrix);
 printf("Expected output:\n");
 float eoINV_sample1_matrix[3][3] = {{-0.038911,0.159533,-0.124514},{-0.027237,0.011673,0.112840},{0.245136,-0.105058,-0.015564}};
 MatrixPrint(eoINV_sample1_matrix);
 printf("\n");
 printf("\n");
 
/* Check inverse on sample2_matrix */ 
 printf("Operation: compute matrix inverse of sample2 matrix\n");
 printf("Output:\n");
 MatrixInverse(sample2_matrix,out_matrix);
 MatrixPrint(out_matrix);
 printf("Expected output:\n");
 float eoINV_sample2_matrix[3][3] = {{-0.127753,-0.030837,-0.145374},{-0.079295,-0.088106,0.013216},{-0.070485,-0.189427,-0.321586}};
 MatrixPrint(eoINV_sample2_matrix);
 printf("\n");
 printf("\n");


printf("****************************\n");
printf("********  SUMMARY  *********\n");
printf("****************************\n");

int functionTests[] = {eqPass,mulPass};
const char *functionNames[2];
functionNames[0] = "MatrixEquals()";
functionNames[1] = "MatrixMultiply()";
printf("%s\n", functionNames[0]);
printf("%s\n", functionNames[1]);
int functionsPassed = 0;
for (int i = 0; i < functionTests; i++) {
  if(functionTests[i]==4)
  {
      printf("PASSED %d / %d: %s\n", functionTests[i],4, functionNames[i]);
      functionsPassed++;
  }
  else
  {
      //printf("FAILED%d / %d\n", functionTests[i],4);
  }
}

//printf("%d out of %d functions passed (%.2f%%).",functionsPassed,9,(float)functionsPassed/9 * 100.0);

 /*
 * consistent formatting.  
 * @param: mat, pointer to a 3x3 float array
 * @return: none
 * The printed matrix should be aligned in a grid when called with positive or
 *  negative numbers.  It should be able to display at least FP_DELTA precision, and
 *  should handle numbers as large as 999.0 or -999.0
 */
    
    
    
}
