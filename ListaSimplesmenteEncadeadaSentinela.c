#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int info;
    struct no *prox;
} No;

No *criaNo(int val)
{
    No *n = (No *)malloc(sizeof(No));
    n->info = val;
    n->prox = NULL;
    return n;
}

void insereInicio(No *l, int val)
{
    No *novo = criaNo(val);
    novo->prox = l->prox;
    l->prox = novo;
}

void insereFim(No *l, int val)
{
    No *novo = criaNo(val);
    No *aux = l;
    while (aux->prox)
    {
        aux = aux->prox;
    }
    aux->prox = novo;
}

No *busca(No *l, int val, No **prev)
{
    No *aux = l->prox;
    *prev = l;
    while (aux && aux->info < val)
    {
        *prev = aux;
        aux = aux->prox;
    }
    return aux;
}

void insereOrdenado(No *l, int val)
{
    No *novo = criaNo(val);
    No *prev = NULL;
    No *atual = busca(l, val, &prev);
    novo->prox = atual;
    prev->prox = novo;
}

void imprimeLista(No *l)
{
    No *aux = l->prox;
    while (aux)
    {
        printf("%d ", aux->info);
        aux = aux->prox;
    }
}

void removeInicio(No *l)
{
    No *aux = l->prox;
    if (aux)
    {
        l->prox = aux->prox;
        free(aux);
    }
}

void removeFim(No *l)
{
    No *aux = l->prox;
    No *prev = l;
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

int main()
{
    No *l = (No *)calloc(1, sizeof(No));
    insereOrdenado(l, 2);
    insereOrdenado(l, 4);
    insereOrdenado(l, 1);
    insereOrdenado(l, 6);
    insereOrdenado(l, 3);
    insereOrdenado(l, 8);
    imprimeLista(l);
    printf("\n");
    removeInicio(l);
    removeFim(l);
    imprimeLista(l);
}