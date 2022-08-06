/******************************************************************************

                TEST HARNESS FOR MATRIX MATH FUNCTIONS
        This file outputs test results for functions in MatrixMath.c
    **Must have MatrixMath.h header file in directory for compilation**

db   d8b   db d88888b db       .o88b.  .d88b.  .88b  d88. d88888b
88   I8I   88 88'     88      d8P  Y8 .8P  Y8. 88'YbdP`88 88'    
88   I8I   88 88ooooo 88      8P      88    88 88  88  88 88ooooo
Y8   I8I   88 88~~~~~ 88      8b      88    88 88  88  88 88~~~~~ 
`8b d8'8b d8' 88.     88booo. Y8b  d8 `8b  d8' 88  88  88 88.   
`8b8' `8d8'  Y88888P Y88888P  `Y88P'  `Y88P'  YP  YP  YP Y88888P 
    
*******************************************************************************/

// Standard libraries
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//CMPE13 Support Library
#include "BOARD.h"




// User libraries:
#include "MatrixMath.h"


int main ()
{
  BOARD_Init ();

  /* Initialize example matrices used for testing */

  float zero_matrix[3][3] = { {}, {}, {} };
  float sample1_matrix[3][3] = { {3, 4, 5}, {7, 8, 2}, {0, 9, 1} };
  float sample2_matrix[3][3] = { {-7, -4, 3}, {6, -7, -3}, {-2, 5, -2} };
  float identity_matrix[3][3] = { {1, 0, 0}, {0, 1, 0}, {0, 0, 1} };
  float out_matrix[3][3];

  /* varaibles for each function (except MatrixPrint), to count # of tests passed */
  int eqPass = 0;
  int addPass = 0;
  int mulPass = 0;
  int scalMulPass = 0;
  int scalAddPass = 0;
  int transPass = 0;
  int tracePass = 0;
  int detPass = 0;
  int invPass = 0;


  /* test pass function to print frequency of tests passed if output equaled expected output */
  void testPassed (float m[3][3], float e[3][3], int *pass)
  {
    if (MatrixEquals (m, e))
      {
	*pass = *pass + 1;
      }
  }


/******************************************************************************
 * Matrix Print Check:
 *****************************************************************************/
/**/ 
  printf ("************************** \n");
  printf ("** MATRIX PRINT CHECK **\n");
  printf ("**************************\n");


  /* Check print on zero_matrix */
  printf ("Operation: print zero matrix\n");
  printf ("Output:\n");
  MatrixPrint (zero_matrix);
  printf
    ("Expected output:\n%11.5f %11.5f %11.5f\n%11.5f %11.5f %11.5f\n%11.5f %11.5f %11.5f\n",
     0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000, 0.00000,
     0.00000);
  printf ("\n");
  printf ("\n");


  /* Check print on identity_matrix */
  printf ("Operation: print identity matrix\n");
  printf ("Output:\n");
  MatrixPrint (identity_matrix);
  printf
    ("Expected output:\n%11.5f %11.5f %11.5f\n%11.5f %11.5f %11.5f\n%11.5f %11.5f %11.5f\n",
     1.00000, 0.00000, 0.00000, 0.0000, 1.0000, 0.0000, 0.00000, 0.00000,
     1.00000);
  printf ("\n");
  printf ("\n");


  /* Check print on sample1_matrix */
  printf ("Operation: print sample1 matrix\n");
  printf ("Output:\n");
  MatrixPrint (sample1_matrix);
  printf
    ("Expected output:\n%11.5f %11.5f %11.5f\n%11.5f %11.5f %11.5f\n%11.5f %11.5f %11.5f\n",
     3.00000, 4.00000, 5.00000, 7.00000, 8.00000, 2.00000, 0.00000, 9.00000,
     1.00000);
  printf ("\n");
  printf ("\n");


  /* Check print on sample2_matrix */
  printf ("Operation: print sample2 matrix\n");
  printf ("Output:\n");
  MatrixPrint (sample2_matrix);
  printf
    ("Expected output:\n%11.5f %11.5f %11.5f\n%11.5f %11.5f %11.5f\n%11.5f %11.5f %11.5f\n",
     -7.00000, -4.00000, 3.00000, 6.00000, -7.00000, -3.00000, -2.00000,
     5.00000, -2.00000);
  printf ("\n");
  printf ("\n");


 /******************************************************************************
 * Matrix Equals Check:
 *****************************************************************************/
/**/ 
  printf ("************************** \n");
  printf ("** MATRIX EQUALS CHECK **\n");
  printf ("**************************\n");


  /* Check equals on zero_matrix */
  printf ("Operation: Check zero matrix = zero matrix\n");
  printf ("Output:%d\n", MatrixEquals (zero_matrix, zero_matrix));
  printf ("Expected output:%d", 1);

  if (MatrixEquals (zero_matrix, zero_matrix) == 1)
    {
      eqPass++;
    }

  printf ("\n");
  printf ("\n");




  /* Check equals on identity_matrix */
  printf ("Operation: Check zero matrix = identity matrix\n");
  printf ("Output:%d\n", MatrixEquals (zero_matrix, identity_matrix));
  printf ("Expected output:%d", 0);

  if (MatrixEquals (zero_matrix, identity_matrix) == 0)
    {
      eqPass++;
    }

  printf ("\n");
  printf ("\n");


  /* Check equals on sample1_matrix */
  printf ("Operation: Check sample1 matrix = sample1 matrix\n");
  printf ("Output:%d\n", MatrixEquals (sample1_matrix, sample1_matrix));
  printf ("Expected output:%d", 1);

  if (MatrixEquals (sample1_matrix, sample1_matrix) == 1)
    {
      eqPass++;
    }

  printf ("\n");
  printf ("\n");


  /* Check equals on sample2_matrix */
  printf ("Operation: Check sample2 matrix = sample1 matrix\n");
  printf ("Output:%d\n", MatrixEquals (sample2_matrix, sample1_matrix));
  printf ("Expected output:%d", 0);

  if (MatrixEquals (sample2_matrix, sample1_matrix) == 0)
    {
      eqPass++;
    }


  printf ("\n");
  printf ("\n");


 /******************************************************************************
 * Matrix Add Check:
 *****************************************************************************/
 /**/ 
  printf ("*****************************\n");
  printf ("**    MATRIX ADD CHECK     **\n");
  printf ("*****************************\n");


  /* Check matrix add on zero_matrix */
  printf ("Operation: add zero matrix to zero matrix\n");
  printf ("Output:\n");
  MatrixAdd (zero_matrix, zero_matrix, out_matrix);
  MatrixPrint (out_matrix);
  printf ("Expected output:\n");
  MatrixPrint (zero_matrix);
  testPassed (out_matrix, zero_matrix, &addPass);
  printf ("\n");
  printf ("\n");


  /* Check matrix add on identity_matrix */
  printf ("Operation: add identity matrix to identity matrix\n");
  printf ("Output:\n");
  MatrixAdd (identity_matrix, identity_matrix, out_matrix);
  MatrixPrint (out_matrix);
  printf ("Expected output:\n");
  float eoadd_identity_matrix[3][3] = { {2, 0, 0}, {0, 2, 0}, {0, 0, 2} };
  MatrixPrint (eoadd_identity_matrix);
  testPassed (out_matrix, eoadd_identity_matrix, &addPass);
  printf ("\n");
  printf ("\n");

  /* Check matrix add on sample1_matrix */
  printf ("Operation: add sample1 matrix to sample1 matrix\n");
  printf ("Output:\n");
  MatrixAdd (sample1_matrix, sample1_matrix, out_matrix);
  MatrixPrint (out_matrix);
  printf ("Expected output:\n");
  float eoadd_sample1_matrix[3][3] = { {6, 8, 10}, {14, 16, 4}, {0, 18, 2} };
  MatrixPrint (eoadd_sample1_matrix);
  testPassed (out_matrix, eoadd_sample1_matrix, &addPass);
  printf ("\n");
  printf ("\n");


  /* Check scalar add on sample2_matrix */
  printf ("Operation: add sample2 matrix to sample1 matrix\n");
  printf ("Output:\n");
  MatrixAdd (sample2_matrix, sample1_matrix, out_matrix);
  MatrixPrint (out_matrix);
  printf ("Expected output:\n");
  float eoadd_sample2_matrix[3][3] =
    { {-4, 0, 8}, {13, 1, -1}, {-2, 14, -1} };
  MatrixPrint (eoadd_sample2_matrix);
  testPassed (out_matrix, eoadd_sample2_matrix, &addPass);
  printf ("\n");
  printf ("\n");



 /******************************************************************************
 * Matrix Multiply Check:
 *****************************************************************************/
/**/ 
  printf ("************************** \n");
  printf ("** MATRIX MULTPLY CHECK **\n");
  printf ("**************************\n");


  /* Check matrix multiply on zero_matrix */
  printf ("Operation: Check matrix product of zero matrix and zero matrix\n");
  MatrixMultiply (zero_matrix, zero_matrix, out_matrix);
  printf ("Output:\n");
  MatrixPrint (out_matrix);
  printf ("Expected output:\n");
  MatrixPrint (zero_matrix);
  testPassed (out_matrix, zero_matrix, &mulPass);

  printf ("\n");
  printf ("\n");


  /* Check matrix multiply on identity_matrix */
  printf("Operation: Check matrix product of identity matrix and identity matrix\n");
  MatrixMultiply (identity_matrix, identity_matrix, out_matrix);
  printf ("Output:\n");
  MatrixPrint (out_matrix);
  printf ("Expected output:\n");
  MatrixPrint (identity_matrix);
  testPassed (out_matrix, identity_matrix, &mulPass);

  printf ("\n");
  printf ("\n");


  /* Check matrix multiply on sample1_matrix */
  printf
    ("Operation: Check matrix product of sample1 matrix and identity matrix\n");
  MatrixMultiply (sample1_matrix, identity_matrix, out_matrix);
  printf ("Output:\n");
  MatrixPrint (out_matrix);
  printf ("Expected output:\n");
  MatrixPrint (sample1_matrix);
  testPassed (out_matrix, sample1_matrix, &mulPass);
  printf ("\n");
  printf ("\n");


  /* Check matrix multiply on sample2_matrix */
  printf
    ("Operation: Check matrix product of sample2 matrix and sample1 matrix\n");
  MatrixMultiply (sample2_matrix, sample1_matrix, out_matrix);
  printf ("Output:\n");
  MatrixPrint (out_matrix);
  printf ("Expected output:\n");
  float eomul_sample2sample1_matrix[3][3] =
    { {-49.000000, -33.000000, -40.000000}, {-31.000000, -59.000000,
					     13.000000}, {29.000000,
							  14.000000,
							  -2.000000} };
  MatrixPrint (eomul_sample2sample1_matrix);
  testPassed (out_matrix, eomul_sample2sample1_matrix, &mulPass);

  printf ("\n");
  printf ("\n");

/******************************************************************************
 * Matrix Scalar Add Check:
 *****************************************************************************/
/**/ 
  printf ("*****************************\n");
  printf ("** MATRIX SCALAR ADD CHECK **\n");
  printf ("*****************************\n");


  /* Check scalar add on zero_matrix */
  printf ("Operation: add scalar 1 to zero matrix\n");
  printf ("Output:\n");
  MatrixScalarAdd (1, zero_matrix, out_matrix);
  MatrixPrint (out_matrix);
  printf ("Expected output:\n");
  float eoscadd_zero_matrix[3][3] = { {1, 1, 1}, {1, 1, 1}, {1, 1, 1} };
  MatrixPrint (eoscadd_zero_matrix);
  testPassed (out_matrix, eoscadd_zero_matrix, &scalAddPass);
  printf ("\n");
  printf ("\n");


  /* Check scalar add on identity_matrix */
  printf ("Operation: add scalar 95 to identity matrix\n");
  printf ("Output:\n");
  MatrixScalarAdd (95, identity_matrix, out_matrix);
  MatrixPrint (out_matrix);
  printf ("Expected output:\n");
  float eoscadd_identity_matrix[3][3] =
    { {96.000000, 95.000000, 95.000000}, {95.000000, 96.000000, 95.000000},
    {95.000000, 95.000000, 96.000000} };
  MatrixPrint (eoscadd_identity_matrix);
  testPassed (out_matrix, eoscadd_identity_matrix, &scalAddPass);
  printf ("\n");
  printf ("\n");

  /* Check scalar add on sample1_matrix */
  printf ("Operation: add scalar -86 to sample1 matrix\n");
  printf ("Output:\n");
  MatrixScalarAdd (-86, sample1_matrix, out_matrix);
  MatrixPrint (out_matrix);
  printf ("Expected output:\n");
  float eoscadd_sample1_matrix[3][3] =
    { -83.000000, -82.000000, -81.000000, -79.000000, -78.000000, -84.000000,
-86.000000, -77.000000, -85.000000 };
  MatrixPrint (eoscadd_sample1_matrix);
  testPassed (out_matrix, eoscadd_sample1_matrix, &scalAddPass);
  printf ("\n");
  printf ("\n");


  /* Check scalar add on sample2_matrix */
  printf ("Operation: add scalar -6.5783 to sample2 matrix\n");
  printf ("Output:\n");
  MatrixScalarAdd (-6.5783, sample2_matrix, out_matrix);
  MatrixPrint (out_matrix);
  printf ("Expected output:\n");
  float eoscadd_sample2_matrix[3][3] =
    { -13.578300, -10.578300, -3.578300, -0.578300, -13.578300, -9.578300,
-8.578300, -1.578300, -8.578300 };
  MatrixPrint (eoscadd_sample2_matrix);
  testPassed (out_matrix, eoscadd_sample2_matrix, &scalAddPass);
  printf ("\n");
  printf ("\n");


/******************************************************************************
 * Matrix Scalar Multiply Check:
 *****************************************************************************/
/**/ 
  printf ("*********************************\n");
  printf ("** MATRIX SCALAR MULTPLY CHECK **\n");
  printf ("*********************************\n");


  /* Check scalar multiply on zero_matrix */
  printf ("Operation: multiply scalar 1 to zero matrix\n");
  printf ("Output:\n");
  MatrixScalarMultiply (1, zero_matrix, out_matrix);
  MatrixPrint (out_matrix);
  printf ("Expected output:\n");
  MatrixPrint (zero_matrix);
  testPassed (out_matrix, zero_matrix, &scalMulPass);
  printf ("\n");
  printf ("\n");


  /* Check scalar multiply on identity_matrix */
  printf ("Operation: multiply scalar 95 to identity matrix\n");
  printf ("Output:\n");
  MatrixScalarMultiply (95, identity_matrix, out_matrix);
  MatrixPrint (out_matrix);
  printf ("Expected output:\n");
  float eoscamul_identity_matrix[3][3] =
    { 95.000000, 0.000000, 0.000000, 0.000000, 95.000000, 0.000000, 0.000000,
0.000000, 95.000000 };
  MatrixPrint (eoscamul_identity_matrix);
  testPassed (out_matrix, eoscamul_identity_matrix, &scalMulPass);
  printf ("\n");
  printf ("\n");

  /* Check scalar multiply on sample1_matrix */
  printf ("Operation: multiply scalar -86 to sample1 matrix\n");
  printf ("Output:\n");
  MatrixScalarMultiply (-86, sample1_matrix, out_matrix);
  MatrixPrint (out_matrix);
  printf ("Expected output:\n");
  float eoscamul_sample1_matrix[3][3] =
    { -258.000000, -344.000000, -430.000000, -602.000000, -688.000000,
-172.000000, 0.000000, -774.000000, -86.000000 };
  MatrixPrint (eoscamul_sample1_matrix);
  testPassed (out_matrix, eoscamul_sample1_matrix, &scalMulPass);
  printf ("\n");
  printf ("\n");


  /* Check scalar multiply on sample2_matrix */
  printf ("Operation: multiply scalar -6.5783 to sample2 matrix\n");
  printf ("Output:\n");
  MatrixScalarMultiply (-6.5783, sample2_matrix, out_matrix);
  MatrixPrint (out_matrix);
  printf ("Expected output:\n");
  float eoscamul_sample2_matrix[3][3] =
    { 46.048100, 26.313200, -19.734900, -39.469799, 46.048100, 19.734900,
13.156600, -32.891499, 13.156600 };
  MatrixPrint (eoscamul_sample2_matrix);
  testPassed (out_matrix, eoscamul_sample2_matrix, &scalMulPass);
  printf ("\n");
  printf ("\n");

/******************************************************************************
 * Matrix Trace Check:
 *****************************************************************************/
/**/ 

  printf ("************************\n");
  printf ("** MATRIX TRACE CHECK **\n");
  printf ("************************\n");


  /* Check trace on zero_matrix */
  printf ("Operation: compute trace of zero matrix\n");
  printf ("Output:%f\n", MatrixTrace (zero_matrix));
  printf ("Expected output:%f\n", 0.000000);
  if (MatrixTrace (zero_matrix) == 0.000000)
    {
      tracePass++;
    }
  printf ("\n");
  printf ("\n");


  /* Check trace on identity_matrix */
  printf ("Operation: compute trace of identity matrix\n");
  printf ("Output:%f\n", MatrixTrace (identity_matrix));
  printf ("Expected output:%f\n", 3.000000);
  if (MatrixTrace (identity_matrix) == 3.000000)
    {
      tracePass++;
    }
  printf ("\n");
  printf ("\n");


  /* Check trace on zero_matrix */
  printf ("Operation: compute trace of sample1 matrix\n");
  printf ("Output:%f\n", MatrixTrace (sample1_matrix));
  printf ("Expected output:%f\n", 12.000000);
  if (MatrixTrace (sample1_matrix) == 12.000000)
    {
      tracePass++;
    }
  printf ("\n");
  printf ("\n");


  /* Check trace on zero_matrix */
  printf ("Operation: compute trace of sample2 matrix\n");
  printf ("Output:%f\n", MatrixTrace (sample2_matrix));
  printf ("Expected output:%f\n", -16.000000);
  if (MatrixTrace (sample2_matrix) == -16.000000)
    {
      tracePass++;
    }
  printf ("\n");
  printf ("\n");

/******************************************************************************
 * Matrix Transpose Check:
 *****************************************************************************/
/**/ 
  printf ("****************************\n");
  printf ("** MATRIX TRANSPOSE CHECK **\n");
  printf ("****************************\n");


  /* Check transpose on zero_matrix */
  printf ("Operation: compute transpose of zero matrix\n");
  printf ("Output:\n");
  MatrixTranspose (zero_matrix, out_matrix);
  MatrixPrint (out_matrix);
  printf ("Expected output:\n");
  MatrixPrint (zero_matrix);
  testPassed (out_matrix, zero_matrix, &transPass);
  printf ("\n");
  printf ("\n");


  /* Check transpose on identity_matrix */
  printf ("Operation: compute transpose of identity matrix\n");
  printf ("Output:\n");
  MatrixTranspose (identity_matrix, out_matrix);
  MatrixPrint (out_matrix);
  printf ("Expected output:\n");
  MatrixPrint (identity_matrix);
  testPassed (out_matrix, identity_matrix, &transPass);
  printf ("\n");
  printf ("\n");


  /* Check transpose on sample1_matrix */
  printf ("Operation: compute transpose of sample1 matrix\n");
  printf ("Output:\n");
  MatrixTranspose (sample1_matrix, out_matrix);
  MatrixPrint (out_matrix);
  printf ("Expected output:\n");
  float eotrans_sample1_matrix[3][3] = { {3, 7, 0}, {4, 8, 9}, {5, 2, 1} };
  MatrixPrint (eotrans_sample1_matrix);
  testPassed (out_matrix, eotrans_sample1_matrix, &transPass);
  printf ("\n");
  printf ("\n");


  /* Check transpose on sample2_matrix */
  printf ("Operation: compute transpose of sample1 matrix\n");
  printf ("Output:\n");
  MatrixTranspose (sample2_matrix, out_matrix);
  MatrixPrint (out_matrix);
  printf ("Expected output:\n");
  float eotrans_sample2_matrix[3][3] =
    { {-7, 6, -2}, {-4, -7, 5}, {3, -3, -2} };
  MatrixPrint (eotrans_sample2_matrix);
  testPassed (out_matrix, eotrans_sample2_matrix, &transPass);
  printf ("\n");
  printf ("\n");


/******************************************************************************
 * Matrix Determinant Check:
 *****************************************************************************/
   /**/ printf ("******************************\n");
  printf ("** MATRIX DETERMINANT CHECK **\n");
  printf ("******************************\n");


/* Check determinant on zero_matrix */
  printf ("Operation: compute determinant of zero matrix\n");
  printf ("Output:%f\n", MatrixDeterminant (zero_matrix));
  printf ("Expected output:%f\n", 0.000000);
  if (MatrixDeterminant (zero_matrix) == 0.000000)
    {
      detPass++;

    }
  printf ("\n");
  printf ("\n");


  /* Check determinant on identity_matrix */
  printf ("Operation: compute determinant of identity matrix\n");
  printf ("Output:%f\n", MatrixDeterminant (identity_matrix));
  printf ("Expected output:%f\n", 1.000000);
  if (MatrixDeterminant (identity_matrix) == 1.000000)
    {
      detPass++;
    }
  printf ("\n");
  printf ("\n");


  /* Check determinant on zero_matrix */
  printf ("Operation: compute determinant of sample1 matrix\n");
  printf ("Output:%f\n", MatrixDeterminant (sample1_matrix));
  printf ("Expected output:%f\n", 257.000000);
  if (MatrixDeterminant (sample1_matrix) == 257.000000)
    {
      detPass++;
    }
  printf ("\n");
  printf ("\n");


  /* Check determinant on zero_matrix */
  printf ("Operation: compute determinant of sample2 matrix\n");
  printf ("Output:%f\n", MatrixDeterminant (sample2_matrix));
  printf ("Expected output:%f\n", -227.000000);
  if (MatrixDeterminant (sample2_matrix) == -227.000000)
    {
      detPass++;
    }
  printf ("\n");
  printf ("\n");

/******************************************************************************
 * Matrix Inverse Check:
 *****************************************************************************/
   /**/ printf ("****************************\n");
  printf ("** MATRIX INVERSE CHECK **\n");
  printf ("****************************\n");


/* Check inverse on zero_matrix */
  printf ("Operation: compute matrix inverse of zero matrix\n");
  printf ("Output:\n");
  float eoinv_zero_matrix[3][3] = { };
  MatrixAdd (zero_matrix, out_matrix, eoinv_zero_matrix);
  MatrixInverse (zero_matrix, out_matrix);
  printf ("Expected output:\nThe matrix is not invertible.\n");
  testPassed (out_matrix, eoinv_zero_matrix, &invPass);
  printf ("\n");
  printf ("\n");


/* Check inverse on identity_matrix */
  printf ("Operation: compute matrix inverse of identity matrix\n");
  printf ("Output:\n");
  MatrixInverse (identity_matrix, out_matrix);
  MatrixPrint (out_matrix);
  printf ("Expected output:\n");
  MatrixPrint (identity_matrix);
  testPassed (out_matrix, identity_matrix, &invPass);
  printf ("\n");
  printf ("\n");


/* Check inverse on sample1_matrix */
  printf ("Operation: compute matrix inverse of sample1 matrix\n");
  printf ("Output:\n");
  MatrixInverse (sample1_matrix, out_matrix);
  MatrixPrint (out_matrix);
  printf ("Expected output:\n");
  float eoinv_sample1_matrix[3][3] =
    { {-0.038911, 0.159533, -0.124514}, {-0.027237, 0.011673, 0.112840},
    {0.245136, -0.105058, -0.015564} };
  MatrixPrint (eoinv_sample1_matrix);
  testPassed (out_matrix, eoinv_sample1_matrix, &invPass);

  printf ("\n");
  printf ("\n");

/* Check inverse on sample2_matrix */
  printf ("Operation: compute matrix inverse of sample2 matrix\n");
  printf ("Output:\n");
  MatrixInverse (sample2_matrix, out_matrix);
  MatrixPrint (out_matrix);
  printf ("Expected output:\n");
  float eoinv_sample2_matrix[3][3] =
    { {-0.127753, -0.030837, -0.145374}, {-0.079295, -0.088106, 0.013216},
    {-0.070485, -0.189427, -0.321586} };
  MatrixPrint (eoinv_sample2_matrix);
  testPassed (out_matrix, eoinv_sample2_matrix, &invPass);

  printf ("\n");
  printf ("\n");


/******************************************************************************
 * SUMMARY OF CHECKS AND TESTS PASSED
 *****************************************************************************/
   /**/ printf ("****************************\n");
  printf ("********  SUMMARY  *********\n");
  printf ("****************************\n");

  printf ("\n");

  int functionTests[9] = { eqPass,
    addPass,
    mulPass,
    scalAddPass,
    scalMulPass,
    tracePass,
    transPass,
    detPass,
    invPass
  };

  const char *functionNames[9] =
    { "MatrixEquals()", "MatrixAdd()", "MatrixMultiply()",
"MatrixScalarAdd()", "MatrixScalarMultiply()", "MatrixTrace()", "MatrixTranspose()",
"MatrixDeterminant()", "MatrixInverse()" };

  int functionsPassed = 0;
  for (int i = 0; i < 9; i++)
    {
      if (functionTests[i] == 4)
	{
	  
	  printf ("PASSED %d / %d: %s\n", functionTests[i], 4,
		  functionNames[i]);
	  functionsPassed++;
	}
      else
	{
	  printf ("FAILED %d / %d: %s\n", functionTests[i], 4,
		  functionNames[i]);
	}
    }

  printf ("%d out of %d functions passed (%.2f%%).", functionsPassed, 9,
	  (float) functionsPassed / 9 * 100.0);

  BOARD_End ();
  while (1);


}
