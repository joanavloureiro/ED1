#include "listaMat.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cel Celula;

struct cel{
    Matriz* mat;
    Celula* prox;
};

struct lista{
    Celula* Prim;
    Celula* Ult;
};

Lista* inicializaLista(void){
    Lista* lista = (Lista*) malloc (sizeof (Lista));
    lista->Prim = NULL;
    lista->Ult = NULL;
}

void imprimeLista(Lista* l){
    Celula* p;

    for(p = l->Prim; p!=NULL; p= p->prox){
        imprimeMatriz(p->mat);
        printf("\n");
    }
}
//no inciio
void insereLista(Lista* l, Matriz* mat){
    Celula* nova = (Celula*) malloc (sizeof (Celula));
    nova->mat = mat;

    nova->prox = l->Prim;
    l->Prim = nova;

    if(l->Ult == NULL){
        l->Ult=nova;
    }
}

Matriz* retiraLista(Lista* l, int pos){
    int i=0;
    Celula* p = l->Prim;
    Matriz* mat;
    Celula* ant = NULL;

    //faz a busca
    while (p!=NULL && i<pos)
    {
        ant = p;
        p = p->prox;
        i++;
    }

    //lista vazia ou nao encontrou matriz
    if(p==NULL){
        return NULL;
    }

    //atribui a matriz de retorno
    mat = p->mat; 

    //se for unico
    if(p == l->Prim && p == l->Ult){
        l->Prim = l->Ult = NULL;
    }
    else if(p == l->Prim){ //se for o primeiro
        l->Prim = p->prox;
    }
    else if(p == l->Ult){ //se for o ultimo
        l->Ult = ant;
        l->Ult->prox = NULL;
    }
    else{ //caso comum
        ant->prox = p->prox;
    }

    free(p);

    return mat;
    
}

void destroiLista(Lista* l){
    Celula* p = l->Prim;
    Celula* t;

    while (p != NULL)
    {
        t = p->prox;
        destroiMatriz(p->mat);
        free(p);
        p=t;
    }

    free(l);
    
}