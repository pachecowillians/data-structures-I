#include "LCDE.h"

LCDE *criaNo(int value)
{
    LCDE *novo = (LCDE *)malloc(sizeof(LCDE));
    if (!novo)
    {
        printf("errou");
        exit(1);
    }
    else
    {
        novo->value = value;
        novo->prox = NULL;
        novo->prev = NULL;
    }
    return novo;
}

void insereInicio(LCDE **l, int value)
{
    LCDE *novo = criaNo(value);

    if (!(*l))
    {
        novo->prev = novo;
        novo->prox = novo;
        (*l) = novo;
    }
    else
    {
        novo->prox = (*l)->prox;
        novo->prev = (*l);
        (*l)->prox = novo;
        (*l)->prox->prev = novo;
    }
}

void insereFim(LCDE **l, int value)
{
    LCDE *novo = criaNo(value);

    if (!(*l))
    {
        novo->prev = novo;
        novo->prox = novo;
        (*l) = novo;
    }
    else
    {
        novo->prox = (*l)->prox;
        novo->prev = (*l);
        (*l)->prox = novo;
        (*l)->prox->prev = novo;
        (*l) = novo;
    }
}

void removeInicio(LCDE **l)
{
    if ((*l))
    {
        LCDE *removido = (*l)->prox;
        if (removido && removido->prox && removido->prox != removido)
        {
            (*l)->prox = removido->prox;
            removido->prox->prev = (*l);
        }
        else
        {
            (*l) = NULL;
        }
        free(removido);
    }
}

void removeFim(LCDE **l)
{
    if ((*l))
    {
        LCDE *anterior = (*l)->prox;
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
            (*l)->prox->prev = anterior;
            free((*l));
            (*l) = anterior;
        }
    }
}

void imprimeLista(LCDE **l)
{
    if ((*l))
    {
        LCDE *aux = (*l)->prox;
        do
        {
            printf("%d ", aux->value);
            aux = aux->prox;
        } while (aux != (*l)->prox);
    }
    printf("\n");
}

void liberaLista(LCDE **l)
{
    if (*l)
    {
        LCDE *r = (*l);
        (*l) = (*l)->prox;
        r->prox = NULL;

        while ((*l))
        {
            LCDE *n = (*l);
            (*l) = (*l)->prox;
            free(n);
        }
    }
}
