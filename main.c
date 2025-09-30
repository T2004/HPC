#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

// Function to print matrix
void print_matrix(int *matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i * size + j]);
        }
        printf("\n");
    }
}

// Function to initialize matrix with random values
void initialize_matrix(int *matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i * size + j] = rand() % 10;  // Random values between 0-9
        }
    }
}

// Function to calculate Floyd-Warshall algorithm
void floyd_warshall(int *matrix, int size) {
    for (int k = 0; k < size; k++) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (matrix[i * size + j] > matrix[i * size + k] + matrix[k * size + j]) {
                    matrix[i * size + j] = matrix[i * size + k] + matrix[k * size + j];
                }
            }
        }
    }
}

int main(int argc, char *argv[]) {
    int size = 4;
    int *matrix = (int *)malloc(size * size * sizeof(int));

    // Initialize MPI
    MPI_Init(&argc, &argv);

    // Initialize the matrix with random values
    initialize_matrix(matrix, size);

    // Print the initial matrix from the root process (rank 0)
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    if (rank == 0) {
        printf("Initial Matrix:\n");
        print_matrix(matrix, size);
    }

    // Apply Floyd-Warshall algorithm
    floyd_warshall(matrix, size);

    // Print the updated matrix only from the root process (rank 0)
    if (rank == 0) {
        printf("Matrix after Floyd-Warshall:\n");
        print_matrix(matrix, size);
    }

    // Finalize MPI and free allocated memory
    MPI_Finalize();
    free(matrix);

    return 0;
}
