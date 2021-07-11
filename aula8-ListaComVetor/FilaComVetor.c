#include "FilaComVetor.h"
#include <stdio.h>
#include <stdlib.h>

#define TAM 10

struct fila {
    int ini;
    int n;
    Aluno* alunos[TAM];
};

Fila* InicFila(void){
    Fila* f = (Fila*) malloc(sizeof (Fila));
    f->ini = 0;
    f->n = 0;
    return f;
}

//insere fila (SEMPRE no final)
void InsereFila(Fila* f, Aluno* al){
    //testa se fila esta cheia
    if(!f || f->n >= TAM){
        printf ("\nPilha invalida ou cheia!\n");
        return;
    }
    //achando o final da fila circular
    int pos = (f->ini + f->n) % TAM;
    //inserindo no final
    f->alunos[pos] = al;
    //incrementando numero alunos
    f->n++;
}

//retirna fila (SEMPRE no inicio)
Aluno* RetiraFila (Fila* f){
    if(!f || f->n == 0){
        printf ("\nPilha invalida ou cheia!\n");
        return NULL;
    }

    Aluno* al = f->alunos[f->ini];

    //faz incremento circular do indice do inicio
    f->ini = (f->ini+1)%TAM;

    f->n--;

    return al;
}

//Imprime fila (do inicio ao final)
void ImprimeFila (Fila* f){
    int i;
    int pos = 0;

    if(!f){
        return;
    }

    for(i=0; i<f->n; i++){
        ImprimeAluno(f->alunos[pos]);
    }
}

//libera memoria da fila (e nao dos alunos)
void DestroiFila(Fila* f){
    if(!f){
        return;
    }

    free(f); //ver se precisa destruir aluno
}