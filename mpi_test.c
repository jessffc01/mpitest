#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

#define N 1024  // Dimensão da matriz

void some_operation(int *matrix, int size) {
    // Realiza alguma operação simplificada na matriz
    for (int i = 0; i < size; i++)
        matrix[i] += 1;
}

int main(int argc, char* argv[]) {
    int rank, size;
    int *matrix = NULL;
    int i;

    // Inicialização do MPI
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Medição de tempo inicial
    double start_time, end_time;
    start_time = MPI_Wtime();

    // Alocação da matriz
    matrix = (int*)malloc(N * N * sizeof(int));

    // Inicialização da matriz
    if (rank == 0) {
        for (i = 0; i < N * N; i++) {
            matrix[i] = i;
        }
    }

    // Primeira primitiva coletiva: Broadcast
    MPI_Bcast(matrix, N * N, MPI_INT, 0, MPI_COMM_WORLD);

    // Realiza alguma operação com parte da matriz
    some_operation(matrix + rank * (N * N / size), N * N / size);

    // Segunda primitiva coletiva: Gather
    int *result = NULL;
    if (rank == 0) {
        result = (int*)malloc(N * N * sizeof(int));
    }
    MPI_Gather(matrix + rank * (N * N / size), N * N / size, MPI_INT, result, N * N / size, MPI_INT, 0, MPI_COMM_WORLD);

    // Imprimir resultado final no processo mestre
    if (rank == 0) {
        printf("Resultado de parte da matriz: %d\n", result[0]);
        free(result);
    }

    free(matrix);

    // Medição de tempo final
    end_time = MPI_Wtime();

    // Calcular e imprimir o tempo de execução
    if (rank == 0) {
        printf("Tempo de execução: %f segundos\n", end_time - start_time);
    }

    // Finalização do MPI
    MPI_Finalize();
    
    return 0;
}