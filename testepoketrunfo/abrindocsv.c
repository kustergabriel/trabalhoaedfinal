#include <stdio.h>
#include <string.h>
#define Max_Linhas_Arq 1024


int main() {
    char line[Max_Linhas_Arq];
    //tenta abrir o arquivo
    FILE *file = fopen("/Meus Projetos/Trabalho Final AED1/trabalhoaedfinal/testepoketrunfo/pokemon.csv", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo pokemon.csv!\n");
        return 1;
    }

    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fclose(file);
    return 0;
}

// function for open arquive

void openarq ()