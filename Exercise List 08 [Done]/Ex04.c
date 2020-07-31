/*
4.Elabore um programa que leia 10 números inteiros e armazene em um vetor. 
Depois de preenchido o vetor, imprima somente os números pares do vetor.
*/

//ler dez numeros inteiros, e imprimir os de valor par
//nao chequei por valores repetidos (seria preciso?)


#include <stdio.h>

int main (void) {

    int numero[10], auxiliar=0; //e possivel fazer sem a auxiliar

    printf("\nSaiba os numeros pares de um conjunto de dez.\n");

    //receber o input dos dez numeros
    for (int i=0; i<10; i++) {   

        printf("Digite um numero inteiro e tecle enter: ", i+1);
        scanf("%d", &numero[i]);

    }

    //checar e imprimir os pares
    printf("Os numeros pares sao:\n");
    for (int i=0; i<10; i++) {

        if (numero[i] % 2 == 0) {
            printf("%d  ", numero[i]);
            auxiliar++;
        }

    }

    //caso nenhum seja par
    if (auxiliar == 0) 
        printf("nenhum numero inserido e par.");

    return 0;
}