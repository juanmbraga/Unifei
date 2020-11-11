#include <stdio.h>
#include <stdlib.h>

#include "pilha.h"

// definicao do tipo elemento
struct elemento{
    char dado;
    Elemento *proximo;
};

//typedef do elemento
typedef struct elemento Elemento;

//criando nó descritor
struct descritor{
    Elemento* topo;
    int quantidade;
};


Pilha* criarPilha(void){
    // Alocar dinamicamente 
    Pilha* pilha = (Pilha*) malloc(sizeof(Pilha));

    // Inicializar em caso de sucesso na alocacao
    if(pilha != NULL){
        pilha->topo = NULL;
        pilha->quantidade = 0;        
    }

    // Retorne o endereco alocado
    return pilha;
}


int liberarPilhas(Pilha* pilha[3]){

    // Repetir para todos as possiveis pilhas
    for(int i=0; i<3; i++){

        // Caso a pilha ja esteja vazia
        if(pilha[i] == NULL){
            continue;
        }

        int atual;

        // Liberar todos os elementos
        while(pilha[i]->topo != NULL){
            atual = pilha[i]->topo;
            pilha[i]->topo = pilha[i]->topo->proximo;
            free(atual);
        }

        free(pilha[i]);
    }

    return 0;
}


int tamanhodaPilha(Pilha* pilha){
    // Checa a existencia da fila
    if (pilha == NULL)
        return -1;

    return pilha->quantidade;
}


Elemento* criarElemento(){
    Elemento* no = (Elemento*) malloc(sizeof(Elemento));

    if(no == NULL){
        return 0;
    }

    return no;
}


int empilhar(Pilha* pilha, char dado){
    // Checa a existencia da fila
    if (pilha == NULL){
        return -1;
    }

    // Verificar ordem alfabetica (A<E<I<O<U)
    if(consultarTopoPilha(pilha) < dado){
        return 1;
    }

    // Inserir elemento 
    Elemento* no = (Elemento*) malloc(sizeof(Elemento));

    // Em caso de erro ao alocar
    if(no == NULL){
        return -1;
    }

    // Caso for o primeiro item a ser inserido na lista
    if(pilha->topo == NULL){
        no->proximo = NULL;
    }

    // Atribuir valores e inserir na pilha
    no->dado = dado;
    no->proximo = pilha->topo;
    pilha->topo = no;
    pilha->quantidade++;

    return 0;
}


char desenpilhar(Pilha* pilha){
    // Checar existencia ou se pilha esta limpa
    if(pilha == NULL || pilha->quantidade == 0){
        return 0;
    }

    char dado;
    Elemento* no;

    // Salva dado temporariamente
    dado = pilha->topo->dado;

    // Remove e libera primeiro item
    no = pilha->topo;
    pilha->topo = no->proximo;
    free(no);
    pilha->quantidade--;

    return dado;
}



