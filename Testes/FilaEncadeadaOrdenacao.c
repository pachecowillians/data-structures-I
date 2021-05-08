#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct no
{
    int info;
    struct no *prox;
} No;

typedef struct filaEncadeada
{
    No *prim;
    No *ultimo;
} FilaEncadeada;

FilaEncadeada *CriaFila()
{
    FilaEncadeada *f = (FilaEncadeada *)malloc(sizeof(FilaEncadeada));
    f->prim = NULL;
    f->ultimo = NULL;
    return f;
}

No *CriaNo(int val)
{
    No *n = (No *)malloc(sizeof(No));
    n->info = val;
    n->prox = NULL;
    return n;
}

void InsereFila(FilaEncadeada *f, No *n)
{
    if (f->prim == NULL && f->ultimo == NULL)
    {
        f->prim = n;
        f->ultimo = n;
    }
    else
    {
        f->ultimo->prox = n;
        f->ultimo = n;
    }
}

int RemoveFila(FilaEncadeada *f)
{
    No *removido = f->prim;
    f->prim = f->prim->prox;
    if (f->prim == NULL)
    {
        f->ultimo = NULL;
    }
    int val = removido->info;
    free(removido);
    return val;
}

void ImprimeFila(FilaEncadeada *f)
{
    for (No *i = f->prim; i != NULL; i = i->prox)
    {
        printf("%d ", i->info);
    }
}

void Troca(FilaEncadeada *f, int val)
{
    No *i = f->prim;
    FilaEncadeada *fAux = CriaFila();
    int ValErrado;
    while (i != NULL)
    {
        if (i->info == val)
        {
            i = i->prox;
            ValErrado = RemoveFila(f);
        }
        else
        {
            i = i->prox;
            InsereFila(fAux, CriaNo(RemoveFila(f)));
        }
    }
    i = fAux->prim;
    int ValorRemovido = -1;
    while (fAux->prim != NULL)
    {
        ValorRemovido = fAux->prim->info;
        if (ValorRemovido < ValErrado)
        {
            i = i->prox;
            InsereFila(f, CriaNo(RemoveFila(fAux)));
        }
        else if (ValErrado != -1 && ValorRemovido > ValErrado)
        {
            InsereFila(f, CriaNo(ValErrado));
            ValErrado = -1;
        }
        else
        {
            i = i->prox;
            InsereFila(f, CriaNo(RemoveFila(fAux)));
        }
    }
    if (ValErrado != -1)
    {
        InsereFila(f, CriaNo(ValErrado));
    }
}

void Ordena(FilaEncadeada *f)
{
    No *i = f->prim;
    int maior = -1, menor = -1;
    while (i != NULL)
    {
        if (i == f->prim)
        {
            maior = i->info;
            menor = i->info;
        }
        else
        {
            if (i->info > maior)
            {
                maior = i->info;
            }
            if (i->info < menor)
            {
                menor = i->info;
            }
        }
        i = i->prox;
    }

    while (f->prim->info != menor || f->ultimo->info != maior)
    {
        i = f->prim;

        while (i != NULL)
        {
            if (i->prox != NULL && i->info > i->prox->info)
            {
                Troca(f, i->info);
            }
            i = i->prox;
        }
    }
}

int main()
{
    FilaEncadeada *f = CriaFila();
    InsereFila(f, CriaNo(3));
    InsereFila(f, CriaNo(2));
    InsereFila(f, CriaNo(4));
    InsereFila(f, CriaNo(1));
    ImprimeFila(f);
    printf("\n");
    Ordena(f);
    ImprimeFila(f);
}