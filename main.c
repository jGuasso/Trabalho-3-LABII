/*
Definição de como escrever:
Variaveis: camelCase
Funcoes: snake_case
Tipos: PascalCase
*/

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

int main(){
    ListaAluno *listaAlunos= NULL;
    ListaProfessor *listaProfessores= NULL;
    ListaProjeto *listaProjetos= NULL;
    ListaVinculo *listaVinculos= NULL;
    menu_inicial(listaAlunos, listaProfessores, listaProjetos, listaVinculos);
}