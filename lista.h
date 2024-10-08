#ifndef LISTA_H
#define LISTA_H

typedef struct aluno
{
    int matricula;
    char *nome;
    char *telefone;
}Aluno;

typedef struct professor
{
    int codigo;
    char *nome;
    char *departamento;
}Professor;

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

typedef struct vinculo
{
    Aluno *aluno;
    Projeto *projeto;
    float bolsa;
}Vinculo;


#endif // LISTA_H