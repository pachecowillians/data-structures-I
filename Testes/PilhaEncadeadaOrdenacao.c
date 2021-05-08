#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct no
{
    int info;
    struct no *prox;
} No;

typedef struct pilhaEncadeada
{
    No *topo;
} PilhaEncadeada;

PilhaEncadeada *CriaPilha()
{
    PilhaEncadeada *p = (PilhaEncadeada *)malloc(sizeof(PilhaEncadeada));
    p->topo = NULL;
    return p;
}

No *CriaNo(int val)
{
    No *n = (No *)malloc(sizeof(No));
    n->info = val;
    n->prox = NULL;
    return n;
}

void Push(PilhaEncadeada *p, No *n)
{
    n->prox = p->topo;
    p->topo = n;
}

int Pop(PilhaEncadeada *p)
{
    No *removido = p->topo;
    int val = removido->info;
    p->topo = p->topo->prox;
    free(removido);
    return val;
}

void ImprimePilha(PilhaEncadeada *p)
{
    for (No *i = p->topo; i != NULL; i = i->prox)
    {
        printf("%d ", i->info);
    }
}

void TrocaMenor(PilhaEncadeada *p, int val)
{
    PilhaEncadeada *pAux = CriaPilha();
    No *i = p->topo;
    while (i->info != val)
    {
        i = i->prox;
        Push(pAux, CriaNo(Pop(p)));
    }
    int valTrocado = Pop(p);
    while (pAux->topo != NULL)
    {
        int vPop = Pop(pAux);
        if (valTrocado < vPop)
        {
            Push(p, CriaNo(vPop));
        }
        else if (valTrocado > vPop)
        {
            Push(pAux, CriaNo(vPop));
            Push(p, CriaNo(valTrocado));
            valTrocado = -1;
        }
    }
    if (valTrocado > 0)
    {
        Push(p, CriaNo(valTrocado));
    }
}

void Ordena(PilhaEncadeada *p)
{
    No *i = p->topo;
    while (i != NULL)
    {
        if (i->prox != NULL && i->prox->info < i->info)
        {
            TrocaMenor(p,i->prox->info);
        }else{
            i = i->prox;
        }
    }
}

int main()
{
    PilhaEncadeada *p = CriaPilha();
    Push(p, CriaNo(1));
    Push(p, CriaNo(5));
    Push(p, CriaNo(3));
    Push(p, CriaNo(8));
    Push(p, CriaNo(2));
    Push(p, CriaNo(4));
    ImprimePilha(p);
    printf("\n");
    Ordena(p);
    ImprimePilha(p);
}
