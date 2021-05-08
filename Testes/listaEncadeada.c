#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct lista
{
    int info;
    struct lista *next;
} Lista;

Lista *CriaLista()
{
    return NULL;
}

Lista *InsereInicioLista(Lista *l, int valor)
{
    Lista *no = (Lista *)malloc(sizeof(Lista));
    no->info = valor;
    no->next = l;
    return no;
}

Lista *InsereListaOrdenada(Lista *l, int valor)
{
    Lista *no = (Lista *)malloc(sizeof(Lista));
    Lista *prev = NULL;
    Lista *i = l;

    while (i != NULL && valor > i->info){
        prev = i;
        i = i->next;
    }
    if (prev == NULL){
        no->info = valor;
        no->next = i;
        return no;
    }else{
        prev->next = no;
        no->next = i;
        no->info = valor;
        return l;
    }
}


Lista * RemoverElementoLista(Lista *l, int valor){
    Lista *prev = NULL;
    Lista *i = l;
    while (i!= NULL){
        if (i->info == valor && prev != NULL){
            prev->next = i->next;
            free(i);
            return l;
        }else if(i->info == valor && prev == NULL){
            l = i->next;
            free(i);
            return l;
        }
        prev = i;
        i = i->next;
    }   
    free(i);
    return l; 
}

void ImprimirLista(Lista *l)
{
    for (Lista *i = l; i != NULL; i = i->next)
    {
        printf("\n%d", i->info);
    }
}

int main()
{
    Lista *l = CriaLista();
    //l = InsereInicioLista(l, 3);
    //l = InsereInicioLista(l, 2);
    //l = InsereInicioLista(l, 1);
    l = InsereListaOrdenada(l,4);
    l = InsereListaOrdenada(l,2);
    l = InsereListaOrdenada(l,8);
    l = InsereListaOrdenada(l,1);
    l = InsereListaOrdenada(l,112);
    l = InsereListaOrdenada(l,56);
    l = InsereListaOrdenada(l,32);
    //l = RemoverElementoLista(l,112);
    ImprimirLista(l);
}