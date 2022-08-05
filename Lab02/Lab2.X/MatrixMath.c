// Standard libraries
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "MatrixMath.h"

void MatrixPrint(float mat[DIM][DIM])
{
    int r, c;
    for (r = 0; r < DIM; r++) {
    for (c = 0; c < DIM; c++) {
        printf("%f ", mat[r][c]);
   }
    printf("\n");
}
}

int MatrixEquals(float mat1[DIM][DIM], float mat2[DIM][DIM])
{
    int r, c;
    float diff;
    for (r = 0; r < DIM; r++) {
    for (c = 0; c < DIM; c++) {
            //printf("%f\n", mat1[r][c]);
            //printf("%f\n", mat2[r][c]);
            //printf("%f\n", mat1[r][c]-mat2[r][c]);
        if( mat1[r][c]-mat2[r][c] < -1*FP_DELTA ||  mat1[r][c]-mat2[r][c] > FP_DELTA)
        {
            //printf("FALSE\n");
            return 0;
        }
   }
    }
    //printf("TRUE\n");
    return 1;
}


void MatrixAdd(float mat1[DIM][DIM], float mat2[DIM][DIM], float result[DIM][DIM])
{
    int r, c;
    //float res = result;
    for (r = 0; r < DIM; r++) {
    for (c = 0; c < DIM; c++) {
            //printf("%f\n", mat1[r][c]);
            //printf("%f\n", mat2[r][c]);
            //printf("%f\n", mat1[r][c]+mat2[r][c]);
            result[r][c] = mat1[r][c]+mat2[r][c];
            //printf("%f\n", res[r][c]);
            if(result[r][c] == 0) result[r][c] = 0;
   }
    
}
}
void MatrixMultiply(float mat1[DIM][DIM], float mat2[DIM][DIM], float result[DIM][DIM])
{
    int r, c, t;
    for (r = 0; r < DIM; r++) {
        
    for (t = 0; t < DIM; t++) {
    float sum = 0;
    for (c = 0; c < DIM; c++) {
        //printf("Index1:%d%d\nIndex2:%d%d\n",r,c,c,t);
        //printf("Product:%f\n",mat1[r][c]*mat2[c][t]);
            sum = sum + mat1[r][c]*mat2[c][t];
        //printf("Sum:%f\n",sum);
   }
   result[r][t]=sum;
   if(result[r][c] == 0) result[r][c] = 0;
    }
    }
}
void MatrixScalarAdd(float x, float mat[DIM][DIM], float result[DIM][DIM])
{
    int r, c;
    //float res = result;
    //printf("Scalar:%f\n", x);
    for (r = 0; r < DIM; r++) {
    for (c = 0; c < DIM; c++) {
            //printf("Original:%f\n", mat[r][c]);
            //printf("Scalar:%f\n", x);
            //printf("%f\n", mat2[r][c]);
            //printf("Added:%f\n", x + mat[r][c]);
            result[r][c] = x + mat[r][c];
            if(result[r][c] == 0) result[r][c] = 0;
            //printf("%f\n", res[r][c]);
   }
    }
}

void MatrixScalarMultiply(float x, float mat[DIM][DIM], float result[DIM][DIM])
{
    int r, c;
    //printf("Scalar:%f\n", x);
    for (r = 0; r < DIM; r++) {
    for (c = 0; c < DIM; c++) {
            //printf("Original:%f\n", mat[r][c]);
            //printf("Scalar:%f\n", x);
            //printf("Added:%f\n", x * mat[r][c]);
            result[r][c] = x * mat[r][c];
            if(result[r][c] == 0) result[r][c] = 0;
   }
    }
}

float MatrixTrace(float mat[DIM][DIM])
{
    int r;
    float trace;
    for (r = 0; r < DIM; r++) {
        //printf("Index:%d%d\n",r,r);
        //printf("Number:%f\n", mat[r][r]);
        //printf("Sum:%f\n", trace + mat[r][r]);
        trace = trace + mat[r][r];
    }
    return trace;
}

