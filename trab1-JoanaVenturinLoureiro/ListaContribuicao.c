#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaContribuicao.h"

typedef struct celContribuicao CelulaContribuicao;

struct celContribuicao{
    Contribuicao* contribuicao;
    CelulaContribuicao* prox;
};


struct listaContribuicao {
    CelulaContribuicao* Prim;
    CelulaContribuicao* Ult;
};

ListaContribuicao* InicListaContribuicao(void) {
    ListaContribuicao* lista = (ListaContribuicao*) malloc (sizeof (ListaContribuicao));
    lista->Prim = NULL;
    lista->Ult = NULL;

    return lista;
}

void InsereContribuicao (ListaContribuicao* lista, Contribuicao* contrib) {
    CelulaContribuicao* nova = (CelulaContribuicao*) malloc (sizeof (CelulaContribuicao));

    nova->contribuicao = contrib;
    nova->prox = NULL;

    if (lista->Ult == NULL && lista->Prim == NULL){
        lista->Ult = nova;
        lista->Prim = nova;
    }
    else{
        lista->Ult->prox = nova;
        lista->Ult = nova;
    }
    
}

void ImprimeListaContribuicao (FILE* saida, ListaContribuicao* lista) {
    CelulaContribuicao* p; //ponteiro auxiliar

    fprintf(saida, "--> Textos\n");

    for(p = lista->Prim; p!= NULL; p = p->prox){
        ImprimeContribuicao(saida, p->contribuicao);
    }
}

void ImprimeListaHistoricoContribuicao(FILE* saida, ListaContribuicao* lista){
    CelulaContribuicao* p;
    Editor* editor;

    fprintf(saida, "--> Historico de contribuicoes\n");

    for (p = lista->Prim; p != NULL; p = p->prox)
    {
        
        ImprimeHistoricoContribuicao(saida, p->contribuicao);
    }
    
    fprintf(saida, "\n");
}

Contribuicao* RetornaContribuicaoNaLista(ListaContribuicao* lista, char* chave){
    CelulaContribuicao* p = lista->Prim;
    CelulaContribuicao* ant = NULL;

    while (p!=NULL && strcmp(RetornaNomeContribuicao(p->contribuicao), chave)){
        ant = p;
        p = p->prox;
    }

    //lista vazia ou nao encontrou contribuicao
    if(p==NULL){
        return NULL;
    }
    
    return p->contribuicao;
}

Contribuicao* RetiraContribuicao (ListaContribuicao* lista, char* chave){
    CelulaContribuicao* p = lista->Prim;
    Contribuicao* contrib;
    CelulaContribuicao* ant = NULL;

    //faz a busca
    while (p!=NULL && strcmp(RetornaNomeContribuicao(p->contribuicao), chave)){
        ant = p;
        p = p->prox;
    }

    //lista vazia ou nao encontrou contribuicao
    if(p==NULL){
        return NULL;
    }

    AlteraRetirado(p->contribuicao);

    //atribui a contribuicao de retorno
    contrib = p->contribuicao;

    //free(p);

    return contrib; 
}

void DestroiListaContribuicaoNaPagina(ListaContribuicao* contrib){
    CelulaContribuicao* p = contrib->Prim;
    CelulaContribuicao* t;

    while (p != NULL)
    {
        t = p->prox;
        free(p);
        p=t;
    }

    free(contrib);
}

void DestroiListaContribuicao(ListaContribuicao* lista){
    CelulaContribuicao* p = lista->Prim;
    CelulaContribuicao* t;

    while (p != NULL)
    {
        t = p->prox;
        DestroiContribuicao(p->contribuicao);
        free(p);
        p=t;
    }

    free(lista);
    
}