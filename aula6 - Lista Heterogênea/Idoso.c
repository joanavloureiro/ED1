#include "Idoso.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct idoso
{
    char* nome;
    int idade;
    float planoDeSaude;
};

Idoso* InicIdoso (char* nome, int idade, float plano){
    Idoso* novo = (Idoso*) malloc (sizeof (Idoso));
    novo->nome = strdup (nome);
    novo->idade = idade;
    novo->planoDeSaude = plano;

    return novo;
}

void ImprimeIdoso (Idoso* idoso){
    printf("nome: %s,\n idade: %d,\n plano de saude: %.2f \n\n", idoso->nome, idoso->idade, idoso->planoDeSaude);
}

Idoso* RetornaIdoso (Idoso* idoso){
    return idoso;
}

char* RetornaNomeIdoso (Idoso* idoso){
    return idoso->nome;
}

int RetornaIdadeIdoso (Idoso* idoso){
    return idoso->idade;
}

float RetornaplanoDeSaude (Idoso* idoso){
    return idoso->planoDeSaude;
}

void DestroiIdoso (Idoso* idoso){
    free (idoso->nome);
    free (idoso);
}