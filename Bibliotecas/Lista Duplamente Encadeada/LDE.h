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
LDE *busca(LDE *L, int value);

int listaVazia(LDE *f);
int ultimoElemento(LDE *l);

void insereInicio(LDE *f, int value);
void insereFim(LDE *l, int value);
void insereOrdenado(LDE *l, int id);
void removeInicio(LDE *l);
void removeFim(LDE *f);
void removeValor(LDE *l, int value);
void imprime(LDE *f);
void liberaLista(LDE *l);

#endif
