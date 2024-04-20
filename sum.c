#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#define ARRAY_SIZE 1000
int main(int argc, char* argv[]) {
    int rank, size;
    int numbers[ARRAY_SIZE];
    int local_sum = 0, global_sum = 0;
MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
if (rank == 0) {
        srand(time(NULL));
        for (int i = 0; i < ARRAY_SIZE; i++) {
            numbers[i] = rand() % 1000;
        }
    }
 MPI_Bcast(numbers, ARRAY_SIZE, MPI_INT, 0, MPI_COMM_WORLD);
for (int i = rank; i < ARRAY_SIZE; i += size) {
        local_sum += numbers[i];
    }
 MPI_Reduce(&local_sum, &global_sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
 if (rank == 0) {
        printf("Global sum: %d\n", global_sum);
    }
MPI_Finalize();
    return 0;
}

