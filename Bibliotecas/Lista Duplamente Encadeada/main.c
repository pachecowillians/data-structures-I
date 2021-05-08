#include "LDE.h"

int main()
{
    LDE *l = novaLista();
    insereFim(l, 1);
    insereFim(l, 2);
    insereFim(l, 3);
    insereFim(l, 4);
    insereOrdenado(l, 8);
    insereOrdenado(l, 2);
    insereOrdenado(l, 0);
    insereOrdenado(l, 6);
    removeValor(l, 6);
    removeValor(l, 2);
    imprime(l);
    liberaLista(l);
}
