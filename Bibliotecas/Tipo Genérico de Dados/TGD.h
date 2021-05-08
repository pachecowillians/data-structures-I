
#ifndef __TGD_H__
#define __TGD_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tgd
{
    void * value;
    struct tgd *prox;
} TGD;

TGD *criaNo(void * value);
TGD *busca(TGD *l, void *value, TGD **prev, int (*menorQue)(void *, void *));
TGD *novaLista();

void insereInicio(TGD *l, void * value);
void insereFim(TGD *l, void * value);
void insereOrdenado(TGD *l, void *value, int (*menorQue)(void *, void *));
void imprimeLista(TGD *l, void (*imprime) (void *));
void removeInicio(TGD *l);
void removeFim(TGD *l);
void liberaLista(TGD *l, void (*liberaValor)(void *));

#endif
