#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pagina.h"


struct pagina {
    char* nomePagina;
    char* nomeArquiv;
    ListaContribuicao* ListaContrib;
    ListaPagina* ListaLinks;
};

Pagina* InicPagina (char* nomePag, char* nomeArq) {
    Pagina* pag = (Pagina*) malloc (sizeof (Pagina));

    pag->nomePagina = strdup(nomePag);
    pag->nomeArquiv = strdup(nomeArq);
    pag->ListaContrib = InicListaContribuicao();
    pag->ListaLinks = InicListaPagina();

    return pag;
}

void InsereContribuicaoPagina (Pagina* pagina, Contribuicao* contrib) {
    InsereContribuicao(pagina->ListaContrib, contrib);
}

void InsereLinkPagina (Pagina* pagina, Pagina* link) {
    InserePagina(pagina->ListaLinks, link);
}

void RetiraContribuicaoPagina (Pagina* pagina, Contribuicao* contrib) {

    RetiraContribuicao(pagina->ListaContrib, RetornaNomeContribuicao(contrib));
}

void RetiraLinkPagina (Pagina* pagina, Pagina* link) {
    Pagina* deletapag;

    deletapag = RetiraPagina(pagina->ListaLinks, RetornaNomePagina(link));
}

char* RetornaNomeArquivoPagina (Pagina* pag){
    return pag->nomeArquiv;
}

char* RetornaNomePagina (Pagina* pag){
    return pag->nomePagina;
}

ListaContribuicao* RetornaListaContribuicao (Pagina* pag){
    return pag->ListaContrib;
}

ListaPagina* RetornaListaLinks (Pagina* pag){
    return pag->ListaLinks;
}

void ImprimePagina (FILE* saida, Pagina* pag){
    fprintf(saida, "%s\n\n", pag->nomePagina);

    if(pag->ListaContrib != NULL){
       ImprimeListaHistoricoContribuicao(saida, pag->ListaContrib);
    } 
    if(pag->ListaLinks != NULL){
       ImprimeListaLinkPagina(saida, pag->ListaLinks);
    }
    if(pag->ListaContrib != NULL){
       ImprimeListaContribuicao(saida, pag->ListaContrib);
    } 
    
}

void DestroiPagina (Pagina* pag){
    free (pag->nomePagina);
    free (pag->nomeArquiv);
    DestroiListaLinkNaPagina(pag->ListaLinks);
    DestroiListaContribuicaoNaPagina(pag->ListaContrib);
    
    free (pag);
}