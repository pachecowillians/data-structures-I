#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct ArvoreAVL
{
    int info;
    int altura;
    struct ArvoreAVL *dir;
    struct ArvoreAVL *esq;
} No;

No *CriaArvore()
{
    return NULL;
}

No *CriaNo(int val)
{
    No *n = (No *)malloc(sizeof(No));
    n->info = val;
    n->altura = 0;
    n->dir = NULL;
    n->esq = NULL;
    return n;
}

int CalculaAlturaNo(No *raiz)
{
    if (raiz)
    {
        int alturaEsquerda = 1 + CalculaAlturaNo(raiz->esq);
        int alturaDireita = 1 + CalculaAlturaNo(raiz->dir);

        return (alturaDireita > alturaEsquerda) ? alturaDireita : alturaEsquerda;
    }
    else
    {
        return -1;
    }
}

No *InsereArvore(No *raiz, No *n)
{
    if (!raiz)
    {
        n->altura = CalculaAlturaNo(raiz);
        return n;
    }
    else
    {
        if (n->info < raiz->info)
        {
            raiz->esq = InsereArvore(raiz->esq, n);
        }
        else
        {
            raiz->dir = InsereArvore(raiz->dir, n);
        }
        return raiz;
    }
}

void ImprimeArvore(No *raiz)
{
    if (raiz)
    {
        printf("%d( ", raiz->info);
        ImprimeArvore(raiz->esq);
        ImprimeArvore(raiz->dir);
        printf(") ");
    }
    else
    {
        printf("(x) ");
    }
}

No *RotacionaDireita(No *raiz)
{
    No *filho = raiz->esq;
    raiz->esq = filho->dir;
    filho->dir = raiz;
    filho->altura = CalculaAlturaNo(filho);
    raiz->altura = CalculaAlturaNo(raiz);
    return filho; //Filho vai subir na arvore
}

No *RotacionaEsquerda(No *raiz)
{
    No *filho = raiz->dir;
    raiz->dir = filho->esq;
    filho->esq = raiz;
    filho->altura = CalculaAlturaNo(filho);
    raiz->altura = CalculaAlturaNo(raiz);
    return filho; //Filho vai subir na arvore
}

No *RotacionaEsquerdaDireita(No *raiz)
{
    raiz->esq = RotacionaEsquerda(raiz->esq);
    return RotacionaDireita(raiz);
}

No *RotacionaDireitaEsquerda(No *raiz)
{
    raiz->dir = RotacionaDireita(raiz->dir);
    return RotacionaEsquerda(raiz);
}

int NoBalanceado(No *n)
{
    int val = CalculaAlturaNo(n->esq) - CalculaAlturaNo(n->dir);
    return (val >= -1 && val <= 1) ? 1 : 0;
}

No *Balanceamento(No *raiz)
{
    if (raiz)
    {
        int AlturaEsq = CalculaAlturaNo(raiz->esq);
        int alturaDir = CalculaAlturaNo(raiz->dir);
        int fatBalanceamento = AlturaEsq - alturaDir;
        if (NoBalanceado(raiz) == 0)
        {
            if (AlturaEsq < alturaDir && !NoBalanceado(raiz->dir))
            {
                return RotacionaDireitaEsquerda(raiz);
            }
            if (AlturaEsq > alturaDir && !NoBalanceado(raiz->esq))
            {
                return RotacionaEsquerdaDireita(raiz);
            }
            if (AlturaEsq > alturaDir && alturaDir ==0)
            {
                return RotacionaEsquerdaDireita(raiz);
            }
            if (alturaDir > AlturaEsq && AlturaEsq ==0)
            {
                return RotacionaDireitaEsquerda(raiz);
            }
            if (AlturaEsq > alturaDir && alturaDir ==-1)
            {
                return RotacionaEsquerdaDireita(raiz);
            }
            if (alturaDir > AlturaEsq && AlturaEsq ==-1)
            {
                return RotacionaDireitaEsquerda(raiz);
            }
            if (AlturaEsq > alturaDir)
            {
                return RotacionaDireita(raiz);
            }
            if (AlturaEsq < alturaDir)
            {
                return RotacionaEsquerda(raiz);
            }
        }
        raiz->esq = Balanceamento(raiz->esq);
        raiz->dir = Balanceamento(raiz->dir);
    }
    else
    {
        return raiz;
    }
}

int ArvoreBalanceada(No *raiz)
{
    if (raiz)
    {
        if (NoBalanceado(raiz)==0)
        {
            return 0;
        }
        int SomaEsquerda = ArvoreBalanceada(raiz->esq);
        int SomaDireita = ArvoreBalanceada(raiz->dir);
        if (SomaEsquerda == 0 || SomaDireita == 0)
        {
            return 0;
        }
        
    }
    else
    {
        return 1;
    }
}

No *BalanceiaArvore(No *raiz)
{
    do
    {
        raiz = Balanceamento(raiz);
    } while (ArvoreBalanceada(raiz) == 0);
    return raiz;
}

int main()
{
    No *a = CriaArvore();
    a = InsereArvore(a, CriaNo(50));
    a = InsereArvore(a, CriaNo(17));
    a = InsereArvore(a, CriaNo(76));
    a = InsereArvore(a, CriaNo(9));
    a = InsereArvore(a, CriaNo(23));
    a = InsereArvore(a, CriaNo(54));
    a = InsereArvore(a, CriaNo(14));
    a = InsereArvore(a, CriaNo(19));
    a = InsereArvore(a, CriaNo(72));
    a = InsereArvore(a, CriaNo(12));
    a = InsereArvore(a, CriaNo(67));

    ImprimeArvore(a);
    printf("\n\n");

    a = BalanceiaArvore(a);

    ImprimeArvore(a);
    printf("\n");
}
