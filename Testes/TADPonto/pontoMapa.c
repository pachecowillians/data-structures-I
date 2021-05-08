#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "ponto.c"

int main(){
    Ponto *origem = NULL;
    //printf("%p", origem);
    origem = cria(0,0);
    Ponto *p1 = cria(1,1);
    float x,y;

    acessa(origem,&x,&y);
    atribui(p1,12,12);
    printf("\n%f",distancia(origem,p1));
    printf("\n%f %f", origem->x, origem->y);

    Ponto *difPonto = Subtracao(p1,origem);
    Ponto *somaPonto = Soma(p1,origem);
    printf("\n%f %f", difPonto->x, difPonto->y);
    printf("\n%f %f", somaPonto->x, somaPonto->y);
}