#include "TGD.h"

TGD *criaNo(void *value)
{
    TGD *n = (TGD *)malloc(sizeof(TGD));
    n->value = value;
    n->prox = NULL;
    return n;
}

TGD *novaLista()
{
    TGD *l = (TGD *)calloc(1, sizeof(TGD));
    if (!l)
    {
        printf("Erro de alocacao de memoria.\n");
        exit(1);
    }
    return l;
}

void insereInicio(TGD *l, void *value)
{
    TGD *novo = criaNo(value);
    novo->prox = l->prox;
    l->prox = novo;
}

void insereFim(TGD *l, void *value)
{
    TGD *novo = criaNo(value);
    TGD *aux = l;
    while (aux->prox)
        aux = aux->prox;

    aux->prox = novo;
}

TGD *busca(TGD *l, void *value, TGD **prev, int (*menorQue)(void *, void *))
{
    TGD *aux = l->prox;
    *prev = l;
    while (aux && menorQue(aux->value, value))
    {
        *prev = aux;
        aux = aux->prox;
    }
    return aux;
}

void insereOrdenado(TGD *l, void *value, int (*menorQue)(void *, void *))
{
    TGD *novo = criaNo(value);
    TGD *prev = NULL;
    TGD *atual = busca(l, value, &prev, menorQue);
    novo->prox = atual;
    prev->prox = novo;
}

void imprimeLista(TGD *l, void (*imprime)(void *))
{
    TGD *aux = l->prox;
    while (aux)
    {
        imprime(aux->value);
        aux = aux->prox;
    }
    printf("\n");
}

void removeInicio(TGD *l)
{
    TGD *aux = l->prox;
    if (aux)
    {
        l->prox = aux->prox;
        free(aux);
    }
}

void removeFim(TGD *l)
{
    TGD *aux = l->prox;
    TGD *prev = l;
    if (aux)
    {
        while (aux->prox)
        {
            prev = aux;
            aux = aux->prox;
        }
        prev->prox = NULL;
        free(aux);
    }
}

void liberaLista(TGD *l, void (*liberaValor)(void *))
{
    TGD *aux = l->prox;
    while (aux)
    {
        TGD *n = aux;
        aux = aux->prox;
        liberaValor(n->value);
        free(n);
    }
    free(l);
}