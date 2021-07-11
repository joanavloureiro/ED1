#include "Crianca.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct crianca
{
    char* nome;
    int idade;
    char* responsavel;
};

Crianca* InicCrianca (char* nome, int idade, char* responsavel){
    Crianca* novo = (Crianca*) malloc (sizeof (Crianca));
    novo->nome = strdup (nome);
    novo->idade = idade;
    novo->responsavel = strdup(responsavel);

    return novo;
}

void ImprimeCrianca (Crianca* crianca){
    printf("nome: %s,\n idade: %d,\n responsavel: %s \n\n", crianca->nome, crianca->idade, crianca->responsavel);
}

Crianca* RetornaCrianca (Crianca* crianca){
    return crianca;
}

char* RetornaNomeCrianca (Crianca* crianca){
    return crianca->nome;
}

int RetornaIdadeCrianca (Crianca* crianca){
    return crianca->idade;
}

char* RetornaResponsavel (Crianca* crianca){
    return crianca->responsavel;
}

void DestroiCrianca (Crianca* crianca){
    free (crianca->nome);
    free (crianca->responsavel);
    free (crianca);
}