#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

#define tam 10

int MeuArray[tam];
int somaArrayMulti = 0;
int somaArraySingle = 0;

void multiThread(){
    clock_t time;
    time = clock();
    #pragma omp parallel for  private( i, j) num_threads(2)
    for (int i=0; i < tam; i++){
        if (somaArrayMulti == 0) {
            somaArrayMulti = MeuArray[i];
        } else {
            somaArrayMulti = somaArrayMulti + MeuArray[i];
        }
    }
    time = clock() -time;
    printf("Tempo de execucao multi: %lf\n\n", ((double)time)/((CLOCKS_PER_SEC/1000)));
}

void singleThread(){
    clock_t time2;
    time2 = clock();
    #pragma omp parallel for num_threads(1)
    for (int i=0; i < tam; i++){
        if (somaArraySingle == 0) {
            somaArraySingle = MeuArray[i];
        } else {
            somaArraySingle = somaArraySingle + MeuArray[i];
        }
    }
    time2 = clock() -time2;
    printf("Tempo de execucao single: %lf\n\n", ((double)time2)/((CLOCKS_PER_SEC/1000)));
}
void ExibirVetor(){
    printf("Array: ");
    for (int i=0; i < tam; i++){
        printf("%d  ", MeuArray[i]);
    }
    printf("\n\n");
    printf("Soma Single: %d\n", somaArraySingle);
    printf("\n");
    printf("Soma Multi: %d\n", somaArrayMulti);
}

void AdicionarDados(){
    srand(time(NULL));
    for (int i=0; i < tam; i++){
        MeuArray[i] = rand() % 1000;
    }
}

int main(){
    AdicionarDados();
    multiThread();
    singleThread();
    ExibirVetor();
    return 0;
}
