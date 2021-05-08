#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct arvoreBinaria
{
    int info;
    struct arvoreBinaria *sae;
    struct arvoreBinaria *sad;
} ArvoreBinaria;

ArvoreBinaria *Inicializa()
{
    return NULL;
}

ArvoreBinaria *InsereArvore(ArvoreBinaria *raiz, ArvoreBinaria *no)
{
    if (raiz == NULL)
    {
        return no;
    }
    if (no->info < raiz->info)
    {
        raiz->sae = InsereArvore(raiz->sae, no);
    }
    else
    {
        raiz->sad = InsereArvore(raiz->sad, no);
    }
    return raiz;
}

ArvoreBinaria *CriaNo(int val)
{
    ArvoreBinaria *no = malloc(sizeof(ArvoreBinaria));
    no->info = val;
    no->sad = NULL;
    no->sae = NULL;
    return no;
}

void ImprimeArvore(ArvoreBinaria *a)
{
    if (a != NULL)
    {
        printf("%d", a->info);
        printf("( ");
        ImprimeArvore(a->sae);
        ImprimeArvore(a->sad);
        printf(") ");
    }
    else
    {
        printf("(x) ");
    }
}

ArvoreBinaria *BuscaBinaria(ArvoreBinaria *a, int val)
{
    if (a == NULL)
    {
        return NULL;
    }
    else
    {
        if (a->info == val)
        {
            return a;
        }
        else
        {
            if (a->info > val)
            {
                return BuscaBinaria(a->sae, val);
            }
            else
            {
                return BuscaBinaria(a->sad, val);
            }
        }
    }
}

int NumeroNos(ArvoreBinaria *raiz)
{
    if (raiz == NULL)
    {
        return 0;
    }
    else
    {
        return NumeroNos(raiz->sae) + 1 + NumeroNos(raiz->sad);
    }
}

ArvoreBinaria *BuscaNo(ArvoreBinaria *raiz, int val, ArvoreBinaria **pai)
{
    ArvoreBinaria *atual = raiz;
    *pai = NULL;
    while (atual)
    {
        if (atual->info == val)
        {
            return atual;
        }
        *pai = atual;
        if (val < atual->info)
        {
            atual = atual->sae;
        }
        else
        {
            atual = atual->sad;
        }
    }
    return NULL;
}

ArvoreBinaria *RemoveNo(ArvoreBinaria *raiz, int val)
{
    ArvoreBinaria *pai, *no, *p, *q;
    no = BuscaNo(raiz, val, &pai);
    if (no == NULL)
    {
        return raiz;
    }
    if (!no->sad || !no->sae)
    {
        if (!no->sae)
        {
            q = no->sad;
        }
        else
        {
            q = no->sae;
        }
    }
    else
    {
        p = no;
        q = no->sae;
        while (q->sad)
        {
            p = q;
            q = q->sad;
        }
        if (p != no)
        {
            p->sad = q->sae;
            q->sae = no->sae;
        }
        q->sad = no->sad;
    }
    if (!pai)
    {
        free(no);
        return q;
    }
    if (val < pai->info)
    {
        pai->sae = q;
    }
    else
    {
        pai->sad = q;
    }
    free(no);
    return raiz;
}

int Altura(ArvoreBinaria *a)
{
    if (a != NULL)
    {
        int somaEsquerda = 1 + Altura(a->sae);
        int somaDireita = 1 + Altura(a->sad);
        return (somaEsquerda > somaDireita) ? somaEsquerda : somaDireita;
    }
    else
    {
        return 0;
    }
}

int main()
{
    ArvoreBinaria *a = Inicializa();
    a = InsereArvore(a, CriaNo(5));
    a = InsereArvore(a, CriaNo(2));
    a = InsereArvore(a, CriaNo(6));
    a = InsereArvore(a, CriaNo(1));
    a = InsereArvore(a, CriaNo(3));
    a = InsereArvore(a, CriaNo(4));
    ImprimeArvore(a);
    printf("\nAltura (Nós): %d", Altura(a));
    /*
    ArvoreBinaria *val = BuscaBinaria(a, 2);
    printf("%d", val->info);
    printf("\n%d", NumeroNos(a));
    printf("\n");
    ImprimeArvore(a);
    RemoveNo(a, 2);
    printf("\n");
    ImprimeArvore(a);*/
}