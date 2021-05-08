#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct arvoreNaria
{
    int info;
    struct arvoreNaria *primfilho;
    struct arvoreNaria *prox;
} ArvoreNaria;

ArvoreNaria *CriaNovoNo(int val)
{
    ArvoreNaria *no = malloc(sizeof(ArvoreNaria));
    no->info = val;
    no->primfilho = NULL;
    no->prox = NULL;
    return no;
}

ArvoreNaria *Inicializa(int val)
{
    return CriaNovoNo(val);
}

ArvoreNaria *BuscaChave(ArvoreNaria *raiz, int val)
{
    if (raiz == NULL)
    {
        return NULL;
    }
    if (raiz->info == val)
    {
        return raiz;
    }
    ArvoreNaria *p = raiz->primfilho;
    while (p)
    {
        ArvoreNaria *resp = BuscaChave(p, val);
        if (resp)
        {
            return resp;
        }
        p = p->prox;
    }
    return NULL;
}

int Insere(ArvoreNaria *raiz, int val, int valPai)
{
    ArvoreNaria *pai = BuscaChave(raiz, valPai);
    if (!pai)
    {
        return 0;
    }
    ArvoreNaria *filho = CriaNovoNo(val);
    ArvoreNaria *p = pai->primfilho;
    if (!p)
    {
        pai->primfilho = filho;
    }
    else
    {
        while (p->prox)
        {
            p = p->prox;
        }
        p->prox = filho;
    }
    return 1;
}

void ImprimeArvore(ArvoreNaria *raiz)
{
    if (raiz == NULL)
    {
        return;
    }
    printf("%d(", raiz->info);
    ArvoreNaria *p = raiz->primfilho;
    while (p)
    {
        ImprimeArvore(p);
        p = p->prox;
    }
    printf(")");
}

int main()
{
    ArvoreNaria *a = Inicializa(8);
    Insere(a,1,8);
    Insere(a,2,8);
    Insere(a,3,8);
    Insere(a,4,8);
    Insere(a,5,1);
    Insere(a,6,4);
    ImprimeArvore(a);
}