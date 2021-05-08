#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct chave
{
    int chave;
    int repeticoes;
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
        if (t->valoresHash[i]) //Percorre as posições que tem alguma chave
        {
            printf("\nValor: %d - Repetições: %d", t->valoresHash[i]->chave, t->valoresHash[i]->repeticoes);
        }
    }
}

void InsereTabela(int val, TabelaHash *t)
{
    int hash = Hashing(val, t);
    int i = hash;
    if (t->valoresHash[hash])
    {
        if (t->valoresHash[hash]->chave == val)
        {
            (t->valoresHash[hash]->repeticoes)++;
        }
        else
        {
            while (t->valoresHash[i] && i < t->tamanho) //Se tiver colisão, procura a casa da direita até o fim do vetor
            {
                i++;
            }
            if (i < t->tamanho) //Se achou alguma posição vazia a direita do hash e antes do fim do vetor
            {
                t->valoresHash[i] = (Chave *)malloc(sizeof(Chave));
                t->valoresHash[i]->chave = val;
                t->valoresHash[i]->repeticoes = 1;
            }
            else
            {
                int j = 0;
                i = hash;
                while (t->valoresHash[j] && j < i) //Se tiver colisão, procura um espaço vazio do começo do vetor até o hash
                {
                    j++;
                }
                if (j < i) // Se achou alguma posição vazia antes do hash
                {
                    t->valoresHash[i] = (Chave *)malloc(sizeof(Chave));
                    t->valoresHash[i]->chave = val;
                    t->valoresHash[i]->repeticoes = 1;
                }
                else
                {
                    printf("Falha na inserção. O vetor está cheio"); //O vetor está cheio. Nesse caso, é mais viável usar a lista encadeada
                }
            }
        }
    }
    else
    {
        t->valoresHash[hash] = (Chave *)malloc(sizeof(Chave));
        t->valoresHash[hash]->chave = val;
        t->valoresHash[hash]->repeticoes = 1;
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
