#ifndef PilhaDpl_h
#define PilhaDpl_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Aluno.h"

typedef struct indicePilha IndicePilha;

typedef struct tipoPilhaDupla TipoPilhaDupla;

TipoPilhaDupla* InicPilha();

//inclui topo
void push (TipoPilhaDupla* p, Aluno* al);

//retira do topo
Aluno* pop (TipoPilhaDupla* p, int tipo);

//imprime topo para base
void ImprimePilha (TipoPilhaDupla* pilha);

//destroi pilha
void DestroiPilha (TipoPilhaDupla* pilha);

#endif /* PilhaDpl_h */