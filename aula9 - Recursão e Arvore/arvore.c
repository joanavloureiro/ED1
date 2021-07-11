#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "arvore.h"

struct arv {
    Aluno* info;
    struct arv* esq;
    struct arv* dir;
};

//cria arvore vazia
Arv* arv_criavazia (void){
    return NULL;
}

//cria uma arvore com a informacao do no raiz c, e com sub-arvore esq e e sub arvore direita d
Arv* arv_cria(Aluno* al, Arv* e, Arv* d){
    Arv* a = (Arv*) malloc (sizeof(Arv));
    a->info = al;
    a->dir = d;
    a->esq = e;

    return a;
}

//libera o espaco de memoria ocupado pela arvore a
Arv* arv_libera (Arv* a){
    if(!arv_vazia(a)){
        arv_libera(a->esq);
        arv_libera(a->dir);
        free(a);
    }
    return NULL;
}

//retorna true se arvore estiver vazia e false caso contrario
int arv_vazia (Arv* a){
    if(a==NULL){
        return 1;
    }
    return 0;
}

//indica a ocorrencia (1) ou nao (0) do aluno
int arv_pertence (Arv* a, Aluno* al){
    if(arv_vazia(a)){
        return 0;
    }
    else{
        return a->info==al || arv_pertence(a->esq, al) || arv_pertence(a->dir, al);
    }
}

//imprime as informacoes dos nos das arvores
void arv_imprime (Arv* a){
    printf("<");
    if(!arv_vazia(a)){
        ImprimeAluno(a->info);
        arv_imprime(a->esq);
        arv_imprime(a->dir);
    }
    printf(">");
}

//retorna pai de um dado no
Arv* arv_pai(Arv* a, Aluno* al){
    if (arv_vazia(a)){
        return NULL;
    }
    if((!arv_vazia(a->esq) && !strcmp(RetornaNome(a->esq->info), RetornaNome(al))) ||
         (!arv_vazia(a->dir) && !strcmp(RetornaNome(a->dir->info), RetornaNome(al)))){
        return a;
    }
    
    Arv* aux = arv_pai(a->esq,al);
    if(aux == NULL)
        aux= arv_pai(a->dir,al);
    return aux;
}

//retorna quantidade de folhas de uma arvore binaria
int folhas(Arv* a){
    if(arv_vazia(a->esq) && arv_vazia(a->dir)){
        return 1;
    }
    else if(!arv_vazia(a->esq) && arv_vazia(a->dir)) {
        return folhas(a->dir);
    }
    else if(arv_vazia(a->esq) && !arv_vazia(a->dir)){
        return folhas(a->dir);
    }
    return folhas(a->esq) + folhas(a->dir);
}

//retorna o numero de ocorrencias de um dado caracter na arvore
int ocorrencias(Arv* a, Aluno* al){
    if(arv_vazia(a))
        return 0;
    if(!strcmp(RetornaNome(a->info), RetornaNome(al)))
        return (1 + 
            ocorrencias(a->dir, al) +
            ocorrencias(a->esq,al));

    return (ocorrencias(a->dir, al) +
            ocorrencias(a->esq,al));
}

//retorna o campo informacao de um dado no
Aluno* info (Arv* a){
    if(!arv_vazia(a)){
        return a->info;
    }
    return 0;
}

static int max2 (int a, int b){
    return (a > b) ? a : b;
}

//Retorna a altura da árvore binaria
int altura (Arv* a){
    if(arv_vazia(a))
        return -1;
    else
        return 1 + max2 (altura(a->esq), altura(a->dir));
    
}