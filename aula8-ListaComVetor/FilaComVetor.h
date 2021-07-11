#ifndef FilaComVetor_h
#define FilaCOmVetor_h

#include <stdio.h>
#include "Aluno.h"

typedef struct fila Fila;

Fila* InicFila(void);

//insere fila (SEMPRE no final)
void InsereFila(Fila* f, Aluno* al);

//retirna fila (SEMPRE no inicio)
Aluno* RetiraFila (Fila* f);

//Imprime fila (do inicio ao final)
void ImprimeFila (Fila* f);

//libera memoria da fila (e nao dos alunos)
void DestroiFila(Fila* f);

#endif /* FilaComVetor_h */
