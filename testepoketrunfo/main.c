// main.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "utils.h"

#define NRO_CARTAS 5
#define MAX_POKEMONS 800

int main() {
    char aux[MAX_POKEMONS];
    int telaload = 0;
    Nodo* lista = cria_lista();

    // Abre o arquivo e verifica se foi aberto corretamente
    FILE *pokemon = openarq("pokemon.csv");
    if (pokemon == NULL) {
        return 1;
    }

    // Lê todas as linhas e armazena na lista
    while (fgets(aux, sizeof(aux), pokemon)) {
        lista = insere_lista(lista, aux);
    }

    telainicial0(); // Imprime a tela inicial

    // Tela de load do jogo
    do {
        telainicial(&telaload);
        if (telaload == 0) {
            consultapokedex(lista);
        } else if (telaload == 1) {
            int cartas[MAX_POKEMONS];
            for (int j = 0; j < MAX_POKEMONS; j++) {
                cartas[j] = j;
            }

            shuffle(cartas, MAX_POKEMONS); // Embaralha as cartas
            printf("Cartas embaralhadas, o que deseja fazer agora?\n");

        } else if (telaload == 2) {
            printf("Pensar no que vai ser feito!!\n");
        }
    } while (telaload != 10);

    printf("Jogo encerrado, obrigado por jogar!!!\n");

    free_lista(lista); // Libera a memória das linhas
    fclose(pokemon); // Fecha o arquivo .csv

    return 0;
}
