#ifndef Contribuicao_h
#define Contribuicao_h

#include <stdio.h>
#include "ListaEditor.h"

typedef struct contribuicao Contribuicao;

//recebe como input os itens da struct e de output a contribuicao criada
Contribuicao* InicContribuicao (char* texto, char* nome, Editor* editor);

char* RetornaTextoContribuicao (Contribuicao* contribuicao);

char* RetornaNomeContribuicao (Contribuicao* contribuicao);

Editor* RetornaEditorContribuicao (Contribuicao* contribuicao);

void AlteraRetirado(Contribuicao* contrib);

void ImprimeContribuicao (FILE* saida, Contribuicao* contribuicao);

//imprime a contribuicao, se o int retira for 0, vai estar representada como retirada
void ImprimeHistoricoContribuicao(FILE* saida, Contribuicao* contrib);

//da free em todos os itens da contribuicao que foram criados com malloc
void DestroiContribuicao (Contribuicao* contribuicao);

#endif /* Contribuicao_h */