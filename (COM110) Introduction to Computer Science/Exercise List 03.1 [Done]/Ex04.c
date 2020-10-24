/*
4.Elabore um  algoritmo que calcule quantas notas de 50, 10 e 1 são 
necessárias para se  pagar  uma  conta cujo  valor  é  fornecido.
Considere  que  o  valor  é  sempre  maior que 0. 
*/

//Calcular quantas notas de 50, 10 e 1 sao necessarias para dado valor


#include <stdio.h>

int main (void) {
    
    //declaracao das variaveis
    int valor;

    //input e interacao com usuario
    printf("\nSaiba quantas notas de 50, 10 e 1 precisara.\n");
    printf("\nDigite um valor de ate tres digitos: ");
    scanf("%d", &valor);

    //Calculo e impressão dos resultados
    printf("\nSerao necessarias \n%d notas de 50 reais,", valor/50);
    printf("\n%d notas de 10 reais e", (valor % 50)/10);
    printf("\n%d notas de 1 real.", ((valor % 50)% 10));

    /*Alternativamente

        printf("\nSerao necessarias \n%d notas de 50 reais,", valor/50);
        valor = valor % 50; //armazena o resto da divisao por 50
        printf("\n%d notas de 10 reais e", valor/10);
        valor = valor % 10; //armazena o resto da divisao por 10
        printf("\n%d notas de 1 real.", valor);
    */

    return 0;
}