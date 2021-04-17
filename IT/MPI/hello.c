#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <mpi.h>

int main(int argc, char **argv)
{
	int rank, size;
	char name[MPI_MAX_PROCESSOR_NAME];
	
	int len = MPI_MAX_PROCESSOR_NAME + 100;
	char *buf = (char*)malloc(sizeof(char) * len);
	
	int t;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Get_processor_name(name, &t);
	
	printf("#%d: size = %d, host = '%s'\n", rank, size, name);
	
	MPI_Finalize();
	return 0;
}

