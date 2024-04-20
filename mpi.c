#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define ARRAY_SIZE 1000

int main(int argc, char* argv[]) {
    int rank, size;
    int numbers[ARRAY_SIZE];
    int local_min, local_max, global_min, global_max;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Generate random numbers on rank 0
    if (rank == 0) {
        srand(time(NULL));
        for (int i = 0; i < ARRAY_SIZE; i++) {
            numbers[i] = rand() % 1000;
        }
    }

    // Distribute the numbers to all processes
    MPI_Bcast(numbers, ARRAY_SIZE, MPI_INT, 0, MPI_COMM_WORLD);

    // Calculate local min and max
    local_min = local_max = numbers[0];
    for (int i = rank; i < ARRAY_SIZE; i += size) {
        if (numbers[i] < local_min) {
            local_min = numbers[i];
        }
        if (numbers[i] > local_max) {
            local_max = numbers[i];
        }
    }

    // Reduce local min and max to get the global min and max
    MPI_Reduce(&local_min, &global_min, 1, MPI_INT, MPI_MIN, 0, MPI_COMM_WORLD);
    MPI_Reduce(&local_max, &global_max, 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);

    // Print the global min and max on rank 0
    if (rank == 0) {
        printf("Global min: %d\n", global_min);
        printf("Global max: %d\n", global_max);
    }

    MPI_Finalize();
    return 0;
}

