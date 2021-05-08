#ifndef __LCDE_H__
#define __LCDE_H__

#include <stdio.h>
#include <stdlib.h>

typedef struct lcde
{
    int value;
    struct lcde *prox;
    struct lcde *prev;
} LCDE;

LCDE *criaNo(int value);
void insereInicio(LCDE **l, int value);
void insereFim(LCDE **l, int value);
void removeInicio(LCDE **l);
void removeFim(LCDE **l);
void imprimeLista(LCDE **l);
void liberaLista(LCDE **l);

#endif
