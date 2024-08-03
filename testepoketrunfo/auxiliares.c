#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "auxiliares.h"

FILE *openarq(const char *filename) {
    FILE *pokemon = fopen(filename, "r");
    if (pokemon == NULL) {
        printf("Erro ao abrir o arquivo %s!\n", filename);
        return NULL;
    }
    return pokemon;
}

void consultapokedex(Lista* lista) {
    char nomepokemon[100];
    int encontrado = 0;
    printf("Insira o nome do Pokemon que deseja buscar: ");
    scanf("%99s", nomepokemon);

    for (int i = 0; nomepokemon[i]; i++) {
        nomepokemon[i] = toupper(nomepokemon[i]); // converte o nome do pokemon pra letras maisculas
    }
    for (Nodo* p = lista->head; p != NULL; p = p->prox) {
        char linhaaux[MAX_POKEMONS];
        strcpy(linhaaux, p->linha);
        for (int k = 0; linhaaux[k]; k++) {
            linhaaux[k] = toupper(linhaaux[k]);
        }
        if (strstr(linhaaux, nomepokemon) != NULL) {
            printf("%s", p->linha);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Pokemon nao encontrado!\n");
    }
}

void telainicial0(void) {
    printf("----------------------Seja bem vindo ao POKETRUNFO!----------------------\n");
    printf("----------------------Insira uma tecla para Comecar a jogar----------------------\n");
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

void embaralharcartas(int array[], int n) {
    srand(time(NULL));
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        troca(&array[i], &array[j]);
    }
}