void MatrixTranspose(float mat[DIM][DIM], float result[DIM][DIM])
{
    int r, c;
    for (r = 0; r < DIM; r++) {
    for (c = 0; c < DIM; c++) {
            //printf("Original:%f\n", mat[r][c]);
            //printf("Switch:%f\n", mat[c][r]);
            //printf("%f\n", mat2[r][c]);
            result[r][c] = mat[c][r];
            //printf("%f\n", res[r][c]);
   }
    }
    
}

void MatrixSubmatrix(int i, int j, float mat[DIM][DIM], float result[DIM-1][DIM-1])
{
    int r, c;
    int a = 0;
    for (r = 0; r < DIM; r++) {
        int b = 0;
        //printf("r:%d\n", r);
        //printf("a:%d\n", a);
        //printf("b:%d\n", b);
    for (c = 0; c < DIM; c++) {
        //printf("c:%d\n", c);
        if(r != i-1 &&  c != j-1)
        {
            //printf("IndexMat:%d%d\n", r, c);
            //printf("IndexRES:%d%d\n", a, b);
            //printf("Added:%f\n", mat[r][c]);
            result[a][b] = mat[r][c];
            b++;
        }
   }
   //printf("b(endloop):%d\n", b);
   if(b>0)
        {
            a++;
            //printf("a(endloop):%d\n", a);
        }
        else
    {
        //printf("No number added\n");
    }
    }
    
    /*
    int e, f;
    for (e = 0; e < 2; e++) {
    for (f = 0; f < 2; f++) {
        printf("%f ", result[e][f]);
   }
    printf("\n");
    
}*/
   
}

float MatrixDeterminant(float mat[DIM][DIM])
{
    float det = mat[0][0]*((mat[1][1]*mat[2][2])-(mat[1][2]*mat[2][1]))-(mat[0][1]*((mat[1][0]*mat[2][2])-(mat[1][2]*mat[2][0])))+mat[0][2]*((mat[1][0]*mat[2][1])-(mat[1][1]*mat[2][0]));
    return det;
}

void MatrixInverse(float mat[DIM][DIM], float result[DIM][DIM])
{
    if(MatrixDeterminant(mat) !=0 )
    {
    float cof[DIM][DIM];
    
    int r, c;
    for (r = 0; r < DIM; r++) {
    for (c = 0; c < DIM; c++) {
        
            //printf("Original:%f\n", mat[r][c]);
            //printf("Switch:%f\n", mat[c][r]);
            float subMatrix[2][2];
            MatrixSubmatrix(r+1, c+1, mat, subMatrix);
            //printf("Submatrix%d%d\n", r, c);
            
          /* int w, q;
    for (w = 0; w < 2; w++) {
    for (q = 0; q < 2; q++) {
        printf("%f ", subMatrix[w][q]);
   }
    printf("\n");
}*/
            //printf("a*d:%f\n", (subMatrix[0][0]*subMatrix[1][1]));
            //printf("b*c:%f\n", (subMatrix[0][1]*subMatrix[1][0]));
            //printf("diff:%f\n", ((subMatrix[0][0]*subMatrix[1][1])-(subMatrix[0][1]*subMatrix[1][0])));
            if((r+c+2) % 2 == 0)
            {
            cof[r][c] = ((subMatrix[0][0]*subMatrix[1][1])-(subMatrix[0][1]*subMatrix[1][0]));
            //printf("CofMatrix at%d%d\n", r, c);
            //MatrixPrint(cof);
            }
            else
            {
            cof[r][c] = (-1)*((subMatrix[0][0]*subMatrix[1][1])-(subMatrix[0][1]*subMatrix[1][0]));
            //printf("CofMatrix at%d%d\n", r, c);
            //MatrixPrint(cof);
            }
            
   }
   }
   float adj[DIM][DIM];
    MatrixTranspose(cof, adj);
    //printf("TranposeADJ:\n");
    //MatrixPrint(adj);
    
   MatrixScalarMultiply(1/MatrixDeterminant(mat), adj, result);
    }
    else
    {
        printf("The matrix is not invertible.\n");
    }
   
   
   

}
