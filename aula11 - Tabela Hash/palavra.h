#ifndef Palavra_h
#define Palavra_h
#include <stdio.h>

typedef struct palavra Palavra;

Palavra* inicPalavra(char* str);

char* retornaString(Palavra* pal);

void atualizaOcorrencias(Palavra* pal);

int retornaOcorrencias(Palavra* pal);

Palavra* buscaPalavra(Palavra* pal, char* string);

Palavra* inserePalavralista(Palavra* lista, Palavra *p);

int contaPalavraslista(Palavra* pal);

void imprimelista(Palavra* pal);

void liberalistaPalavra(Palavra* pal);

#endif