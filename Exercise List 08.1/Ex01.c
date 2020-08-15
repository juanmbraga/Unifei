/*
1.Elabore  um  programa  que  preencha  os  elementos  de  uma  matriz  2  x  3  
de  números  inteiros. Depois de preenchida, imprima os elementos digitados linha 
por linha e depois o valor do maior elemento.
*/

//preencher vetor 2x3 de inteiros, depois imprimir os elementos linha por linha e o maior valor


#include <stdio.h>

int main (void) {

    int vetor[2][3], maior;

    printf("\nReveja os elementos de uma matriz 2x3 e saiba seu maior valor.\n");

//receber os dados
    for (int i=0; i<2; i++) {

        for (int j=0; j<3; j++) {

            printf("\nInsira um valor para a casa (%d,%d): ", i+1, j+1);
            scanf("%d", &vetor[i][j]);

        }

    }

//imprimir os dados inseridos
    printf("Segue a matriz inserida:\n\n");
    for (int i=0; i<2; i++) {

        for (int j=0; j<3; j++) {

            printf("%d  ", vetor[i][j]);
        
        }

        printf("\n");
    
    }

//procurar pelo maior valor
    maior = vetor[0][0]; //inicializar, para nao sair zero em caso de todos serem negativos.

    for (int i=0; i<2; i++) {
        for (int j=0; j<3; j++) {

            if (vetor[i][j] > maior)
                maior = vetor[i][j]; 
                
        }
    }

    printf ("\nO maior valor da lista e o %d.", maior);

    return 0; 
}