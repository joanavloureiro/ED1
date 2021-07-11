#ifndef ListaDpl_h
#define ListaDpl_h

#include <stdio.h>
#include "Produtos.h"

typedef struct listadpl ListaDpl;

ListaDpl* InicLista(void);

ListaDpl* InsereLista (ListaDpl* lista, Produto* produto);

ListaDpl* RetiraLista (ListaDpl* lista, char* chave);

void ImprimeLista (ListaDpl* lista);

void DestroiLista (ListaDpl* lista);

#endif /* ListaDpl_h */