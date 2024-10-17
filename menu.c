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

        scanf("%d",(int*)&op);
        switch (op)
        {
        case sair:
            return;
            break;

        case alunos:
            listaAlunos= menu_alunos(listaAlunos);
            break;

        case projetos:
            listaProjetos= menu_projetos(listaProjetos,listaProfessores);
            break;

        case vinculos:
            listaVinculos= menu_vinculos(listaVinculos);
            break;

        case professores:
            listaProfessores= menu_professores(listaProfessores);
            break;
        }
    }
}

ListaAluno * menu_alunos(ListaAluno *listaAlunos){
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

        scanf("%d",(int*)&op);
        switch (op)
        {
        case sair:
            return listaAlunos;
            break;

        case cadastrar:
            listaAlunos = cadastrar_alunos(listaAlunos);
            break;

        case listar:
            imprimir_alunos(listaAlunos);
            break;
        }
    }
    return listaAlunos;
}

ListaProjeto * menu_projetos(ListaProjeto *listaProjetos,ListaProfessor *listaProfessores){
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

        scanf("%d",(int*)&op);
        switch (op)
        {
        case sair:
            return listaProjetos;
            break;

        case cadastrar:
            listaProjetos= cadastrar_projetos(listaProjetos,listaProfessores);
            break;

        case listar:
            imprimir_projetos(listaProjetos);
            break;
        }
    }
    return listaProjetos;
}

ListaVinculo * menu_vinculos(ListaVinculo *listaVinculos){
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

        scanf("%d",(int*)&op);
        switch (op)
        {
        case sair:
            return listaVinculos;
            break;

        case criar:
            listaVinculos =  criar_vinculos(listaVinculos);
            break;

        case excluir:
            excluir_vinculos(listaVinculos);
            break;

        case listar:
            imprimir_vinculos(listaVinculos);
            break;
        }
    }
    return listaVinculos;
}

ListaProfessor * menu_professores(ListaProfessor *listaProfessores){
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

        scanf("%d",(int*)&op);
        switch (op)
        {
        case sair:
            return listaProfessores;
            break;

        case cadastrar:
            listaProfessores = cadastrar_professores(listaProfessores);
            break;

        case listar:
            imprimir_professores(listaProfessores);
            break;
        }
    }
    return listaProfessores;
}