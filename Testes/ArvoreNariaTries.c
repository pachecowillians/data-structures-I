#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct no
{
    struct no *filhos[26];
    int fim;
} No;

No *CriaNovoNo()
{
    No *p = malloc(sizeof(No));
    if (p)
    {
        p->fim = 0;
        for (int i = 0; i < 26; i++)
        {
            p->filhos[i] = NULL;
        }
    }
    return p;
}

No *Inicializa()
{
    return CriaNovoNo();
}

int MapearIndice(char c)
{
    char a = (c >= 'a' && c <= 'z') ? (int)'a' : (int)'A';
    return (int)c - (int)a;
}

void Insere(No *raiz, char *chave)
{
    int nivel;
    int compr = strlen(chave);
    int i;
    No *p = raiz;
    for (nivel = 0; nivel < compr; nivel++)
    {
        i = MapearIndice(chave[nivel]);
        if (!p->filhos[i])
        {
            p->filhos[i] = CriaNovoNo();
        }
        p = p->filhos[i];
    }
    p->fim = 1;
}

int Busca(No *raiz, char *chave)
{
    int nivel;
    int compr = strlen(chave);
    int i;
    No *p = raiz;
    for (nivel = 0; nivel < compr; nivel++)
    {
        i = MapearIndice(chave[nivel]);
        if (!p->filhos[i])
        {
            return 0;
        }
        p = p->filhos[i];
    }
    return p->fim;
}

void ImprimeArvore(No *raiz)
{
    if (raiz == NULL)
    {
        return;
    }
    No *p;
    for (int i = 0; i < 26; i++)
    {

        if (raiz->filhos[i])
        {
            printf("%c(", (int)i + (int)'a');
            p = raiz->filhos[i];
            ImprimeArvore(p);
            printf(")");
        }
    }
}

int main()
{
    No *n = Inicializa();
    Insere(n, "Palavra");
    Insere(n, "Box");
    Insere(n, "Boxeador");
    Insere(n, "Bicicleta");
    Insere(n, "Binario");
    //printf("%d", Busca(n, "palav"));
    ImprimeArvore(n);
}
