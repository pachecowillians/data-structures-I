#include "LCSE.h"

int main()
{
    LCSE *l = NULL;
    insereInicio(&l, 3);
    insereInicio(&l, 2);
    insereInicio(&l, 1);
    insereFim(&l, 4);
    insereFim(&l, 5);
    removeInicio(&l);
    removeFim(&l);
    imprimeLista(&l);
    liberaLista(&l);
}
