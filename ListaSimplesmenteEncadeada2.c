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

No *concatena(No *l1, No *l2)
{
    if (!l1)
    {
        return NULL;
    }
    No *aux = l1;
    while (aux->prox)
    {
        aux = aux->prox;
    }
    aux->prox = l2;
    return l1;
}

No *removeRepeticoes(No *l)
{
    No *aux = l;
    while (aux)
    {
        No *aux2 = aux->prox;
        No *anterior = NULL;
        while (aux2)
        {
            if (aux2->chave == aux->chave)
            {
                No *removido = aux2;
                if (anterior)
                {
                    anterior->prox = aux2->prox;
                }
                else
                {
                    aux->prox = aux2->prox;
                }
                aux2 = aux2->prox;
                free(removido);
            }
            else
            {
                anterior = aux2;
                aux2 = aux2->prox;
            }
        }
        aux = aux->prox;
    }
    return l;
}

No *removeRepeticoesOrdenada(No *l)
{
    No *atual = l;
    No *anterior = NULL;
    while (atual)
    {
        if (anterior && anterior->chave == atual->chave)
        {
            No *removido = atual;
            anterior->prox = atual->prox;
            atual = atual->prox;
            free(removido);
        }
        else
        {
            anterior = atual;
            atual = atual->prox;
        }
    }
    return l;
}

//f(n)  = 4 + (n + m)*7
//O(n + m)

No *fusao(No *l1, No *l2)
{
    No *aux1 = l1; //1
    No *aux2 = l2; //1
    No *l3 = NULL; //1
    No *aux3 = l3; //1

    while (aux1 || aux2) //n + m + 1
    {
        if (aux1 && aux2) //1
        {
            if (aux1->chave < aux2->chave) //1
            {
                if (!aux3) //1
                {
                    l3 = aux1;   //1
                    aux3 = aux1; //1
                }
                else
                {
                    aux3->prox = aux1; //1
                    aux3 = aux3->prox; //1
                }
                aux1 = aux1->prox; //1
            }
            else
            {
                if (!aux3) //1
                {
                    l3 = aux2;   //1
                    aux3 = aux2; //1
                }
                else
                {
                    aux3->prox = aux2; //1
                    aux3 = aux3->prox; //1
                }
                aux2 = aux2->prox; //1
            }
        }
        else if (aux1) //1
        {
            aux3->prox = aux1; //1
            aux1 = NULL;       //1
        }
        else
        {
            aux3->prox = aux2; //1
            aux2 = NULL;       //1
        }
    }
    return l3;
}

No *removeTodosValores(No *l, int value)
{
    No *atual = l;
    No *anterior = NULL;
    while (atual)
    {
        if (atual->chave == value)
        {
            if (!anterior)
            {
                No *removido = atual;
                l = atual->prox;
                atual = atual->prox;
                free(removido);
            }
            else
            {
                No *removido = atual;
                anterior->prox = atual->prox;
                atual = atual->prox;
                free(removido);
            }
        }
        else
        {
            anterior = atual;
            atual = atual->prox;
        }
    }
    return l;
}

No *removeUmValor(No *l, int value)
{
    No *atual = l;
    No *anterior = NULL;
    while (atual)
    {
        if (atual->chave == value)
        {
            if (!anterior)
            {
                No *removido = atual;
                l = atual->prox;
                atual = atual->prox;
                atual = NULL;
            }
            else
            {
                No *removido = atual;
                anterior->prox = atual->prox;
                free(removido);
                atual = NULL;
            }
        }
        else
        {
            anterior = atual;
            atual = atual->prox;
        }
    }
    return l;
}

int main()
{
    No *l1 = NULL;
    No *l2 = NULL;

    l1 = insereOrdenado(l1, 2);
    l1 = insereOrdenado(l1, 3);
    l1 = insereOrdenado(l1, 6);
    l1 = insereOrdenado(l1, 1);
    l1 = insereOrdenado(l1, 8);

    l2 = insereOrdenado(l2, 2);
    l2 = insereOrdenado(l2, 2);
    l2 = insereOrdenado(l2, 6);
    l2 = insereOrdenado(l2, 2);
    l2 = insereOrdenado(l2, 8);
    l2 = insereOrdenado(l2, 8);
    l2 = insereOrdenado(l2, 8);

    No *l = NULL;
    //l = concatena(l1, l2);
    l = fusao(l1, l2);
    //l = removeRepeticoes(l);
    //l = removeRepeticoesOrdenada(l);
    l = removeTodosValores(l, 8);
    l = removeUmValor(l, 2);
    imprimeLista(l);
}