#define _GNU_SOURCE

#include <stdio.h>
#include "listaAlunos.h"

int main(int argc, char const *argv[])
{
    ListaGen* lista = criaLista();


    Aluno* carmen = InicAluno("Carmen", 500, 2.79);
    lista = insereLista(lista, carmen);

    Aluno* aline = InicAluno("Aline", 101, 5.2);
    lista = insereLista(lista, aline);

    Aluno* cassia = InicAluno("Cassia", 231, 7.0);
    lista = insereLista(lista, cassia);

    Aluno* odete = InicAluno("Odete", 755, 9.1);
    lista = insereLista(lista, odete);

    Aluno* joaquim = InicAluno("Joaquim", 123, 6.2);
    lista = insereLista(lista, joaquim);

    Aluno* frederico = InicAluno("Frederico", 888, 10.0);
    lista = insereLista(lista, frederico);

    Aluno* jose = InicAluno("Jose", 424, 8.8);
    lista = insereLista(lista, jose);

    imprimeListaAlunos(lista);

    lista = retiraAluno(lista, 231);

    printf("\nImprime Lista de Alunos:\n\n");
    imprimeListaAlunos(lista);

    //Verificar se aluno esta na lista
    int i = pertenceAluno(lista, 1);
    if (i == 0){
        printf("\nAluno esta na lista!\n");
    }
    else{
        printf("Aluno NAO esta na lista!\n");
    }

    //Retorna a media
    printf("\nA media da Turma é: %.2f\n", mediaTurma(lista)); 

    liberaLista(lista);

    DestroiAluno(carmen);
    DestroiAluno(aline);
    DestroiAluno(cassia);
    DestroiAluno(odete);
    DestroiAluno(joaquim);
    DestroiAluno(frederico);
    DestroiAluno(jose);

    return 0;
}
