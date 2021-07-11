#ifndef Produtos_h
#define Produtos_h

#include <stdio.h>
#include "Produtos.h"

typedef struct produto Produto;

Produto* InicProduto (char* nome, float preco, char* categoria);

void ImprimeProduto (Produto* prod);

Produto* RetornaProduto (Produto* prod);

char* RetornaNome (Produto* prod);

float RetornaPreco (Produto* prod);

char* RetornaCategoria (Produto* prod);

void DestroiProduto (Produto* prod);

#endif /* Produtos_h */