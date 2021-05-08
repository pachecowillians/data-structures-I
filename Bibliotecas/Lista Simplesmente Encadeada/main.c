#include "LSE.h"

int main()
{
    LSE *l = novaLista();
    insereInicio(l, 3);
    insereInicio(l, 2);
    insereInicio(l, 1);
    insereFim(l, 4);
    insereOrdenado(l, 6);
    insereOrdenado(l, 5);
    insereOrdenado(l, 2);
    insereOrdenado(l, 8);
    removeFim(l);
    removeInicio(l);
    imprimeLista(l);
    liberaLista(l);
}
