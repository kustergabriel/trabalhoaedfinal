#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NRO_CARTAS 5 // numero de cartas por jogador
#define MAX_POKEMONS 800 // nro de pokemons

FILE *openarq(const char *filename);
void free_lines(char *lines[], int count);

int main() {
    char *linha[MAX_POKEMONS];  // armazenar as linhas do arquvio
    char aux[MAX_POKEMONS];
    int telaload = 0;
    int i = 0;
    char nomepokemon[100];
    int encontrado = 0;

    // tela de carregamento
    printf("----------------------Seja bem vindo ao POKETRUNFO!----------------------\n");
    printf("----------------------Insira uma tecla para Comecar a jogar----------------------\n");
    printf("---------------------- 0 = CONSULTA POKEDEX----------------------\n");
    printf("---------------------- 1 = EMBARALHAR AS CARTAS----------------------\n");
    printf("---------------------- 2 = SORTEIO DAS CARTAS----------------------\n");
    printf("Insira a sua alternativa: ");
    scanf("%d", &telaload);

    // abre o arquivo
    FILE *pokemon = openarq("/Meus Projetos/Trabalho Final AED1/trabalhoaedfinal/testepoketrunfo/pokemon.csv");
    if (pokemon == NULL) {
        return 1; 
    }

    // le todas as linhas e armazena no array de ponteiros
    while (fgets(aux, sizeof(aux), pokemon) && i < MAX_POKEMONS) {    
        linha[i] = strdup(aux); // Duplica a linha e armazena no array de ponteiros
        i++;
    }

    fclose(pokemon);

    // imprime os pokémons na tela conforme a opção escolhida porem nao quero todos, quero so o que o animalzinho digita
    if (telaload == 0) {
        printf("Insira o nome do Pokemon que deseja buscar: ");
        scanf("%99s", nomepokemon);  
    // buscando pelo nome dele (muito maneiro!!!)
        for (int j = 0; j < i; j++) {
            if (strstr(linha[j], nomepokemon) != NULL) { 
                printf("%s", linha[j]);
                encontrado = 1;
                break;
            } 
        }
        if (encontrado != 1)
            printf ("Pokemon nao encontrado, tente digitar com letras maiusculas!");

    } else if (telaload == 1) {
        /*embaralhar as cartas*/
    }


    free_lines(linha, i);

    return 0;
    }

// abre o arquivoooo
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
