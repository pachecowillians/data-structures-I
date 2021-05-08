#include "LDE.h"

LDE *criaNo(int value)
{
    LDE *novo = (LDE *)malloc(sizeof(LDE));
    if (novo)
    {
        novo->prox = NULL;
        novo->prev = NULL;
        novo->value = value;
    }
    else
    {
        printf("Erro de alocacao de memoria.\n");
        exit(1);
    }
    return novo;
}

LDE *novaLista()
{
    LDE *l = (LDE *)calloc(1, sizeof(LDE));
    if (!l)
    {
        printf("Erro de alocacao de memoria.\n");
        exit(1);
    }
    return l;
}

void insereInicio(LDE *l, int value)
{
    LDE *novo = criaNo(value);

    novo->prox = l->prox;

    if (l->prox)
    {
        l->prox->prev = novo;
    }
    else
        l->prev = novo;

    l->prox = novo;
}

void insereFim(LDE *l, int value)
{
    LDE *novo = criaNo(value);

    if (!l->prev)
        l->prox = novo;
    else
    {
        l->prev->prox = novo;
        novo->prev = l->prev;
    }

    l->prev = novo;
}

void insereOrdenado(LDE *l, int id)
{
    LDE *novo = criaNo(id);

    LDE *aux = busca(l, id);

    if (!aux)
    {
        if (!l->prox)
        {
            l->prox = novo;
            l->prev = novo;
        }
        else
        {
            l->prev->prox = novo;
            novo->prev = l->prev;
            l->prev = novo;
        }
    }
    else
    {
        novo->prox = aux;

        if (!aux->prev)
            l->prox = novo;
        else
        {
            novo->prev = aux->prev;
            novo->prev->prox = novo;
        }

        aux->prev = novo;
    }
}

int listaVazia(LDE *l)
{
    return (l->prox) ? 0 : 1;
}

int ultimoElemento(LDE *l)
{
    return (l->prox) ? l->prox->value : -1;
}

void removeInicio(LDE *l)
{
    LDE *aux = l->prox;
    if (aux)
    {
        l->prox = aux->prox;
        if (!aux->prox)
            l->prev = NULL;
        else
            aux->prox->prev = NULL;
        free(aux);
    }
}

void removeFim(LDE *l)
{
    if (!listaVazia(l))
    {
        LDE *n = l->prev;
        l->prev = n->prev;
        if (l->prev)
            l->prev->prox = NULL;
        else
            l->prox = NULL;
        free(n);
    }
}

void removeValor(LDE *l, int value)
{
    LDE *aux = busca(l, value);
    if (!aux)
        printf("Valor inexistente.\n");
    else
    {
        if (aux->prev)
            aux->prev->prox = aux->prox;
        else
            l->prox = aux->prox;

        if (aux->prox)
            aux->prox->prev = aux->prev;
        else
            l->prev = aux->prev;
    }
}

LDE *busca(LDE *L, int value)
{
    LDE *aux = L->prox;
    while (aux && value > aux->value)
        aux = aux->prox;
    return aux;
}

void imprime(LDE *l)
{
    LDE *n = l->prox;
    while (n)
    {
        printf("%d ", n->value);
        n = n->prox;
    }
    printf("\n");
}

void liberaLista(LDE *l)
{
    while (l)
    {
        LDE *n = l;
        l = l->prox;
        free(n);
    }
}