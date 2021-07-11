#include "ListaHet.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CRIANCA 0
#define IDOSO 1
#define ADULTO 2

typedef struct cel Celula;

struct cel
{
    Celula* prox;
    void* item;
    int tipo;
};

struct listaHet
{
    Celula* Prim;
    Celula* Ult;
};


ListaHet* InicLista(){
    ListaHet* lista = (ListaHet*)malloc (sizeof(ListaHet));
    lista->Prim = NULL;
    lista->Ult = NULL;
    
    return lista;
}

void InsereAdulto (ListaHet* lista, Adulto* adulto){
    Celula* nova = (Celula*)malloc (sizeof(Celula));
    nova->item = adulto;
    nova->tipo = ADULTO;
    nova->prox = lista->Prim;
    lista->Prim = nova;
    if(lista->Ult != NULL){
        lista->Ult = nova;
    }
}

void InsereCrianca (ListaHet* lista, Crianca* crianca){
    Celula* nova = (Celula*)malloc (sizeof(Celula));
    nova->item = crianca;
    nova->tipo = CRIANCA;
    nova->prox = lista->Prim;
    lista->Prim = nova;
    if(lista->Ult != NULL){
        lista->Ult = nova;
    }
}

void InsereIdoso (ListaHet* lista, Idoso* idoso){
    Celula* nova = (Celula*)malloc (sizeof(Celula));
    nova->item = idoso;
    nova->tipo = IDOSO;
    nova->prox = lista->Prim;
    lista->Prim = nova;
    if(lista->Ult != NULL){
        lista->Ult = nova;
    }
}


void ImprimeLista (ListaHet* lista){
    Celula* p;

    
    for(p = lista->Prim; p!=NULL; p = p->prox){
        if (p->tipo == ADULTO){
            printf("ADULTO: \n");
            ImprimeAdulto(p->item);
            printf("\n");
        }
        if (p->tipo == CRIANCA){
            printf("CRIANCA: \n");
            ImprimeCrianca(p->item);
            printf("\n");
        }
        if (p->tipo == IDOSO){
            printf("IDOSO: \n");
            ImprimeIdoso(p->item);
            printf("\n");
        }
    }
}

float ValorParque (ListaHet* lista){
    Celula* p = lista->Prim;
    float valor = 0.0;

    while(p!= NULL){
        if (p->tipo == ADULTO)
        {
            valor = valor + 20.0;
        }
        if (p->tipo == CRIANCA)
        {
            valor = valor + 10.0;
        }
        if (p->tipo == IDOSO)
        {
            valor = valor + 5.0;
        }
        p = p->prox;
    }
    return valor;
}

void DestroiLista (ListaHet* lista){
    Celula* p = lista->Prim;
    Celula* t;

    while (p!= NULL){
        t = p->prox;        
        free(p);
        p = t;
    }
}