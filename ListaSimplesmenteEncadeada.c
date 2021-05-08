#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int chave;
    struct no *prox;
} No;

No *criaNo(int valor)
{
    No *novo = (No *)malloc(sizeof(No));
    if (novo)
    {
        novo->chave = valor;
        novo->prox = NULL;
        return novo;
    }
    else
    {
        return NULL;
    }
}

No *insereInicio(No *l, int value)
{

    No *n = criaNo(value);

    if (!l)
    {
        l = n;
    }
    else
    {
        n->prox = l;
        l = n;
    }
    return l;
}

No *insereFim(No *l, int value)
{
    No *n = criaNo(value);
    if (!l)
    {
        l = n;
    }
    else
    {
        No *aux = l;
        while (aux->prox)
        {
            aux = aux->prox;
        }
        aux->prox = n;
    }
    return l;
}

No *insereOrdenado(No *l, int value)
{
    No *n = criaNo(value);
    if (!l)
    {
        l = n;
    }
    else
    {
        No *aux = l;
        No *prev = NULL;
        while (aux && n->chave > aux->chave)
        {
            prev = aux;
            aux = aux->prox;
        }
        if (prev)
        {
            prev->prox = n;
        }
        else
        {
            l = n;
        }

        n->prox = aux;
    }

    return l;
}

void imprimeLista(No *l)
{
    while (l)
    {
        printf("%d\n", l->chave);
        l = l->prox;
    }
}

int main()
{
    No *L = NULL; //Só aponta

    L = insereOrdenado(L, 7);
    L = insereOrdenado(L, 1);
    L = insereOrdenado(L, 0);
    L = insereOrdenado(L, 2);
    L = insereOrdenado(L, 4);
    L = insereOrdenado(L, 10);

    imprimeLista(L);
}