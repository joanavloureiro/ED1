#ifndef MATRIZ_H_
#define MATRIZ_H_

typedef struct matriz Matriz;


Matriz* inicializaMatriz (int nlinhas, int ncolunas);

void modificaElemento (Matriz* mat, int linha, int coluna, int elem);


int recuperaElemento(Matriz* mat, int linha, int coluna);


int recuperaNColunas (Matriz* mat);


int recuperaNLinhas (Matriz* mat);


Matriz* transposta (Matriz* mat);


Matriz* multiplicacao (Matriz* mat1, Matriz* mat2);

void imprimeMatriz(Matriz* mat);


void destroiMatriz(Matriz* mat);

#endif /*MATRIZ_H_*/