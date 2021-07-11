#include "Produtos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct produto
{
    char* nome;
    float preco;
    char* categoria;
};

Produto* InicProduto (char* nome, float preco, char* categoria){
    Produto* prod = (Produto*) malloc (sizeof (Produto));
    prod->nome = strdup (nome);
    prod->preco = preco;
    prod->categoria = strdup (categoria);

    return prod;
}

void ImprimeProduto (Produto* prod){
    printf("nome: %s,\n preco: %.2f,\n categoria: %s \n\n", prod->nome, prod->preco, prod->categoria);
}

Produto* RetornaProduto (Produto* prod){
    return prod;
}

char* RetornaNome (Produto* prod){
    return prod->nome;
}

float RetornaPreco (Produto* prod){
    return prod->preco;
}

char* RetornaCategoria (Produto* prod){
    return prod->categoria;
}

void DestroiProduto (Produto* prod){
    free (prod->nome);
    free (prod->categoria);
    free (prod);
}

