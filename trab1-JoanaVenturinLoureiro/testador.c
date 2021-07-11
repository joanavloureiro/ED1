#include <stdio.h>
#include "ListaEditor.h"
#include "Editor.h"
#include "Contribuicao.h"
#include "ListaContribuicao.h"
#include "Pagina.h"
#include "ListaPagina.h"

void INSEREPAGINA(char* nomePagina, char* nomeArquiv, ListaPagina* lista){

    
    Pagina* pag = InicPagina(nomePagina, nomeArquiv);
    InserePagina(lista, pag);

}

void RETIRAPAGINA(char* nomePagina, FILE* LOG, ListaPagina* lista){
    Pagina* pagina;

    pagina = RetiraPagina(lista, nomePagina); 

    if(!pagina)
        fprintf(LOG,"ERRO: não existe a pagina %s \n", nomePagina);           
    else
        DestroiPagina(pagina);

    
}

void INSEREEDITOR(char* nomeEditor, ListaEditor* lista){
    Editor* editor = InicEditor(nomeEditor);
    InsereEditorListaEditor(lista, editor);
}

void INSERECONTRIBUICAO(ListaPagina* listaPagina, ListaContribuicao* listaContribuicao, char* nomePagina, Editor* editor, char* nomeContribuicao, char* textoContribuicao){
    Contribuicao* contrib;    

    contrib = InicContribuicao(textoContribuicao, nomeContribuicao, editor);

    InsereContribuicao(listaContribuicao, contrib);
    InsereContribuicaoPagina (RetornaPaginaNaLista(listaPagina, nomePagina), contrib);
}

void RETIRACONTRIBUICAO(Pagina* pagina, char* nomeContribuicao){

    RetiraContribuicao(RetornaListaContribuicao(pagina), nomeContribuicao);

}

void INSERELINK(Pagina* pagina, Pagina* pagina2){

    InsereLinkPagina (pagina, pagina2);
}

void RETIRALINK(Pagina* pagina, Pagina* pagina2){

    RetiraLinkPagina(pagina, pagina2);
    
}

void IMPRIMEPAGINA(ListaPagina* lista, char* chave){
    
    ImprimeUmaPaginaListaPagina (lista, chave);
}

void IMPRIMEWIKED(ListaPagina* listaPagina){

    ImprimeListaPagina(listaPagina);
}

