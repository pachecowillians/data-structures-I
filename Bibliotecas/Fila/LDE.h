#ifndef __LDE_H__
#define __LDE_H__

#include <stdio.h>
#include <stdlib.h>

typedef struct lde
{
    int value;
    struct lde *prox;
    struct lde *prev;
} LDE;

LDE *criaNo(int value);
LDE *novaLista();
int listaVazia(LDE *f);
int ultimoElemento(LDE *l);
void insereInicio(LDE *f, int value);
void removeFim(LDE *f);
void imprime(LDE *f);
void liberaLista(LDE *l);

#endif
