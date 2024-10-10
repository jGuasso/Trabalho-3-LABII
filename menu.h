#ifndef MENU_H
#define MENU_H
#include "lista.h"

void menu_inicial(ListaAluno *listaAlunos, ListaProfessor *listaProfessores, ListaProjeto *listaProjetos, ListaVinculo *listaVinculos);

void menu_professores(ListaProfessor *listaProfessores);

void menu_alunos(ListaAluno *listaAlunos);

void menu_vinculos(ListaVinculo *listaVinculos);

void menu_projetos(ListaProjeto *listaProjetos);


#endif // MENU_H
