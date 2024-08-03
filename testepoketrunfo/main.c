#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"
#include "auxiliares.h"

#define MAX_POKEMONS 800

int main() {
    char aux[MAX_POKEMONS]; // para duplicar a linha do arquivo
    int telaload = 0;

    //abre o arquivo e verifica se foi aberto corretamente.
    FILE *pokemon = openarq("/Meus Projetos/Trabalho Final AED1/trabalhoaedfinal/testepoketrunfo/pokemon.csv");
    if (pokemon == NULL) {
        return 1; 
    }

    while (fgets(aux, sizeof(aux), pokemon)) { // le as linhas e armazena na lista
        insere_lista(lista, aux);
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
            printf("Cartas embaralhadas, o que deseja fazer agora?\n");

        } else if (telaload == 2) {
            printf("Pensar no que vai ser feito!!\n");
        }
    } while (telaload != 10);
    printf("Jogo encerrado, obrigado por jogar!!!\n");

    free_lista(lista); // liberando memoria das linhas
    fclose(pokemon); // fecha o arquivo .csv

    return 0;
}
