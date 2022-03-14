#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

#define QTD_THREADS 3

void * media(void *arg);

void * minimo(void *arg);

void * maximo(void *arg);

int med = 0;
int min = 0;
int max = 0;

int main (void){
        int quantidadeDeEntradas = 0;
        pthread_t threadMedia;
        pthread_t threadMinimo;
        pthread_t threadMaximo;

        scanf("%d", &quantidadeDeEntradas);

        int * entradas = (int *)malloc((quantidadeDeEntradas + 1) * sizeof(int));

        entradas[0] = quantidadeDeEntradas;

        int entrada = 0;

        for (int i = 1; i < (quantidadeDeEntradas + 1); i++){
            scanf("%d", &entradas[i]);
        }

        pthread_create(&threadMedia, NULL, media, &entradas);
        pthread_create(&threadMinimo, NULL, minimo, &entradas);
        pthread_create(&threadMaximo, NULL, maximo, &entradas);

        pthread_join(threadMedia, (void*)&med);
        pthread_join(threadMinimo, (void*)&min);
        pthread_join(threadMaximo, (void*)&max);

        printf("O valor médio é: %d\n", med);
        printf("O valor mínimo é: %d\n", min);
        printf("O valor máximo é: %d\n", max);

        return 0;
}

void * media(void *arg){
    int * numeros = (int *)arg;
    int soma;
    int n = numeros[0];

    for (int i = 1; i < (n + 1); ++i) {
        soma += numeros[i];
    }
    med = soma/n;
}

void * minimo(void *arg){
    int * numeros = (int *)arg;
    int n = numeros[0];

    for (int i = 1; i < (n + 1); ++i) {
        if (i = 0){
            min = numeros[0];
        }
        else{
            if(min > numeros[i]){
                min = numeros[i];
            }
        }
    }
}

void * maximo(void *arg){
    int * numeros = (int *)arg;
    int n = numeros[0];

    for (int i = 1; i < (n + 1); ++i) {
        if (i = 0){
            max = numeros[0];
        }
        else{
            if(max < numeros[i]){
                max = numeros[i];
            }
        }
    }
}