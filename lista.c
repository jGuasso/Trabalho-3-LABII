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

    novoNo->info.orcAtual=novoNo->info.orcAprovado;

    flush_in();

    novoNo->info.coordenador = vincular_proj_prof(listaProfessores);

    return novoNo;
}

void imprimir_projetos(ListaProjeto *listaProjetos){
    ListaProjeto *p=listaProjetos;

    for ( ; p!=NULL; p=p->prox)
    {
        printf("\n\n Codigo do projeto: %d",p->info.codigo);
        printf("\n Professor coordenador: %s",p->info.coordenador->nome);
        printf("\n Descricao: %s",p->info.descricao);
        printf("\n Orcamento aprovado: R$%.2f",p->info.orcAprovado);
        printf("\n Orcamento atual: R$%.2f",p->info.orcAtual);
        printf("\n Tipo: ");
        switch (p->info.tipo)
        {
        case Ensino:
            printf("Ensino");
            break;
        case Pesquisa:
            printf("Pesquisa");
            break;
        case Extensao:
            printf("Extensao");
            break;
        default:
            break;
        }
    }
}

Projeto *vincular_vinc_proj(ListaProjeto *listaProjetos){
    ListaProjeto *p;
    int escolha;
    
    while (1)
    {
        printf("\nEscolha o Projeto: ");

        imprimir_projetos(listaProjetos);

        printf("\nDigite o codigo do projeto:");
        scanf("%d",&escolha);

        for (p=listaProjetos; p != NULL ;p=p->prox)
        {
            if(escolha==p->info.codigo){
                return &p->info;
            }
        }
    }

    return NULL;
}


Aluno *vincular_vinc_aluno(ListaAluno *listaAlunos){
    ListaAluno *p;
    int escolha;
    
    while (1)
    {
        printf("\nEscolha o Aluno: ");

        imprimir_alunos(listaAlunos);

        printf("\nDigite a matricula do aluno:");
        scanf("%d",&escolha);

        for (p=listaAlunos; p != NULL ;p=p->prox)
        {
            if(escolha==p->info.matricula){
                return &p->info;
            }
        }
    }

    return NULL;
}

ListaVinculo * criar_vinculos(ListaVinculo *listaVinculos, ListaProjeto *listaProjetos, ListaAluno *listAlunos){
    if (listaProjetos==NULL)
    {
        printf("\n\nNao existem projetos cadastrados");
        return NULL;
    }
    if (listAlunos==NULL)
    {
        printf("\n\nNao existem alunos cadastrados");
        return NULL;
    }
    ListaVinculo * novoNo;
    novoNo=(ListaVinculo*)malloc(sizeof(ListaVinculo));
    novoNo->prox=listaVinculos;
    novoNo->info.projeto=vincular_vinc_proj(listaProjetos);
    novoNo->info.aluno=vincular_vinc_aluno(listAlunos);

    do
    {
        printf("\nO valor da bolsa deve ir de 0 a no maximo %2.f",novoNo->info.projeto->orcAtual/12.0);
        printf("\nDigite o valor da bolsa mensal do aluno: ");
        flush_in();
        scanf("%f",&novoNo->info.bolsa);

    } while (novoNo->info.bolsa<0|| novoNo->info.bolsa*12>novoNo->info.projeto->orcAtual);

    novoNo->info.projeto->orcAtual-=novoNo->info.bolsa*12;
    

    flush_in();
    return novoNo;
}

ListaVinculo* excluir_vinculos(ListaVinculo *listaVinculos){
    int mat, cod, meses;
    ListaVinculo *p=listaVinculos,*ant=NULL;
    printf("\n\nDigite a matricula do aluno: ");
    scanf("%d",&mat);
    printf("\n\nDigite o codigo do projeto: ");
    scanf("%d",&cod);
    printf("\n\nQuantidade de meses que a bolsa nao sera paga: ");
    scanf("%d",&meses);

    for (; p!=NULL; p=p->prox)
    {
        if (p->info.projeto->codigo==cod &&
            p->info.aluno->matricula==mat)
        {
            p->info.projeto->orcAtual+= p->info.bolsa*meses;
            if(ant==NULL){
                ant= p->prox;
                free(p);
                return ant;
            }
            else
            {
                ant->prox=p->prox;
                free(p);
                return listaVinculos;
            }
            
        }
        ant=p;
    }
    return listaVinculos;
}

void imprimir_vinculos(ListaVinculo *listaVinculos){
    ListaVinculo *p=listaVinculos;

    for ( ; p!=NULL; p=p->prox)
    {
        printf("\n\n Projeto:(%d) %s",p->info.projeto->codigo,p->info.projeto->descricao);
        printf("\n Aluno:(%d) %s",p->info.aluno->matricula,p->info.aluno->nome);
        printf("\n bolsa: R$%.2f",p->info.bolsa);
    }
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

void imprimir_relatorio(ListaProjeto *listaProjetos, ListaVinculo *listaVinculos){
    ListaProjeto *p=listaProjetos;
    ListaVinculo *k;
    char ver;

    for ( ; p!=NULL; p=p->prox)
    {
        printf("\n\n Codigo do projeto: %d",p->info.codigo);
        printf("\n Professor coordenador: %s",p->info.coordenador->nome);
        printf("\n Descricao: %s",p->info.descricao);
        printf("\n Orcamento aprovado: R$%.2f",p->info.orcAprovado);
        printf("\n Orcamento atual: R$%.2f",p->info.orcAtual);
        printf("\n Tipo: ");
        switch (p->info.tipo)
        {
        case Ensino:
            printf("Ensino");
            break;
        case Pesquisa:
            printf("Pesquisa");
            break;
        case Extensao:
            printf("Extensao");
            break;
        default:
            break;
        }

        ver=0;
        printf("\nAlunos:");
        for (k = listaVinculos; k!=NULL; k=k->prox)
        {
            if(k->info.projeto->codigo==p->info.codigo){
                printf("\n %s",k->info.aluno->nome);
                ver=1;
            }
        }
        if(ver==0){
            printf("\n Nao ha alunos vinculados a este projeto");
        }
        
    }

}