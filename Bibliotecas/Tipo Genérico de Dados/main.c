#include "TGD.h"

typedef struct livro{
    int numPag;
    char * nome;
}Livro;

void imprime(void *v)
{
    Livro *l = (Livro *)v;
    printf("%d %s\n", l->numPag, l->nome);
}

int menorQue(void *v1, void *v2)
{
    Livro *l1 = (Livro *)v1;
    Livro *l2 = (Livro *)v2;

    return l1->numPag < l2->numPag;
}

Livro *criaValor(int numPag, char * nome)
{
    Livro *n = (Livro *)malloc(sizeof(Livro));
    n->nome = (char *)malloc(300*sizeof(char));
    strcpy(n->nome,nome);
    n->numPag = numPag;
    return n;
}

void liberaValor(void *value)
{
    Livro *l = (Livro *)value;
    free(l->nome);
    free(l);
}

int main()
{
    TGD *l = novaLista();
    insereInicio(l, criaValor(2,"a volta dos q n foram"));
    insereInicio(l, criaValor(3, "carlos"));
    insereInicio(l, criaValor(4, "a pereba"));
    insereInicio(l, criaValor(5, "a onda"));
    insereFim(l, criaValor(1, "cuxaixang"));
    insereFim(l, criaValor(0, "shakaramanai"));

    TGD *l2 = novaLista();
    insereOrdenado(l2, criaValor(2, "suco de pera"), menorQue);
    insereOrdenado(l2, criaValor(0, "abacate"), menorQue);
    insereOrdenado(l2, criaValor(1, "serm nome"), menorQue);
    insereOrdenado(l2, criaValor(6, "alsdla"), menorQue);
    insereOrdenado(l2, criaValor(9, "dadkjff"), menorQue);
    insereOrdenado(l2, criaValor(3, "adhfghkfs"), menorQue);

    imprimeLista(l, imprime);
    printf("\n");
    imprimeLista(l2, imprime);

    removeInicio(l);
    removeInicio(l);
    removeFim(l);

    printf("\n");

    imprimeLista(l, imprime);

    liberaLista(l, liberaValor);
    liberaLista(l2, liberaValor);
}
