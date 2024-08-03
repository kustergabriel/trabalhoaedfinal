// utils.c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"

FILE *openarq(const char *filename) {
    FILE *pokemon = fopen(filename, "r");
    if (pokemon == NULL) {
        printf("Erro ao abrir o arquivo %s!\n", filename);
        return NULL;
    }
    return pokemon;
}

void telainicial0(void) {
    printf("----------------------Seja bem-vindo ao POKETRUNFO!----------------------\n");
    printf("----------------------Insira uma tecla para começar a jogar----------------------\n");
}

void telainicial(int *opcao) {
    printf("---------------------- 0 = CONSULTA POKEDEX----------------------\n");
    printf("---------------------- 1 = EMBARALHAR AS CARTAS----------------------\n");
    printf("---------------------- 2 = SORTEIO DAS CARTAS----------------------\n");
    printf("---------------------- 10 = SAIR DO JOGO----------------------\n");
    printf("Insira a sua alternativa: ");
    scanf("%d", opcao);
}

void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void shuffle(int array[], int n) {
    srand(time(NULL));
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        troca(&array[i], &array[j]);
    }
}
