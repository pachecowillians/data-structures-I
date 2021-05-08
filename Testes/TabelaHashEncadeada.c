#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct chave
{
    int chave;
    int repeticoes;
    struct chave *prox;
} Chave;

typedef struct tabelaHash
{
    int tamanho;
    Chave **valoresHash;
} TabelaHash;

TabelaHash *CriaTabela(int tamanho)
{
    TabelaHash *t = (TabelaHash *)malloc(sizeof(TabelaHash)); //Cria a struct tabela
    t->tamanho = tamanho;
    t->valoresHash = (Chave **)malloc(tamanho * sizeof(Chave *)); //Aloca espaço para os 41 valores de chave
    for (int i = 0; i < tamanho; i++)
    {
        t->valoresHash[i] = NULL; //Inicializo a tabela com NULL
    }

    return t;
}

int Hashing(int val, TabelaHash *t) //Função de dispersão
{
    return val % t->tamanho;
}

void ImprimeValores(TabelaHash *t)
{
    for (int i = 0; i < t->tamanho; i++)
    {
        if (t->valoresHash[i]) //Se tiver valores com aquele hash
        {
            Chave *c = t->valoresHash[i];
            while (c) //percorre a lista encadeada
            {
                printf("\nValor: %d - Repetições: %d", c->chave, c->repeticoes);
                c = c->prox;
            }
        }
    }
}

void InsereTabela(int val, TabelaHash *t)
{
    int hash = Hashing(val, t);
    int i = hash;
    if (t->valoresHash[hash]) //Se já tem algum valor na posição do hash (colisão)
    {
        Chave *c = t->valoresHash[hash];
        while (c->prox && c->chave != val) //Percorre até achar um valor igual, ou terminar a lista
        {
            c = c->prox;
        }
        if (c->chave == val) //Se tiver um valor igual, incrementa
        {
            (c->repeticoes)++;
        }
        else
        {
            if (!c->prox) //Se chegou ao fim da lista, insere o novo valor nela
            {
                c->prox = (Chave *)malloc(sizeof(Chave));
                c->prox->chave = val;
                c->prox->repeticoes = 1;
                c->prox->prox = NULL;
            }
        }
    }
    else //Se não tem colisão
    {
        t->valoresHash[hash] = (Chave *)malloc(sizeof(Chave));
        t->valoresHash[hash]->chave = val;
        t->valoresHash[hash]->repeticoes = 1;
        t->valoresHash[hash]->prox = NULL;
    }
    ImprimeValores(t);
}

int main()
{
    TabelaHash *t = CriaTabela(41);
    char resp = 's';
    int val;
    system("clear"); //Limpa a tela
    while (resp != 'n')
    {
        __fpurge(stdin); //Limpa o buffer do teclado
        printf("Digite o valor: ");
        scanf("%d", &val);
        InsereTabela(val, t);
        __fpurge(stdin); //Limpa o buffer do teclado
        printf("\nDeseja Inserir outro valor? (s/n)");
        scanf("%c", &resp);
    }
}
