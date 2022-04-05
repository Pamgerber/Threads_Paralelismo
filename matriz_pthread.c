#include <stdio.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#define QtdLinhaMatriz 3
#define QtdColunaMatriz 3

pthread_mutex_t insercao_mutua = PTHREAD_MUTEX_INITIALIZER;

int MatrizA[QtdLinhaMatriz][QtdColunaMatriz];
int MatrizB[QtdLinhaMatriz][QtdColunaMatriz];
int MultiplicacaoMatricial[QtdLinhaMatriz][QtdColunaMatriz];
int MultiplicacaoPosicional[QtdLinhaMatriz][QtdColunaMatriz];
int MultiplicacaoMatricialSingle[QtdLinhaMatriz][QtdColunaMatriz];
int MultiplicacaoPosicionalSingle[QtdLinhaMatriz][QtdColunaMatriz];

void AdicionaDados();
void MatricialLinha0();
void MatricialLinha1();
void MatricialLinha2();
void ExibirMatriz();
void PosicionalLinha0();
void PosicionalLinha1();
void PosicionalLinha2();
void ExibirPosicional();
void SingleMatricial();
void SinglePosicional();
void ExibirMatricialSingle();
void ExibirPosicionalSingle();

void ExibirMatricialSingle(){
    printf("Matriz Matricial(single):\n");

    for (int i=0; i < QtdLinhaMatriz; i++){
        for(int j=0; j < QtdColunaMatriz; j++){
            printf("%d", MultiplicacaoMatricialSingle[i][j]);
            printf("  ");
        }
        printf("\n");
    }

    printf("\n");
}

void ExibirPosicionalSingle(){
    printf("Matriz Posicional(single):\n");

    for (int i=0; i < QtdLinhaMatriz; i++){
        for(int j=0; j < QtdColunaMatriz; j++){
            printf("%d", MultiplicacaoPosicionalSingle[i][j]);
            printf("  ");
        }
        printf("\n");
    }

    printf("\n");
}

void SinglePosicional(){
    for (int i=0; i < QtdLinhaMatriz; i++){
        for(int j=0; j < QtdColunaMatriz; j++){
            MultiplicacaoPosicionalSingle[i][j] = MatrizA[i][j] * MatrizB[i][j];
        }
    }
}

void SingleMatricial(){
    for (int k1=0; k1 < QtdLinhaMatriz; k1++){
        for(int k2=0; k2 < QtdColunaMatriz; k2++){
            int temp = 0;
            for(int i=0; i < QtdLinhaMatriz; i++){
                temp = temp + MatrizA[k1][i] * MatrizB[i][k2];
            }
            MultiplicacaoMatricialSingle[k1][k2] = temp;
        }
    }
}

void PosicionalLinha0(){
    double verificacao = 0;
    while(verificacao == 0){
        for (int i=0; i == 0; i++){
            for(int j=0; j < QtdColunaMatriz; j++){
                MultiplicacaoPosicional[i][j] = MatrizA[i][j] * MatrizB[i][j];
            }
        }
        pthread_mutex_unlock( &insercao_mutua);
        verificacao++;
    }
}
void PosicionalLinha1(){
    double verificacao = 0;
    while(verificacao == 0){
        for (int i=1; i == 1; i++){
            for(int j=0; j < QtdColunaMatriz; j++){
                MultiplicacaoPosicional[i][j] = MatrizA[i][j] * MatrizB[i][j];
            }
        }
        pthread_mutex_unlock( &insercao_mutua);
        verificacao++;
    }
}
void PosicionalLinha2(){
    double verificacao = 0;
    while(verificacao == 0){
        for (int i=2; i == 2; i++){
            for(int j=0; j < QtdColunaMatriz; j++){
                MultiplicacaoPosicional[i][j] = MatrizA[i][j] * MatrizB[i][j];
            }
        }
        pthread_mutex_unlock( &insercao_mutua);
        verificacao++;
    }
}

void MatricialLinha0(){
    double verificacao = 0;
    while(verificacao == 0){
        pthread_mutex_lock( &insercao_mutua);
        for (int k1=0; k1 == 0; k1++){
            for(int k2=0; k2 < QtdColunaMatriz; k2++){
                int temp = 0;
                for(int i=0; i < QtdLinhaMatriz; i++){
                    temp = temp + MatrizA[k1][i] * MatrizB[i][k2];
                }
                MultiplicacaoMatricial[k1][k2] = temp;
            }
        }
        pthread_mutex_unlock( &insercao_mutua);
        verificacao++;
    }
}

void MatricialLinha1(){
    double verificacao = 0;
    while(verificacao == 0){
        pthread_mutex_lock( &insercao_mutua);
        for (int k1=1; k1 == 1; k1++){
            for(int k2=0; k2 < QtdColunaMatriz; k2++){
                int temp = 0;
                for(int i=0; i < QtdLinhaMatriz; i++){
                    temp = temp + MatrizA[k1][i] * MatrizB[i][k2];
                }
                MultiplicacaoMatricial[k1][k2] = temp;
            }
        }
        pthread_mutex_unlock( &insercao_mutua);
        verificacao++;
    }
}

