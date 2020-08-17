/*
1.Elabore  um  programa  que  preencha  os  elementos  de  uma  matriz  2  x  3  
de  números  inteiros. Depois de preenchida, imprima os elementos digitados linha 
por linha e depois o valor do maior elemento.
*/

//preencher vetor 2x3, depois imprimir os elementos linha por linha e o maior valor


#include <stdio.h>
#include <stdlib.h> //para system("cls")

int main (void) {

    int vetor[2][3], maior;

    system("cls");

    printf("\nReveja os elementos de uma matriz 2x3 e saiba seu maior valor.\n\n");

    for (int i=0; i<2; i++) {   //receber os valores do usuario
        for (int j=0; j<3; j++) {
            printf("Insira um valor para a casa (%d,%d): ", i+1, j+1);
            scanf("%d", &vetor[i][j]);
        }
    }

    for (int i=0; i<2; i++) {   //imprimir todos os valores por linha
        for (int j=0; j<3; j++) {
            printf("%d ", vetor[i][j]);
        }
        printf("\n");
    }

    maior = vetor[0][0];    //inicializando a variavel (com zero poderia nao funcionar caso tudo fosse negativo)

    for (int i=0; i<2; i++) {   //verificar qual e o maior item
        for(int j=0; j<3; j++) {
            if (vetor[i][j] > maior)
                maior = vetor[i][j];
        }
    }

    printf("\nO maior item e de numero %d.", maior);    //imprimir o maior numero
}