#include <stdio.h>
#include <stdlib.h>
#include "Aluno.h"

//descomentar para usar fila com vetor
//#include "FilaComVetor.h"

//descomentar para usar fila com sentinela
#include "FilaComSentinela.h"
#include "ListaComSentinela.h"


int main(){
    //criando alunos para teste
    Aluno* carmen = InicAluno("Carmen", 500, 2.79);
    Aluno* odete = InicAluno("Odete", 755, 3.1);
    Aluno* pedro = InicAluno("Pedro", 321, 4.0);
    Aluno* aline = InicAluno("Aline", 101, 5.2);
    
    Fila* f = InicFila();
    Fila* f2 = InicFila();

    InsereFila(f, carmen);
    InsereFila(f, odete);
    InsereFila(f, pedro);
    InsereFila(f, aline);

    printf("\nImprimindo Fila f:\n");
    ImprimeFila(f);

    InsereFila(f2, RetiraFila(f));

    printf("\nImprimindo Fila f sem Carmen:\n");
    ImprimeFila(f);

    printf("\nImprimindo Fila f2:\n");
    ImprimeFila(f2);

    InsereFila(f2, RetiraFila(f));
    printf("\nImprimindo Fila f sem Odete:\n");
    ImprimeFila(f);

    printf("\nImprimindo Fila f2:\n");
    ImprimeFila(f2);

    DestroiAluno (carmen);
    DestroiAluno (odete);
    DestroiAluno (pedro);
    DestroiAluno (aline);

    DestroiFila(f);
    DestroiFila(f2);

    return 0;

}