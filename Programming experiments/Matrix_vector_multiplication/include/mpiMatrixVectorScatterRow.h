#ifndef MPI_MATRIX_VECTOR_SCATTER_ROW_H
#define MPI_MATRIX_VECTOR_SCATTER_ROW_H

#include <mpi.h>

void mpiMatrixVectorScatterRow(const double *mat,
                              double **local_mat,
                              double **vect,
                              int *local_rows,
                              const int *rows,
                              const int *cols,
                              MPI_Comm comm);

#endif // MPI_MATRIX_VECTOR_SCATTER_ROW_H