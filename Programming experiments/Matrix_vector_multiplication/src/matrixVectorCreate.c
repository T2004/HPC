#include "matrixVectorCreate.h"
#include <stdlib.h>

void matrixVectorCreate(double **mat, double **vect, int rows, int cols)
{
    *mat = (double *)malloc(rows * cols * sizeof(double));
    *vect = (double *)malloc(cols * sizeof(double));
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            (*mat)[i * cols + j] = rand() % 100 + 1;
        }
    }
    for (int i = 0; i < cols; i++)
    {
        (*vect)[i] = rand() % 100 + 1;
    }
}