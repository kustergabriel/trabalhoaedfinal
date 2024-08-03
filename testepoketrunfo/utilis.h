// utils.h

#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>

// Funções utilitárias
FILE *openarq(const char *filename);
void telainicial(int *opcao);
void telainicial0(void);
void shuffle(int array[], int n);
void troca(int *a, int *b);

#endif
