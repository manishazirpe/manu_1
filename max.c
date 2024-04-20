#include <mpi.h>
 #include <stdio.h>
 #include <stdlib.h>
 #define ARRAY_SIZE 1000
 int main(int argc, char* argv[]) {
    int rank, size, i;
    int array[ARRAY_SIZE];
    int local_max, global_max;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    srand(rank + time(NULL));
    for(i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 100;
        if(i == 0 || array[i] > local_max) {
            local_max = array[i];
        }
    }
    printf("Local max for process %d is %d\n", rank, local_max);
    MPI_Reduce(&local_max, &global_max, 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);
    if (rank == 0) {
        printf("Global max = %d\n", global_max);
    }
    MPI_Finalize();
    return 0;
 }