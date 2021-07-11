#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaPagina.h"
#include "Pagina.h"

typedef struct celPagina CelulaPagina;

struct celPagina{
    Pagina* pagina;
    CelulaPagina* prox;
};


struct listaPagina {
    CelulaPagina* Prim;
    CelulaPagina* Ult;
};

ListaPagina* InicListaPagina(void) {
    ListaPagina* lista = (ListaPagina*) malloc (sizeof (ListaPagina));
    lista->Prim = NULL;
    lista->Ult = NULL;

    return lista;
}

void InserePagina (ListaPagina* lista, void* pagina) {
    CelulaPagina* nova = (CelulaPagina*) malloc (sizeof (CelulaPagina));

    nova->pagina = pagina;
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

void ImprimeListaPagina ( ListaPagina* lista) {
    CelulaPagina* p; //ponteiro auxiliar

    for(p = lista->Prim; p!= NULL; p = p->prox){
        FILE* saida;
        saida = fopen(RetornaNomePagina(p->pagina), "w"); 

        ImprimePagina(saida, p->pagina);

        fprintf(saida,"\n");
        fclose(saida);
    }
}

void ImprimeUmaPaginaListaPagina (ListaPagina* lista,char* chave){

    CelulaPagina* p = lista->Prim;
    Pagina* pag;
    CelulaPagina* ant = NULL;


    //faz a busca
    while (p!=NULL && strcmp(RetornaNomePagina(p->pagina), chave)){
        ant = p;
        p = p->prox;        
    }

    //atribui a pagina de retorno
    pag = p->pagina; 

    FILE* saida;
    saida = fopen(RetornaNomePagina(pag), "w");

    ImprimePagina(saida, pag);

    fprintf(saida, "\n");
    fclose(saida);

    //free(p);

}

void ImprimeListaLinkPagina (FILE* saida, ListaPagina* lista){
    CelulaPagina* p; //ponteiro auxiliar

    fprintf(saida, "--> Links\n");

    for(p = lista->Prim; p!= NULL; p = p->prox){
        fprintf(saida, "%s ", RetornaNomeArquivoPagina(p->pagina));
        fprintf(saida, "%s \n", RetornaNomePagina(p->pagina));
    }
    fprintf(saida, "\n");
}

void* RetornaPaginaNaLista(ListaPagina* lista, char* chave){
    CelulaPagina* p = lista->Prim;
    CelulaPagina* ant = NULL;

    while (p!=NULL && strcmp(RetornaNomePagina(p->pagina), chave)){
        ant = p;
        p = p->prox;
    }

    //lista vazia ou nao encontrou pagina
    if(p==NULL){
        return NULL;
    }
    
    return p->pagina;
}

void* RetiraPagina (ListaPagina* lista, char* chave){
    CelulaPagina* p = lista->Prim;
    Pagina* pag;
    CelulaPagina* ant = NULL;


    //faz a busca
    while (p!=NULL && strcmp(RetornaNomePagina(p->pagina), chave)){
        ant = p;
        p = p->prox;
        
    }

    //lista vazia ou nao encontrou pagina
    if(p==NULL){
        return NULL;
    }
    
    printf("-------pagina pra apagar!!!!!!!!!------");
    printf("%s", RetornaNomePagina(p->pagina));

    //atribui a pagina de retorno
    pag = p->pagina; 

    printf("OIIIII");

    printf("%s", RetornaNomePagina(pag));

    //se for unico
    if(p == lista->Prim && p == lista->Ult){
        lista->Prim = lista->Ult = NULL;
    }
    else if(p == lista->Prim){ //se for o primeiro
        lista->Prim = p->prox;
    }
    else if(p == lista->Ult){ //se for o ultimo
        lista->Ult = ant;
        lista->Ult->prox = NULL;
    }
    else{ //caso comum
        ant->prox = p->prox;
    }

    RetiraLinkDasPaginas(lista, chave);

    free(p);

    return pag; 
}

void RetiraLinkDasPaginas (ListaPagina* lista, char* chave){
    CelulaPagina* p = lista->Prim;
    CelulaPagina* ant = NULL;
    ListaPagina* links;
    CelulaPagina* l;
    CelulaPagina* lAnt = NULL;

    //for: entra na lista wikED de paginas, while para entrar em cada lista de link de cada página e retirar o link
    for(p = lista->Prim; p!= NULL; p=p->prox){
        links = RetornaListaLinks(p->pagina);
        
        l = links->Prim;

        while (l!=NULL && strcmp(RetornaNomePagina(l->pagina), chave)){
            lAnt = l;
            l = l->prox;
        }

        //se for unico
        if(l == links->Prim && l == links->Ult){
            links->Prim = links->Ult = NULL;
        }
        else if(l == links->Prim){ //se for o primeiro
            links->Prim = p->prox;
        }
        else if(l == links->Ult){ //se for o ultimo
            links->Ult = lAnt;
            links->Ult->prox = NULL;
        }
        else{ //caso comum
            lAnt->prox = l->prox;
        }

    }
    

}

int Caminho(void* pagOrigem, void* pagDest){
    ListaPagina* visita = InicListaPagina();
    ListaPagina* links = RetornaListaLinks (pagOrigem);

    VerificaCaminhosPossiveis(pagOrigem, visita, links);

    if(RetornaPaginaNaLista(visita, RetornaNomePagina(pagDest))){
        CelulaPagina* p = visita->Prim;
        CelulaPagina* t;

        while( p != NULL){
            t = p;
            p = p->prox;
            free(t);
        }

        free(visita);
        return 1;
    }
    else{

        CelulaPagina* p = visita->Prim;
        CelulaPagina* t;

        while( p != NULL){
            t = p;
            p = p->prox;
            free(t);
        }

        free(visita);
        return 0;
    }
    
}

void VerificaCaminhosPossiveis(void* pagOrigem, ListaPagina* visita, ListaPagina* links){
    InserePagina(visita, pagOrigem);

    ListaPagina* listaLink = links;
    CelulaPagina* p;
    Pagina* pag;
    char* nomePag;

    for (p = listaLink->Prim; p!=NULL; p = p->prox) {
        nomePag = RetornaNomePagina(p->pagina);

        pag = RetornaPaginaNaLista(visita, nomePag);

        if(pag == NULL){
            VerificaCaminhosPossiveis(p->pagina, visita, links);
        }
    }
}

void DestroiListaLinkNaPagina(ListaPagina* link){
    CelulaPagina* p = link->Prim;
    CelulaPagina* t;

    while (p != NULL)
    {
        t = p->prox;
        free(p);
        p=t;
    }

    free(link);
}

void DestroiListaPagina(ListaPagina* lista){
    CelulaPagina* p = lista->Prim;
    CelulaPagina* t;

    while (p != NULL)
    {
        t = p->prox;
        DestroiPagina(p->pagina);
        free(p);
        p=t;
    }

    free(lista);
    
}