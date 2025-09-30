#ifndef MPI_MATRIX_VECTOR_READ_FILE_H
#define MPI_MATRIX_VECTOR_READ_FILE_H

#include <mpi.h>

void mpiMatrixVectorReadFile(const char *filename,
                            double **local_mat, 
                            double **vect, 
                            int *local_rows, 
                            int *rows,
                            int *cols,
                            MPI_Comm comm);

#endif // MPI_MATRIX_VECTOR_READ_FILE_H