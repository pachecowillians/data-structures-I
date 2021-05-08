#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno{
    int matricula;
    char nome[40];
} Aluno;

typedef struct aluno *PAluno;

void InsereLista(Aluno *a, PAluno *lista, int *sizeList){
    lista[(*sizeList)] = a;
    (*sizeList)++;
}

void Inicializa(PAluno *lista, int sizeList){
    for (int i = 0; i < sizeList; i++)
    {
        lista[0] = NULL;
    }
}

void RemoverLista(PAluno *lista, int posicaoRemover){
    if (lista[posicaoRemover] != NULL)
    {
        free(lista[posicaoRemover]);
        lista[posicaoRemover] = NULL;        
    }
}

void ImprimeEspecifico(PAluno *lista, int pos){
    if (lista[pos]!= NULL){
        printf("%s %d", lista[pos]->nome, lista[pos]->matricula);
    }else{
        printf("Aluno não encontrado");
    }
}

void ImprimeTodos(PAluno *lista, int tam){
    for (int i = 0; i < tam; i++)
    {
        if (lista[i]!= NULL){
            printf("\n%s %d", lista[i]->nome, lista[i]->matricula);
        }
    }
}

int InterfaceRemove(){
    int posicaoRemover;
    system("clear");
    printf("Digite a posição a ser removida do vetor: ");
    scanf(" %d", &posicaoRemover);
    return posicaoRemover;
}

Aluno * InterfaceInsere(){
    Aluno *a = malloc(sizeof(Aluno));;
    system("clear");
    printf("Inserir: \n");
    __fpurge(stdin);
    printf("Digite o nome do aluno: ");
    scanf(" %[^\n]", a->nome);
    __fpurge(stdin);
    printf("Digite a matrícula do aluno: ");
    scanf("%d", &a->matricula);
    
    return a;
}

int main(){
    int sizeList=0;
    //Aluno * listaAluno[100];
    //(Aluno *) listaAluno[100];
    PAluno listaAluno[100];
    Inicializa(listaAluno,100);
    InsereLista(InterfaceInsere(), listaAluno, &sizeList);
    InsereLista(InterfaceInsere(), listaAluno, &sizeList);
    RemoverLista(listaAluno,InterfaceRemove());
    ImprimeEspecifico(listaAluno,0);
    ImprimeEspecifico(listaAluno,1);
    ImprimeTodos(listaAluno,sizeList);
    

}
