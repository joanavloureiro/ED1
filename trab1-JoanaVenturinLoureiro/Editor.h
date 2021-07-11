#ifndef Editor_h
#define Editor_h

#include <stdio.h>

typedef struct editor Editor;

Editor* InicEditor (char* nome);

char* RetornaNomeEditor (Editor* editor);

void ImprimeEditor (Editor* editor);

void DestroiEditor (Editor* editor);


#endif /* Editor_h */