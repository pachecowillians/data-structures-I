#include "LCDE.h"

int main()
{
    LCDE *l = NULL;
    insereInicio(&l, 3);
    insereInicio(&l, 2);
    insereInicio(&l, 1);
    insereFim(&l, 4);
    insereFim(&l, 9);
    insereFim(&l, 3);
    insereInicio(&l, 0);
    removeInicio(&l);
    removeFim(&l);
    imprimeLista(&l);
    liberaLista(&l);
}
