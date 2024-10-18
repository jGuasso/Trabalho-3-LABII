#include "lista.h"
#include <stdio.h>
#include <stdlib.h>


// Funcao usada para limpar o buffer
// https://pt.stackoverflow.com/questions/9427/limpeza-do-buffer-do-teclado-após-scanf
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

    return novoNo;
}

void imprimir_alunos(ListaAluno *listaAlunos){
    ListaAluno *p=listaAlunos;

    for ( ; p!=NULL; p=p->prox)
    {
        printf("\n\n Nome: %s",p->info.nome);
        printf("\n Matricula: %d",p->info.matricula);
        printf("\n Telefone: %s",p->info.telefone);
    }
    

}

Professor * vincular_proj_prof(ListaProfessor *listaProfessores){
    ListaProfessor *p;
    int escolha;
    
    while (1)
    {
        printf("\nEscolha o professor responsavel: ");

        imprimir_professores(listaProfessores);

        printf("\nDigite o codigo do professor:");
        scanf("%d",&escolha);

        for (p=listaProfessores; p != NULL ;p=p->prox)
        {
            if(escolha==p->info.codigo){
                return &p->info;
            }
        }
    }

    return NULL;
}

ListaProjeto * cadastrar_projetos(ListaProjeto *listaProjetos, ListaProfessor *listaProfessores){
    if (listaProfessores==NULL)
    {
        printf("\n\nNao existem professores cadastrados!");
        return listaProjetos;
    }
    ListaProjeto* novoNo;
    novoNo=(ListaProjeto*)malloc(sizeof(ListaProjeto));
    novoNo->prox=listaProjetos;
    novoNo->info.descricao= (char*) malloc(sizeof(char)*80);

    flush_in();

    printf("\nDigite o codigo do projeto: ");
    scanf("%d",&novoNo->info.codigo);

    flush_in();

    printf("\nDigite a descricao do projeto: ");
    scanf("%[^\n]",novoNo->info.descricao);

    flush_in();
    do
    {
        printf("\nQual o tipo do projeto:");
        printf("\n1 - Ensino");
        printf("\n2 - Pesquisa");
        printf("\n3 - Extensao\n");
        scanf("%d",(int*)&novoNo->info.tipo);
    } while (novoNo->info.tipo<1||
             novoNo->info.tipo>3);


    flush_in();

    do
    {
        printf("\nDigite o orcamento aprovado para o projeto: ");
        scanf("%f",&novoNo->info.orcAprovado);
    } while (novoNo->info.orcAprovado<0);

    do
    {
        printf("\nDigite o orcamento atual do projeto: ");
        scanf("%f",&novoNo->info.orcAtual);
    } while (!(novoNo->info.orcAtual<=novoNo->info.orcAprovado &&
               novoNo->info.orcAtual>=0));

    flush_in();

    novoNo->info.coordenador = vincular_proj_prof(listaProfessores);

    return novoNo;
}

void imprimir_projetos(ListaProjeto *listaProjetos){
    ListaProjeto *p=listaProjetos;

    for ( ; p!=NULL; p=p->prox)
    {
        printf("\n%d",p->info.codigo);
        printf("\n%s",p->info.coordenador->nome);
        printf("\n%s",p->info.descricao);
        printf("\n%f",p->info.orcAprovado);
        printf("\n%f",p->info.orcAtual);
        switch (p->info.tipo)
        {
        case Ensino:
            printf("\nEnsino");
            break;
        case Pesquisa:
            printf("\nPesquisa");
            break;
        case Extensao:
            printf("\nExtensao");
            break;
        default:
            break;
        }
    }
}

Projeto *vincular_vinc_proj(ListaProjeto *listaProjetos){

}

ListaVinculo * criar_vinculos(ListaVinculo *listaVinculos, ListaProjeto *listaProjetos, ListaAluno *listAlunos){
    ListaVinculo * novoNo;
    novoNo=(ListaVinculo*)malloc(sizeof(ListaVinculo));   
    
    flush_in();

    

}

void excluir_vinculos(ListaVinculo *listaVinculos){

}

void imprimir_vinculos(ListaVinculo *listaVinculos){

}

ListaProfessor * cadastrar_professores(ListaProfessor *listaProfessores){
    ListaProfessor* novoNo;
    novoNo=(ListaProfessor*)malloc(sizeof(ListaProfessor));
    novoNo->prox=listaProfessores;
    novoNo->info.nome= (char*) malloc(sizeof(char)*50);
    novoNo->info.departamento= (char*) malloc(sizeof(char)*50);

    flush_in();

    printf("\nDigite o codigo do professor: ");
    scanf("%d",&novoNo->info.codigo);

    flush_in();

    printf("\nDigite o nome do professor: ");
    scanf("%[^\n]",novoNo->info.nome);

    flush_in();

    printf("\nDigite departamento do professor: ");
    scanf("%[^\n]",novoNo->info.departamento);

    flush_in();

    return novoNo;
}

void imprimir_professores(ListaProfessor *listaProfessores){
    ListaProfessor *p=listaProfessores;

    for ( ; p!=NULL; p=p->prox)
    {
        printf("\n\n Nome: %s",p->info.nome);
        printf("\n Codigo: %d",p->info.codigo);
        printf("\n Departamento: %s",p->info.departamento);
    }
}