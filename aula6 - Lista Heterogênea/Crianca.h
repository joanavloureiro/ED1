#ifndef Crianca_h
#define Crianca_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct crianca Crianca;

Crianca* InicCrianca (char* nome, int idade, char* responsavel);

void ImprimeCrianca (Crianca* crianca);

Crianca* RetornaCrianca (Crianca* crianca);

char* RetornaNomeCrianca (Crianca* crianca);

int RetornaIdadeCrianca (Crianca* crianca);

char* RetornaResponsavel (Crianca* crianca);

void DestroiCrianca (Crianca* crianca);

#endif /* Crianca_h */