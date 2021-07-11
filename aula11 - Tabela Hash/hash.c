#include "hash.h"
#include "palavra.h"
#include <stdlib.h>
#include <string.h>

struct hash{
    Palavra** vet;
    int tamanho;
};

//funcao local!
static int hash (char* s, int tamanho){
    int i;
    int total = 0;

    for (i = 0; s[i] != '\0'; i++){
        total += s[i];
    }

    return (total % tamanho);
}

Hash* inicHash (int tamanho){
    int i;

    Hash *h = (Hash *)malloc(sizeof(Hash));
    h->tamanho = tamanho;

    //inic o vetor da hash
    h->vet = (Palavra**)malloc(tamanho*sizeof(Palavra*));

    //vamos iniciar a tabela com NULL (importante valor de comparação na busca)
    for (i = 0; i < tamanho; i++){
        h->vet[i] = NULL;
    }

    return h;
}

Palavra* acessa (Hash *h, char *string){
    Palavra* p;

    int indice = hash(string, h->tamanho);

    p = buscaPalavra(h->vet[indice], string);

    if (p){
        return p;
    }
    //caso não tenha encontrado na tabela (p é NULL), insere a nova palavra

    p = inicPalavra(string);

    h->vet[indice] = inserePalavralista(h->vet[indice], p);
    return p;
}

void imprimeHash(Hash *h){
    int i;

    for (i = 0; i < h->tamanho; i++){
        printf("\nPosição vet[%d]: \n ", i);
        imprimelista(h->vet[i]);
    }
}

void liberaHash(Hash *h){
    int i;
    for (i = 0; i < h->tamanho; i++){
        liberalistaPalavra(h->vet[i]);
    }

    free(h->vet);
    free(h);
}