int main(int argc, char** argv){

    //mensagem de erro
    if (argc <= 1) {
         printf("ERRO: O diretorio de arquivos de configuracao nao foi informado\n");
         return 0;
     }

    FILE *ARQ = fopen(argv[1], "r");
    FILE *LOG = fopen("log.txt", "w");
    char comando[50];
    char vet[3][50];
    char textoContribuicao[10000];
    Contribuicao* contrib;
    Editor* editor;
    Pagina* pagina;
    Pagina* pagina2;

    if (ARQ == NULL){

        printf("Erro ao tentar abrir o arquivo");
        exit(1);
    }

    ListaEditor* listaEditor = InicListaEditor();
    ListaContribuicao* listaContribuicao = InicListaContribuicao();
    ListaPagina* listaPagina = InicListaPagina();


    while(1){

        fscanf(ARQ,"%s", comando);
        printf("----%s----\n", comando);

        if(strcmp(comando, "INSEREPAGINA")== 0){

            fscanf(ARQ,"%s %s",vet[0],vet[1]);
            INSEREPAGINA(vet[0], vet[1], listaPagina);

        }

        else if(strcmp(comando, "RETIRAPAGINA")== 0){

            fscanf(ARQ,"%s",vet[0]);
            RETIRAPAGINA(vet[0], LOG, listaPagina);
            
        }

        else if(strcmp(comando, "INSEREEDITOR")== 0){
            
            fscanf(ARQ,"%s", vet[0]);
            INSEREEDITOR(vet[0], listaEditor);
        }

        else if(strcmp(comando, "INSERECONTRIBUICAO")== 0){
            char c = '\0';

            fscanf(ARQ,"%s %s %s", vet[0], vet[1], vet[2]); //fisica pedro c1.txt
            
            FILE *ARQ2= fopen(vet[2], "r");

            textoContribuicao[0] = '\0';
            for (int j = 0; j < 10000; j++)
            {
                textoContribuicao[j] = '\0';
            }
            

            if (ARQ2 == NULL) 
            {
                fprintf(LOG,"ERRO: abertura do arquivo");
                exit(1);
            }

            int i = 0;
            while( !feof(ARQ2) && i<10000) {

                c = fgetc(ARQ2);
                textoContribuicao[i] = c;
                i++;
            }
            textoContribuicao[i-1] = '\0';
            
            fclose(ARQ2);

            pagina= RetornaPaginaNaLista(listaPagina, vet[0]);
            
            editor = RetornaEditorNaLista(listaEditor, vet[1]);

            contrib = RetornaContribuicaoNaLista(RetornaListaContribuicao(pagina), vet[2]);
            
            if(!pagina)
                fprintf(LOG,"ERRO:a pagina %s nao existe\n",vet[0]); 
            else if (!editor)  
                fprintf(LOG,"ERRO:o editor %s nao existe\n",vet[1]); 
            else if(contrib)
                fprintf(LOG,"ERRO: a contribuicao %s ja existe na pagina %s.\n",vet[0], vet[2]);     
            else
                INSERECONTRIBUICAO(listaPagina, listaContribuicao, vet[0], editor, vet[2], textoContribuicao);

        }

        else if(strcmp(comando, "RETIRACONTRIBUICAO")== 0){

            fscanf(ARQ,"%s %s %s", vet[0], vet[1], vet[2]); //artes ana c1.txt

            pagina= RetornaPaginaNaLista(listaPagina, vet[0]);
            
            editor = RetornaEditorNaLista(listaEditor, vet[1]);

            contrib = RetornaContribuicaoNaLista(RetornaListaContribuicao(pagina), vet[2]);
            
            if(!pagina)
                fprintf(LOG,"ERRO:a pagina %s nao existe\n",vet[0]); 
            else if (!editor)  
                fprintf(LOG,"ERRO:o editor %s nao existe\n",vet[1]); 
            else if(!contrib)
                fprintf(LOG,"ERRO: a contribuicao %s nao existe na pagina %s.\n",vet[2], vet[0]);     
            else if(strcmp(vet[1],RetornaNomeEditor(editor)))
                fprintf(LOG,"ERRO: apenas o proprio editor da contribuiçao pode exclui-la.");
            else           
                RETIRACONTRIBUICAO( pagina, vet[2]);
        }

        else if(strcmp(comando, "INSERELINK")== 0){
            fscanf(ARQ,"%s %s", vet[0],vet[1]);

            Pagina* link = RetornaPaginaNaLista(RetornaListaLinks(pagina), vet[0]);
            pagina= RetornaPaginaNaLista(listaPagina, vet[0]);
            pagina2= RetornaPaginaNaLista(listaPagina, vet[1]);
            

            if(!pagina)
                fprintf(LOG,"ERRO:a pagina %s nao existe\n",vet[0]); 
            else if (!pagina2)
                fprintf(LOG,"ERRO:a pagina %s nao existe\n",vet[1]); 
            else if (link)
                fprintf(LOG,"ERRO:a pagina %s ja contem link para a pagina %s\n",vet[0],vet[1]);
            else
                INSERELINK(pagina, pagina2);
        }

        else if(strcmp(comando, "RETIRALINK")== 0){
            fscanf(ARQ,"%s %s", vet[0],vet[1]);
            Pagina* link = RetornaPaginaNaLista(RetornaListaLinks(pagina), vet[0]);
            pagina= RetornaPaginaNaLista(listaPagina, vet[0]);
            pagina2= RetornaPaginaNaLista(listaPagina, vet[1]);

            if(!pagina)
                fprintf(LOG,"ERRO:a pagina %s nao existe\n",vet[0]); 
            else if(!pagina2)
                fprintf(LOG,"ERRO:a pagina %s nao existe\n",vet[1]); 
            else if (!link)
                fprintf(LOG,"ERRO:a pagina %s nao contem link para a pagina %s\n",vet[0],vet[1]);
            else
                RETIRALINK(pagina, pagina2);
        }

        else if(strcmp(comando, "CAMINHO")== 0){
            fscanf(ARQ,"%s %s", vet[0],vet[1]);
            pagina= RetornaPaginaNaLista(listaPagina, vet[0]);
            pagina2= RetornaPaginaNaLista(listaPagina, vet[1]);

            if(!pagina)
                fprintf(LOG,"ERRO:a pagina %s nao existe\n",vet[0]); 
            else if(!pagina2)
                fprintf(LOG,"ERRO:a pagina %s nao existe\n",vet[1]);

            else{
                if(Caminho(pagina, pagina2)){
                    fprintf(LOG,"HA CAMINHO DA PAGINA %s PARA %s\n",vet[0], vet[1]);
                }
                else
                {
                    fprintf(LOG,"NAO HA CAMINHO DA PAGINA %s PARA %s\n",vet[0], vet[1]);
                }
                
            }
        }

        else if(strcmp(comando, "IMPRIMEPAGINA")== 0){
            fscanf(ARQ,"%s", vet[0]);

            pagina = RetornaPaginaNaLista(listaPagina, vet[0]);

            if(!pagina)
                fprintf(LOG,"ERRO:a pagina %s nao existe\n",vet[0]); 
            else{
                IMPRIMEPAGINA(listaPagina, vet[0]);
            }
        }

        else if(strcmp(comando, "IMPRIMEWIKED")== 0){
            IMPRIMEWIKED(listaPagina);
        }

        else if(strcmp(comando, "FIM")== 0)
        {
            DestroiListaPagina(listaPagina);
            DestroiListaContribuicao(listaContribuicao);
            DestroiListaEditor(listaEditor);
            break;
        }

        fscanf(ARQ,"%*c");

    }
    
    fclose(ARQ);
    fclose(LOG);

    return 0;
}