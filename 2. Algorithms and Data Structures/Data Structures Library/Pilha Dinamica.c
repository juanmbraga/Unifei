#include <stdio.h>
#include <stdlib.h>
#include "Pilha Dinamica.h"

// definicao do tipo elemento
struct elemento{
    int dado;
    struct elemento *proximo;
};

//typedef do elemento
typedef struct elemento Elemento;

//criando nó descritor
struct descritor{
    Elemento* topo;
    int quantidade;
};

//typedef do elemento
typedef struct descritor Pilha;


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


int liberarPilha(Pilha* pilha){

    // Caso a pilha ja esteja vazia
    if(pilha == NULL){
        return 0;
    }

    Elemento* atual;

    // Liberar todos os elementos
    while(pilha->topo != NULL){
        atual = pilha->topo;
        pilha->topo = pilha->topo->proximo;
        free(atual);
    }

    // Liberar o no descritor
    free(pilha);

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


int empilhar(Pilha* pilha, int dado){
    // Checa a existencia da fila
    if (pilha == NULL){
        return -1;
    }

    // Inserir elemento 
    Elemento* no = (Elemento*) malloc(sizeof(Elemento));

    // Em caso de erro ao alocar
    if(no == NULL){
        return -1;
    }

    // Atribuir valores e inserir na pilha
    no->dado = dado;
    no->proximo = pilha->topo;
    pilha->topo = no;
    pilha->quantidade++;

    return 0;
}


int desempilhar(Pilha* pilha){
    // Checar existencia ou se pilha esta limpa
    if(pilha == NULL || pilha->quantidade == 0){
        return 0;
    }

    int dado;
    Elemento* no;

    // Salva dado temporariamente
    dado = pilha->topo->dado;

    // Remove e libera primeiro item
    no = pilha->topo;
    pilha->topo = no->proximo;
    free(no);
    pilha->quantidade--;

    // Convenientemente retorna o dado
    return dado;
}


int consultarPilha(Pilha* pilha){
    // Caso nao existir ou for vazia
    if(pilha == NULL || pilha->topo == NULL){
        return -1;
    }

    return pilha->topo->dado;
}


void imprimePilhaRecursivaDefinida(Elemento* pilha, int tamanho){
    // Parar ao atingir o fim da pilha
    if(tamanho == 0) return;

    int atual;

    if(pilha != NULL){
        atual = pilha->dado;
        pilha = pilha->proximo;
    } else {
        atual = 0;
    }

    imprimePilhaRecursivaDefinida(pilha, --tamanho);
    
    // Imprime o valor
    printf("\n%d", atual);
}

void imprimePilhaRecursivaInvertida(Elemento* pilha){
    // Parar ao atingir o fim da pilha
    if(pilha == NULL) return;

    // Pegue o valor e passe o proximo elemento a variavel local pilha
    int atual = pilha->dado;
    pilha = pilha->proximo;

    // Recursivamente chama o proximo elemento
    imprimePilhaRecursivaInvertida(pilha);
    
    // Imprime o valor
    printf("\n%d", atual);
}


void imprimePilhaRecursiva(Elemento* pilha){
    // Parar ao atingir o fim da pilha
    if(pilha == NULL) return;

    // Recursivamente chama o proximo elemento
    imprimePilhaRecursiva(pilha->proximo);
    
    // Imprime o valor
    printf("\n%d", pilha->dado);
}


void imprimePilha(Pilha* pilha){
    
    // Imprime toda a pilha
    //imprimePilhaRecursiva(pilha->topo);
    
    // Imprime toda a pilha de maneira invertida
    //imprimePilhaRecursivaInvertida(pilha->topo);
    
    // Imprime um valor determinado de elementos de uma pilha, colocando algo (zeros) quando a fila chegar ao fim
    //int tamanho = 5;
    //imprimePilhaRecursivaDefinida(pilha->topo, tamanho);
}