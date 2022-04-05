#include <stdio.h>
#include <omp.h>
#include <time.h>

#define tam1 3
#define tam2 3

int matriz_A[tam2][tam1];
int matriz_B[tam1][tam2];
int matriz_result[tam2][tam1];

void multiThread(){
        clock_t time;
        time = clock();
        #pragma omp parallel for  private( i, j) num_threads(2)
        for (int k1=0; k1 < tam2; k1++){
            for(int k2=0; k2 < tam1; k2++){
                int temp = 0;
                for(int i=0; i < tam2; i++){
                    temp = temp + matriz_A[k1][i] * matriz_B[i][k2];
                }
                matriz_result[k1][k2] = temp;
            }
        }

    time = clock() -time;
    printf("Tempo de execucao multi: %lf\n\n", ((double)time)/((CLOCKS_PER_SEC/1000)));
}

void singleThread(){
    clock_t time2;
    time2 = clock();
        #pragma omp parallel for num_threads(1)
        for (int k1=0; k1 < tam2; k1++){
            for(int k2=0; k2 < tam1; k2++){
                int temp = 0;
                for(int i=0; i < tam2; i++){
                    temp = temp + matriz_A[k1][i] * matriz_B[i][k2];
                }
                matriz_result[k1][k2] = temp;
            }
        }
    time2 = clock() -time2;
    printf("Tempo de execucao single: %lf\n", ((double)time2)/((CLOCKS_PER_SEC/1000)));
}
void ExibirMatriz(){
    printf("\n");
    printf("Matriz A: \n\n");
    for (int i =0; i<tam2 ; i++){
        for(int j =0; j< tam1; j++){
            printf("%d ", matriz_A[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    printf("Matriz B: \n\n");
    for (int i =0; i<tam2 ; i++){
        for(int j =0; j< tam1; j++){
            printf("%d ", matriz_B[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    printf("Matriz Resultado: \n\n");
    for (int i =0; i<tam2 ; i++){
        for(int j =0; j< tam1; j++){
            printf("%d ", matriz_result[i][j]);
        }
        printf("\n\n");
    }
}
int main(){

    for (int i =0; i<tam2 ; i++){
        for(int j =0; j< tam1; j++){
            matriz_A[i][j] = i+j+1;
            matriz_B[j][i] = j+2;
            matriz_result[i][j] = 0;
        }
    }

    multiThread();
    singleThread();
    ExibirMatriz();
    return 0;
}
