#include <stdio.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#define TamanhoArray 10


int MeuArray[TamanhoArray];
int somaArray = 0;
int somaArrayMulti1 = 0;
int somaArrayMulti2 = 0;
int somaArrayMulti = 0;

void Soma();
void SomaMulti1();
void SomaMulti2();
void AdicionaDados();
void ImprimirArray();

void ImprimirArray(){
    printf("Array:\n\n");
    for(int i=0; i < TamanhoArray; i++){
        printf("%d   ",MeuArray[i]);
    }
    printf("\n\n");
}

void Soma(){
    for (int i=0; i < TamanhoArray; i++){
        if (somaArray == 0) {
            somaArray = MeuArray[i];
        } else {
            somaArray = somaArray + MeuArray[i];
        }
    }
}

void SomaMulti1(){
    for (int i = 0; i < TamanhoArray/2; i++){
        if (somaArrayMulti1 == 0) {
            somaArrayMulti1 = MeuArray[i];
        } else {
            somaArrayMulti1 = somaArrayMulti1 + MeuArray[i];
        }
    }
}

void SomaMulti2(){
    for (int i = TamanhoArray/2; i < TamanhoArray; i++){
        if (somaArrayMulti2 == 0) {
            somaArrayMulti2 = MeuArray[i];
        } else {
            somaArrayMulti2 = somaArrayMulti2 + MeuArray[i];
        }
    }
}

void AdicionaDados(){
    // Adicionando dados ao Array
    srand(time(NULL));
    for (int i=0; i<TamanhoArray; i++){
        MeuArray[i] = rand()%1000;
    }
}

int main()
{
    AdicionaDados();

    clock_t time;
    time = clock();

    pthread_t t1;

    pthread_create(&t1, NULL, (void *) Soma, NULL);
    pthread_join(t1, NULL);

    ImprimirArray();
    printf("Valor da Soma: %d\n\n", somaArray);

    time = clock() -time;

    printf("Tempo de execucao soma array: %lf\n\n", ((double)time)/((CLOCKS_PER_SEC/1000)));

    clock_t time2;
    time2 = clock();

    pthread_t t2, t3;

    pthread_create(&t2, NULL, (void *) SomaMulti1, NULL);
    pthread_create(&t3, NULL, (void *) SomaMulti2, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    ImprimirArray();
    somaArrayMulti = somaArrayMulti1 + somaArrayMulti2;
    printf("Valor da Soma: %d\n\n", somaArrayMulti);

    time = clock() -time2;

    printf("Tempo de execucao soma array(multi): %lf\n\n", ((double)time)/((CLOCKS_PER_SEC/1000)));

    return 0;
}
