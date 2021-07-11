#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

int main (){

    //criando alunos para teste
    Aluno* aline = InicAluno("Aline", 101, 5.2);
    Aluno* carmen = InicAluno("Carmen", 500, 2.79);
    Aluno* odete = InicAluno("Odete", 755, 3.1);
    Aluno* pedro = InicAluno("Pedro", 321, 4.0);
    Aluno* raissa = InicAluno("Raissa", 111, 10.0);
    Aluno* tiago = InicAluno("Tiago", 909, 9.0);
    Aluno* joaquim= InicAluno("Joaquim", 909, 9.0);

    //Cria uma arvore para teste
    Arv* a = arv_cria(aline, 
                arv_cria(carmen, 
                    arv_criavazia(), 
                    arv_cria(odete, arv_criavazia(),
                        arv_criavazia())
            ), 
            arv_cria(pedro, 
            arv_cria(raissa, arv_criavazia(), 
                arv_criavazia()), 
            arv_cria(tiago, arv_criavazia(),
                arv_criavazia())
                )
            );

    arv_imprime(a);
    printf("\n");

    //Verifica se "Carmen" pertence à árvore
    int pertence = arv_pertence(a, carmen);
    printf("Aluno carmen pertence? %d\n", pertence);

    //Verifica se joaquim pertence à árvore
    pertence = pertence = arv_pertence(a, joaquim);
    printf("Aluno joaquim pertence? %d\n", pertence);

    //Retorna o pai de carmen (aline)
    Arv* pai = arv_pai(a, carmen);
    printf("Pai de carmen: %s \n", RetornaNome(info(pai)));

    //Retorna o número de folhas da árvore (3)
    int f = folhas(a);
    printf("Numero de folhas da arvore: %d \n", f);

    //Retorna o número de ocirrencias de "Raissa" (1)
    int i = ocorrencias(a, raissa);
    printf("Numero de ocorrencias de raissa: %d\n", i);

    //Retorna altura da arvore (2)
    int alt = altura(a);
    printf("Altura da arvore: %d\n", alt);

    //Libera a memória alocada
    a = arv_libera(a);
    DestroiAluno(aline);
    DestroiAluno(carmen);
    DestroiAluno(odete);
    DestroiAluno(pedro);
    DestroiAluno(raissa);
    DestroiAluno(tiago);

    return 0;
}