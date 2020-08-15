/*
2.Escreva  um  programa  que  preencha  uma  matriz  de  dimensão  N  
(N  <=10  e  deve  ser  digitado pelo  usuário)  e  retorne  a  soma  dos  
elementos  positivos  da  matriz. O  preenchimento  da  matriz deve ser feito 
separado do cálculo da soma.
*/

//preencher matriz de ate 10 linhas/colunas, e imprimir a soma dos elementos positivos.


#include <stdio.h>

int main (void) {

    int linha, coluna, soma=0;

    printf("\nReveja os elementos de uma matriz 2x3 e saiba seu maior valor.\n");

    do {
        printf("\nPor favor, defina a quantidade de itens por linha (coluna): ");
        scanf("%d", &coluna);
        printf("Agora, digite o numero de linhas: ");
        scanf("%d", &linha);
    }
    while (linha < 0 || linha > 10 ||coluna < 0 || coluna > 10);

    int vetor[linha][coluna];

    for (int i=0; i<linha; i++) {
        for (int j=0; j<coluna; j++) {
            printf("\nInsira um valor para a casa (%d,%d): ", i+1, j+1);
            scanf("%d", &vetor[i][j]);
        }
    }

    for (int i=0; i<linha; i++) {
        for (int j=0; j<coluna; j++) {
            if (vetor[i][j] > 0)
                soma += vetor[i][j];
        }    
    }

    printf ("\nA soma dos valores positivos da lista e de %d.", soma);

    return 0; 
}