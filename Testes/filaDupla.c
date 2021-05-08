#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct no{
    int info;
    struct no *next;
    struct no *prev;
}No;

typedef struct filaDupla{
    No *first;
    No *last;
}FilaDupla;

FilaDupla * CriaFila (void){
    FilaDupla *f = malloc(sizeof(FilaDupla));
    f->first = NULL;
    f->last = NULL;
    return f;
}

FilaDupla * InsereInicio (FilaDupla* f, int v){
    No *n = malloc(sizeof(No));
    n->info = v;
    if (f->first != NULL)
    {
        n->next = f->first;
        n->prev = NULL;
        f->first->prev = n;
        f->first = n;
    }else{
        n->next = NULL;
        n->prev = NULL;
        f->last = n;  
        f->first = n;
    }
    return f;
}

FilaDupla * InsereFim (FilaDupla* f, int v){
    No *n = malloc(sizeof(No));
    n->info = v;
    if (f->first != NULL)
    {
        n->next = NULL;
        n->prev = f->last;
        f->last->next = n;
        f->last = n;
    }else{
        n->next = NULL;
        n->prev = NULL;
        f->last = n;  
        f->first = n;
    }
    return f;
}

FilaDupla * RetiraInicio (FilaDupla* f){
    No *n = f->first;
    f->first = f->first->next;
    f->first->prev = NULL;
    free(n);
    return f;
}

FilaDupla * RetiraFim (FilaDupla* f){
    No *n = f->last;
    f->last = f->last->prev;
    f->last->next = NULL;
    free(n);
    return f;
}

void ImprimeFila(FilaDupla *f){
    for (No *i = f->first; i != NULL; i = i->next)
    {
        printf("\n%d", i->info);
    }
    
}

int main(){
    FilaDupla *f = CriaFila();
    f = InsereInicio(f,1);
    f = InsereInicio(f,2);
    f = InsereInicio(f,3);
    f = InsereFim(f,4);
    f = RetiraInicio(f);
    f = RetiraFim(f);
    ImprimeFila(f);
}