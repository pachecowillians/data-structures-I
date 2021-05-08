#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listaCircularDuplamenteEncadeada{
    int info;
    struct listaCircularDuplamenteEncadeada *next;
    struct listaCircularDuplamenteEncadeada *prev;
}ListaCircularDuplamenteEncadeada;

ListaCircularDuplamenteEncadeada * CriaLista(){
    return NULL;
}

ListaCircularDuplamenteEncadeada * InsereLista(ListaCircularDuplamenteEncadeada *l, int v){
    ListaCircularDuplamenteEncadeada *lista = malloc(sizeof(ListaCircularDuplamenteEncadeada));
    if (l == NULL){
        lista->info = v;
        lista->next = lista;
        lista->prev = lista;
    }else{
        lista->info = v;
        lista->next = l;
        lista->prev = l->prev;
        l->prev->next = lista;
        l->prev = lista;
    }
    return lista;
}

ListaCircularDuplamenteEncadeada * RemoveLista(ListaCircularDuplamenteEncadeada *l, int v){
    ListaCircularDuplamenteEncadeada *p = l;
    do{
        p = p->next;
    } while (p->info != v && p != l); 
    if (p->info==v){
        p->prev->next = p->next;
        p->next->prev = p->prev;
        free(p);
    }
    return l;
    
}

void ImprimeListaCrescente(ListaCircularDuplamenteEncadeada *l){
    ListaCircularDuplamenteEncadeada *p = l;
    do{
        printf("\n%d", p->info);
        p = p->next;
    } while (p != l);   
}

void ImprimeListaDecrescente(ListaCircularDuplamenteEncadeada *l){
    ListaCircularDuplamenteEncadeada *p = l;
    do{
        printf("\n%d", p->info);
        p = p->prev;
    } while (p != l);   
}

int main(){
    ListaCircularDuplamenteEncadeada *l = CriaLista();
    l = InsereLista(l,1);
    l = InsereLista(l,2);
    l = InsereLista(l,3);
    l = InsereLista(l,4);
    l = RemoveLista(l,3);
    ImprimeListaCrescente(l);
    printf("\n");
    ImprimeListaDecrescente(l);
}