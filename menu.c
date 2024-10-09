#include "menu.h"
#include <stdio.h>


void menu_inicial(){
    enum {
        sair,
        alunos,
        projetos,
        vinculos,
        professores
    }op;
    
    while (1)
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
            menu_alunos();
            break;

        case projetos:
            menu_projetos();
            break;

        case vinculos:
            menu_vinculos();
            break;

        case professores:
            menu_professores();
            break;
        }
    }
}

void menu_alunos(){

}

void menu_projetos(){

}

void menu_vinculos(){

}

void menu_professores(){
    
}