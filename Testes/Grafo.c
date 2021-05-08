#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct no
{
    int info;
    struct no *prox;
} No;

typedef struct listaDeLigacoes
{
    No *prim;
} ListaDeLigacoes;

typedef struct grafo
{
    int numNos;
    int numLigacoes;
    ListaDeLigacoes *ligacoes;
} Grafo;

Grafo *CriaGrafo(int numNos)
{
    Grafo *g = (Grafo *)malloc(sizeof(Grafo));
    g->numNos = numNos;
    g->numLigacoes = 0;
    g->ligacoes = (ListaDeLigacoes *)malloc(numNos * sizeof(ListaDeLigacoes));
    for (int i = 0; i < numNos; i++)
    {
        g->ligacoes[i].prim = NULL;
    }

    return g;
}

No *CriaNo(int val)
{
    No *n = (No *)malloc(sizeof(No));
    n->info = val;
    n->prox = NULL;
    return n;
}

void InsereLigacao(Grafo *g, int inicio, int fim)
{
    int inicioVetor = inicio -1;
    if (!g->ligacoes[inicioVetor].prim)
    {
        g->ligacoes[inicioVetor].prim = CriaNo(fim);
        (g->numLigacoes)++;
    }
    else
    {
        No *primeiro = g->ligacoes[inicioVetor].prim;
        No *novoNo = CriaNo(fim);

        novoNo->prox = primeiro;
        g->ligacoes[inicioVetor].prim = novoNo;
        (g->numLigacoes)++;
    }
}

void ImprimeGrafo(Grafo *g)
{
    printf("Grafo:\n");
    for (int i = 0; i < g->numNos; i++)
    {
        printf("\n%d: ",i+1);
        No *j = g->ligacoes[i].prim;
        while (j)
        {
            printf("%d ", j->info);
            j = j->prox;
        }
    }
}

int main()
{
    Grafo *g = CriaGrafo(5);
    InsereLigacao(g, 1, 2);
    InsereLigacao(g, 1, 3);
    InsereLigacao(g, 1, 4);
    InsereLigacao(g, 3, 4);
    InsereLigacao(g, 4, 1);
    InsereLigacao(g, 4, 5);
    InsereLigacao(g, 5, 2);
    InsereLigacao(g, 2, 3);
    ImprimeGrafo(g);
}