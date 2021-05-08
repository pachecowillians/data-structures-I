
#ifndef __LDE_H__
#define __LDE_H__

#include <stdio.h>
#include <stdlib.h>
#include "LSE.h"

typedef struct pilha
{
    int numElementos;
    LSE *pilha;
} Pilha;

Pilha *novaPilha();

int top(Pilha *p);
int tamanho(Pilha *p);

void push(Pilha *p, int value);
void pop(Pilha *p);
void libera(Pilha *p);
void imprime(Pilha *p);

#endif
