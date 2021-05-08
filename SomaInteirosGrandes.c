#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no
{
    int chave;
    struct no *prox;
} No;

No *criaNo(int chave)
{
    No *novo = (No *)malloc(sizeof(No));
    if (!novo)
    {
        printf("deu ruim.");
        exit(1);
    }
    else
    {
        novo->chave = chave;
        novo->prox = NULL;
    }
    return novo;
}

void insereInicio(No *l, int chave)
{
    No *novo = criaNo(chave);
    if (l->prox == l)
        novo->prox = l;

    else
        novo->prox = l->prox;

    l->prox = novo;
}

void imprimeLista(No *l)
{
    No *aux = l->prox;
    while (aux != l)
    {
        printf("%d", aux->chave);
        aux = aux->prox;
    }
    printf("\n");
}

void criaLista(No *l, char *numero)
{
    int i = 0;
    int sobra = 0;
    int nos = 0;
    char numeroInserir[6] = "";

    while (numero[i] != '\0')
    {
        i++;
    }

    sobra = i % 5;
    nos = (i - sobra) / 5;

    for (i = 0; i < sobra; i++)
    {
        strncat(numeroInserir, &numero[i], 1);
    }

    insereInicio(l, atoi(numeroInserir));

    for (int j = 0; j < nos; j++)
    {
        strcpy(numeroInserir, "");
        for (int k = 0; k < 5; k++)
        {
            strncat(numeroInserir, &numero[i], 1);
            i++;
        }
        insereInicio(l, atoi(numeroInserir));
    }
}

void somaNumeros(No *n1, No *n2, No *resultado)
{
    No *aux1 = n1->prox;
    No *aux2 = n2->prox;
    int soma = 0;
    int resto = 0;
    do
    {
        if (aux1->chave > 0)
        {
            soma += aux1->chave + resto;
            aux1 = aux1->prox;
        }
        if (aux2->chave > 0)
        {
            soma += aux2->chave + resto;
            aux2 = aux2->prox;
        }
        resto = soma / 100000;
        soma %= 100000;
        insereInicio(resultado, soma);
        soma = 0;

    } while (aux1->chave > 0 || aux2->chave > 0);
}

void liberaLista(No *l)
{
    No *aux = l->prox;
    l->prox = NULL;
    while (aux)
    {
        No *removido = aux;
        aux = aux->prox;
        free(removido);
    }
}

char n1[100000000] = "";
char n2[100000000] = "";

int main()
{
    No *l1 = (No *)calloc(1, sizeof(No));
    l1->chave = -1;
    l1->prox = l1;

    No *l2 = (No *)calloc(1, sizeof(No));
    l2->chave = -1;
    l2->prox = l2;

    No *soma = (No *)calloc(1, sizeof(No));
    soma->chave = -1;
    soma->prox = soma;

    printf("Digite o primeiro inteiro: ");
    scanf("%s", n1);
    printf("Digite o segundo inteiro: ");
    scanf("%s", n2);

    criaLista(l1, n1);
    criaLista(l2, n2);

    somaNumeros(l1, l2, soma);
    printf("%s + %s  = ", n1, n2);
    imprimeLista(soma);

    liberaLista(l1);
    liberaLista(l2);
    liberaLista(soma);
}