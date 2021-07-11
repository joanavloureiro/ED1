#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PilhaDpl.h"
#define MaxTam 100
#define REPROVADO 0
#define APROVADO 1

struct indicePilha{
    int Topo;
    int Base;
};

struct tipoPilhaDupla {
    Aluno* Alunos[MaxTam];
    IndicePilha Pilha1;
    IndicePilha Pilha2;
};


TipoPilhaDupla* InicPilha (){
TipoPilhaDupla* p = (TipoPilhaDupla*) malloc (sizeof (TipoPilhaDupla));
p->Pilha1.Base = 0;
p->Pilha1.Topo = -1; 

p->Pilha2.Base = MaxTam -1;
p->Pilha2.Topo = MaxTam; 

return p;
}

void push (TipoPilhaDupla* p, Aluno* al){
    if(!p ||( p->Pilha1.Topo == p->Pilha2.Topo -1 )){
        printf("p cheia!\n");
        return;
    }
    if(!al){
        printf("Animal invalido!\n");
        return;
    }

    if(RetornaCr(al) >= 6){
        p->Alunos[p->Pilha1.Topo+1] = al;
        p->Pilha1.Topo++;
    }
    if(RetornaCr(al) < 6){
        p->Alunos[p->Pilha2.Topo-1] = al;
        p->Pilha2.Topo--;
    }
}

Aluno* pop (TipoPilhaDupla* p, int tipo){

    if(!p || p->Pilha1.Topo == -1 || p->Pilha2.Topo == MaxTam){
            printf("Pilha vazia!\n");
            return NULL;
    }
    Aluno* aluno;

    if(tipo == APROVADO){
        aluno = p->Alunos[p->Pilha1.Topo];
        p->Pilha1.Topo--;
    }

    if(tipo == REPROVADO){
        aluno = p->Alunos[p->Pilha2.Topo];
        p->Pilha2.Topo++;
    }

    return aluno;
}

void ImprimePilha (TipoPilhaDupla* pilha){
    if(!pilha)
        return;

    int i;
    printf("\nPILHA 1:\n");
    for(i=(pilha->Pilha1.Topo);i>=0;i--)
        ImprimeAluno(pilha->Alunos[i]);

    printf("\nPILHA 2:\n");
    for(i=(pilha->Pilha2.Topo);i<MaxTam;i++)
        ImprimeAluno(pilha->Alunos[i]);
}

void DestroiPilha (TipoPilhaDupla* pilha){
    if(!pilha)
        return;
    
    free(pilha);
}