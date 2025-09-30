#include "matVectMult.h"
#include <stdlib.h>

void matVectMult(const double *mat,
                   const double *vect,
                   double *result_vect,
                   const int rows,
                   const int cols)
{
    result_vect = (double *)malloc(rows * sizeof(double));
    int row, col;
    for (row = 0; row < rows; row++)
    {
        result_vect[row] = 0.0;
        for (col = 0; col < cols; col++)
            result_vect[row] += mat[row * cols + col] * vect[col];
    }
}