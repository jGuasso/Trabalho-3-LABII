#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

//Funcao usada para limpar o buffer
void flush_in(){
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){} 
}

ListaAluno * cadastrar_alunos(ListaAluno *listaAlunos){
    ListaAluno* novoNo;
    novoNo=(ListaAluno*)malloc(sizeof(ListaAluno));
    novoNo->prox=listaAlunos;
    novoNo->info.nome= (char*) malloc(sizeof(char)*50);
    novoNo->info.telefone= (char*) malloc(sizeof(char)*20);

    flush_in();

    printf("\nDigite o numero da matricula do aluno: ");
    scanf("%d",&novoNo->info.matricula);

    flush_in();

    printf("\nDigite o nome do aluno: ");
    scanf("%[^\n]",novoNo->info.nome);

    flush_in();

    printf("\nDigite o numero de telefone do aluno: ");
    scanf("%[^\n]",novoNo->info.telefone);

    flush_in();

    printf("\n%d\n%s\n%s",novoNo->info.matricula,
                              novoNo->info.nome,
                              novoNo->info.telefone);

    return novoNo;
}

void imprimir_alunos(ListaAluno *listaAlunos){
    ListaAluno *p=listaAlunos;

    for ( ; p!=NULL; p=p->prox)
    {
        printf("\n%d\n%s\n%s",p->info.matricula,
                              p->info.nome,
                              p->info.telefone);
    }
    

}

ListaProjeto * cadastrar_projetos(ListaProjeto *listaProjetos){

}

void imprimir_projetos(ListaProjeto *listaProjetos){

}

ListaVinculo * criar_vinculos(ListaVinculo *listaVinculos){

}

void excluir_vinculos(ListaVinculo *listaVinculos){

}

void imprimir_vinculos(ListaVinculo *listaVinculos){

}

ListaProfessor * cadastrar_professores(ListaProfessor *listaProfessores){

}

void imprimir_professores(ListaProfessor *listaProfessores){

}