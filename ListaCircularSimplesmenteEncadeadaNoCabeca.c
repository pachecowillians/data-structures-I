#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int chave;
    struct no *prox;
} No;

No *criaNo(int chave)
{
    No *novo = (No *)malloc(sizeof(No));
    if (!novo)
    {
        printf("deu ruim.");
        exit(1);
    }
    else
    {
        novo->chave = chave;
        novo->prox = NULL;
    }
    return novo;
}

void insereInicio(No *l, int chave)
{
    No *novo = criaNo(chave);
    if (l->prox == l)
        novo->prox = l;

    else
        novo->prox = l->prox;

    l->prox = novo;
}

void insereFim(No *l, int chave)
{
    No *novo = criaNo(chave);
    if (l->prox == l)
    {
        novo->prox = l;
        l->prox = novo;
    }
    else
    {
        No *anterior = l->prox;
        while (anterior->prox != l)
        {
            anterior = anterior->prox;
        }
        anterior->prox = novo;
        novo->prox = l;
    }
}

void removeInicio(No *l)
{
    No *removido = l->prox;
    if (removido->prox != removido)
    {
        l->prox = removido->prox;
        free(removido);
    }
    else
    {
        l->prox = l;
    }
}

void removeFim(No *l)
{
    No *removido = l->prox;
    No *anterior = l;
    if (l->prox != l)
    {
        while (removido->prox != l)
        {
            anterior = removido;
            removido = removido->prox;
        }

        anterior->prox = l;
        free(removido);
    }
}

void imprimeLista(No *l)
{
    No *aux = l->prox;
    while (aux != l)
    {
        printf("%d ", aux->chave);
        aux = aux->prox;
    }
}

int main()
{
    No *l = (No *)calloc(1, sizeof(No));
    l->prox = l;

    insereFim(l, 1);
    insereFim(l, 2);
    insereFim(l, 2);
    insereFim(l, 2);

    removeFim(l);
    removeFim(l);

    imprimeLista(l);
}