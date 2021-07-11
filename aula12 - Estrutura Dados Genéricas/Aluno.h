#ifndef Aluno_h
#define Aluno_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno Aluno;

Aluno* InicAluno (char* nome, int matricula, float cr);

void ImprimeAluno (Aluno* aluno);

Aluno* RetornaAluno (Aluno* aluno);

char* RetornaNome (Aluno* aluno);

int RetornaMatricula (Aluno* aluno);

float RetornaCr (Aluno* aluno);

void DestroiAluno (Aluno* aluno);

#endif /* Aluno_h */