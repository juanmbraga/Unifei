/*
4.Escreva um programa que leia uma matriz 5 x 5 e imprima sua diagonal primária e secundária.

Na  álgebra  linear,  os  índices  (i,j)  dos  elementos  da  diagonal  secundária  de  uma  
matriz  NxN apresentam  o  seguinte  comportamento:  i+j=N+1. Você pode  usar  esta regra  para  
resolver  o problema.  Contudo,  em  C,  os  índices  iniciam  em  0  e,na  álgebra  linear,  
os  índices  começam com 1.  Logo,  você  deverá  fazer  as  adaptações  necessárias  para  
adequar  os  valores  dos  índices em uma matriz em C.
*/

//ler matriz 5x5 e imprimir as duas diagonais. (presumindo que a matriz seja de valores inteiros.)


#include <stdio.h>
#include <stdlib.h>

int main (void) {

    int matriz[5][5];

    system("cls");
    printf("Saiba os itens das duas diagonais de uma matriz 5x5.\n\n");

    //receber input
    for (int i=0; i<5; i++) {

        for (int j=0; j<5; j++) {

            printf("\nDigite o valor da casa (%d,%d) e tecle enter: ", i+1, j+1);
            scanf("%d", &matriz[i][j]);

        }
    }

    //imprimir diagonal principal
    printf("Os valores da diagonal principal sao:\n");
    for (int i=0; i<5; i++) {

        for (int j=0; j<5; j++) {

            if (i == j)
                printf ("%d, ", matriz[i][j]);
        }
    }

    //imprimir diagonal secundaria
    printf("\nE os da secundaria sao:\n");
    for (int i=0; i<5; i++) {

        for (int j=0; j<5; j++) {

            if (i+j == 4)
                printf("%d, ", matriz[i][j]);
        }
    }

}