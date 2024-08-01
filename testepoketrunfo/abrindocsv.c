#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

/*criar o .c o .h e o makefile*/

#define NRO_CARTAS 5 // numero de cartas por jogador
#define MAX_POKEMONS 800 // nro de pokemons

FILE *openarq(const char *filename);
void free_lines(char *lines[], int count);
void consultapokedex (char *linha[], int count);
void telainicial (int *opcao);
void telainicial0 (void);
void shuffle(int array[], int n);
void troca(int *a, int *b);

int main() {
    char *linha[MAX_POKEMONS];  // armazenar as linhas do arquvio
    char aux[MAX_POKEMONS]; // para duplicar a linha mesmo do arquivo
    int telaload = 0;
    int i = 0; 

    //abre o arquivo e verifica se foi aberto corretamente.
    FILE *pokemon = openarq("/Meus Projetos/Trabalho Final AED1/trabalhoaedfinal/testepoketrunfo/pokemon.csv");
    if (pokemon == NULL) {
        return 1; 
    }

    // le todas as linhas e armazena no array de ponteiros
    while (fgets(aux, sizeof(aux), pokemon) && i < MAX_POKEMONS) {    
        linha[i] = strdup(aux); 
        i++;
    }

    telainicial0(); // imprime a tela inicial
    
    // tela de load do jogo
    do {
        telainicial(&telaload);
        if (telaload == 0) {
            consultapokedex(linha, i); /* acho que tenho que muda essa funcao para ser com listas!!*/
        } else if (telaload == 1) {
            int cartas[MAX_POKEMONS];
            for (int j = 0; j < MAX_POKEMONS; j++) {
                cartas[j] = j;
            }

            /*  printf("Cartas antes do embaralhamento:\n");
            for (int j = 0; j < NRO_CARTAS; j++) {
                printf("%d ", cartas[j]);
            }
            printf("\n"); */

            shuffle(cartas, MAX_POKEMONS); // aqui esta sendo aleatorizado
            printf ("Cartas embaralhadas, o que deseja fazer agora? ");
            printf("\n");

           /* printf("Cartas embaralhadas:\n");
            for (int j = 0; j < NRO_CARTAS; j++) {
                printf("%s", linha[cartas[j]]);
            }
            printf("\n"); */

        } else if (telaload == 2) {
            printf("Pensar no que vai ser feito!!\n");
        }
    } while (telaload != 10);
        printf("Jogo encerrado, obrigado por jogar!!!\n");

    free_lines(linha, i); // liberando memoria das linhas
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

    // funcao que libera a memoria para as linhas
void free_lines(char *lines[], int count) {
    for (int i = 0; i < count; i++) {
        free(lines[i]); 
    }
}

    // funcao para consultar a pokedex pelo nome do pokemon
void consultapokedex (char *lines[], int count) {
    char nomepokemon[100];
    int encontrado = 0;
    printf("Insira o nome do Pokemon que deseja buscar: ");
    scanf("%99s", nomepokemon);  

    for (int i = 0; nomepokemon[i]; i++) {
        nomepokemon[i] = toupper(nomepokemon[i]); // converte o nome do pokemon pra letras maisculas
    }

    for (int j = 0; j < count; j++) {
        char *linhaaux = strdup(lines[j]); // por que eu preciso duplicar???? 
            if (linhaaux == NULL) {
                printf("Erro de alocação de memória!\n");
                break;
            }
        for (int k = 0; linhaaux[k]; k++) {
            linhaaux[k] = toupper(linhaaux[k]);
        }
            if (strstr(linhaaux, nomepokemon) != NULL) {  /*strstr muito massa essa funcao!!!*/
                printf("%s", lines[j]);
                encontrado = 1;
                free(linhaaux);
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
void shuffle(int array[], int n) {
    srand(time(NULL));
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        troca(&array[i], &array[j]);
    }
}