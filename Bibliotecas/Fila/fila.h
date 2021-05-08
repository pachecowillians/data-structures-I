#ifndef __FILA_H__
#define __FILA_H__

#include <stdio.h>
#include <stdlib.h>
#include "LDE.h"

typedef struct fila
{
    int numElementos;
    LDE *fila;
} Fila;

Fila *criaFila();
int empty(Fila *f);
int size(Fila *f);
int front(Fila *f);
void push(Fila *f, int value);
void pop(Fila *f);
void print(Fila *f);
void libera(Fila *f);

#endif
