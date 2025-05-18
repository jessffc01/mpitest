# MPI Test Project

## Descrição

Este projeto contém um exemplo de programa em MPI (Message Passing Interface) que realiza operações em uma matriz distribuída entre múltiplos processos. O objetivo é demonstrar conceitos básicos de computação paralela utilizando MPI em C.

## Pré-requisitos

- Linux Mint ou qualquer distribuição Linux compatível
- MPI instalado (por exemplo, MPICH ou OpenMPI)
- GCC para compilar o código C

## Instalação

1. Clone o repositório:

   ```bash
   git clone https://github.com/jessffc01/mpitest.git
2. Compile o programa
    cd mpitest
mpicc -o mpi_test mpi_test.c
3. Execute o programa
   mpirun -np <número_de_processos> ./mpi_test
Substitua <número_de_processos> pelo número de processos desejado.
Funcionamento

O programa distribui uma matriz entre múltiplos processos, executa operações paralelas e utiliza primitivas coletivas como MPI_Bcast e MPI_Gather para comunicação e coleta de dados entre os processos.
Métricas de Performance

Você pode medir o tempo de execução, speedup e eficiência computacional executando o programa com diferentes números de processos e comparando os resultados.
Contribuições

Contribuições são bem-vindas! Sinta-se à vontade para abrir issues ou enviar pull requests.
Licença

Este projeto é licenciado sob a MIT License.
Autores
Jess FFC e Kassiano
