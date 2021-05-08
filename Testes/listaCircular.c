#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listaCircular{
    int info;
    struct listaCircular *next;
}ListaCircular;

ListaCircular * CriaLista(){
    return NULL;
}

ListaCircular * InsereLista(ListaCircular *l, int v){
    ListaCircular *lista = malloc(sizeof(ListaCircular));
    if (l == NULL){
        lista->info = v;
        lista->next = lista;
    }else{
        lista->info = v;
        ListaCircular *p = l;
        do{
            p = p->next;
        } while (p->next != l); 
        p->next = lista;
        lista->next = l;
    }
    return lista;
}

ListaCircular * RemoveLista(ListaCircular *l, int v){
    ListaCircular *p = l;
    ListaCircular *elem;
    do{
        p = p->next;
    } while (p->next->info != v && p->next != l); 
    if (p->next->info==v){
        elem = p->next;
        p->next = elem->next;
        free(elem);
    }
    return p->next;
    
}

void ImprimeLista(ListaCircular *l){
    ListaCircular *p = l;
    do{
        printf("\n%d", p->info);
        p = p->next;
    } while (p != l);   
}

int main(){
    ListaCircular *l = CriaLista();
    l = InsereLista(l,1);
    l = InsereLista(l,2);
    l = InsereLista(l,3);
    l = InsereLista(l,4);
    l = RemoveLista(l,4);
    ImprimeLista(l);
}