#include "pilha.h"

int main()
{
    Pilha *p = novaPilha();
    push(p, 1);
    push(p, 2);
    push(p, 3);
    pop(p);
    imprime(p);
    push(p, 5);
    imprime(p);
    printf("%d\n", tamanho(p));
    printf("%d\n", top(p));
    libera(p);
}