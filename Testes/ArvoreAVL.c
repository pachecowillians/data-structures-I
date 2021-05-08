#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct arvoreAVL
{
    int info;
    struct arvoreAVL *dir, *esq;
    int h;
} No, *Pno;

Pno CriaNo(int val)
{
    Pno no = malloc(sizeof(No));
    no->dir = NULL;
    no->esq = NULL;
    no->h = 0;
    no->info = val;
}

Pno Inicializa()
{
    return NULL;
}

int Max(int a, int b)
{
    return (a > b) ? a : b;
}

int Altura(Pno raiz)
{
    if (!raiz)
    {
        return -1;
    }
    return raiz->h;
}

Pno RotacionaDireita(Pno r)
{
    Pno aux;
    aux = r->esq;
    r->esq = aux->dir;
    aux->dir = r;

    r->h = Max(Altura(r->dir), Altura(r->esq)) + 1;
    aux->h = Max(Altura(aux->esq), r->h) + 1;

    return aux;
}

Pno RotacionaEsquerda(Pno r)
{
    Pno aux;
    aux = r->dir;
    r->dir = aux->esq;
    aux->esq = r;

    r->h = Max(Altura(r->dir), Altura(r->esq)) + 1;
    aux->h = Max(Altura(aux->dir), r->h) + 1;

    return aux;
}

Pno RotacionaEsquerdaDireita(Pno r)
{
    r->esq = RotacionaEsquerda(r->esq);
    return RotacionaDireita(r);
}

Pno RotacionaDireitaEsquerda(Pno r)
{
    r->dir = RotacionaDireita(r->dir);
    return RotacionaEsquerda(r);
}

Pno Insere(Pno raiz, int val)
{
    if (!raiz)
    {
        return CriaNo(val);
    }
    if (val < raiz->info)
    {
        raiz->esq = Insere(raiz->esq, val);
        if (Altura(raiz->esq) - Altura(raiz->dir) == 2)
        {
            if (val < raiz->esq->info)
            {
                raiz = RotacionaDireita(raiz);
            }
            else
            {
                raiz = RotacionaEsquerdaDireita(raiz);
            }
        }
    }
    else
    {
        if (val > raiz->info)
        {
            raiz->dir = Insere(raiz->dir, val);
            if (Altura(raiz->dir) - Altura(raiz->esq) == 2)
            {
                if (val > raiz->dir->info)
                {
                    raiz = RotacionaEsquerda(raiz);
                }
                else
                {
                    raiz = RotacionaDireitaEsquerda(raiz);
                }
            }
        }
    }
    raiz->h = Max(Altura(raiz->esq), Altura(raiz->dir)) + 1;
    return raiz;
}

void ImprimeArvore(Pno a)
{
    if (a != NULL)
    {
        printf("%d", a->info);
        printf("( ");
        ImprimeArvore(a->esq);
        ImprimeArvore(a->dir);
        printf(") ");
    }
    else
    {
        printf("(x) ");
    }
}

int main()
{
    Pno a = Inicializa();
    a = Insere(a, 1);
    a = Insere(a, 4);
    a = Insere(a, 5);
    a = Insere(a, 2);
    ImprimeArvore(a);
}