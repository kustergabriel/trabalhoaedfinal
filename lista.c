// lista.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lista.h"

Nodo* cria_lista() {
    return NULL;
}

Nodo* insere_lista(Nodo* lista, char* linha) {
    Nodo* novo = (Nodo*) malloc(sizeof(Nodo));
    if (novo == NULL) {
        printf("Erro de alocação de memória!\n");
        return lista;
    }
    strcpy(novo->linha, linha);
    novo->prox = lista;
    return novo;
}

void imprime_lista(Nodo* lista) {
    Nodo* p;
    for (p = lista; p != NULL; p = p->prox) {
        printf("Valor: %s\n", p->linha);
    }
}

void free_lista(Nodo* lista) {
    Nodo* p = lista;
    while (p != NULL) {
        Nodo* temp = p->prox;
        free(p);
        p = temp;
    }
}

void consultapokedex(Nodo* lista) {
    char nomepokemon[100];
    int encontrado = 0;
    printf("Insira o nome do Pokemon que deseja buscar: ");
    scanf("%99s", nomepokemon);

    for (int i = 0; nomepokemon[i]; i++) {
        nomepokemon[i] = toupper(nomepokemon[i]); // Converte o nome do Pokémon para letras maiúsculas
    }

    for (Nodo* p = lista; p != NULL; p = p->prox) {
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

    if (!encontrado)
        printf("Pokemon não encontrado!\n");
}
