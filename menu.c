#include "menu.h"
#include <stdio.h>
#include <stdbool.h>


void menu_inicial(ListaAluno *listaAlunos, ListaProfessor *listaProfessores, ListaProjeto *listaProjetos, ListaVinculo *listaVinculos){
    enum {
        sair,
        alunos,
        projetos,
        vinculos,
        professores
    }op;
    
    while (true)
    {
        printf("\n\tMenu");
        printf("\n1 - Alunos");
        printf("\n2 - Projetos");
        printf("\n3 - Vinculos");
        printf("\n4 - Professores");
        printf("\n\n0 - Sair\n");

        scanf("%d",&op);
        switch (op)
        {
        case sair:
            return;
            break;

        case alunos:
            menu_alunos(listaAlunos);
            break;

        case projetos:
            menu_projetos(listaProjetos);
            break;

        case vinculos:
            menu_vinculos(listaVinculos);
            break;

        case professores:
            menu_professores(listaProfessores);
            break;
        }
    }
}

void menu_alunos(ListaAluno *listaAlunos){
    enum {
        sair,
        cadastrar,
        listar,
    }op;


    while (true)
    {
        printf("\n\tAlunos");
        printf("\n1 - Cadastrar");
        printf("\n2 - Listar");
        printf("\n\n0 - Sair\n");

        scanf("%d",&op);
        switch (op)
        {
        case sair:
            return;
            break;

        case cadastrar:
            cadastrar_alunos(listaAlunos);
            break;

        case listar:
            imprimir_alunos(listaAlunos);
            break;
        }
    }
}

void menu_projetos(ListaProjeto *listaProjetos){
    enum {
        sair,
        cadastrar,
        listar,
    }op;


    while (true)
    {
        printf("\n\tProjetos");
        printf("\n1 - Cadastrar");
        printf("\n2 - Listar");
        printf("\n\n0 - Sair\n");

        scanf("%d",&op);
        switch (op)
        {
        case sair:
            return;
            break;

        case cadastrar:
            cadastrar_projetos(listaProjetos);
            break;

        case listar:
            imprimir_projetos(listaProjetos);
            break;
        }
    }
}

void menu_vinculos(ListaVinculo *listaVinculos){
    enum {
        sair,
        criar,
        excluir,
        listar,
    }op;


    while (true)
    {
        printf("\n\tVinculos");
        printf("\n1 - Criar");
        printf("\n2 - Excluir");
        printf("\n3 - Listar");
        printf("\n\n0 - Sair\n");

        scanf("%d",&op);
        switch (op)
        {
        case sair:
            return;
            break;

        case criar:
            criar_vinculos(listaVinculos);
            break;

        case excluir:
            excluir_vinculos(listaVinculos);
            break;

        case listar:
            imprimir_vinculos(listaVinculos);
            break;
        }
    }
}

void menu_professores(ListaProfessor *listaProfessores){
     enum {
        sair,
        cadastrar,
        listar,
    }op;


    while (true)
    {
        printf("\n\tProfessores");
        printf("\n1 - Cadastrar");
        printf("\n2 - Listar");
        printf("\n\n0 - Sair\n");

        scanf("%d",&op);
        switch (op)
        {
        case sair:
            return;
            break;

        case cadastrar:
            cadastrar_professores(listaProfessores);
            break;

        case listar:
            imprimir_professores(listaProfessores);
            break;
        }
    }
}