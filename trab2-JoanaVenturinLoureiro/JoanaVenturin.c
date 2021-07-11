#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arv.h"

int main (int argc, char** argv){

    //mensagem de erro
    if (argc <= 1) {
        printf("ERRO: O diretorio de arquivos de configuracao nao foi informado\n");
        return 0;
     }

    //abrindo arquivos
    FILE *ARQ = fopen(argv[1], "r");
    FILE *SAIDA = fopen("saida.txt", "w");
    int pos = 0;
    
    if (ARQ == NULL){

        printf("Erro ao tentar abrir o arquivo");
        exit(1);
    }

    
    //le todo o arquivo entrada.txt e cria e destroi a arvore no final de cada while para ser reutilizada em cada equação
    while (!feof(ARQ)){
        char* equacao = (char*) malloc(300*sizeof(char));

        fscanf(ARQ,"%s", equacao);
        
        //Criando arvore
        Arv* a = abb_cria();
        a = abb_insere(a);
        pos=0;

        

        a = abb_parse(a, equacao, &pos); //insere valores nas posicoes
        fprintf(SAIDA, "%.0f\n", resultadoEquacao(a)); //salva o resultado no arquivo de saida
        
   
        a = abb_libera(a);
        free(equacao);
        
    }

    
    

    fclose(ARQ);
    fclose(SAIDA);

    return 0;
}