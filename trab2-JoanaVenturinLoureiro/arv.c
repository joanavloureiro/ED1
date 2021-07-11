#include "arv.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct arv {
    char valor;
    float numero;
    Arv* esq;
    Arv* dir;
};

Arv* abb_cria (void){
    return NULL;
}

Arv* abb_insere (Arv* a){
    a = (Arv*) malloc (sizeof(Arv));

    a->esq = a->dir = NULL;
    a->valor = '\0';
    a->numero = -1; //nao ha valores negativos como exemplo

}

void abb_imprime( Arv* a){
    if(a != NULL){
        abb_imprime(a->esq);

        //printa como diferentes tipos de variaveis se for o simbolo ou o numero
        if(Simbolo){
            printf("%c", a->valor);
        }

        if(Numero){
            printf("%.2f", a->numero);
        }
        
        abb_imprime(a->dir);
    }
}

int Simbolo (char c){
    if (c <= '9' && c >= '0'){
        return 1;
    } 
    else{
        return 0;
    }
}

int Numero (char c){
    if(c == '+' || c == '-' || c == '/' || c == '*'){
        return 1;
    }
    else{
        return 0;
    }

}

float resultadoEquacao (Arv* arv){

    //retorna diretamente o numero se n houver operaçoes a serem resolvidas
    if (arv->esq==NULL && arv->dir==NULL){
        return arv->numero;
    }

    //representa numeros dos nós esquerdos e será o resultado de cada +, -, / ou *
    float numE = resultadoEquacao(arv->esq);

    //representa numeros dos nós direitos
    float numD = resultadoEquacao(arv->dir);

    //faz operacoes matematicas
    if (arv->valor == '+'){
        numE += numD;
    }
    
    if (arv->valor == '-'){
        numE -= numD;
    }

    if (arv->valor == '/'){
        numE /= numD;
    }
    
    if (arv->valor == '*'){
        numE *= numD;
    }

    
    return numE;
}

Arv* abb_parse (Arv* arv, char* item, int* pos){

    //se for abrindo parenteses
    if(item[*pos] == '('){
        //se proximo item tambem for parenteses, ja aloca espaço para proxima parte da equaçao
        if(item[(*pos) + 1]=='('){
            *pos += 1; //passa para a proxima posição na string

            if (arv->esq==NULL){ //verifica arvore vazia
                arv->esq = abb_insere(arv->esq);//aloca espaço para a arv
            } 

            arv->esq = abb_parse(arv->esq, item, pos); //vai para o proximo nó a esquerda
        }
        else{
            *pos += 1; //passa para a proxima posição na string se fosse um numero
        }


    }  

    //se for numero 
    if(item[*pos] <= '9' && item[*pos] >= '0'){
        char *n = strtok(item + *pos, ")"); //lê valor até )

        arv->numero = atof(n); //armazena o numero em float

        int tam = strlen(n) + 1; //calcula tamanho do numero

        *pos += tam; //passa para a posição apos final do numero

        return arv; //caminha pro nó pai
    }

    //se for operador
    if(item[*pos] == '+' || item[*pos] == '-' || item[*pos] == '/' || item[*pos] == '*'){
        arv->valor = item[*pos]; //armazena o operador
        *pos += 1; //passa para a proxima posição

        if (arv->dir==NULL){ //verifica arvore vazia
            arv->dir = abb_insere(arv->dir); //aloca espaço para a arv
        }

        arv->dir = abb_parse(arv->dir, item, pos); //vai para o proximo nó a direita
    }

    //fechando equaçao ou parte dela
    if( item[*pos] == ')'){
        *pos += 1; //passa para a proxima posição na string
        return arv; //retorna ao nó anterior
    }
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