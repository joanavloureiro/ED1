#include "listaAlunos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cr {
    int n;    //n de alunos
    float CR; //CR acumulado
};

//definindo as funcoes de callback

static int comparacaoMat(void* aluno, void* mat){
    Aluno* a = (Aluno*)aluno;
    int* imat = (int *)mat;

    //retorna 0 se forem iguais
    if (RetornaMatricula(a) == *imat){
        return 0;
    }

    //Retorna 1 se forem diferentes
    return 1;
}

static int imprime(void* aluno, void* dado){
    ImprimeAluno(aluno);
    return 1; //para continuar loop
}

static int acumula(void* aluno, void* dado){

    struct cr *acumulado = (struct cr *)dado;
    acumulado->CR += RetornaCr(aluno);
    acumulado->n++;
    return 1;
}

//---------------------------------------------

ListaGen* retiraAluno(ListaGen* lista, int matricula){
    return retiraLista(lista, comparacaoMat, &matricula);
}

int pertenceAluno(ListaGen* lista, int matricula){
    return percorreLista(lista, comparacaoMat, &matricula);
}

void imprimeListaAlunos(ListaGen* lista){
    percorreLista(lista, imprime, NULL);
}

float mediaTurma(ListaGen* lista){

    struct cr* acumulado = (struct cr*)malloc(sizeof(struct cr));
    acumulado->CR = 0.0;
    acumulado->n = 0;

    percorreLista(lista, acumula, acumulado);

    float media = acumulado->CR / acumulado->n;

    free(acumulado);
    return media;
}