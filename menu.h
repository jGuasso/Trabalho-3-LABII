#ifndef MENU_H
#define MENU_H
#include "lista.h"

void menu_inicial(ListaAluno *listaAlunos, ListaProfessor *listaProfessores, ListaProjeto *listaProjetos, ListaVinculo *listaVinculos);

ListaProfessor * menu_professores(ListaProfessor *listaProfessores);

ListaAluno * menu_alunos(ListaAluno *listaAlunos);

ListaVinculo * menu_vinculos(ListaVinculo *listaVinculos);

ListaProjeto * menu_projetos(ListaProjeto *listaProjetos,ListaProfessor *listaProfessores);


#endif // MENU_H
