#include <stdio.h>
#include <string.h>
#define Max_Linhas_Arq 1024

FILE *openarq (const char *filename);

int main() {
    char line[Max_Linhas_Arq];
    FILE *file = openarq("/Meus Projetos/Trabalho Final AED1/trabalhoaedfinal/testepoketrunfo/pokemon.csv");
    

    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fclose(file);
    return 0;
}

// function for open arquive

FILE *openarq(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo %s!\n", filename);
        return NULL;
    }
    return file;
}