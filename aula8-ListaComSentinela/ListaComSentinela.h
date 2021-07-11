#ifndef ListaComSentinela_h
#define ListaComSentinela_h

#include <stdio.h>
#include "Aluno.h"

typedef struct lista Lista;

Lista* InicLista(void);

void InsereListaUlt(Lista* lista, Aluno* al);

void ImprimeLista(Lista* lista);

Aluno* RetiraLista(Lista* lista, char* chave);

Aluno* RetiraPosicao (Lista* lista, int pos);

void DestroiLista(Lista* lista);


#endif /* ListaComSentinela_h */