#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct pilha
{
    struct no *prim;
} Pilha;

typedef struct no
{
    float info;
    struct no *next;
} No;

Pilha *CriaPilha()
{
    Pilha *p = malloc(sizeof(Pilha));
    p->prim = NULL;
    return p;
}

Pilha *RemovePilha(Pilha *p)
{
    No *n = p->prim;
    p->prim = n->next;
    free(n);
    return p;
}

Pilha *Numero(Pilha *p, float value)
{
    No *n = malloc(sizeof(No));
    n->info = value;
    n->next = p->prim;
    p->prim = n;
    return p;
}

Pilha *Operador(Pilha *p, char operador)
{
    float n1, n2;
    switch (operador)
    {
    case '+':
        n1 = p->prim->info;
        p = RemovePilha(p);
        n2 = p->prim->info;
        p = RemovePilha(p);

        p = Numero(p, n1 + n2);
        return p;
        break;

    case '-':
        n1 = p->prim->info;
        p = RemovePilha(p);
        n2 = p->prim->info;
        p = RemovePilha(p);

        p = Numero(p, n1 - n2);
        return p;
        break;

    case '*':
        n1 = p->prim->info;
        p = RemovePilha(p);
        n2 = p->prim->info;
        p = RemovePilha(p);

        p = Numero(p, n1 * n2);
        return p;
        break;

    case '/':
        n1 = p->prim->info;
        p = RemovePilha(p);
        n2 = p->prim->info;
        p = RemovePilha(p);

        p = Numero(p, n1 / n2);
        return p;
        break;

    default:
        return p;
        break;
    }
}

void ImprimePilha(Pilha *p)
{
    for (No *i = (No *)p->prim; i != NULL; i = i->next)
    {
        printf("\n%.2f", i->info);
    }
}

Pilha *Calcula(Pilha *p, char *expressao)
{
    for (int i = 0; i < strlen(expressao); i++)
    {
        
        if (expressao[i]>='0' && expressao[i]<='9')
        {
            if (i!=0 && expressao[i-1]>='0' && expressao[i-1]<='9')
            {
                int n = p->prim->info;
                p = RemovePilha(p);
                int value = expressao[i]-'0';
                p = Numero(p,value+n*10);
            }else{
                int value = expressao[i]-'0';
                p = Numero(p,value);
            }
            
            
        }else if (expressao[i]=='+' || expressao[i]=='-' || expressao[i]=='*' || expressao[i]=='/')
        {
            p = Operador(p,expressao[i]);
        }
        
    }
    return p;
}

int main()
{
    char expressao[50];
    Pilha *p = CriaPilha();
    system("clear");
    printf("CALCULADORA PÓS FIXADA\n");
    printf("\n\nEscreva a expressão: \n");
    __fpurge(stdin);
    scanf("%[^\n]", expressao);
    p = Calcula(p, expressao);
    ImprimePilha(p);
}