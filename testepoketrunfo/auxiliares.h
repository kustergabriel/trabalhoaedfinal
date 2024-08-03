#ifndef AUXILIARES_H
#define AUXILIARES_H

#include "Lista.h"

FILE *openarq(const char *filename);
void consultapokedex(Lista* lista);
void telainicial(int *opcao);
void telainicial0(void);
void embaralharcartas(int array[], int n);
void troca(int *a, int *b);

#endif // AUXILIARES_H
