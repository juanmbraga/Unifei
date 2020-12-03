#include <stdio.h>
#include <stdlib.h>


typedef struct descritor Pilha; 

// Funcao para criar uma pilha
Pilha* criarPilha();
//retornos: NULL= erro, !NULL= sucesso


// Funcao para liberar um vetor de tres pilhas
int liberarPilha(Pilha* pilha);


// Retorna o numero de elementos na pilha
int tamanhodaPilha(Pilha* pilha);
//retornos: -1= nao existe, outros: tamanho


// Insere na pilha
int empilhar(Pilha* pilha, int dado);
//retornos: 0= sucesso, -1= nao existe ou erro ao alocar


// Retirar o primeiro item da pilha e o retorna
int desempilhar(Pilha* pilha);
//retornos: 0= vazia ou inexistente, !0= letra retirada (sucesso)


// Retorna o primeiro item da pilha
int consultarPilha(Pilha* pilha);
//retornos: -1= pilha nao existe ou esta vazia


// Imprime a pilha de uma maneira escolhida (personalizar implementacao)
void imprimePilha(Pilha* pilha);


/* Funcoes internas a imprimePilha que utilizam a estrutura "Elemento" nao disponibilizada para uso na main

    // Imprime um valor determinado de elementos de uma pilha, colocando algo (zero) quando a fila chegar ao fim
        void imprimePilhaRecursivaDefinida(Elemento* pilha);

    // Imprime toda a pilha de maneira invertida
        void imprimePilhaRecursivaInvertida(Elemento* pilha);

    // Imprime toda a pilha
        void imprimePilhaRecursiva(Elemento* pilha);
*/