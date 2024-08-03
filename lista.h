// lista.h

#ifndef LISTA_H
#define LISTA_H

#define MAX_POKEMONS 800

typedef struct nodo {
    char linha[MAX_POKEMONS];
    struct nodo* prox;
} Nodo;

// Funções de lista
Nodo* cria_lista();
Nodo* insere_lista(Nodo* lista, char* linha);
void imprime_lista(Nodo* lista);
void free_lista(Nodo* lista);

// Função de consulta
void consultapokedex(Nodo* lista);

#endif
