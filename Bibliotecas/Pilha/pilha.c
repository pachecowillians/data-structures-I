#include "pilha.h"

Pilha *novaPilha()
{
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    if (p)
    {
        p->numElementos = 0;
        p->pilha = novaLista();
    }
    else
    {
        printf("Erro de alocacao de memoria.\n");
        exit(1);
    }
    return p;
}

void push(Pilha *p, int value)
{
    insereInicio(p->pilha, value);
    p->numElementos++;
}

void pop(Pilha *p)
{
    removeInicio(p->pilha);
    p->numElementos--;
}

int top(Pilha *p)
{
    return primeiroElemento(p->pilha);
}

void libera(Pilha *p)
{
    liberaLista(p->pilha);
    p->pilha = NULL;
}

int tamanho(Pilha *p)
{
    return p->numElementos;
}

void imprime(Pilha *p)
{
    imprimeLista(p->pilha);
}