#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "matriz.h"

struct matriz
{
    int l, c;
    float *v;
};
Matriz *cria(int m, int n)
{
    Matriz *mat = (Matriz *)malloc(sizeof(Matriz));
    if (mat == NULL)
    {
        printf("Memória insuficiente.");
        exit(1);
    }
    mat->l = m;
    mat->c = n;
    mat->v = (float *)malloc(m * n * sizeof(float));

    return mat;
}
void libera(Matriz *mat)
{
    free(mat);
}
float acessa(Matriz *mat, int i, int j)
{
    int k;
    /* índice do elemento no vetor */
    if (i < 0 || i >= mat->l || j < 0 || j >= mat->c)
    {
        printf("Acesso inválido!\n");
        exit(1);
    }
    k = i * mat->c + j;
    return mat->v[k];
}

void atribui(Matriz *mat, int i, int j, float v)
{
    int k;
    /* índice do elemento no vetor */
    if (i < 0 || i >= mat->l || j < 0 || j >= mat->c)
    {
        printf("Atribuição inválida!\n");
        exit(1);
    }
    k = i * mat->c + j;
    mat->v[k] = v;
}
int linhas(Matriz *mat)
{
    return mat->l;
}
int colunas(Matriz *mat)
{
    return mat->c;
}
