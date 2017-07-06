#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
    // Initialize the MPI environment
    MPI_Init(NULL, NULL);

    // Get the number of processes
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // Get the rank of the process
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    // Get the name of the processor
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    int name_len;
    MPI_Get_processor_name(processor_name, &name_len);

    // Print off a hello world message
    printf("Hello world from processor %s, rank %d"
           " out of %d processors\n",
           processor_name, world_rank, world_size);
    
    // send a message
    int msg_send = 100 + world_rank;
    int next_world = (world_rank + 1) % world_size;
    MPI_Send(&msg_send, 1, MPI_INT, next_world, 0, MPI_COMM_WORLD);

    // recv a message
    int last_world = (world_rank + world_size - 1) % world_size;
    int msg_recv;
    MPI_Status status;
    MPI_Recv(&msg_recv, 1, MPI_INT, last_world, 0, MPI_COMM_WORLD, &status);
    printf("get msg %d\n", msg_recv);

    // mpi reduce
    int reduce_rec = 234;
    MPI_Reduce(&world_rank, &reduce_rec, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    printf("I'm %d, reduce_res is %d\n", world_rank, reduce_rec);
    int all_reduce_rec = 123;
    MPI_Allreduce(&world_rank, &all_reduce_rec, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);
    printf("I'm %d, all_reduce_res is %d\n", world_rank, all_reduce_rec);

    // Finalize the MPI environment.
    MPI_Finalize();
}
