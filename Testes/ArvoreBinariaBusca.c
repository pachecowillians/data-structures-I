#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct no
{
    int info;
    struct no *esq;
    struct no *dir;
} No;

typedef struct arvoreBinariaBusca
{
    No *raiz;
} ArvoreBuscaBinaria;

ArvoreBuscaBinaria *CriaArvore()
{
    ArvoreBuscaBinaria *a = (ArvoreBuscaBinaria *)malloc(sizeof(ArvoreBuscaBinaria));
    a->raiz = NULL;
    return a;
}

No *CriaNo(int val)
{
    No *n = (No *)malloc(sizeof(No));
    n->info = val;
    n->dir = NULL;
    n->esq = NULL;
    return n;
}

No *InsereNo(No *a, No *n)
{
    if (a == NULL)
    {
        return n;
    }
    else
    {
        if (n->info < a->info)
        {
            a->esq = InsereNo(a->esq, n);
        }
        else
        {
            a->dir = InsereNo(a->dir, n);
        }
        return a;
    }
}

void ImprimeArvore(No *a)
{
    if (a)
    {
        printf("%d( ", a->info);
        ImprimeArvore(a->esq);
        ImprimeArvore(a->dir);
        printf(") ");
    }
    else
    {
        printf("(x) ");
    }
}

int NumeroElementos(No *a)
{
    if (a == NULL)
    {
        return 0;
    }
    else
    {
        return NumeroElementos(a->dir) + 1 + NumeroElementos(a->esq);
    }
}

int Altura(No *a)
{
    if (!a)
    {
        return 0;
    }
    else
    {
        int SomaEsquerda = 1 + Altura(a->esq);
        int SomaDireita = 1 + Altura(a->dir);
        return (SomaDireita > SomaEsquerda) ? SomaDireita : SomaEsquerda;
    }
}

No *RemoveElemento(No *raiz, int val)
{
    if (!raiz)
    {
        return NULL;
    }
    else
    {
        No *paiDoRemovido = NULL;            // Pai do elemento removido
        No *removido = NULL;                 // Elemento removido
        No *noDireitaSE = NULL;              // Nó mais a direita da subarvore esquerda
        No *paiNoDireitaSE = NULL;           // Pai do nó mais a direita da subarvore esquerda
        No *filhoEsquerdaNoDireitaSE = NULL; // Filho da esquerda do nó mais a direita da subarvore esquerda
        No *i = raiz;
        while (i)
        {
            if (i->info == val) // Se achou o valor
            {
                removido = i;
                if (i->esq)
                {
                    paiNoDireitaSE = i;
                }
                i = i->esq; //Vai para a SAE para começar a buscar o elemento mais a direita
            }
            else if (!removido) //Se não achou ainda
            {
                paiDoRemovido = i;
                if (val < i->info) //Percorre a arvore em busca binária
                {
                    i = i->esq;
                }
                else
                {
                    i = i->dir;
                }
            }
            else if (removido)
            {
                if (i->dir != NULL && i->dir->dir == NULL)
                {
                    paiNoDireitaSE = i;
                }
                if (i->dir == NULL)
                {
                    noDireitaSE = i;
                }
                i = i->dir;
            }
        }

        if (noDireitaSE && noDireitaSE->esq != NULL)
        {
            filhoEsquerdaNoDireitaSE = noDireitaSE->esq;
        }
        /*
        printf("\n\n%p", removido);
        printf("\n%p", paiDoRemovido);
        printf("\n%p", noDireitaSE);
        printf("\n%p", paiNoDireitaSE);
        printf("\n%p", filhoEsquerdaNoDireitaSE);*/

        //Começa a remoção
        if (noDireitaSE) //Se tiver um nó mais a direita da subarvore esquerda
        {
            if (paiNoDireitaSE != removido)
            {
                noDireitaSE->esq = removido->esq;
                noDireitaSE->dir = removido->dir;
                paiNoDireitaSE->dir = filhoEsquerdaNoDireitaSE;
            }
            else
            {
                noDireitaSE->dir = removido->dir;
                paiNoDireitaSE->dir = filhoEsquerdaNoDireitaSE;
            }
        }
        else
        {
            if (paiDoRemovido)
            {
                if (paiDoRemovido->dir == removido)
                {
                    paiDoRemovido->dir = removido->dir;
                    
                }
                else if (paiDoRemovido->esq == removido)
                {
                    paiDoRemovido->esq = removido->dir; // Não tem a esquerda, se tiver a direita, vai receber o valor e se não tiver, recebe null
                }
            }
        }
        if (paiDoRemovido && paiDoRemovido->esq == removido) //Se um filho estiver de um lado ou do outro do pai
        {
            paiDoRemovido->esq = noDireitaSE;
        }
        else if (paiDoRemovido && paiDoRemovido->dir == removido)
        {
            paiDoRemovido->dir = noDireitaSE;
        }
        No *direitaRemovido = removido->dir;
        free(removido);
        if (!paiDoRemovido) //Remove raiz
        {
            return (noDireitaSE) ? noDireitaSE : direitaRemovido;
        }
        else
        {
            return raiz;
        }
    }
}

