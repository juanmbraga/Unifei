// Biblioteca de funcoes para manipulacao de tipo de dado:
// Lista Encadeada Generica com No Descritor

#include <stdio.h>
#include <stdlib.h>
#include "banco.h"

typedef struct elemento {
    int tipo; 
    void* dado;
    Elemento* proximo;
} Elemento;


typedef struct descritor {
    Elemento* inicio;
    Elemento* fim;
    int quantidade;
} Lista;


Lista* criaLista(){

    Lista* lista = (Lista*) malloc(sizeof(Lista));

    if(lista != NULL){
        
        // inicializa os dados do descritor 
        lista->inicio = NULL;
        lista->fim = NULL;
        lista->quantidade = 0;

    }

    return lista;
}                        


int liberaLista (Lista* lista){

    // caso ela estiver vazia
    if(lista = NULL){
        return 1;
    }

    // elemento temporario
    Elemento* atual;

    // limpar item por item
    while(atual != NULL){
        atual = lista->inicio;
        lista->inicio = lista->inicio->prox;
        lista->quantidade--;
        
        // limpar o dado generico e o elemento
        free(atual->dado);
        free(atual);
    }

    // limpar o descritor
    free(lista);

    return 0;
}


int tamanhoFila(Fila* fila){
    // caso optar por nao conter o descritor ou a variavel quantidade nele, seria preciso percorrer a lista

    // caso a fila nao existir
    if(fila = NULL){
        return -1;
    }
    
    // retorna o valor salvo da quantidade
    return fila->quantidade;
}


int desenfileirar(Fila* fila){

    //verifica se fila existe
    if(fila == NULL){
        return 1;
    }

    // verifica se lista esta vazia
    if(fila->inicio == NULL){
        return 2;
    }

    // retira o primeiro elemento da lista
    Elemento* no = NULL;
    no = fila->inicio;
    fila->inicio = fila->inicio->prox;
    fila->quantidade--;

    // libera o elemento retirado e seu dado interno
    free(no->dado);
    free(no);

    // se o elemento removido era o unico
    if(fila->inicio = NULL){
        fila->fim = NULL;
    }

    return 0;
}