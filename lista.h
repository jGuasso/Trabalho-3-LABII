#ifndef LISTA_H
#define LISTA_H

typedef struct aluno
{
    int matricula;
    char *nome;
    char *telefone;
}Aluno;

typedef struct listaluno
{
    Aluno info;
    struct listaluno *prox;
}ListaAluno;

typedef struct professor
{
    int codigo;
    char *nome;
    char *departamento;
}Professor;

typedef struct listprofessor
{
    Professor info;
    struct listprofessor *prox;
}ListaProfessor;

typedef enum tipoprojeto{
    Ensino=1,
    Pesquisa=2,
    Extensao=3
} TipoProjeto;

typedef struct projeto
{
    int codigo;
    char *descricao;
    TipoProjeto tipo;
    float orcAprovado;
    float orcAtual;
    Professor *coordenador;
}Projeto;

typedef struct listprojeto
{
    Projeto info;
    struct listprojeto *prox;
}ListaProjeto;

typedef struct vinculo
{
    Aluno *aluno;
    Projeto *projeto;
    float bolsa;
}Vinculo;

typedef struct listvinculo
{
    Vinculo info;
    struct listvinculo *prox;
}ListaVinculo;

ListaAluno * cadastrar_alunos(ListaAluno *listaAlunos);

void imprimir_alunos(ListaAluno *listaAlunos);

ListaProjeto * cadastrar_projetos(ListaProjeto *listaProjetos, ListaProfessor *listaProfessores);

void imprimir_projetos(ListaProjeto *listaProjetos);

ListaVinculo * criar_vinculos(ListaVinculo *listaVinculos, ListaProjeto *listaProjetos, ListaAluno *listAlunos);

void excluir_vinculos(ListaVinculo *listaVinculos);

void imprimir_vinculos(ListaVinculo *listaVinculos);

ListaProfessor * cadastrar_professores(ListaProfessor *listaProfessores);

void imprimir_professores(ListaProfessor *listaProfessores);

#endif // LISTA_H