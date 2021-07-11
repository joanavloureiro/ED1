#include <stdio.h>
#include "ListaDpl.h"

int main(){
    Produto* deletaProduto;
    //produtos para teste
    Produto* maca = InicProduto("Maca", 0.50, "frutas");
    Produto* trakinas = InicProduto("Trakinas", 3.00, "biscoitos");
    Produto* macarrao = InicProduto("Macarrao", 3.50, "massas");
    Produto* sucoDeUva = InicProduto("Suco de Uva", 5.80, "sucos");


    //Inicializa lista
    ListaDpl* lista = InicLista();

    //atualizando lista
    lista = InsereLista( lista, maca);
    lista = InsereLista( lista, trakinas);
    lista = InsereLista( lista, macarrao);
    lista = InsereLista( lista, sucoDeUva);
    

    printf("Imprimindo Lista:\n");
    ImprimeLista(lista);

    //retirando segundo item
    lista = RetiraLista(lista, "Trakinas");
    DestroiProduto(trakinas);

    printf("Imprimindo Lista:\n");
    ImprimeLista(lista);

    //retirando ultimo item
    lista = RetiraLista(lista, "Suco de Uva");
    DestroiProduto(sucoDeUva);

    printf("Imprimindo Lista:\n");
    ImprimeLista(lista);

    //retirando ultimo item
    lista = RetiraLista(lista, "Maca");
    DestroiProduto(maca);

    printf("Imprimindo Lista:\n");
    ImprimeLista(lista);

    //inserindo novo item
    Produto* pera = InicProduto("Pera", 0.75, "frutas");
    lista = InsereLista(lista, pera);

    printf("Imprimindo Lista:\n");
    ImprimeLista(lista);

    DestroiLista(lista);

    return 0;
}