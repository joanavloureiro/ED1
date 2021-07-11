#include "Adulto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct adulto
{
    char* nome;
    int idade;
    float cpf;
};

Adulto* InicAdulto (char* nome, int idade, int cpf){
    Adulto* novo = (Adulto*) malloc (sizeof (Adulto));
    novo->nome = strdup (nome);
    novo->idade = idade;
    novo->cpf = cpf;

    return novo;
}

void ImprimeAdulto (Adulto* adulto){
    printf("nome: %s,\n idade: %d,\n cpf: %.2f \n\n", adulto->nome, adulto->idade, adulto->cpf);
}

Adulto* RetornaAdulto (Adulto* adulto){
    return adulto;
}

char* RetornaNomeAdulto (Adulto* adulto){
    return adulto->nome;
}

int RetornaIdadeAdulto (Adulto* adulto){
    return adulto->idade;
}

float RetornaCpf (Adulto* adulto){
    return adulto->cpf;
}

void DestroiAdulto (Adulto* adulto){
    free (adulto->nome);
    free (adulto);
}