#ifndef ListaContribuicao_h
#define ListaContribuicao_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Contribuicao.h"
#include "Editor.h"
#include "ListaEditor.h"

typedef struct listaContribuicao ListaContribuicao;

ListaContribuicao* InicListaContribuicao();

void InsereContribuicao (ListaContribuicao* lista, Contribuicao* contrib);

void ImprimeListaContribuicao (FILE* saida, ListaContribuicao* lista);

void ImprimeListaHistoricoContribuicao(FILE* saida, ListaContribuicao* lista);

Contribuicao* RetornaContribuicaoNaLista(ListaContribuicao* lista, char* chave);

Contribuicao* RetiraContribuicao (ListaContribuicao* lista, char* chave);

void DestroiListaContribuicaoNaPagina(ListaContribuicao* contrib);

void DestroiListaContribuicao (ListaContribuicao* lista);

#endif /* ListaContribuicao_h */