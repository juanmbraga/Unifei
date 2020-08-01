/*
1.Elabore  um  programa  que  preencha  os  elementos  de  uma  matriz  2  x  3  
de  números  inteiro. Depois de preenchida, imprima os elementos digitados linha 
por linha e depois o valor do maior elemento.
*/

//preencher vetor 2x3, depois imprimir os elementos linha por linha e o maior valor


#include <stdio.h>

int main (void) {

    int vetor[2][3], maior;

    printf("\nReveja os elementos de uma matriz 2x3 e saiba seu maior valor.\n");

    for (int i=0;i<2;i++) {
        for (int j=0;j<3;j++) {
            printf("\nInsira um valor para a casa (%d,%d): ", i+1, j+1);
            scanf("%d", vetor[i][j]);
        }
    }

}