#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int value;
    struct no *prox;
} No;

typedef struct base
{
    No *primeiro;
    No *ultimo;
    struct base *proxLinha;
} Base;

No *criaNo(int value)
{
    No *novo = (No *)malloc(sizeof(No));
    novo->value = value;
    novo->prox = NULL;
    return novo;
}

Base *criaBase()
{
    Base *nova = (Base *)calloc(1, sizeof(Base));
    return nova;
}

No *busca(Base *l, int val, No **prev)
{
    No *aux = l->primeiro;
    *prev = NULL;
    while (aux && aux->value < val)
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

void insereLinha(Base *m, Base *l)
{
    Base *aux = m;
    while (aux->proxLinha)
    {
        aux = aux->proxLinha;
    }
    aux->proxLinha = l;
}

void imprimeLista(Base *l)
{
    No *aux = l->primeiro;
    while (aux)
    {
        printf("%d ", aux->value);
        aux = aux->prox;
    }
}

void imprimeMatriz(Base *l)
{
    Base *auxb = l;
    while (auxb)
    {
        No *aux = auxb->primeiro;
        while (aux)
        {
            printf("%d ", aux->value);
            aux = aux->prox;
        }
        printf("\n");
        auxb = auxb->proxLinha;
    }
}

int main()
{
    Base *m = criaBase();
    Base *l1 = criaBase();

    insereOrdenado(l1, 3);
    insereOrdenado(l1, 1);
    insereOrdenado(l1, 4);
    insereOrdenado(l1, 0);

    Base *l2 = criaBase();

    insereOrdenado(l2, 8);
    insereOrdenado(l2, 5);
    insereOrdenado(l2, 1);

     Base *l3 = criaBase();

    insereOrdenado(l3, 17);
    insereOrdenado(l3, 5);
    insereOrdenado(l3, 65);
    insereOrdenado(l3, 10);
    insereOrdenado(l3, 0);

    insereLinha(m, l1);
    insereLinha(m, l2);
    insereLinha(m, l3);

    imprimeMatriz(m);
}