#ifndef Idoso_h
#define Idoso_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct idoso Idoso;

Idoso* InicIdoso (char* nome, int idade, float plano);

void ImprimeIdoso (Idoso* idoso);

Idoso* RetornaIdoso (Idoso* idoso);

char* RetornaNomeIdoso (Idoso* idoso);

int RetornaIdadeIdoso (Idoso* idoso);

float RetornaPlanoDeSaude (Idoso* idoso);

void DestroiIdoso (Idoso* idoso);

#endif /* Idoso_h */