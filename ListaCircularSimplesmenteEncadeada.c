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

No *insereInicio(No *l, int chave)
{
    No *novo = criaNo(chave);
    if (!l)
    {
        novo->prox = novo;
        l = novo;
    }
    else
    {
        novo->prox = l->prox;
        l->prox = novo;
    }

    return l;
}

No *insereFim(No *l, int chave)
{
    No *novo = criaNo(chave);
    if (!l)
    {
        novo->prox = novo;
        l = novo;
    }
    else
    {
        novo->prox = l->prox;
        l->prox = novo;
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
            printf("%d ", aux->chave);
            aux = aux->prox;
        } while (aux != l->prox);
    }
}

int main()
{
    No *l = NULL;
    l = insereFim(l, 2);
    l = insereFim(l, 3);
    l = insereFim(l, 4);
    l = removeFim(l);
    l = removeFim(l);
    l = removeFim(l);

    imprimeLista(l);
}