int main()
{
    ArvoreBuscaBinaria *a = CriaArvore();
    a->raiz = InsereNo(a->raiz, CriaNo(50));
    a->raiz = InsereNo(a->raiz, CriaNo(25));
    a->raiz = InsereNo(a->raiz, CriaNo(10));
    a->raiz = InsereNo(a->raiz, CriaNo(30));
    a->raiz = InsereNo(a->raiz, CriaNo(5));
    a->raiz = InsereNo(a->raiz, CriaNo(35));
    a->raiz = InsereNo(a->raiz, CriaNo(1));
    a->raiz = InsereNo(a->raiz, CriaNo(40));
    a->raiz = InsereNo(a->raiz, CriaNo(75));
    a->raiz = InsereNo(a->raiz, CriaNo(60));
    a->raiz = InsereNo(a->raiz, CriaNo(90));
    a->raiz = InsereNo(a->raiz, CriaNo(55));
    a->raiz = InsereNo(a->raiz, CriaNo(95));
    a->raiz = InsereNo(a->raiz, CriaNo(51));
    a->raiz = InsereNo(a->raiz, CriaNo(99));
    a->raiz = InsereNo(a->raiz, CriaNo(61));
    a->raiz = InsereNo(a->raiz, CriaNo(57));
    a->raiz = InsereNo(a->raiz, CriaNo(56));
    a->raiz = InsereNo(a->raiz, CriaNo(59));
    a->raiz = InsereNo(a->raiz, CriaNo(58));

    ImprimeArvore(a->raiz);
    printf("\nNumeroElementos: %d", NumeroElementos(a->raiz));
    printf("\nAltura: %d", Altura(a->raiz));
    a->raiz = RemoveElemento(a->raiz, 50);
    a->raiz = RemoveElemento(a->raiz, 25);
    a->raiz = RemoveElemento(a->raiz, 10);
    a->raiz = RemoveElemento(a->raiz, 30);
    a->raiz = RemoveElemento(a->raiz, 5);
    a->raiz = RemoveElemento(a->raiz, 35);
    a->raiz = RemoveElemento(a->raiz, 1);
    a->raiz = RemoveElemento(a->raiz, 40);
    a->raiz = RemoveElemento(a->raiz, 75);
    a->raiz = RemoveElemento(a->raiz, 60);
    a->raiz = RemoveElemento(a->raiz, 90);
    a->raiz = RemoveElemento(a->raiz, 55);
    a->raiz = RemoveElemento(a->raiz, 95);
    a->raiz = RemoveElemento(a->raiz, 51);
    a->raiz = RemoveElemento(a->raiz, 99);
    a->raiz = RemoveElemento(a->raiz, 61);
    a->raiz = RemoveElemento(a->raiz, 57);
    a->raiz = RemoveElemento(a->raiz, 56);
    a->raiz = RemoveElemento(a->raiz, 59);
    a->raiz = RemoveElemento(a->raiz, 58);

    printf("\n");
    ImprimeArvore(a->raiz);
    printf("\nNumeroElementos: %d", NumeroElementos(a->raiz));
    printf("\nAltura: %d", Altura(a->raiz));
}