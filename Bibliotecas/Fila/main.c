#include "fila.h"

int main()
{
    Fila *f = criaFila();
    printf("%d\n", empty(f));
    push(f, 2);
    push(f, 3);
    push(f, 4);
    push(f, 5);
    print(f);
    printf("%d\n", empty(f));
    printf("%d\n", size(f));
    pop(f);
    printf("%d\n", size(f));
    print(f);
    printf("%d\n", front(f));
    push(f, 7);
    printf("%d\n", front(f));
    print(f);
    libera(f);
}
