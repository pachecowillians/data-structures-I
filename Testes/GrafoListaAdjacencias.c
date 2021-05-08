#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct adjacencia
{
    int vertice;
    int peso;
    struct adjacencia *prox;
} Adjacencia;

typedef struct vertice
{
    Adjacencia *prim;
} Vertice;

typedef struct grafo
{
    int vertices;
    int arestas;
    Vertice *adj;
} Grafo;

Grafo *CriaGrafo(int v)
{
    Grafo *g = malloc(sizeof(Grafo));
    g->vertices = v;
    g->arestas = 0;
    g->adj = (Vertice *)malloc(v * sizeof(Vertice));
    for (int i = 0; i < v; i++)
    {
        g->adj[i].prim = NULL;
    }
    return g;
}

Adjacencia *CriaAdj(int v, int peso)
{
    Adjacencia *temp = (Adjacencia *)malloc(sizeof(Adjacencia));
    temp->vertice = v;
    temp->peso = peso;
    temp->prox = NULL;
    return temp;
}

int CriaAresta(Grafo *g, int vi, int vf, int peso)
{
    if (!g)
    {
        return 0;
    }
    if ((vf < 0) || vf >= g->vertices)
    {
        return 0;
    }
    if ((vi < 0) || vi >= g->vertices)
    {
        return 0;
    }
    Adjacencia *novo = CriaAdj(vf, peso);
    novo->prox = g->adj[vi].prim;
    g->adj[vi].prim = novo;
    (g->arestas)++;
    return 1;
}

void ImprimeGrafo(Grafo *g)
{
    printf("Vértices: %d. Arestas: %d.\n", g->vertices, g->arestas);
    for (int i = 0; i < g->vertices; i++)
    {
        printf("v%d: ", i);
        Adjacencia *a = g->adj[i].prim;
        while (a)
        {
            printf("v%d(%d) ", a->vertice, a->peso);
            a = a->prox;
        }
        printf("\n");
    }
}

int main()
{
    Grafo *g = CriaGrafo(5);

    CriaAresta(g,0,1,2);
    CriaAresta(g,1,2,4);
    CriaAresta(g,2,0,12);
    CriaAresta(g,2,4,40);
    CriaAresta(g,3,1,3);
    CriaAresta(g,4,3,8);

    ImprimeGrafo(g);
}