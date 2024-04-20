#include <mpi.h>
 #include <stdio.h>
 #include <stdlib.h>
 #define ARRAY_SIZE 1000
 int main(int argc, char* argv[]) {
    int rank, size, i;
    int array[ARRAY_SIZE];
    int local_min, global_min;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    srand(rank + time(NULL));
    for(i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 100;
        if(i == 0 || array[i] < local_min) {
            local_min = array[i];
        }
    }
    printf("Local min for process %d is %d\n", rank, local_min);
    MPI_Reduce(&local_min, &global_min, 1, MPI_INT, MPI_MIN, 0, MPI_COMM_WORLD);
    if (rank == 0) {
        printf("Global min = %d\n", global_min);
    }
    MPI_Finalize();
    return 0;
 }