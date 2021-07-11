#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Adulto.h"
#include "Crianca.h"
#include "Idoso.h"
#include "ListaHet.h"

int main(int argc, const char * argv[]){
    //criando idosos para teste
    Idoso* joaquim = InicIdoso("Joaquim", 63, 123);
    Idoso* frederico = InicIdoso("Frederico", 88, 681);
    Idoso* odete = InicIdoso("Odete", 75, 111);

    //criando adultos para teste
    Adulto* carmen = InicAdulto("Carmen", 50, 170);
    Adulto* jose = InicAdulto("Jose", 42, 969);
    Adulto* cassia = InicAdulto("Cassia", 23, 120);

    //criando criancas para teste
    Crianca* pedro = InicCrianca("Pedro", 7, "Cassia");
    Crianca* aline = InicCrianca("Aline", 10, "Jose");

    ListaHet* parque = InicLista();

    InsereIdoso(parque, joaquim);
    InsereIdoso(parque, frederico);
    InsereIdoso(parque, odete);

    InsereAdulto(parque, carmen);
    InsereAdulto(parque, jose);
    InsereAdulto(parque, cassia);

    InsereCrianca(parque, pedro);
    InsereCrianca(parque, aline);

    printf("Imprimindo a lista:\n");
    ImprimeLista(parque);

    printf("VALOR: %.2f ", ValorParque(parque));

    DestroiLista(parque);

    DestroiAdulto(carmen);
    DestroiAdulto(jose);
    DestroiAdulto(cassia);

    DestroiIdoso(joaquim);
    DestroiIdoso(frederico);
    DestroiIdoso(odete);

    DestroiCrianca(pedro);
    DestroiCrianca(aline);

    return 0;
}