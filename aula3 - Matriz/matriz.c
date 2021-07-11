#include <stdio.h>
#include "matriz.h"
#include <stdlib.h>

struct matriz{
    int** inicio;
    int ncolunas;
    int nlinhas;
};

Matriz* inicializaMatriz (int nlinhas, int ncolunas){
    Matriz* m = (Matriz *)malloc(sizeof(Matriz)); //nova struct sendo inicializada;

    if(m == NULL) return m;

    m->nlinhas = nlinhas;
    m->ncolunas = ncolunas;
    m->inicio =  (int**) malloc( nlinhas * sizeof(int*)); //inicializa ponteiro para a matriz

    for(int i = 0; i < nlinhas; i++){
        m->inicio[i] = (int*) malloc (ncolunas * sizeof(int));
    }

    if (m->inicio == NULL){
        free (m);
        return NULL;
    }

    return m;
}


void modificaElemento (Matriz* mat, int linha, int coluna, int elem){

    mat->inicio[linha][coluna] = elem;
}


int recuperaElemento(Matriz* mat, int linha, int coluna){

    return mat->inicio[linha][coluna];
}

int recuperaNColunas (Matriz* mat){

    return mat->ncolunas;
}

int recuperaNLinhas (Matriz* mat){

    return mat->nlinhas;
}


Matriz* transposta (Matriz* mat){
    int i=0, j=0;
    Matriz* transposta;

    transposta = inicializaMatriz(mat->ncolunas, mat->nlinhas);

    for(i=0; i<mat->nlinhas; i++){
        for(j=0; j<mat->ncolunas; j++){
            transposta->inicio[j][i] = mat->inicio[i][j];
        }
    }

    return transposta;
}


Matriz* multiplicacao (Matriz* mat1, Matriz* mat2){
    int produto=0, elem1=0, elem2=0;
    Matriz* mult = inicializaMatriz(mat1->nlinhas, mat2->ncolunas);
    
    for (int l = 0; l < mat1->nlinhas; l++){
        for(int c=0; c < mat2->ncolunas; c++){
            produto = 0;
            for(int i=0; i< mat1->ncolunas; i++){
                elem1 = recuperaElemento(mat1, l, i);
                elem2 = recuperaElemento(mat2, i, c);
                produto = produto + elem1*elem2;
            }
            mult->inicio[l][c] = produto;
        }
    }
    return mult;
}



void imprimeMatriz(Matriz* mat){
    int i=0, j=0;

  for(i=0; i< mat->nlinhas;i++){
      for(j=0; j< mat->ncolunas; j++){
          printf("%d ", mat->inicio[i][j]);
      }
      printf("\n");
  }

}


void destroiMatriz(Matriz* mat){
    if(mat){
    if(mat->inicio){
        for(int i = 0; i < mat->nlinhas; i++){
            free(mat->inicio[i]);
        }
        free(mat->inicio);
    }
    free (mat);
  }
}


//#endif /*MATRIZ_H_*/