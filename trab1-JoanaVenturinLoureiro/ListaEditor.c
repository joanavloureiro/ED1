#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaEditor.h"

typedef struct celeditor CelulaEditor;

struct celeditor{
    Editor* editor;
    CelulaEditor* prox;
};


struct listaEditor {
    CelulaEditor* Prim;
    CelulaEditor* Ult;
};

ListaEditor* InicListaEditor(void) {
    ListaEditor* lista = (ListaEditor*) malloc (sizeof (ListaEditor));
    lista->Prim = NULL;
    lista->Ult = NULL;

    return lista;
}

void InsereEditorListaEditor (ListaEditor* lista, Editor* editor) {
    CelulaEditor* nova = (CelulaEditor*) malloc (sizeof (CelulaEditor));

    nova->editor = editor;
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

Editor* RetornaEditorNaLista(ListaEditor* lista, char* chave){
    CelulaEditor* p = lista->Prim;
    CelulaEditor* ant = NULL;

    while (p!=NULL && strcmp(RetornaNomeEditor(p->editor), chave)){
        ant = p;
        p = p->prox;
    }

    //lista vazia ou nao encontrou editor
    if(p==NULL){
        return NULL;
    }
    
    return p->editor;
}

void ImprimeListaEditor (ListaEditor* lista) {
    CelulaEditor* p; //ponteiro auxiliar

    for(p = lista->Prim; p!= NULL; p = p->prox){
        ImprimeEditor(p->editor);
    }
}

Editor* RetiraEditorListaEditor (ListaEditor* lista, char* chave){
    CelulaEditor* p = lista->Prim;
    Editor* editor;
    CelulaEditor* ant = NULL;

    //faz a busca
    while (p!=NULL && strcmp(RetornaNomeEditor(p->editor), chave)){
        ant = p;
        p = p->prox;
    }

    //lista vazia ou nao encontrou editor
    if(p==NULL){
        return NULL;
    }

    //atribui a editor de retorno
    editor = p->editor; 

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

    free(p);

    return editor;
    
}

void DestroiListaEditor(ListaEditor* lista){
    CelulaEditor* p = lista->Prim;
    CelulaEditor* t;

    while (p != NULL)
    {
        t = p->prox;
        DestroiEditor(p->editor);
        free(p);
        p=t;
    }

    free(lista);
    
}