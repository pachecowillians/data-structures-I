#include "LSE.h"

LSE *criaNo(int value)
{
    LSE *n = (LSE *)malloc(sizeof(LSE));
    n->value = value;
    n->prox = NULL;
    return n;
}

LSE *novaLista()
{
    LSE *l = (LSE *)calloc(1, sizeof(LSE));
    if (!l)
    {
        printf("Erro de alocacao de memoria.\n");
        exit(1);
    }
    return l;
}

void insereInicio(LSE *l, int value)
{
    LSE *novo = criaNo(value);
    novo->prox = l->prox;
    l->prox = novo;
}

void insereFim(LSE *l, int value)
{
    LSE *novo = criaNo(value);
    LSE *aux = l;
    while (aux->prox)
        aux = aux->prox;

    aux->prox = novo;
}

LSE *busca(LSE *l, int value, LSE **prev)
{
    LSE *aux = l->prox;
    *prev = l;
    while (aux && aux->value < value)
    {
        *prev = aux;
        aux = aux->prox;
    }
    return aux;
}

void insereOrdenado(LSE *l, int value)
{
    LSE *novo = criaNo(value);
    LSE *prev = NULL;
    LSE *atual = busca(l, value, &prev);
    novo->prox = atual;
    prev->prox = novo;
}

void imprimeLista(LSE *l)
{
    LSE *aux = l->prox;
    while (aux)
    {
        printf("%d ", aux->value);
        aux = aux->prox;
    }
    printf("\n");
}

void removeInicio(LSE *l)
{
    LSE *aux = l->prox;
    if (aux)
    {
        l->prox = aux->prox;
        free(aux);
    }
}

void removeFim(LSE *l)
{
    LSE *aux = l->prox;
    LSE *prev = l;
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

void liberaLista(LSE *l)
{
    while (l)
    {
        LSE *n = l;
        l = l->prox;
        free(n);
    }
}