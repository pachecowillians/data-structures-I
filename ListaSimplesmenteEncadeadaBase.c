#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int info;
    struct no *prox;
} No;

typedef struct base
{
    struct no *primeiro;
    struct no *ultimo;
} Base;

No *criaNo(int val)
{
    No *novo = (No *)malloc(sizeof(No));
    novo->info = val;
    novo->prox = NULL;
    return novo;
}

void insereInicio(Base *l, int val)
{
    No *novo = criaNo(val);
    if (!novo)
        exit(1);

    novo->prox = l->primeiro;
    l->primeiro = novo;
    if (!l->ultimo)
        l->ultimo = novo;
}

void insereFim(Base *l, int val)
{
    No *novo = criaNo(val);
    if (!novo)
        exit(1);
    if (l->ultimo)
    {
        l->ultimo->prox = novo;
        l->ultimo = novo;
    }
    else
    {
        l->primeiro = novo;
        l->ultimo = novo;
    }
}

No *busca(Base *l, int val, No **prev)
{
    No *aux = l->primeiro;
    *prev = NULL;
    while (aux && aux->info < val)
    {
        *prev = aux;
        aux = aux->prox;
    }
    return aux;
}

void insereOrdenado(Base *l, int val)
{
    No *novo = criaNo(val);
    No *prev = NULL;
    No *atual = busca(l, val, &prev);
    novo->prox = atual;
    if (!l->primeiro) //Vazia
    {
        l->primeiro = novo;
        l->ultimo = novo;
    }
    else if (!prev) //Começo
    {
        l->primeiro = novo;
    }
    else if (!atual) //Fim
    {
        l->ultimo->prox = novo;
        l->ultimo = novo;
    }
    else //Meio
    {
        prev->prox = novo;
    }
}

void removeInicio(Base *l)
{
    No *aux = l->primeiro;
    if (aux)
    {
        l->primeiro = aux->prox;
        free(aux);
    }
}

void removeFim(Base *l)
{
    No *aux = l->primeiro;
    No *prev = NULL;
    if (aux)
    {
        while (aux->prox)
        {
            prev = aux;
            aux = aux->prox;
        }
        prev->prox = NULL;
        l->ultimo = prev;
        free(aux);
    }
}

void imprimeLista(Base *l)
{
    No *aux = l->primeiro;
    while (aux)
    {
        printf("%d ", aux->info);
        aux = aux->prox;
    }
}

int main()
{
    Base *l = (Base *)calloc(1, sizeof(Base));
    insereOrdenado(l, 2);
    insereOrdenado(l, 6);
    insereOrdenado(l, 1);
    insereOrdenado(l, 5);
    insereOrdenado(l, 8);
    insereOrdenado(l, 0);
    imprimeLista(l);
    printf("\n");
    removeInicio(l);
    removeFim(l);
    imprimeLista(l);
}