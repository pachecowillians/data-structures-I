#include "fila.h"

Fila *criaFila()
{
    Fila *f = (Fila *)malloc(sizeof(Fila));

    if (f)
    {
        f->numElementos = 0;
        f->fila = (LDE *)calloc(1, sizeof(LDE));
    }
    else
    {
        printf("Erro de alocacao de memoria.\n");
        exit(1);
    }

    return f;
}

void push(Fila *f, int value)
{
    insereInicio(f->fila, value);
    f->numElementos++;
}

int empty(Fila *f)
{
    return listaVazia(f->fila);
}

int size(Fila *f)
{
    return f->numElementos;
}

int front(Fila *f)
{
    return ultimoElemento(f->fila);
}

void pop(Fila *f)
{
    if (!empty(f))
    {
        removeFim(f->fila);
        f->numElementos--;
    }
}

void print(Fila *f)
{
    imprime(f->fila);
}

void libera(Fila *f)
{
    liberaLista(f->fila);
    f->fila = NULL;
}