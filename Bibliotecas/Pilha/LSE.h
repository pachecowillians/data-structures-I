
#ifndef __LSE_H__
#define __LSE_H__

#include <stdio.h>
#include <stdlib.h>

typedef struct lse
{
    int value;
    struct lse *prox;
} LSE;

LSE *criaNo(int value);
LSE *busca(LSE *l, int value, LSE **prev);
LSE *novaLista();

void insereInicio(LSE *l, int value);
void insereFim(LSE *l, int value);
void insereOrdenado(LSE *l, int value);
void imprimeLista(LSE *l);
void removeInicio(LSE *l);
void removeFim(LSE *l);
void liberaLista(LSE *l);
int primeiroElemento(LSE *l);

#endif
