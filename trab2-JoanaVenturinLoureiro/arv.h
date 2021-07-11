#ifndef abb_h
#define abb_h
#include <stdio.h>

typedef struct arv Arv;

/*Inicializa uma arvore
 * inputs: nenhum
 * output: ponteiro para arv
 * pre-condicao: nenhuma
 * pos-condicao: nenhuma
 */
Arv* abb_cria (void);

/*aloca espaço para uma arv
 * inputs: ponteiro para arv
 * output: ponteiro para a arvore inicializado
 * pre-condicao: existir ponteiro para arv null
 * pos-condicao: arvore agora com espaço alocado
 */
Arv* abb_insere (Arv* arv);

/*Imprime arvore
 * inputs: arvore para impressao
 * output: nenhum
 * pre-condicao: arvore ser diferente de null
 * pos-condicao: nenhum
 */
void abb_imprime( Arv* a);

/*Resultado da equacao enviada pelo arquivo entrada.txt
 * inputs: a arvore extrair o resultado
 * output: float com o resultado
 * pre-condicao: arvore nao ser null
 * pos-condicao: arvore nao mudar ou retirar seus valores
 */
float resultadoEquacao (Arv* a);

/*Ser simbolo ou nao
 * inputs: caracter
 * output: ser (1) ou nao ser (0) um simbolo +,-, / ou *
 * pre-condicao: char ser parte da arv e nao ser '\0'
 * pos-condicao: nenhuma
 */
int Simbolo (char c);

/*Ser numero ou nao
 * inputs: caracter
 * output: ser (1) ou nao ser (0) um numero
 * pre-condicao: char ser parte da arv e nao ser '\0'
 * pos-condicao: nenhuma
 */
int Numero (char c);

/*Inicializa uma arvore
 * inputs: arvore para ser preenchida
 * output: arvore modificada
 * pre-condicao: arvore ja ter espaco alocado
 * pos-condicao: arvore foi preenchida com valores (char e float)
 */
Arv* abb_parse (Arv* arv, char* item, int* pos);

/*Arvore estar vazia ou nao
 * inputs: arvore a ser analisada
 * output: estar (1) ou nao estar (0) vazia
 * pre-condicao: arvore existir
 * pos-condicao: nenhuma
 */
int abb_vazia (Arv* a);

/*Liberar arvore
 * inputs: arvore a ser liberada
 * output: arvore vazia
 * pre-condicao: arvore nao ser null
 * pos-condicao: memoria alocada para a arvore estar livre
 */
Arv* abb_libera(Arv* a);


#endif /* abb_h */