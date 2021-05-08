#ifndef __LCSE_H__
#define __LCSE_H__

#include <stdio.h>
#include <stdlib.h>

typedef struct lcse
{
    int value;
    struct lcse *prox;
} LCSE;

LCSE *criaNo(int value);
void insereInicio(LCSE **l, int value);
void insereFim(LCSE **l, int value);
void removeInicio(LCSE **l);
void removeFim(LCSE **l);
void imprimeLista(LCSE **l);
void liberaLista(LCSE **l);

#endif
