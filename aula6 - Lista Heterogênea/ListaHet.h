#ifndef ListaHet_h
#define ListaHet_h

#include <stdio.h>
#include "Adulto.h"
#include "Idoso.h"
#include "Crianca.h"

typedef struct listaHet ListaHet;

ListaHet* InicLista(void);

void InsereAdulto (ListaHet* lista, Adulto* adulto);

void InsereCrianca (ListaHet* lista, Crianca* crianca);

void InsereIdoso (ListaHet* lista, Idoso* idoso);

void ImprimeLista (ListaHet* lista);

float ValorParque (ListaHet* lista);

void DestroiLista (ListaHet* lista);

#endif /* ListaHet_h */