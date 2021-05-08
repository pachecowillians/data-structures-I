#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define RET 0
#define TRI 1
#define QUA 2

typedef struct Retangulo{
    int b,h;
} Retangulo;

typedef struct Triangulo{
    int b,h;
} Triangulo;

typedef struct Quadrado{
    int l;
} Quadrado;

typedef struct listaGenerica{
    int tipo;
    void *info;
    struct listaGenerica *next;
} listaGenerica;

listaGenerica * CriaLista(){
    return NULL;
}

listaGenerica * InsereRetanguloLista(listaGenerica *l, int b, int h){
    Retangulo *r = malloc(sizeof(Retangulo));
    r->b = b;
    r->h = h;
    
    listaGenerica *lAux = malloc(sizeof(listaGenerica));
    lAux->tipo = RET;
    lAux->info = (Retangulo*)r;
    lAux->next = l;

    return lAux;
}

listaGenerica * InsereTrianguloLista(listaGenerica *l, int b, int h){
    Triangulo *t = malloc(sizeof(Triangulo));
    t->b = b;
    t->h = h;
    
    listaGenerica *lAux = malloc(sizeof(listaGenerica));
    lAux->tipo = TRI;
    lAux->info = (Triangulo*)t;
    lAux->next = l;

    return lAux;
}

listaGenerica * InsereQuadradoLista(listaGenerica *l, int lado){
    Quadrado *q = malloc(sizeof(Quadrado));
    q->l = lado;
    
    listaGenerica *lAux = malloc(sizeof(listaGenerica));
    lAux->tipo = QUA;
    lAux->info = (Quadrado*)q;
    lAux->next = l;

    return lAux;
}

void MostrarLista(listaGenerica *l){
    for (listaGenerica *i = l; i != NULL; i = i->next){
        if (i->tipo == RET){
            Retangulo *r = (Retangulo *)i->info;
            printf("\nRetângulo\nBase: %d\nAltura: %d", r->b, r->h);
        }else if (i->tipo == TRI){
            Triangulo *t = (Triangulo *)i->info;
            printf("\nTriângulo\nBase: %d\nAltura: %d", t->b, t->h);
        }else if (i->tipo == QUA){
            Quadrado *q = (Quadrado *)i->info;
            printf("\nQuadrado\nLado: %d", q->l);
        }
        printf("\n");
    }
    
}

int main(){
    listaGenerica *lista = CriaLista();
    lista = InsereRetanguloLista(lista, 1,2);
    lista = InsereTrianguloLista(lista, 3,4);
    lista = InsereQuadradoLista(lista, 5);
    lista = InsereTrianguloLista(lista, 6,7);
    lista = InsereQuadradoLista(lista, 8);
    lista = InsereRetanguloLista(lista, 9,10);
    MostrarLista(lista);
}