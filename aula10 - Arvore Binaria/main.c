#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abb.h"

int main (){

    //criando alunos para teste
    Aluno* aline = InicAluno("Aline", 101, 5.2);
    Aluno* carmen = InicAluno("Carmen", 500, 2.79);
    Aluno* odete = InicAluno("Odete", 755, 3.1);
    Aluno* pedro = InicAluno("Pedro", 321, 4.0);
    Aluno* raissa = InicAluno("Raissa", 111, 10.0);
    Aluno* tiago = InicAluno("Tiago", 909, 9.0);
    Aluno* joaquim= InicAluno("Joaquim", 900, 9.0);

    //Criando arvore para teste
    Arv* a = abb_cria();

    //Inserindo alunos na arvore
    a = abb_insere(a, aline);
    a = abb_insere(a, carmen);
    a = abb_insere(a, odete);
    a = abb_insere(a, pedro);
    a = abb_insere(a, raissa);
    a = abb_insere(a, tiago);
    

    printf("Imprimindo arvore abb:\n");
    abb_imprime(a);
    printf("\n\n");

    //retirando tiago
    a = abb_retira(a, 909); 


    printf("Imprimindo arvore abb sem tiago:\n");
    abb_imprime(a);
    printf("\n\n");

    //Insere aluno novo e antigo
    a = abb_insere(a, joaquim);
    a = abb_insere(a, tiago);
    
    
    printf("Imprimindo arvore abb:\n");
    abb_imprime(a);
    printf("\n\n");

    //retirando aline
    a = abb_retira(a, 101); 


    printf("Imprimindo arvore abb:\n");
    abb_imprime(a);
    printf("\n\n");

   
    a = abb_libera(a);
    DestroiAluno(aline);
    DestroiAluno(carmen);
    DestroiAluno(odete);
    DestroiAluno(pedro);
    DestroiAluno(raissa);
    DestroiAluno(tiago);
    DestroiAluno(joaquim);

    return 0;
}