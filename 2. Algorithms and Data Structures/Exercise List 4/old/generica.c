// Biblioteca de funcoes para manipulacao de tipo de dado:
// Fila Encadeada Generica com No Descritor

#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
    int tipo; 
    void* dado;
    Elemento* proximo;
} Elemento;


typedef struct descritor {
    Elemento* inicio;
    Elemento* fim;
    int quantidade;
} Fila;


Fila* criaFila(){

    Fila* fila = (Fila*) malloc(sizeof(Fila));

    if(fila != NULL){
        
        // inicializa os dados do descritor 
        fila->inicio = NULL;
        fila->fim = NULL;
        fila->quantidade = 0;

    }

    return fila;
}                        


int liberaLista (Fila* fila){

    // caso ela estiver vazia
    if(fila = NULL){
        return 1;
    }

    // elemento temporario
    Elemento* atual;

    // limpar item por item
    while(atual != NULL){
        atual = fila->inicio;
        fila->inicio = fila->inicio->prox;
        fila->quantidade--;
        
        // limpar o dado generico e o elemento
        free(atual->dado);
        free(atual);
    }

    // limpar o descritor
    free(fila);

    return 0;
}


int tamanhoFila(Fila* fila){
    // caso optar por nao conter o descritor ou a variavel quantidade nele, seria preciso percorrer a fila

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

    // verifica se fila esta vazia
    if(fila->inicio == NULL){
        return 2;
    }

    // retira o primeiro elemento da fila
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