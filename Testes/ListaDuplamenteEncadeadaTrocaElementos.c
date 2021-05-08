#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct no
{
    int info;
    struct no *prox;
    struct no *prev;

} No;

typedef struct listaDuplamenteEncadeada
{
    No *prim;
    No *ultimo;
} ListaDuplamenteEncadeada;

ListaDuplamenteEncadeada *CriaLista()
{
    ListaDuplamenteEncadeada *l = (ListaDuplamenteEncadeada *)malloc(sizeof(ListaDuplamenteEncadeada));
    l->prim = NULL;
    l->ultimo = NULL;
    return l;
}

No *CriaNo(int val)
{
    No *n = (No *)malloc(sizeof(No));
    n->info = val;
    n->prox = NULL;
    n->prev = NULL;
    return n;
}

void InsereLista(ListaDuplamenteEncadeada *l, No *n)
{
    if (l->prim != NULL)
    {
        l->prim->prev = n;
    }
    n->prox = l->prim;
    n->prev = NULL;
    l->prim = n;
    if (l->prim != NULL && l->prim->prox == NULL)
    {
        l->ultimo = n;
    }
}

void RemoveLista(ListaDuplamenteEncadeada *l, int val)
{
    for (No *i = l->prim; i != NULL; i = i->prox)
    {
        if (i->info == val)
        {
            No *anterior = i->prev;
            No *proximo = i->prox;
            No *removido = i;
            if (anterior != NULL)
            {
                anterior->prox = proximo;
            }
            else
            {
                l->prim = proximo;
            }
            if (proximo != NULL)
            {
                proximo->prev = anterior;
            }
            else
            {
                l->ultimo = anterior;
            }
            free(removido);
        }
    }
}

void ImprimeListaAscendente(ListaDuplamenteEncadeada *l)
{
    for (No *i = l->prim; i != NULL; i = i->prox)
    {
        printf("%d ", i->info);
    }
}

void ImprimeListaDescendente(ListaDuplamenteEncadeada *l)
{
    for (No *i = l->ultimo; i != NULL; i = i->prev)
    {
        printf("%d ", i->info);
    }
}

void Troca(ListaDuplamenteEncadeada *l, int v1, int v2)
{
    No *nv1 = NULL, *anteriorv1, *proximov1, *nv2 = NULL, *anteriorv2, *proximov2;
    for (No *i = l->prim; i != NULL && (nv1 == NULL || nv2 == NULL); i = i->prox)
    {
        if (i->info == v1)
        {
            nv1 = i;
            anteriorv1 = i->prev;
            proximov1 = i->prox;
        }
        if (i->info == v2)
        {
            nv2 = i;
            anteriorv2 = i->prev;
            proximov2 = i->prox;
        }
    }

    if (nv1->prox == nv2 || nv1->prev == nv2) //Vizinhos
    {

        if (nv1->prox == nv2) // v1 -> v2
        {
            if (!anteriorv1 || !proximov2)
            {
                if (anteriorv1) // v2 = ultimo
                {
                    anteriorv1->prox = nv2;
                    l->ultimo = nv1;
                }
                if (proximov2) // v1 = primeiro
                {
                    proximov2->prev = nv1;
                    l->prim = nv2;
                }
            }
            else
            {
                anteriorv1->prox = nv2;
                proximov2->prev = nv1;
            }
            nv2->prev = anteriorv1;
            nv2->prox = nv1;

            nv1->prox = proximov2;
            nv1->prev = nv2;
        }
        else
        { // v2 -> v1

            if (!anteriorv2 || !proximov1)
            {
                if (anteriorv2) // v1 = ultimo
                {
                    anteriorv2->prox = nv1;
                    l->ultimo = nv2;
                }
                if (proximov1) // v2 = primeiro
                {
                    proximov1->prev = nv2;
                    l->prim = nv1;
                }
            }
            else
            {
                anteriorv2->prox = nv1;
                proximov1->prev = nv2;
            }

            nv2->prox = proximov1;
            nv2->prev = nv1;

            nv1->prev = anteriorv2;
            nv1->prox = nv2;
        }
    }
    else
    {
        if (!anteriorv2 || !proximov1 || !anteriorv1 || !proximov2)
        {
            if (anteriorv2)
            {
                anteriorv2->prox = nv1;
            }
            else
            {
                l->prim = nv1;
            }
            if (proximov1)
            {
                proximov1->prev = nv2;
            }
            else
            {
                l->ultimo = nv2;
            }
            if (anteriorv1)
            {
                anteriorv1->prox = nv2;
            }
            else
            {
                l->prim = nv2;
            }
            if (proximov2)
            {
                proximov2->prev = nv1;
            }
            else
            {
                l->ultimo = nv1;
            }
        }
        else
        {
            anteriorv2->prox = nv1;
            proximov1->prev = nv2;
            anteriorv1->prox = nv2;
            proximov2->prev = nv1;
        }
        nv2->prev = anteriorv1;
        nv2->prox = proximov1;

        nv1->prox = proximov2;
        nv1->prev = anteriorv2;
    }
}

void Ordena(ListaDuplamenteEncadeada *l)
{
    int menor = -1;
    int maior = -1;
    for (No *i = l->prim; i != NULL; i = i->prox)
    {
        if (i == l->prim)
        {
            menor = i->info;
            maior = i->info;
        }
        else
        {
            if (i->info < menor)
            {
                menor = i->info;
            }
            if (i->info > maior)
            {
                maior = i->info;
            }
        }
    }
    while (l->prim->info != menor || l->ultimo->info != maior)
    {
        for (No *i = l->prim; i != NULL; i = i->prox)
        {
            if (i->prox != NULL && i->info > i->prox->info)
            {
                printf("\n");
                ImprimeListaAscendente(l);
                printf("\n");
                printf("Troca %d por %d\n", i->info, i->prox->info);
                Troca(l, i->info, i->prox->info);
            }
        }
    }
}

int main()
{
    ListaDuplamenteEncadeada *l = CriaLista();
    InsereLista(l, CriaNo(2));
    InsereLista(l, CriaNo(4));
    InsereLista(l, CriaNo(1));
    InsereLista(l, CriaNo(5));
    InsereLista(l, CriaNo(6));
    InsereLista(l, CriaNo(3));
    InsereLista(l, CriaNo(9));
    //Testando função troca
    ImprimeListaAscendente(l);
    printf("\n");
    ImprimeListaDescendente(l);
    printf("\n\n");
    Troca(l, 6, 2);
    ImprimeListaAscendente(l);
    printf("\n");
    ImprimeListaDescendente(l);

    //Ordenando o vetor com a função troca

    printf("\n\n");
    ImprimeListaAscendente(l);
    printf("\n");
    Ordena(l);
    printf("\n");
    ImprimeListaAscendente(l);
}