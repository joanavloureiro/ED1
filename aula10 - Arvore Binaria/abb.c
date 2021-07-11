#include "abb.h"
#include <stdio.h>
#include <stdlib.h>

struct arv {
    Aluno* info;
    Arv* esq;
    Arv* dir;
};

Arv* abb_cria (void){
    return NULL;
}

void abb_imprime( Arv* a){
    if(a != NULL){
        abb_imprime(a->esq);
        ImprimeAluno(a->info);
        abb_imprime(a->dir);
    }
}

//retorna ponteiro para o nó que contem aluno ou NULL
Arv* abb_busca (Arv* r, int chave){
    if(r == NULL){
        return NULL;
    }
    else if(RetornaMatricula(r->info) > chave){
        return abb_busca(r->esq, chave);
    }
    else if(RetornaMatricula(r->info) < chave){
        return abb_busca(r->dir, chave);
    }
    else{
        return r;
    }
}

Arv* abb_insere (Arv* a, Aluno* al){
    if(a==NULL){
        a = (Arv*) malloc (sizeof(Arv));
        a->info = al;
        a->esq = a->dir = NULL;
    }
    
    //procura aonde inserir
    else if(RetornaMatricula(al) < RetornaMatricula(a->info)){
        a->esq = abb_insere(a->esq, al);
    }
    else{
        a->dir = abb_insere(a->dir, al);
    }
    return a;   
}

Arv* abb_retira (Arv* r, int v){
    if(r == NULL){
        return NULL;
    }
    else if( RetornaMatricula(r->info) > v){
        r->esq = abb_retira(r->esq, v);
    }
    else if( RetornaMatricula(r->info) < v){
        r->dir = abb_retira(r->dir, v);
    }
    //achou!
    else
    {
        if(r->esq == NULL && r->dir == NULL){
            free(r);
            r = NULL;
        }
        else if(r->esq == NULL){
            Arv* t = r;
            r = r->dir;
            free(t);
        }
        else if(r->dir == NULL){
            Arv* t = r;
            r = r->esq;
            free(t);
        }
        else{
            Arv* f = r->esq;

            while(f->dir != NULL){
                f = f->dir;
            }

            Aluno* t = r->info;

            r->info= f->info;
            f->info = t;

            r->esq = abb_retira(r->esq, v);

        }
    }
    return r;
    
}

int abb_vazia (Arv* a){
    if(a==NULL){
        return 1;
    }
    return 0;
}

Arv* abb_libera(Arv* a){
    if(!abb_vazia(a)){
        abb_libera(a->esq);
        abb_libera(a->dir);
        free(a);
    }
    return NULL;
}