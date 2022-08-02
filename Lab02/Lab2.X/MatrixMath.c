/* ************************************************************************** */
/** Implementation of Matrix Math Functions

  @File MatrixMath
    MatrixMath.c

  @Description
    This file implements Matrix operations from function prototypes in header file.

 */
/* ************************************************************************** */

// Standard libraries
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void MatrixPrint(float mat[3][3])
{
    int r, c;
    for (r = 0; r < 4; r++) {
    for (c = 0; c < 4; c++) {
        printf("%f ", mat[r][c]);
    }
}
}


