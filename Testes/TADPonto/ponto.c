#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ponto.h"

struct ponto
{
    float x;
    float y;
};

Ponto *cria(float x, float y)
{
    Ponto *p = (Ponto *)malloc(sizeof(Ponto));
    if (p == NULL)
    {
        printf("Memória insuficiente!\n");
        exit(1);
    }
    p->x = x;
    p->y = y;
    return p;
}
void libera(Ponto *p)
{
    free(p);
}
void acessa(Ponto *p, float *x, float *y)
{
    *x = p->x;
    *y = p->y;
}
void atribui(Ponto *p, float x, float y)
{
    p->x = x;
    p->y = y;
}
float distancia(Ponto *p1, Ponto *p2)
{
    float dx = p2->x - p1->x;
    float dy = p2->y - p1->y;
    return sqrt(dx * dx + dy * dy);
}

Ponto * Subtracao(Ponto *p1, Ponto *p2)
{
    Ponto *pFinal = (Ponto *)malloc(sizeof(Ponto));
    pFinal->x = p1->x - p2->x;
    pFinal->y = p1->y - p2->y;
    return pFinal;
}

Ponto * Soma(Ponto *p1, Ponto *p2)
{
    Ponto *pFinal = (Ponto *)malloc(sizeof(Ponto));
    pFinal->x = p1->x + p2->x;
    pFinal->y = p1->y + p2->y;
    return pFinal;
}