#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int info;
    struct no *prox;
    struct no *prev;

} No;

No *criaNo(int value)
{
    No *novo = (No *)malloc(sizeof(No));
    if (!novo)
    {
        printf("errou");
        exit(1);
    }
    else
    {
        novo->info = value;
        novo->prox = NULL;
        novo->prev = NULL;
    }
    return novo;
}

No *insereInicio(No *l, int value)
{
    No *novo = criaNo(value);
    if (!l)
    {
        novo->prev = novo;
        novo->prox = novo;
        l = novo;
    }
    else
    {
        novo->prox = l->prox;
        novo->prev = l;
        l->prox = novo;
        l->prox->prev = novo;
    }
    return l;
}

No *insereFim(No *l, int value)
{
    No *novo = criaNo(value);
    if (!l)
    {
        novo->prev = novo;
        novo->prox = novo;
        l = novo;
    }
    else
    {
        novo->prox = l->prox;
        novo->prev = l;
        l->prox = novo;
        l->prox->prev = novo;
        l = novo;
    }
    return l;
}

No *removeInicio(No *l)
{
    if (l)
    {
        No *removido = l->prox;
        if (removido && removido->prox && removido->prox != removido)
        {
            l->prox = removido->prox;
            removido->prox->prev = l;
        }
        else
        {
            l = NULL;
        }
        free(removido);
    }
    return l;
}

No *removeFim(No *l)
{
    if (l)
    {
        No *anterior = l->prox;
        if (anterior->prox == anterior)
        {
            free(anterior);
            l = NULL;
        }
        else
        {
            while (anterior->prox != l)
            {
                anterior = anterior->prox;
            }

            anterior->prox = l->prox;
            l->prox->prev = anterior;
            free(l);
            l = anterior;
        }
    }
    return l;
}
void imprimeLista(No *l)
{
    if (l)
    {
        No *aux = l->prox;
        do
        {
            printf("%d ", aux->info);
            aux = aux->prox;
        } while (aux != l->prox);
    }
}

int main()
{
    No *l = NULL;
    l = insereFim(l, 1);
    l = insereFim(l, 2);
    l = insereFim(l, 1);
    l = insereFim(l, 1);
    l = removeFim(l);
    l = removeFim(l);
    l = removeFim(l);
    l = removeFim(l);
    l = removeFim(l);

    imprimeLista(l);
}