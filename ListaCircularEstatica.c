#include <stdio.h>
#include <stdlib.h>

void insereInicio(int *l, int *inicio, int *fim, int *numElementos, int total, int chave)
{
    if (*numElementos < total)
    {
        if (*numElementos == 0)
            l[*inicio] = chave;
        else
        {
            (*inicio)--;
            if (*inicio < 0)
                *inicio = total - 1;
            l[*inicio] = chave;
        }
        (*numElementos)++;
    }
}

void insereFim(int *l, int *inicio, int *fim, int *numElementos, int total, int chave)
{
    if (*numElementos < total)
    {
        if (*numElementos == 0)
            l[*fim] = chave;
        else
        {
            (*fim)++;
            if (*fim == total)
                *fim = 0;
            l[*fim] = chave;
        }
        (*numElementos)++;
    }
}

void removeFim(int *l, int *inicio, int *fim, int *numElementos, int total)
{
    if (*numElementos > 0)
    {
        (*numElementos)--;
        (*fim)--;
        if (*fim < 0)
            *fim = total - 1;
    }
}

void removeInicio(int *l, int *inicio, int *fim, int *numElementos, int total)
{
    if (*numElementos > 0)
    {
        (*numElementos)--;
        (*inicio)++;
        if (*inicio == total)
            *inicio = 0;
    }
}

void imprimeLista(int *lista, int *inicio, int *fim, int total, int numElementos)
{
    int aux = *inicio;
    int cont = 0;

    while (cont < numElementos)
    {
        printf("%d ", lista[aux]);
        aux++;
        cont++;
        if (aux >= total)
            aux = 0;
    }
}

int main()
{
    int lista[20];
    int total = 20;
    int inicio = 0;
    int fim = 0;
    int numElementos = 0;
    insereFim(lista, &inicio, &fim, &numElementos, total, 4);
    insereFim(lista, &inicio, &fim, &numElementos, total, 5);
    insereFim(lista, &inicio, &fim, &numElementos, total, 6);
    insereFim(lista, &inicio, &fim, &numElementos, total, 7);
    insereFim(lista, &inicio, &fim, &numElementos, total, 8);
    removeFim(lista, &inicio, &fim, &numElementos, total);
    removeFim(lista, &inicio, &fim, &numElementos, total);
    removeInicio(lista, &inicio, &fim, &numElementos, total);
    removeInicio(lista, &inicio, &fim, &numElementos, total);

    imprimeLista(lista, &inicio, &fim, total, numElementos);
}