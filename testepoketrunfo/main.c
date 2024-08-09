#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define NRO_CARTAS 5 // numero de cartas por jogador
#define MAX_POKEMONS 800 // nro de pokemons

// vou utilizar listas para a pokedex
struct nodo {
    char linha[MAX_POKEMONS]; // armazenar a lista
    struct nodo* prox;
};
typedef struct nodo Nodo;

//pilha para distribuir as cartas para os jogadores
typedef struct pilha{
 int n;
 float v[NRO_CARTAS];
}Pilha;


FILE *openarq(const char *filename);
void consultapokedex(Nodo* lista);
void telainicial (int *opcao);
void telainicial0 (void);
void embaralharcartas(int array[], int n, Pilha *p);
void troca(int *a, int *b);
Nodo* cria_lista(void);
Nodo* insere_lista(Nodo* lista, char* linha);
void imprime_lista(Nodo* lista);
void free_lista(Nodo* lista);
void pokeinfo(char *linha);
Pilha* cria_pilha();
void push(Pilha* p, float x);
float pop(Pilha* p);
int vazia(Pilha* p);
void libera_pilha(Pilha* p);
void imprime_pilha(Pilha* p);


int main() {
    //variaveis
    char aux[MAX_POKEMONS]; // para duplicar a linha do arquivo
    int telaload = 0;
    Nodo* lista = cria_lista();
    Pilha* p = cria_pilha();
    
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
            embaralharcartas(cartas, MAX_POKEMONS, p);            
            printf ("Cartas embaralhadas, o que deseja fazer agora?\n");
            imprime_pilha(p); // Imprime as cartas na pilha
        } else if (telaload == 2) {
            printf("Distribuindo Cartas Para os Jogadores!\n");
        }
    } while (telaload != 10);
    
    printf("Jogo encerrado!");

    free_lista(lista); // liberando memoria das linhas
    fclose(pokemon); // fecha o arquivo .csv
    libera_pilha(p); // libera a memoria da pilha

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
    char nomepokemon[40];
    int encontrado = 0;
    printf("Insira o nome do Pokemon que deseja buscar: ");
    scanf("%99s", nomepokemon);  

    for (int i = 0; nomepokemon[i]; i++) {
        nomepokemon[i] = toupper(nomepokemon[i]); // converte o nome do pokemon pra letras maisculas
    }
    for (Nodo* p = lista; p != NULL; p = p->prox) {
        char linhaaux[MAX_POKEMONS];
        strcpy(linhaaux, p->linha);
        for (int k = 1; linhaaux[k]; k++) { //k = 1 para pular a primeira linha do arquivo
            linhaaux[k] = toupper(linhaaux[k]);
        }
        if (strstr(linhaaux, nomepokemon) != NULL) {
            pokeinfo(p->linha);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado)
        printf ("Pokemon nao encontrado!\n");
}

void linhazinha(int width) {
    for (int i = 0; i < width; i++) {
        printf("-");
    }
    printf("\n");
}

void colocarnomeio(const char *text, int width) {
    int padding = (width - strlen(text)) / 2;
    printf("|");
    for (int i = 0; i < padding; i++) {
        printf(" ");
    }
    printf("%s", text);
    for (int i = 0; i < padding; i++) {
        printf(" ");
    }
    printf("|\n");
}

void telainicial0(void) {
    int width = 50;
    linhazinha(width);
    colocarnomeio("Seja bem vindo ao POKETRUNFO!", width);
    linhazinha(width);
    colocarnomeio("Insira uma tecla para comecar a jogar", width);
    linhazinha(width);
}

void telainicial(int *opcao) {
    int width = 50;
    linhazinha(width);
    colocarnomeio("0 = CONSULTA POKEDEX", width);
    colocarnomeio("1 = EMBARALHAR AS CARTAS", width);
    colocarnomeio("2 = SORTEIO DAS CARTAS", width);
    colocarnomeio("10 = SAIR DO JOGO", width);
    linhazinha(width);
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
void embaralharcartas(int array[], int n, Pilha *p) {
    srand(time(NULL));
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        troca(&array[i], &array[j]);
    }
            for (int k = 0; k < NRO_CARTAS; k++) {
                if (p->n == NRO_CARTAS){
                printf("Capacidade da pilha estourou.\n");
                exit(1);
            }
            push(p, array[k]);
        }
}

Nodo* cria_lista(void) {
    return NULL;
}

Nodo* insere_lista(Nodo* lista, char* linha) {
    Nodo* novo = (Nodo*) malloc(sizeof(Nodo));
    if (novo == NULL) {
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

Pilha* cria_pilha(){
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->n = 0; // Inicializa com 0 elementos
    return p;
}

void push(Pilha* p, float x){
 if (p->n == NRO_CARTAS){
     printf("Capacidade da pilha estourou.\n");
    exit(1);
 }
    p->v[p->n] = x;
    p->n++;
}

float pop(Pilha* p){
    if (vazia(p)){
        printf("Pilha vazia.\n");
        exit(1);
    }
    p->n--;
    return p->v[p->n];
}

int vazia(Pilha* p) {
    return p->n == 0; // Retorna 1 (true) se a pilha estiver vazia, 0 (false) caso contrário
}

void libera_pilha(Pilha* p) {
    free(p);
}

void imprime_pilha(Pilha* p) {
    printf("Cartas na sua mao:\n");
    for (int i = 0; (i < p->n); i++) {
        printf("Pokemon: %.f\n", p->v[i]);
    }
}

// parte do kevin
void pokeinfo(char *linha) {
    char *token;
    char *delim = ","; // ou o delimitador que separa os campos no  CSV
    int field = 0;
    
    char linhaCopia[MAX_POKEMONS];
    strcpy(linhaCopia, linha); // Cria uma copia para n modificar a linha original
    
    printf("\n");
    linhazinha(50);
    token = strtok(linhaCopia, delim);
    while (token != NULL) {
        switch (field) {
                case 0:
                printf("#: %s\n", token);
                break;

                case 1:
                printf("Nome: %s\n", token);
                break;

                case 2:
                printf("Type 1: %s\n", token);
                break;

                 case 3:
                printf("Type 2: %s\n", token);
                break;
                
                case 4:
                printf("Total: %s\n", token);
                break;

                case 5:
                printf("HP: %s\n", token);
                break;

                case 6:
                printf("Attack: %s\n", token);
                break;

                case 7:
                printf("Defense: %s\n", token);
                break;

                case 8:
                printf("Sp. Atk: %s\n", token);
                break;

                case 9:
                printf("Sp. Def: %s\n", token);
                break;

                case 10:
                printf("Speed: %s\n", token);
                break;

                case 11:
                printf("Generation: %s\n", token);
                break;

                case 12:
                printf("Legendary: %s\n", token);
                break;
        }
       field++;
        token = strtok(NULL, delim);
    }
    linhazinha(50);
    printf("\n");
}