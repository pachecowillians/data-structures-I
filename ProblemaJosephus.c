#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no
{
    char nome[50];
    struct no *prox;
} No;

No *criaNo(char *nome)
{
    No *novo = (No *)malloc(sizeof(No));
    if (!novo)
    {
        printf("deu ruim.");
        exit(1);
    }
    else
    {
        strcpy(novo->nome, nome);
        novo->prox = NULL;
    }
    return novo;
}

No *insereFim(No *l, char *chave)
{
    No *novo = criaNo(chave);
    if (!l)
    {
        novo->prox = novo;
        l = novo;
    }
    else
    {
        novo->prox = l->prox;
        l->prox = novo;
        l = novo;
    }

    return l;
}

void imprimeLista(No *l)
{
    if (l)
    {
        No *aux = l->prox;
        do
        {
            printf("%s\n", aux->nome);
            aux = aux->prox;
        } while (aux != l->prox);
    }
}

No *josephus(No *l, int n, char *nome)
{
    if (l)
    {
        No *aux = l->prox;
        No *prev = l;
        int contador = 0;

        do
        {
            aux = aux->prox;
        } while (strcmp(aux->prox->nome, nome) != 0 && aux->prox != l->prox);

        if (aux->prox == l->prox && strcmp(aux->prox->nome, nome) != 0)
        {
            printf("O nome buscado não existe.\n");
        }
        else
        {
            while (aux->prox != aux)
            {
                if (contador == n)
                {
                    No *removido = aux;
                    contador = 1;
                    prev->prox = aux->prox;
                    aux = aux->prox;
                    printf("Removido: %s\n", removido->nome);
                    free(removido);
                }
                else
                {
                    prev = aux;
                    aux = aux->prox;
                    contador++;
                }
            }
            return aux;
        }
        return l;
    }
    return l;
}

int main()
{
    No *l = NULL;
    l = insereFim(l, "carlos");
    l = insereFim(l, "pedro");
    l = insereFim(l, "amanda");
    l = insereFim(l, "karla");
    l = insereFim(l, "ricardo");
    l = insereFim(l, "arthur");
    l = insereFim(l, "gabriel");
    imprimeLista(l);
    printf("\n");
    l = josephus(l, 3, "carlos");
    printf("\n");
    imprimeLista(l);
}