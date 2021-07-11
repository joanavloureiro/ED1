#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PilhaDpl.h"
#define REPROVADO 0
#define APROVADO 1

int main(int argc, const char * argv[]){
    Aluno* deletaAluno;

    int i= 0, j=1;
    //criando alunos para teste
    Aluno* carmen = InicAluno("Carmen", 500, 2.79);
    Aluno* odete = InicAluno("Odete", 755, 3.1);
    Aluno* pedro = InicAluno("Pedro", 321, 4.0);
    Aluno* aline = InicAluno("Aline", 101, 5.2);
    Aluno* joaquim = InicAluno("Joaquim", 123, 6.2);
    Aluno* cassia = InicAluno("Cassia", 231, 7.0);
    Aluno* jose = InicAluno("Jose", 424, 8.8);
    Aluno* frederico = InicAluno("Frederico", 888, 10.0);
    

    TipoPilhaDupla* PilhaAlunos = InicPilha();

    push(PilhaAlunos, joaquim);
    push(PilhaAlunos, frederico);
    push(PilhaAlunos, odete);
    push(PilhaAlunos, carmen);
    push(PilhaAlunos, jose);
    push(PilhaAlunos, cassia);
    push(PilhaAlunos, pedro);
    push(PilhaAlunos, aline);

    printf("Imprimindo a pilha:\n");
    ImprimePilha(PilhaAlunos);

    deletaAluno = pop(PilhaAlunos, i);
    DestroiAluno(deletaAluno);
    printf("Imprimindo a pilha:\n");
    ImprimePilha(PilhaAlunos);

    deletaAluno = pop(PilhaAlunos, i);
    DestroiAluno(deletaAluno);
    printf("Imprimindo a pilha:\n");
    ImprimePilha(PilhaAlunos);

    deletaAluno = pop(PilhaAlunos, j);
    DestroiAluno(deletaAluno);
    printf("Imprimindo a pilha:\n");
    ImprimePilha(PilhaAlunos);

    deletaAluno = pop(PilhaAlunos, j);
    DestroiAluno(deletaAluno);


    printf("Imprimindo a pilha:\n");
    ImprimePilha(PilhaAlunos);
    

    DestroiPilha(PilhaAlunos);

    DestroiAluno(carmen);
    DestroiAluno(joaquim);
    DestroiAluno(frederico);
    DestroiAluno(odete);

    return 0;
}