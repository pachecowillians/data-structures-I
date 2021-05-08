#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct ArvoreNariaPalavras
{
    struct ArvoreNariaPalavras *filho[26]; //Cada letra pode ser seguida de 26 possibilidades de letras (vetor de ponteiros para subárvores)
    int fimPalavra;                        //Indica se aquela posição indica o fim de uma palavra
} No;

No *CriaNo()
{
    No *n = (No *)malloc(sizeof(No));
    n->fimPalavra = 0;
    for (int i = 0; i < 26; i++)
    {
        n->filho[i] = NULL;
    }
    return n;
}

No *Inicializa()
{
    return CriaNo(); //Inicia com um nó base, já que as palavras podem começar com 26 letras distintas
}

void InserePalavraArvore(No *raiz, char *palavra)
{
    for (int i = 0; i < strlen(palavra); i++)
    {
        int posicao = (palavra[i] >= 'a' && palavra[i]<='z') ? (int)palavra[i] - (int)'a' : (int)palavra[i] - (int)'A';
        if (!raiz->filho[posicao])
        {
            raiz->filho[posicao] = CriaNo();
        }
        raiz = raiz->filho[posicao];
    }
    raiz->fimPalavra = 1;
}

void ImprimeArvore(No *raiz)
{
    if (raiz == NULL)
    {
        return;
    }
    else
    {
        for (int i = 0; i < 26; i++)
        {
            if (raiz->filho[i])
            {
                printf("%c( ", (int)i + (int)'a');
                ImprimeArvore(raiz->filho[i]);
                printf(") ");
            }
        }
    }
}

int BuscaPalavra(No *raiz, char *palavra)
{
    for (int i = 0; i < strlen(palavra); i++)
    {
        int posicao = (palavra[i] >= 'a' && palavra[i]<='z') ? (int)palavra[i] - (int)'a' : (int)palavra[i] - (int)'A';
        if (raiz->filho[posicao])
        {
            raiz = raiz->filho[posicao];
        }
        else
        {
            return 0;
        }
    }
    return raiz->fimPalavra;
}

int main()
{
    No *a = Inicializa();
    InserePalavraArvore(a, "Palavra");
    InserePalavraArvore(a, "pedra");
    InserePalavraArvore(a, "fogo");
    InserePalavraArvore(a, "forno");
    InserePalavraArvore(a, "feira");
    ImprimeArvore(a);
    printf("%d", BuscaPalavra(a, "palavra"));
}