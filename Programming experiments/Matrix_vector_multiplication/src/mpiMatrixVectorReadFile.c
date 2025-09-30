#include "mpiMatrixVectorReadFile.h"
#include "matrixVectorReadFile.h"
#include "mpiMatrixVectorScatterRow.h"
#include <stdlib.h>

void mpiMatrixVectorReadFile(const char *filename,
                            double **local_mat, 
                            double **vect, 
                            int *local_rows,
                            int *rows,
                            int *cols,
                            MPI_Comm comm)
{
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    // assume both the matrix and the vector are input from a data file.
    double *mat;
    if (rank == 0)
    {
        matrixVectorReadFile("data.txt", &mat, vect, rows, cols);
    }

    mpiMatrixVectorScatterRow(mat, local_mat, vect, local_rows, rows, cols, comm);

    // Clean up
    if (rank == 0)
    {
        free(mat);
    }
}