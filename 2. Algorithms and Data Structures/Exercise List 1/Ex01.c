/*
1.Escreva um programa que leia um número l de linhas e um número c de colunas.
Em seguida, um vetor V de tamanho l∗c e uma matriz M com l linhas e c colunas devem 
ser alocados dinamicamente. Seu programa deve executar as tarefas abaixo sequencialmente,
através de chamadas de funções:

(a)Preencher o vetor V com valores inteiros digitados pelo usuário.
(b)Imprimir o vetor V na tela.
(c)Preencher a matriz M, sequencialmente, com os valores do vetor V.
(d)Imprimir a matriz M na tela.
*/


#include <stdio.h>
#include <stdlib.h>

void preencheVetor(int* vetor, int tamanho);
void imprimeVetor(int* vetor, int tamanho);
void preencheMatriz(int** matriz, int linhas, int colunas, int* vetor); 
//adicionar um "tamanhoVetor" daria, mas ja que se deriva de linhas e colunas, e dispensavel
void imprimeMatriz(int** matriz, int linhas, int colunas);

int main (void) {
    int linhas, colunas;
    int* vetor;
    int** matriz;

    system("cls");
    printf("Preencha um vetor com itens, imprima-o, organize-o em matriz, e a imprima tambem.");

    do {
        printf("\nEscolha um tamanho para as linhas: ");
        scanf("%d", &linhas);
        printf("Agora defina a quantidade de colunas: ");
        scanf("%d", &colunas);
    } while (linhas < 1 || colunas < 1);
    //para evitar problemas com tamanho na conversao de valores negativos para unsigned int, checar
    //https://www.quora.com/What-happens-in-C++-if-you-use-malloc-with-a-negative-parameter?share=1
    
    vetor = malloc(linhas*colunas*sizeof(int));
        if (vetor == NULL) printf("\nMemoria insuficiente.");
        else {
    matriz = malloc(linhas*sizeof(int));
        if (matriz == NULL) printf("\nMemoria insuficiente.");
        else {
    
    for (int i=0; i<linhas; i++) {
        matriz[i] = malloc(colunas*sizeof(int));
        if (matriz[i] == NULL)
            printf("\nMemoria Insuficiente.");
    }

    preencheVetor(vetor, linhas*colunas);
    imprimeVetor(vetor, linhas*colunas);
    preencheMatriz(matriz, linhas, colunas, vetor);
    imprimeMatriz(matriz, linhas, colunas);

    //liberar cada um dos ponteiros para vetor, vetor e ponteiro da matriz
    free(vetor);
    for(int i=0; i<linhas; i++) {   
        free(matriz[i]);
    }
    free(matriz);

    }} 

    printf("\n\nPrograma encerrado.");
    return 0;
}


void preencheVetor (int* vetor, int tamanho) {
    
    for (int i=0; i<tamanho; i++) {
        printf("Insira o valor para a casa %d do vetor: ", i+1);
        scanf("%d", &vetor[i]);
    }

}


void imprimeVetor (int* vetor, int tamanho) {

    //nao foi solicitado que a impressao seja em formato de matriz

    printf("\nOs valores digitados foram:\n");

    for (int i=0; i< tamanho; i++) {
        printf("%d,", vetor[i]);
    }
}


void preencheMatriz(int** matriz, int linhas, int colunas, int* vetor) {

    int aux=0; //tentei fazer algum malabarismo com matematica, como i+j ou algo assim mas nao deu

    for (int i=0; i<linhas; i++) {
        for (int j=0; j<colunas; j++) { //os for()s ja servem de restricao para a leitura do vetor.

            matriz[i][j] = vetor[aux];
            aux++;
        
        }
    }
}


void imprimeMatriz(int** matriz, int linhas, int colunas) {

    printf("A matriz com esses itans ficaria assim:");
    
    for (int i=0; i<linhas; i++) {
        printf("\n\n");
        for (int j=0; j<colunas; j++) {
            printf("%d   ", matriz[i][j]);
        }
    }
}