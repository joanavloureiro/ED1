#ifndef ListaEditor_h
#define ListaEditor_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Editor.h"

typedef struct listaEditor ListaEditor;

ListaEditor* InicListaEditor();

void InsereEditorListaEditor (ListaEditor* lista, Editor* editor);

Editor* RetornaEditorNaLista(ListaEditor* lista, char* chave);

void ImprimeListaEditor (ListaEditor* lista);

Editor* RetiraEditorListaEditor (ListaEditor* lista, char* chave);

void DestroiListaEditor (ListaEditor* lista);

#endif /* ListaEditor_h */