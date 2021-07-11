#ifndef LISTAALUNO_H_
#define LISTAALUNO_H_

#include <stdio.h>
#include "listagen.h"
#include "Aluno.h"

ListaGen* retiraAluno(ListaGen* lista, int matricula);

int pertenceAluno(ListaGen* lista, int matricula);

void imprimeListaAlunos(ListaGen* lista);

float mediaTurma(ListaGen* lista);

#endif /* LISTAALUNO_H_ */
