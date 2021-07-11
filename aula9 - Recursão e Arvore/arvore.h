#ifndef arvore_h
#define arvore_h

#include <stdio.h>
#include "Aluno.h" 

typedef struct arv Arv;

//cria arvore vazia
Arv* arv_criavazia (void);

//cria uma arvore com a informacao do no raiz c, e com sub-arvore esq e e sub arvore direita d
Arv* arv_cria(Aluno* al, Arv* e, Arv* d);

//libera o espaco de memoria ocupado pela arvore a
Arv* arv_libera (Arv* a);

//retorna true se arvore estiver vazia e false caso contrario
int arv_vazia (Arv* a);

//indica a ocorrencia (1) ou nao (0) do aluno
int arv_pertence (Arv* a, Aluno* al);

//imprime as informacoes dos nos das arvores
void arv_imprime (Arv* a);

//retorna pai de um dado no
Arv* arv_pai(Arv* a, Aluno* al);

//retorna quantidade de folhas de uma arvore binaria
int folhas(Arv* a);


//retorna o numero de ocorrencias de um dado caracter na arvore
int ocorrencias(Arv* a, Aluno* aluno);

//retorna o campo informacao de um dado no
Aluno* info (Arv* a);

//Função auxiliar para calculo da altura
static int max2 (int a, int b);

//Retorna a altura da árvore binaria
int altura (Arv* a); 


#endif /* arvore_h */