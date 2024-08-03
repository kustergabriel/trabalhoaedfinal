#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define NRO_CARTAS 5 // numero de cartas por jogador
#define MAX_POKEMONS 800 // nro de pokemons

// vou utilizar listas para a pokedex!!!
struct nodo{
    int valor;
    char linha[MAX_POKEMONS]; // armazenar a lista
    struct nodo* prox;
};
typedef struct nodo Nodo;

FILE *openarq(const char *filename);
void consultapokedex(Nodo* lista);
void telainicial (int *opcao);
void telainicial0 (void);
void embaralharcartas(int array[], int n);
void troca(int *a, int *b);
Nodo* cria_lista(void);
Nodo* insere_lista(Nodo* lista, char* linha);
void imprime_lista(Nodo* lista);
void free_lista(Nodo* lista);

int main() {
    char aux[MAX_POKEMONS]; // para duplicar a linha do arquivo
    int telaload = 0;
    Nodo* lista = cria_lista();

    //abre o arquivo e verifica se foi aberto corretamente.
    FILE *pokemon = openarq("/Meus Projetos/Trabalho Final AED1/trabalhoaedfinal/testepoketrunfo/pokemon.csv");
    if (pokemon == NULL) {
        return 1; 
    }

    while (fgets(aux, sizeof(aux), pokemon)) { // le as linhas e armazena na lista
        lista = insere_lista(lista, aux);
}
    telainicial0(); // imprime a tela inicial
    
    do { // tela de load
        telainicial(&telaload);
        if (telaload == 0) {
            consultapokedex(lista);  
        } else if (telaload == 1) {
            int cartas[MAX_POKEMONS];
            for (int j = 0; j < MAX_POKEMONS; j++) {
                cartas[j] = j;
            }

            embaralharcartas(cartas, MAX_POKEMONS); // aqui esta sendo aleatorizado
            printf ("Cartas embaralhadas, o que deseja fazer agora?\n");

        } else if (telaload == 2) {
            printf("Pensar no que vai ser feito!!\n");
        }
    } while (telaload != 10);
        printf("Jogo encerrado, obrigado por jogar!!!\n");

    free_lista(lista); // liberando memoria das linhas
    fclose(pokemon); // fecha o arquivo .csv

    return 0;
}

// abre o arquivo
FILE *openarq(const char *filename) {
    FILE *pokemon = fopen(filename, "r");
    if (pokemon == NULL) {
        printf("Erro ao abrir o arquivo %s!\n", filename);
        return NULL;
    }   
    return pokemon;
}

// funcao para consultar a pokedex pelo nome do pokemon
void consultapokedex(Nodo* lista) {
    char nomepokemon[100];
    int encontrado = 0;
    printf("Insira o nome do Pokemon que deseja buscar: ");
    scanf("%99s", nomepokemon);  

    for (int i = 0; nomepokemon[i]; i++) {
        nomepokemon[i] = toupper(nomepokemon[i]); // converte o nome do pokemon pra letras maisculas
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
        if (encontrado != 1)
            printf ("Pokemon nao encontrado!\n");
}

    // tela inicial mesmo mesmo
void telainicial0 (void) {
    printf("----------------------Seja bem vindo ao POKETRUNFO!----------------------\n");
    printf("----------------------Insira uma tecla para Comecar a jogar----------------------\n");
}

    // funcao da tela inicial
void telainicial (int *opcao) {
    printf("---------------------- 0 = CONSULTA POKEDEX----------------------\n");
    printf("---------------------- 1 = EMBARALHAR AS CARTAS----------------------\n");
    printf("---------------------- 2 = SORTEIO DAS CARTAS----------------------\n");
    printf("---------------------- 10 = SAIR DO JOGO----------------------\n");
    printf("Insira a sua alternativa: ");
    scanf("%d", opcao);
}

    // vou utilizar o fisher yates  
void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
    // peguei o codigo da internet e implementei aqui
void embaralharcartas(int array[], int n) {
    srand(time(NULL));
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        troca(&array[i], &array[j]);
    }
}

Nodo* cria_lista(void) {
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

void free_lista(Nodo* lista) {
    Nodo* p = lista;
    while (p != NULL) {
        Nodo* temp = p->prox;
        free(p);
        p = temp;
    }
}