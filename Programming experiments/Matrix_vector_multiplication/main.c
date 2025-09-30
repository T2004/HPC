// Implement a matrix-vector multiplication program in which 
// the matrix is distributed among processes in a block-row fashion 
// and the vector is distributed among processes as blocks. 
// You can assume both the matrix and the vector are provided as input data from a file. 
// At the end of the program's execution, the result vector should be distributed 
// among the processes in blocks, and each process will compute its local portion of the result.


#include "matrixVectorReadFile.h"
#include "matrixVectorCreate.h"
#include "mpiMatrixVectorScatterRow.h"
#include "mpiMatrixVectorMultRow.h"
#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    MPI_Init(&argc, &argv);

    int process_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &process_rank);

    // Initialize the matrix and vector based on input (from a file or generated).
    double *matrix = NULL, *vector = NULL;
    int row_count, col_count;
    if (process_rank == 0)
    {
        // Read the matrix and vector from a file or generate them
        // matrixVectorReadFile("data.txt", &matrix, &vector, &row_count, &col_count);
        row_count = 8;
        col_count = 1e6;
        srand(0);
        matrixVectorCreate(&matrix, &vector, row_count, col_count);
    }

    // Ensure the matrix and vector are correctly initialized and print the full matrix
    // if (process_rank == 0)
    // {
    //     printf("%d | Matrix:\n", process_rank);
    //     for (int i = 0; i < row_count; i++)
    //     {
    //         printf("%d | ", process_rank);
    //         for (int j = 0; j < col_count; j++)
    //         {
    //             printf("%.1f ", matrix[i * col_count + j]);
    //         }
    //         printf("\n");
    //     }
    // }

    // Broadcasting row count to all processes and creating sub-communicators
    MPI_Bcast(&row_count, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Comm custom_comm = MPI_COMM_NULL;
    int color_group = (process_rank < row_count) ? 0 : MPI_UNDEFINED;
    MPI_Comm_split(MPI_COMM_WORLD, color_group, process_rank, &custom_comm);
    if (custom_comm == MPI_COMM_NULL)
    {
        MPI_Finalize();
        return 0;
    }

    // Start timer for performance measurement
    MPI_Barrier(custom_comm);
    double start_time = MPI_Wtime();

    double *local_matrix = NULL;
    int local_row_count;
    mpiMatrixVectorScatterRow(matrix, 
                             &local_matrix, 
                             &vector, 
                             &local_row_count, 
                             &row_count, 
                             &col_count, 
                             custom_comm);

    double *computed_vector = NULL;
    mpiMatrixVectorMultRow(local_matrix,
                          vector, 
                          &computed_vector, 
                          local_row_count, 
                          row_count,
                          col_count,
                          custom_comm);

    // Stop timer and calculate elapsed time
    MPI_Barrier(custom_comm);
    double end_time = MPI_Wtime();
    if (process_rank == 0)
    {
        double elapsed_time = end_time - start_time;
        printf("Elapsed time: %.0f µs\n", elapsed_time * 1e6);
    }

    // Display the computed result vector only on root process (rank 0)
    if (process_rank == 0)
    {
        printf("Computed result vector (first few elements): ");
        for (int i = 0; i < row_count; i++)
        {
            printf("%.1f ", computed_vector[i]);
        }
        printf("\n");
    }

    // Clean up dynamically allocated memory
    if (process_rank == 0)
    {
        free(matrix);
        free(vector);
    }
    free(local_matrix);
    free(computed_vector);

    MPI_Comm_free(&custom_comm);

    MPI_Finalize();
    return 0;
}
