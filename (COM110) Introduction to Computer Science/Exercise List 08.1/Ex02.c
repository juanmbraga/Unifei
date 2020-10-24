/*
2.Escreva  um  programa  que  preencha  uma  matriz  de  dimensão  N  
(N  <=10  e  deve  ser  digitado pelo  usuário)  e  retorne  a  soma  
dos  elementos  positivos  da  matriz. O  preenchimento  da  matriz 
deve ser feito separado do cálculo da soma.
*/

//receber matriz de dimensoes definidas pelo usuario (ate 10 linhas/colunas), e retornar soma dos positivos

#include <stdio.h>
#include <stdlib.h> //para system("cls")

int main (void) {

    int linha, coluna, somaPositiva=0;

    system("cls");
    printf("\nSaiba a soma dos elementos positivos de uma matriz de ate 10 linhas ou colunas.\n");

    do {
        printf("\nDigite a quantidade de itens por linha (coluna) e tecle enter: ");
        scanf("%d", &coluna);
    }
    while (coluna < 1 || coluna > 10);

    do {
        printf("Agora, insira a quantidade de linhas e tecle enter: ");
        scanf("%d", &linha);
    }
    while (linha < 1 || linha > 10);

    printf("\nSelecionada matriz %d x %d...\n\n", linha, coluna);

    int vetor[linha-1][coluna-1];

    for (int i=0; i< linha; i++) {
        for (int j=0; j<coluna; j++) {
            printf("Insira o valor do item (%d,%d): ", i+1, j+1);
            scanf("%d", &vetor[i][j]);
        }
    }

    for (int i=0; i< linha; i++) {
        for (int j=0; j<coluna; j++) {
            if (vetor[i][j] > 0)
                somaPositiva += vetor[i][j];
        }
    }

    printf("\nO valor da soma dos numeros positivos e de %d.", somaPositiva);
}