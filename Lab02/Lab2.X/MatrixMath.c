// Standard libraries
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "MatrixMath.h"

void MatrixPrint (float mat[DIM][DIM])
{
  int r, c;
  printf (" ______________________________________\n");
  for (r = 0; r < DIM; r++)
    {
      for (c = 0; c < DIM; c++)
	{
	  printf ("|");
	  printf ("%11.5f ", mat[r][c]);
	}
      printf ("|\n");
      printf (" --------------------------------------\n");
    }
}

int MatrixEquals (float mat1[DIM][DIM], float mat2[DIM][DIM])
{
  int r, c;
  for (r = 0; r < DIM; r++)
    {
      for (c = 0; c < DIM; c++)
	{
	  if (mat1[r][c] - mat2[r][c] < -1 * FP_DELTA
	      || mat1[r][c] - mat2[r][c] > FP_DELTA)
	    {
	      return 0;
	    }
	}
    }
  return 1;
}


void MatrixAdd (float mat1[DIM][DIM], float mat2[DIM][DIM], float result[DIM][DIM])
{
  int r, c;
  for (r = 0; r < DIM; r++)
    {
      for (c = 0; c < DIM; c++)
	{
	  result[r][c] = mat1[r][c] + mat2[r][c];
	  if (result[r][c] == 0)
	    result[r][c] = 0;
	}

    }
}

void MatrixMultiply (float mat1[DIM][DIM], float mat2[DIM][DIM],
		float result[DIM][DIM])
{
  int r, c, t;
  for (r = 0; r < DIM; r++)
    {

      for (t = 0; t < DIM; t++)
	{
	  float sum = 0;
	  for (c = 0; c < DIM; c++)
	    {
	      sum = sum + mat1[r][c] * mat2[c][t];
	    }
	  result[r][t] = sum;
	  if (result[r][c] == 0)
	    result[r][c] = 0;
	}
    }
}

void MatrixScalarAdd (float x, float mat[DIM][DIM], float result[DIM][DIM])
{
  int r, c;
  for (r = 0; r < DIM; r++)
    {
      for (c = 0; c < DIM; c++)
	{
	  result[r][c] = x + mat[r][c];
	  if (result[r][c] == 0) result[r][c] = 0;
	}
    }
}

void MatrixScalarMultiply (float x, float mat[DIM][DIM], float result[DIM][DIM])
{
  int r, c;
  for (r = 0; r < DIM; r++)
    {
      for (c = 0; c < DIM; c++)
	{
	  result[r][c] = x * mat[r][c];
	  if (result[r][c] == 0) result[r][c] = 0;
	}
    }
}

float MatrixTrace (float mat[DIM][DIM])
{
  int r;
  float trace=0;
  for (r = 0; r < DIM; r++)
    {
      trace = trace + mat[r][r];
    }
  return trace;
}

void MatrixTranspose (float mat[DIM][DIM], float result[DIM][DIM])
{
  int r, c;
  for (r = 0; r < DIM; r++)
    {
      for (c = 0; c < DIM; c++)
	{
	  result[r][c] = mat[c][r];
	}
    }

}

void MatrixSubmatrix (int i, int j, float mat[DIM][DIM],
		 float result[DIM - 1][DIM - 1])
{
  int r, c;
  int a = 0;
  for (r = 0; r < DIM; r++)
    {
      int b = 0;
      for (c = 0; c < DIM; c++)
	{
	  if (r != i - 1 && c != j - 1)
	    {
	      result[a][b] = mat[r][c];
	      b++;
	    }
	}
      if (b > 0)
	{
	  a++;
	}
    }

}

float MatrixDeterminant (float mat[DIM][DIM])
{
  float det =
    mat[0][0] * ((mat[1][1] * mat[2][2]) - (mat[1][2] * mat[2][1])) -
    (mat[0][1] * ((mat[1][0] * mat[2][2]) - (mat[1][2] * mat[2][0]))) +
    mat[0][2] * ((mat[1][0] * mat[2][1]) - (mat[1][1] * mat[2][0]));
  return det;
}

void MatrixInverse (float mat[DIM][DIM], float result[DIM][DIM])
{
  if (MatrixDeterminant (mat) != 0)
    {
      float cof[DIM][DIM];

      int r, c;
      for (r = 0; r < DIM; r++)
	{
	  for (c = 0; c < DIM; c++)
	    {
	      float subMatrix[DIM - 1][DIM - 1];
	      MatrixSubmatrix (r + 1, c + 1, mat, subMatrix);
	      
	      if ((r + c + 2) % 2 == 0)
		{
		  cof[r][c] =
		    ((subMatrix[0][0] * subMatrix[1][1]) -
		     (subMatrix[0][1] * subMatrix[1][0]));
		}
	      else
		{
		  cof[r][c] =
		    (-1) * ((subMatrix[0][0] * subMatrix[1][1]) -
			    (subMatrix[0][1] * subMatrix[1][0]));
		}

	    }
	}
      float adj[DIM][DIM];
      MatrixTranspose (cof, adj);

      MatrixScalarMultiply (1 / MatrixDeterminant (mat), adj, result);
    }
  else
    {
      printf ("The matrix is not invertible.\n");
    }




}
