#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Editor.h"

struct editor {
    char* nomeEditor;
};

Editor* InicEditor (char* nome) {
    Editor* editor = (Editor*) malloc (sizeof (Editor));
    editor->nomeEditor = strdup (nome);

    return editor;
}

char* RetornaNomeEditor (Editor* editor){
    return editor->nomeEditor;
}

void ImprimeEditor (Editor* editor){
    printf("%s\n", editor->nomeEditor);
}

void DestroiEditor (Editor* editor){
    free (editor->nomeEditor);
    free (editor);
}