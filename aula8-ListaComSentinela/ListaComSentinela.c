#include "ListaComSentinela.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cel Celula;

struct cel{
    Aluno* aluno;
    Celula* prox;
};

struct lista{
    Celula* Prim;
    Celula* Ult;
};

Lista* InicLista(void){
    Lista* lista = (Lista*) malloc (sizeof (Lista));
    lista->Prim = NULL;
    lista->Ult = NULL;

    return lista;
}

void ImprimeLista(Lista* l){
    Celula* p;

    for(p = l->Prim; p!=NULL; p= p->prox){
        ImprimeAluno(p->aluno);
        printf("\n");
    }
}
//no final
void InsereListaUlt(Lista* l, Aluno* al){
    Celula* nova = (Celula*) malloc (sizeof (Celula));
    nova->aluno = al;
    nova->prox = NULL;

    if(l->Ult == NULL){
        l->Prim = l->Ult = nova;
        return;
    }

    l->Ult->prox = nova;
    l->Ult = nova;

    
}

Aluno* RetiraLista(Lista* l, char* chave){
    int i=0;
    Celula* p = l->Prim;
    Aluno* al;
    Celula* ant = NULL;

    //faz a busca
    while (p!=NULL && strcmp(RetornaNome(p->aluno), chave)){
        ant = p;
        p = p->prox;

    }

    //lista vazia ou nao encontrou Aluno
    if(p==NULL){
        return NULL;
    }

    //atribui a Aluno de retorno
    al = p->aluno; 

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

    return al;
    
}

Aluno* RetiraPosicao(Lista* l, int pos){
    int i=0;
    Celula* p = l->Prim;
    Aluno* al;
    Celula* ant = NULL;

    //faz a busca
    while (p!=NULL && i<pos)
    {
        ant = p;
        p = p->prox;
        i++;
    }

    //lista vazia ou nao encontrou Aluno
    if(p==NULL){
        return NULL;
    }

    //atribui a Aluno de retorno
    al = p->aluno; 

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

    return al;
    
}

void DestroiLista(Lista* l){
    Celula* p = l->Prim;
    Celula* t;

    while (p != NULL)
    {
        t = p->prox;
        free(p);
        p=t;
    }

    free(l);
    
}