#include <stdio.h>
#include <stdlib.h>

//Estrutura da lista de amigos
typedef struct listaA
{
    int id;
    struct listaA *prox;
    struct listaA *prev;
} ListaA;

//Estrutura da lista de usuarios
typedef struct listaU
{
    int value;
    //outros atributos
    struct listaU *prox;
    struct listaU *prev;
    ListaA *l;
} ListaU;

//Cria um nó do tipo ListaA
ListaA *criaNoA(int value)
{
    ListaA *novo = (ListaA *)malloc(sizeof(ListaA));
    if (novo)
    {
        novo->prox = NULL;
        novo->prev = NULL;
        novo->id = value;
    }
    else
    {
        printf("Erro de alocacao de memoria.\n");
        exit(1);
    }
    return novo;
}

//Cria o nó cabeça da lista de amigos
ListaA *novaListaA()
{
    ListaA *l = (ListaA *)calloc(1, sizeof(ListaA));
    if (!l)
    {
        printf("Erro de alocacao de memoria.\n");
        exit(1);
    }
    return l;
}

//Insere no início da lista de amigos
void insereInicioA(ListaA *l, int value)
{
    ListaA *novo = criaNoA(value);

    novo->prox = l->prox;

    if (l->prox)
    {
        l->prox->prev = novo;
    }
    else
        l->prev = novo;

    l->prox = novo;
}

//Imprime lista de amigos
void imprimeA(ListaA *l)
{
    ListaA *n = l->prox;
    while (n)
    {
        printf("%d ", n->id);
        n = n->prox;
    }
    printf("\n");
}

//Cria nó da lista de usuarios
ListaU *criaNoU(int value)
{
    ListaU *novo = (ListaU *)malloc(sizeof(ListaU));
    if (novo)
    {
        novo->prox = NULL;
        novo->prev = NULL;
        novo->value = value;
        novo->l = novaListaA(); //A lista de amigos começa apontando para o nó cabeça da lista
    }
    else
    {
        printf("Erro de alocacao de memoria.\n");
        exit(1);
    }
    return novo;
}

//Criação do nó cabeça para a lista de usuários
ListaU *novaListaU()
{
    ListaU *l = (ListaU *)calloc(1, sizeof(ListaU));
    if (!l)
    {
        printf("Erro de alocacao de memoria.\n");
        exit(1);
    }
    return l;
}

//Insere no inicio da lista de usuários
void insereInicioU(ListaU *l, int value)
{
    ListaU *novo = criaNoU(value);

    novo->prox = l->prox;

    if (l->prox)
    {
        l->prox->prev = novo;
    }
    else
        l->prev = novo;

    l->prox = novo;
}

//Imprime a lista de usuários com a lista de amigos dele
void imprimeU(ListaU *l)
{
    ListaU *n = l->prox;
    while (n)
    {
        printf("Usuario: %d\n", n->value);
        printf("Lista de amigos de %d: \n", n->value);
        imprimeA(n->l); //Imprime lista de amigos do usuario
        n = n->prox;
        printf("\n");
    }
}

int main()
{
    //Cria o nó cabeça da lista de usuários
    ListaU *u = novaListaU();
    //Insere um usuário com valor 1
    insereInicioU(u, 1);
    //u->prox sempre aponta para o primeiro elemento da lista, pois utilizei a implementação por nó cabeça
    //Inserindo valores na lista de amigos do primeiro usuário
    insereInicioA(u->prox->l, 1);
    insereInicioA(u->prox->l, 5);
    insereInicioA(u->prox->l, 8);
    //Inserindo um novo elemento no início da lista
    insereInicioU(u, 2);
    //Inserindo na lista de amigos do novo primeiro usuário (usuário de valor 2)
    insereInicioA(u->prox->l, 4);
    insereInicioA(u->prox->l, 2);
    //Insere novo usuário com valor 3
    insereInicioU(u, 3);
    //Inserindo na lista de amigos do novo primeiro usuário (usuário de valor 3)
    insereInicioA(u->prox->l, 9);
    //Imprime a lista de usuários com a respectiva lista de amigos
    imprimeU(u);
}
