// TAD para Lista Dinâmica Encadeada baseado no livro "Estrutura de dados descomplicada em lingugem C (André Backes)"

#ifndef _LISTA_ENCADEADA
#define _LISTA_ENCADEADA

//typedef struct elemento* Lista;
typedef struct aluno* Lista;

//typedef para usar elemento aluno na main
typedef struct aluno aluno;


// funções para alocar e desalocar memória
Lista* criar_lista();
int liberar_lista(Lista *li);	

// funções para obter informações da lista
int tamanho_lista(Lista *li);
int lista_vazia(Lista *li);
int lista_cheia(Lista *li);

// funções para inserção de elementos da lista
int inserir_lista_inicio(Lista *li, aluno* elemento);
int inserir_lista_final(Lista *li, aluno* elemento);
int inserir_lista_ordenada(Lista *li, aluno* elemento);

// funções para remoção de elementos da lista
int remover_lista_inicio(Lista *li);
int remover_lista_final(Lista *li);
int remover_lista_meio(Lista *li, int matricula);

// funções para buscar elementos na lista
int buscar_lista_posicao(Lista *li, int pos);
int buscar_lista_dado(Lista *li, int matricula);

int imprimir_lista(Lista *li);

//Novas----------------------------------------------

// concatena duas listas recebidas, e retorna uma terceira
Lista* concatenaLista(Lista* lista1, Lista* lista2);
// varre a lista por elementos repetidos, removendo-os
Lista* removeRepetidos(Lista* lista);
// recebe uma lista e a retorna invertida
Lista* inverteLista(Lista* lista);
// checa se os elementos estao ordenados cresc. ou decresc.
int checaOrdenacao(Lista* lista);
// calcula o tamanho recursivamente
int calculaTamanho (aluno* atual);
// calculates size of a given list in a mind boggling way
int calculaTamanhoMindBlownEdition(Lista* lista);
// criar e preencher dados foi adicionada ao TAD
aluno* criar_dado(aluno* elemento);

#endif
