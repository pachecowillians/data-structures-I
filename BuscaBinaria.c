#include "stdio.h"
#include "stdlib.h"

int BuscaBinaria(int value, int *v, int size)
{
    int i = size / 2;
    int posicaoInicial = 0;
    int posicaoFinal = size;
    while (v[i] != value && i != 0 && i != size - 1 && !(v[i + 1] > value && v[i - 1] < value)) //Se valor final for menor que o inicial tb pode ajudar
    {
        if (v[i] < value)
        {
            posicaoInicial = i;
            i += (posicaoFinal - posicaoInicial) / 2;
        }
        else
        {
            posicaoFinal = i;
            i -= (posicaoFinal - posicaoInicial) / 2;
        }
    }
    if (v[i] != value)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int BuscaBinariaRecursiva(int value, int *v, int size) //Colocar mais parametros ajuda
{
    size /= 2;
    if (v[size] == value)
    {
        return 1;
    }
    else if (size == 1)
    {
        return 0;
    }
    else if (v[size] > value)
    {
        return BuscaBinariaRecursiva(value, v, size);
    }
    else
    {
        return BuscaBinariaRecursiva(value, &v[size], size);
    }
}

int main()
{
    int n = 21;
    int *v = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        v[i] = i;
    }
    printf("%d\n", BuscaBinaria(20, v, n));
    printf("%d\n", BuscaBinariaRecursiva(19, v, n));
    free(v);
}