void MatricialLinha2(){
    double verificacao = 0;
    while(verificacao == 0){
        pthread_mutex_lock( &insercao_mutua);
        for (int k1=2; k1 == 2; k1++){
            for(int k2=0; k2 < QtdColunaMatriz; k2++){
                int temp = 0;
                for(int i=0; i < QtdLinhaMatriz; i++){
                    temp = temp + MatrizA[k1][i] * MatrizB[i][k2];
                }
                MultiplicacaoMatricial[k1][k2] = temp;
            }
        }
        pthread_mutex_unlock( &insercao_mutua);
        verificacao++;
    }
}

void AdicionaDados(){
    srand((unsigned) time(NULL));
    //Adiciona 0 a todas as posições da Matriz
    for (int i=0; i < QtdLinhaMatriz; i++){
        for(int j=0; j < QtdColunaMatriz; j++){
            MultiplicacaoMatricial[i][j] = 0;
        }
    }
    //Adicionando números aleatórios de 0 a 10 na MatrizA

    for (int i=0; i < QtdLinhaMatriz; i++){
        for(int j=0; j < QtdColunaMatriz; j++){
            MatrizA[i][j] = rand()%10;
        }
    }

    //Adicionando números aleatórios de 0 a 10 na MatrizB

    for (int i=0; i < QtdLinhaMatriz; i++){
        for(int j=0; j < QtdColunaMatriz; j++){
            MatrizB[i][j] = rand()%10;
        }
    }
}

void ExibirMatriz(){
    //Exibindo matrizA

    printf("Matriz A:\n");

    for (int i=0; i < QtdLinhaMatriz; i++){
        for(int j=0; j < QtdColunaMatriz; j++){
            printf("%d", MatrizA[i][j]);
            printf(" ");
        }
        printf("\n");
    }

    printf("\n");

    //Exibindo MatrizB

    printf("Matriz B:\n");

    for (int i=0; i < QtdLinhaMatriz; i++){
        for(int j=0; j < QtdColunaMatriz; j++){
            printf("%d",MatrizB[i][j]);
            printf(" ");
        }
        printf("\n");
    }

    printf("\n");

    //Exibindo Multiplicação Matricial

    printf("Matriz Matricial:\n");

    for (int i=0; i < QtdLinhaMatriz; i++){
        for(int j=0; j < QtdColunaMatriz; j++){
            printf("%d", MultiplicacaoMatricial[i][j]);
            printf("  ");
        }
        printf("\n");
    }

    printf("\n");
}

void ExibirPosicional(){
    printf("Matriz Posicional:\n");

    for (int i=0; i < QtdLinhaMatriz; i++){
        for(int j=0; j < QtdColunaMatriz; j++){
            printf("%d", MultiplicacaoPosicional[i][j]);
            printf("  ");
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    clock_t time;
    time = clock();

    AdicionaDados();
    pthread_t t1, t2, t3;

    pthread_create(&t1, NULL, (void *) MatricialLinha0, NULL); /*criando a thread para a multiplicação da linha 0*/
    pthread_create(&t2, NULL, (void *) MatricialLinha1, NULL); /*criando a thread para a multiplicação da linha 1*/
    pthread_create(&t3, NULL, (void *) MatricialLinha2, NULL); /*criando a thread para a multiplicação da linha 2*/

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    ExibirMatriz();

    time = clock() -time;

    printf("Tempo de execucao matricial(Multi): %lf\n\n", ((double)time)/((CLOCKS_PER_SEC/1000)));

    clock_t time2;
    time2 = clock();

    pthread_t t4, t5, t6;

    pthread_create(&t4, NULL, (void *) PosicionalLinha0, NULL); /*criando a thread para a multiplicação da linha 0*/
    pthread_create(&t5, NULL, (void *) PosicionalLinha1, NULL); /*criando a thread para a multiplicação da linha 1*/
    pthread_create(&t6, NULL, (void *) PosicionalLinha2, NULL); /*criando a thread para a multiplicação da linha 2*/

    pthread_join(t4, NULL);
    pthread_join(t5, NULL);
    pthread_join(t6, NULL);

    ExibirPosicional();

    time2 = clock() -time2;

    printf("Tempo de execucao posicional(Multi): %lf\n\n", ((double)time2)/((CLOCKS_PER_SEC/1000)));

    clock_t time3;
    time3 = clock();

    pthread_t t7;

    pthread_create(&t7, NULL, (void *) SingleMatricial, NULL);
    pthread_join(t7, NULL);

    ExibirMatricialSingle();

    printf("Tempo de execucao matricial(single): %lf\n\n", ((double)time3)/((CLOCKS_PER_SEC/1000)));

    clock_t time4;
    time4 = clock();

    pthread_t t8;

    pthread_create(&t8, NULL, (void *) SinglePosicional, NULL);
    pthread_join(t8, NULL);

    ExibirPosicionalSingle();

    printf("Tempo de execucao posicional(single): %lf\n", ((double)time4)/((CLOCKS_PER_SEC/1000)));

    return 0;
}
