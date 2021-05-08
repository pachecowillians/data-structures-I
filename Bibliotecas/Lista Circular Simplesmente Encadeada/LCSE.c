#include "LCSE.h"

LCSE *criaNo(int value)
{
    LCSE *novo = (LCSE *)malloc(sizeof(LCSE));

    if (!novo)
    {
        printf("deu ruim.");
        exit(1);
    }
    else
    {
        novo->value = value;
        novo->prox = NULL;
    }

    return novo;
}

void insereInicio(LCSE **l, int value)
{
    LCSE *novo = criaNo(value);
    if (!(*l))
    {
        novo->prox = novo;
        *l = novo;
    }
    else
    {
        novo->prox = (*l)->prox;
        (*l)->prox = novo;
    }
}

void insereFim(LCSE **l, int value)
{
    LCSE *novo = criaNo(value);
    if (!(*l))
    {
        novo->prox = novo;
        (*l) = novo;
    }
    else
    {
        novo->prox = (*l)->prox;
        (*l)->prox = novo;
        (*l) = novo;
    }
}

void removeInicio(LCSE **l)
{
    if ((*l))
    {
        LCSE *removido = (*l)->prox;
        if (removido && removido->prox && removido->prox != removido)
        {
            (*l)->prox = removido->prox;
        }
        else
        {
            (*l) = NULL;
        }
        free(removido);
    }
}

void removeFim(LCSE **l)
{
    if ((*l))
    {
        LCSE *anterior = (*l)->prox;
        if (anterior->prox == anterior)
        {
            free(anterior);
            (*l) = NULL;
        }
        else
        {
            while (anterior->prox != (*l))
            {
                anterior = anterior->prox;
            }

            anterior->prox = (*l)->prox;
            free((*l));
            (*l) = anterior;
        }
    }
}

void imprimeLista(LCSE **l)
{
    if (*l)
    {
        LCSE *aux = (*l)->prox;
        do
        {
            printf("%d ", aux->value);
            aux = aux->prox;
        } while (aux != (*l)->prox);
        printf("\n");
    }
}

void liberaLista(LCSE **l)
{
    if (*l)
    {
        LCSE *r = (*l);
        (*l) = (*l)->prox;
        r->prox = NULL;

        while ((*l))
        {
            LCSE *n = (*l);
            (*l) = (*l)->prox;
            free(n);
        }
    }
}