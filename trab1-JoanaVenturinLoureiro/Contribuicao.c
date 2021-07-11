#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Contribuicao.h"


struct contribuicao {
    Editor* editor;
    char* textoContribuicao;
    char* nomeContribuicao;
    int retirado;
};
//retirado=0;
//nao retirado=1;

Contribuicao* InicContribuicao (char* texto, char* nome, Editor* editor) {
    Contribuicao* contribuicao = (Contribuicao*) malloc (sizeof (Contribuicao));

    contribuicao->nomeContribuicao = strdup(nome);
    contribuicao->textoContribuicao = strdup(texto);
    contribuicao->editor = editor;
    contribuicao->retirado = 1;

    return contribuicao;
}

char* RetornaTextoContribuicao (Contribuicao* contribuicao){
    return contribuicao->textoContribuicao;
}

char* RetornaNomeContribuicao (Contribuicao* contribuicao){
    return contribuicao->nomeContribuicao;
}

Editor* RetornaEditorContribuicao (Contribuicao* contribuicao){
    return contribuicao->editor;
}

void AlteraRetirado(Contribuicao* contrib){
    if(contrib->retirado == 1){
        contrib->retirado = 0;
    }

}

void ImprimeContribuicao (FILE* saida, Contribuicao* contribuicao){
    if(contribuicao->retirado == 1){
        fprintf(saida, "\n-------- %s (%s) --------\n\n", contribuicao->nomeContribuicao, RetornaNomeEditor(contribuicao->editor));
        
        fprintf(saida, "%s\n", contribuicao->textoContribuicao);
    }
}

void ImprimeHistoricoContribuicao(FILE* saida, Contribuicao* contrib){
    if(contrib->retirado == 1){

        fprintf(saida, "%s %s\n", RetornaNomeEditor(contrib->editor), contrib->nomeContribuicao);
    }

    if(contrib->retirado == 0){
        
        fprintf(saida, "%s %s <<retirada>>\n", RetornaNomeEditor(contrib->editor), contrib->nomeContribuicao);
    }
}

void DestroiContribuicao (Contribuicao* contribuicao){
    free (contribuicao->nomeContribuicao);
    free (contribuicao->textoContribuicao);
    free (contribuicao);
}