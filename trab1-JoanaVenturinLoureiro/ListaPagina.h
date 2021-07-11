#ifndef ListaPagina_h
#define ListaPagina_h


typedef struct listaPagina ListaPagina;

ListaPagina* InicListaPagina();


void InserePagina (ListaPagina* lista, void* pagina);

//imprime apenas uma pagina de toda a lista
void ImprimeUmaPaginaListaPagina (ListaPagina* lista, char* chave);

void ImprimeListaPagina (ListaPagina* lista);

void ImprimeListaLinkPagina (FILE* saida, ListaPagina* lista);

void* RetornaPaginaNaLista(ListaPagina* lista, char* chave);

void* RetiraPagina (ListaPagina* lista, char* chave);

//quando deletar uma pagina é necessario percorrer todas as paginas e remover o link que havia em cada um delas
void RetiraLinkDasPaginas (ListaPagina* lista, char* chave);

int Caminho(void* pagOrigem, void* pagDest);

void VerificaCaminhosPossiveis(void* pagOrigem, ListaPagina* visita, ListaPagina* links);

//destroi apenas a lista
void DestroiListaLinkNaPagina(ListaPagina* link);

//destroi a lista e as celulas
void DestroiListaPagina (ListaPagina* lista);

#endif /* ListaPagina_h */