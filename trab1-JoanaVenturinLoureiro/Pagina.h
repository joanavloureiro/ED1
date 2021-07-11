#ifndef Pagina_h
#define Pagina_h

#include "ListaPagina.h"
#include "ListaContribuicao.h"

typedef struct pagina Pagina;

Pagina* InicPagina (char* nomePag, char* nomeArq);

void InsereContribuicaoPagina (Pagina* pagina, Contribuicao* contrib);

void InsereLinkPagina (Pagina* pagina, Pagina* link);

void RetiraContribuicaoPagina (Pagina* pagina, Contribuicao* contrib);

//retira um link da lista de links na pagina
void RetiraLinkPagina (Pagina* pagina, Pagina* link);

char* RetornaNomeArquivoPagina (Pagina* pag);

char* RetornaNomePagina (Pagina* pag);

ListaContribuicao* RetornaListaContribuicao (Pagina* pag);

ListaPagina* RetornaListaLinks (Pagina* pag);

void ImprimePagina (FILE* saida, Pagina* pag);

void DestroiPagina (Pagina* pag);

#endif /* Pagina_h */