#include <stdio.h>
#include <string.h>
#define Max_Linhas_Arq 1024

int main() {
    FILE *file = fopen("pokemon.csv", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo pokemon.csv!\n");
        return 1;
    }

    char line[Max_Linhas_Arq];

    while (fgets(line, Max_Linhas_Arq, file)) {
        // Remover a nova linha no final da linha (se houver)
        line[strcspn(line, "\n")] = 0;

        // Dividir a linha usando a vírgula como delimitador
        char *token = strtok(line, ",");
        while (token != NULL) {
            printf("%s ", token);
            token = strtok(NULL, ",");
        }
        printf("\n");
    }

    fclose(file);
    return 0;
}
