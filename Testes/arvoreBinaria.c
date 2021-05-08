#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct arvoreBinaria{
    char info;
    struct arvoreBinaria *sad;
    struct arvoreBinaria *sae;
}ArvoreBinaria;


ArvoreBinaria * Inicializa(){
    return NULL;
}

ArvoreBinaria * CriaArvore(char info ,ArvoreBinaria *sad, ArvoreBinaria *sae){
    ArvoreBinaria *a = malloc(sizeof(ArvoreBinaria));
    a->info = info;
    a->sad = sad;
    a->sae = sae;
    return a;
}

int Vazia(ArvoreBinaria *a){
    return a==NULL;
}

void ImprimePreOrdem(ArvoreBinaria *a){
    if (!Vazia(a))
    {
        printf(" <%c", a->info);
        ImprimePreOrdem(a->sad);
        ImprimePreOrdem(a->sae);
        printf("> ");
    }else{
        printf(" <> ");
    }
}

void ImprimeOrdemSimetrica(ArvoreBinaria *a){
    if (!Vazia(a))
    {
        ImprimeOrdemSimetrica(a->sad);
        printf("%c ", a->info);
        ImprimeOrdemSimetrica(a->sae);
    }
}

void ImprimePosOrdem(ArvoreBinaria *a){
    if (!Vazia(a))
    {
        ImprimePosOrdem(a->sad);
        ImprimePosOrdem(a->sae);
        printf("%c ", a->info);
    }
}

int Altura(ArvoreBinaria *a){
    int x=0,y=0;
    if (!Vazia(a))
    {
        x = Altura(a->sad);
        y = Altura(a->sae);
        if (x > y) return x+1;
        else return y+1;
    }else{
        return -1;
    }
}

int main(){
    ArvoreBinaria *a = 
    CriaArvore('a',
        CriaArvore('c',
            CriaArvore('f',Inicializa(),Inicializa()),
            CriaArvore('e',Inicializa(),Inicializa())
            ),
        CriaArvore('b',
            CriaArvore('d',Inicializa(),Inicializa()),
            Inicializa()
                    )
                );
    
    printf("%d", Altura(a));
    printf("\n");
    ImprimePreOrdem(a);
    printf("\n");
    ImprimeOrdemSimetrica(a);
    printf("\n");
    ImprimePosOrdem(a);
}