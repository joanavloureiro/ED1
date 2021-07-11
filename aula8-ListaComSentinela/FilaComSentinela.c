#include "FilaComSentinela.h"


#include <stdio.h>
#include <stdlib.h>


struct fila {
    Lista* lista;
};

Fila* InicFila(void){
    Fila* f = (Fila*) malloc(sizeof (Fila));
    f->lista = InicLista();

    return f;
}

//insere fila (SEMPRE no final)
void InsereFila(Fila* f, Aluno* al){
    InsereListaUlt(f->lista, al);
}

//retirna fila (SEMPRE no inicio)
Aluno* RetiraFila (Fila* f){

    return RetiraPosicao(f->lista, 0);
}

//Imprime fila (do inicio ao final)
void ImprimeFila (Fila* f){
    ImprimeLista(f->lista);
}

//libera memoria da fila (e nao dos alunos)
void DestroiFila(Fila* f){
    DestroiLista(f->lista);

    free(f); //ver se precisa destruir aluno
}