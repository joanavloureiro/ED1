#ifndef Adulto_h
#define Adulto_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct adulto Adulto;

Adulto* InicAdulto (char* nome, int idade, int cpf);

void ImprimeAdulto (Adulto* adulto);

Adulto* RetornaAdulto (Adulto* adulto);

char* RetornaNomeAdulto (Adulto* adulto);

int RetornaIdadeAdulto (Adulto* adulto);

float RetornaCpf (Adulto* adulto);

void DestroiAdulto (Adulto* adulto);

#endif /* Adulto_h */