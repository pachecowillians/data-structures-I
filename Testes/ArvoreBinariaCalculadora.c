#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct arvoreBinaria
{
    int info;
    struct arvoreBinaria *dir;
    struct arvoreBinaria *esq;
} No;

No *Inicializa()
{
    return NULL;
}

No *CriaNo(int val)
{
    No *n = (No *)malloc(sizeof(No));
    n->info = val;
    n->dir = NULL;
    n->esq = NULL;
    return n;
}

int Numero(char val)
{
    return val >= '0' && val <= '9';
}

int Operador(char val)
{
    return val == '+' || val == '-' || val == '*' || val == '/';
}

int ConverteParaNumero(char val)
{
    return (int)val - (int)'0';
}

int ConverteParaChar(char val)
{
    return (int)val + (int)'0';
}

char *RemoveEspacos(char *expressao)
{
    int cont = 0;
    for (int i = 0; i < strlen(expressao); i++)
    {
        if (expressao[i] != ' ')
        {
            cont++;
        }
    }
    char *expressaoSemEspaco = (char *)malloc(cont * sizeof(char));
    cont = 0;
    for (int i = 0; i < strlen(expressao); i++)
    {
        if (expressao[i] != ' ')
        {
            expressaoSemEspaco[cont] = expressao[i];
            cont++;
        }
    }
    return expressaoSemEspaco;
}

No *CriaArvore(int pai, int n1, int n2)
{
    No *raiz = CriaNo(pai);
    raiz->esq = CriaNo(n1);
    raiz->dir = CriaNo(n2);
    return raiz;
}

No *UneArvores(No *a1, No *a2, int operacao)
{
    No *raiz = CriaNo(operacao);
    raiz->esq = a1;
    raiz->dir = a2;
    return raiz;
}

No *InsereArvore(No *raiz, char *expressao)
{
    int n1 = 0, n2 = 0;
    char operador, operadorLigacao;
    No *a = NULL;
    for (int i = 0; i < strlen(expressao); i++)
    {
        if (Numero(expressao[i]) == 1)
        {
            if (n1 == 0 && n2 == 0)
            {
                n1 = ConverteParaNumero(expressao[i]);
            }
            else if (n1 != 0 && n2 == 0)
            {
                if (expressao[i - 1] && Numero(expressao[i - 1]) == 1)
                {
                    n1 *= 10;
                    n1 += ConverteParaNumero(expressao[i]);
                }
                else if (expressao[i - 1] && Numero(expressao[i - 1]) == 0)
                {
                    n2 = ConverteParaNumero(expressao[i]);
                }
            }
            else if (n1 != 0 && n2 != 0)
            {
                n2 *= 10;
                n2 += ConverteParaNumero(expressao[i]);
            }
            if (n1 != 0 && i + 1 == strlen(expressao))
            {
                if (n2 != 0)
                {
                    a = UneArvores(a, CriaArvore(ConverteParaNumero(operador), n1, n2), ConverteParaNumero(operadorLigacao));
                }
                else
                {
                    a = UneArvores(a, CriaNo(n1), ConverteParaNumero(operador));
                }
                n1 = 0;
                n2 = 0;
            }
        }
        else
        {
            if (n1 != 0 && n2 == 0 && expressao[i-1] && Numero(expressao[i-1]))
            {
                operador = expressao[i];
            }
            if (n1 == 0 && n2 == 0 && Operador(expressao[i]) == 1)
            {
                operadorLigacao = expressao[i];
            }

            if (n1 != 0 && n2 != 0 && operador != 0)
            {
                if (!a)
                {
                    a = CriaArvore(ConverteParaNumero(operador), n1, n2);
                }
                else
                {
                    a = UneArvores(a, CriaArvore(ConverteParaNumero(operador), n1, n2), ConverteParaNumero(operadorLigacao));
                    operador = 0;
                    operadorLigacao = 0;
                }

                n1 = 0;
                n2 = 0;
            }
            if (n1 != 0 && n2 == 0 && !Operador(expressao[i]) && operador == 0)
            {
                a = UneArvores(a, CriaNo(n1), ConverteParaNumero(operadorLigacao));
                n1 = 0;
                n2 = 0;
            }            
        }
    }
    return a;
}

void ImprimeArvore(No *raiz)
{
    if (raiz)
    {
        if (raiz->dir == NULL)
        {
            printf("%d( ", raiz->info);
        }
        else
        {
            printf("%c( ", ConverteParaChar(raiz->info));
        }

        ImprimeArvore(raiz->esq);
        ImprimeArvore(raiz->dir);
        printf(") ");
    }
}

int main()
{ //IMPORTANTE! -> Os números sempre serão folhas
    char expressao[50] = " ((( 42 + 3 )* 9)+5) / (8-3) * (1+6)";
    No *n = Inicializa();
    char *expressaoSemEspaco = RemoveEspacos(expressao);
    n = InsereArvore(n, expressaoSemEspaco);
    ImprimeArvore(n);
} 