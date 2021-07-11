#include <stdio.h>
#include "listaMat.h"

void completaMatriz(Matriz* mat){
    int i,j;
    
    int col = recuperaNColunas(mat);
    int lin = recuperaNLinhas(mat);

    for(i=0; i<lin; i++)
        for(j=0; j<col ;j++)
            modificaElemento(mat, i, j, i+j);

}

int main(){
    Matriz* deletaMatriz;

    //Incialização das matrizes
    Matriz* mat1 = inicializaMatriz(2,2);
    Matriz* mat2 = inicializaMatriz(5,6);
    Matriz* mat3 = inicializaMatriz(7,7);
    Matriz* mat4 = inicializaMatriz(9,3);
    

    //Completando matrizes
    completaMatriz(mat1);
    completaMatriz(mat2);
    completaMatriz(mat3);
    completaMatriz(mat4);

    Lista* l1 = inicializaLista();
    insereLista(l1,mat1);
    insereLista(l1,mat2);
    insereLista(l1,mat3);
    insereLista(l1,mat4);
    
    printf("Esta eh a sua primeira lista\n");
    printf("\n");
    imprimeLista(l1);
    
    //Lista transposta 
    Lista* ltransp = inicializaLista();
    insereLista(ltransp, transposta(mat1));
    insereLista(ltransp, transposta(mat2));
    insereLista(ltransp, transposta(mat3));
    insereLista(ltransp, transposta(mat4));

    printf("Lista de transpostas:\n\n");
    imprimeLista(ltransp);

    //1 posição da l1 foi excluida
    deletaMatriz = retiraLista(l1, 0);
    destroiMatriz(deletaMatriz);
    printf("Lista sem a primeira matriz\n\n");
    imprimeLista(l1);

    //2 posição da l1 foi excluida
    deletaMatriz = retiraLista(l1, 1);
    destroiMatriz(deletaMatriz);
    printf("Lista sem a primeira e segunda matrizes\n\n");
    imprimeLista(l1);

    //ultima posição da l1 foi excluida
    deletaMatriz = retiraLista(l1, 1);
    destroiMatriz(deletaMatriz);
    printf("Lista sem a primeira, segunda e ultima matrizes\n\n");
    imprimeLista(l1);


    //1 posição da ltransp foi excluida
    deletaMatriz = retiraLista(ltransp, 0);
    destroiMatriz(deletaMatriz);
    printf("Transposta sem a primeira matriz\n\n");
    imprimeLista(ltransp);

    //3 posição da ltransp foi excluida
    deletaMatriz = retiraLista(ltransp, 1);
    destroiMatriz(deletaMatriz);
    printf("Transposta sem a primeira e terceira matrizes\n\n");
    imprimeLista(ltransp);

    //ultima posição da ltransp foi excluida
    deletaMatriz = retiraLista(ltransp, 1);
    destroiMatriz(deletaMatriz);
    printf("Transposta sem a primeira, terceira e ultima matrizes\n\n");
    imprimeLista(ltransp);


    //nova matriz na l1
    Matriz* mat5 = inicializaMatriz(5,5);
    completaMatriz(mat5);
    insereLista(l1,mat5);
    printf("l1 com nova matriz\n");
    imprimeLista(l1);

    //nova matriz na ltransp
    Matriz* mat6 = inicializaMatriz(4,2);
    completaMatriz(mat6);
    insereLista(ltransp, transposta(mat6));
    printf("ltransp com nova matriz\n");
    imprimeLista(ltransp);
    
    

    destroiLista(l1);
    destroiLista(ltransp);

    return 0;
}