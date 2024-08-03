#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"

Lista* cria_lista(void) {
    Lista* nova_lista = (Lista*) malloc(sizeof(Lista));
    if (nova_lista == NULL) {
        printf("Erro de alocação de memória!\n");
        return NULL;
    }
    nova_lista->head = NULL;
    return nova_lista;
}

Nodo* insere_lista(Lista* lista, char* linha) {
    Nodo* novo = (Nodo*) malloc(sizeof(Nodo));
    if (novo == NULL) {
        printf("Erro de alocação de memória!\n");
        return NULL;
    }
    strcpy(novo->linha, linha);
    novo->prox = lista->head;
    lista->head = novo;
    return novo;
}

void imprime_lista(const Lista* lista) {
    Nodo* p = lista->head;
    while (p != NULL) {
        printf("%s", p->linha);
        p = p->prox;
    }
}

void free_lista(Lista* lista) {
    Nodo* p = lista->head;
    while (p != NULL) {
        Nodo* temp = p->prox;
        free(p);
        p = temp;
    }
    free(lista);
}
