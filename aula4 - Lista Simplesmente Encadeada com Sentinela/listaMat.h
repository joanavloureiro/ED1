#ifndef listaMat_h
#define listaMat_h

#include <stdio.h>
#include "Matriz.h"

typedef struct lista Lista;

Lista* inicializaLista(void);

void insereLista(Lista* lista, Matriz* mat);

void imprimeLista(Lista* lista);

Matriz* retiraLista(Lista* lista, int pos);

void destroiLista(Lista* lista);


#endif /* listaMat */