#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int value;
    struct no *prev;
    struct no *prox;
} No;

No *criaNo(int value)
{
    No *novo = (No *)malloc(sizeof(No));
    if (!novo)
    {
        printf("Erro de alocação de memória.");
        exit(1);
    }

    novo->value = value;
    novo->prev = NULL;
    novo->prox = NULL;
    return novo;
}

void imprimeListaDireta(No *l)
{
    No *aux = l;
    while (aux)
    {
        printf("%d ", aux->value);
        aux = aux->prox;
    }
}

No *buscaOrdenado(No *l, int val)
{
    if (!l)
        return l;
    else
    {
        No *aux = l;
        while (aux->prox && val > aux->value)
        {
            aux = aux->prox;
        }
        return aux;
    }
}

No *insereOrdenado(No *l, int value)
{
    No *novo = criaNo(value);
    No *aux = buscaOrdenado(l, value);

    if (!aux)
        l = novo;
    else
    {
        if (aux->value < value) //Caso seja maior que o ultimo elemento da lista
        {
            aux->prox = novo;
            novo->prev = aux;
        }
        else
        {
            if (aux->prev)
            {
                novo->prev = aux->prev;
                aux->prev->prox = novo;
            }
            else
                l = novo;

            novo->prox = aux;
            aux->prev = novo;
        }
    }
    return l;
}

No *insereInicio(No *l, int value)
{
    No *novo = criaNo(value);
    novo->prox = l;
    if (l)
        l->prev = novo;
    return novo;
}

No *insereFim(No *l, int value)
{
    No *novo = criaNo(value);
    No *aux = l;
    if (aux)
    {
        while (aux->prox)
        {
            aux = aux->prox;
        }
        aux->prox = novo;
        novo->prev = aux;
    }
    else
        l = novo;
    return l;
}

No *removeInicio(No *l)
{
    if (l)
    {
        No *aux = l;
        l = l->prox;
        if (l)
            l->prev = NULL;
        free(aux);
    }
    return l;
}

No *removeFim(No *l)
{
    No *aux = l;
    if (aux)
    {
        while (aux->prox)
        {
            aux = aux->prox;
        }
        if (aux->prev)
            aux->prev->prox = NULL;
        else
            l = aux->prev;
        free(aux);
    }
    return l;
}

No *removeChave(No *l, int value)
{
    No *aux = l;
    if (aux)
    {
        while (aux && aux->value != value)
        {
            aux = aux->prox;
        }
        if (aux)
        {
            if (aux->prev)
                aux->prev->prox = aux->prox;
            else
                l = aux->prox;
            if (aux->prox)
                aux->prox->prev = aux->prev;
            free(aux);
        }
    }
    return l;
}

int main()
{
    No *l = NULL;
    l = insereFim(l, 2);
    l = insereFim(l, 3);
    l = insereFim(l, 1);
    l = removeChave(l,3);
    imprimeListaDireta(l);
}