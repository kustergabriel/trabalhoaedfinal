#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NRO_CARTAS 5 // numero de cartas por jogador
#define MAX_POKEMONS 800 // nro de pokemons

FILE *openarq(const char *filename);
void free_lines(char *lines[], int count);
void consultapokedex (char *linha[], int count);

int main() {
    char *linha[MAX_POKEMONS];  // armazenar as linhas do arquvio
    char aux[MAX_POKEMONS];
    int telaload = 0;
    int i = 0;

    FILE *pokemon = openarq("/Meus Projetos/Trabalho Final AED1/trabalhoaedfinal/testepoketrunfo/pokemon.csv");
    if (pokemon == NULL) {
        return 1; 
    }

    // le todas as linhas e armazena no array de ponteiros
    while (fgets(aux, sizeof(aux), pokemon) && i < MAX_POKEMONS) {    
        linha[i] = strdup(aux); 
        i++;
    }

    fclose(pokemon);
    
    // tela de carregamento
    printf("----------------------Seja bem vindo ao POKETRUNFO!----------------------\n");
    printf("----------------------Insira uma tecla para Comecar a jogar----------------------\n");
    do {
    printf("---------------------- 0 = CONSULTA POKEDEX----------------------\n");
    printf("---------------------- 1 = EMBARALHAR AS CARTAS----------------------\n");
    printf("---------------------- 2 = SORTEIO DAS CARTAS----------------------\n");
    printf("---------------------- 10 = SAIR DO JOGO----------------------\n");
    printf("Insira a sua alternativa: ");
    scanf("%d", &telaload);


    // imprime os pokémons na tela conforme a opção escolhida porem nao quero todos, quero so o que o animalzinho digita
    
        if (telaload == 0) {
            consultapokedex(linha,i); // FALTA NESSA FUNCAO AINDA PODER USAR SOMENTE LETRAS MINUSCULAS

        } else if (telaload == 1) {
            /*embaralhar as cartas*/
            /*talvez usar rand aproveitando que eu ja to armazenando eles*/
    }

// condicao pra acabar o jogo    
}   while (telaload != 10);
        printf ("O jogo foi encerrado!");

    free_lines(linha, i); // liberando memoria das linhas

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
// funcao para consultar a pokedex pelo nome do pokemon
void consultapokedex (char *lines[], int count) {
    char nomepokemon[100];
    int encontrado = 0;
    printf("Insira o nome do Pokemon que deseja buscar: ");
        scanf("%99s", nomepokemon);  
    // buscando pelo nome dele (muito maneiro!!!)
        for (int j = 0; j < count; j++) {
            if (strstr(lines[j], nomepokemon) != NULL) {  /*strstr muito massa essa funcao!!!*/
                printf("%s", lines[j]);
                encontrado = 1;
                break;
            } 
        }
        if (encontrado != 1)
            printf ("Pokemon nao encontrado, tente digitar com letras maiusculas!\n");
}