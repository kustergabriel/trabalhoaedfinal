#ifndef LISTA_H
#define LISTA_H

#define MAX_POKEMONS 800

typedef struct nodo {
    int valor;
    char linha[MAX_POKEMONS]; // armazenar a lista
    struct nodo* prox;
} Nodo;

typedef struct {
    Nodo* head;
} Lista;

// Funções para manipular a lista
Lista* cria_lista(void);
Nodo* insere_lista(Lista* lista, char* linha);
void imprime_lista(const Lista* lista);
void free_lista(Lista* lista);

#endif // LISTA_H
