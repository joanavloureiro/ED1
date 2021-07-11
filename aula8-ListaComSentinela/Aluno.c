#include "Aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno
{
    char* nome;
    int matricula;
    float cr;
};

Aluno* InicAluno (char* nome, int matricula, float cr){
    Aluno* novo = (Aluno*) malloc (sizeof (Aluno));
    novo->nome = strdup (nome);
    novo->matricula = matricula;
    novo->cr = cr;

    return novo;
}

void ImprimeAluno (Aluno* aluno){
    printf("nome: %s,\n matricula: %d,\n cr: %.2f \n\n", aluno->nome, aluno->matricula, aluno->cr);
}

Aluno* RetornaAluno (Aluno* aluno){
    return aluno;
}

char* RetornaNome (Aluno* aluno){
    return aluno->nome;
}

int RetornaMatricula (Aluno* aluno){
    return aluno->matricula;
}

float RetornaCr (Aluno* aluno){
    return aluno->cr;
}

void DestroiAluno (Aluno* aluno){
    free (aluno->nome);
    free (aluno);
}