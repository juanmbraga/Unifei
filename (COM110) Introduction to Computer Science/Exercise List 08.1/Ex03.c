/*
3.Elabore um programa que leia o código e a quantidade em estoque de 10 produtos 
e armazene esses  dados  em  uma  matriz de  maneira  que  a  primeira  linha  
contenha  o  código  e  a  segunda linha  seja  preenchida  pela  quantidade. 
Depois  de  preenchida  a  matriz,  imprima  a  quantidade total de produtos e 
o código de todos os produtos com quantidade maior que 10
*/

//receber e colocar informacoes sobre 10 produtos, imprimir a quantidade total
//e o codigo daqueles com mais de 10 em estoque. (codigo na primeira linha, e a 
//quantidade em estoque na segunda)

#include <stdio.h>
#include <stdlib.h> //para system("cls")

int main (void) {

    int vetor[2][10], somaProdutos=0, controle=0; 
    //controle para imprimir mensagem caso nenhum tenha mais de dez em estoque

    system("cls");
    printf("\nSaiba a quantidade total de 10 produtos e o codigo daqueles maiores que 10.\n\n");

    for (int j=0; j<10; j++) {
        printf("Digite o codigo do produto: ");
        scanf("%d", &vetor[0][j]);
        printf("Agora, insira a quantidade em estoque: ");
        scanf("%d", &vetor[1][j]);
    }

    for (int j=0; j<10; j++) {
        somaProdutos += vetor[1][j];
    }

    printf("\nA soma dos produtos em estoque e de %d.", somaProdutos);
    printf("\nCodigos daqueles com mais de dez:\n");

    for (int j=0; j<10; j++) {
        if (vetor[1][j] > 10) {
            printf("%d  ", vetor[0][j]);
            controle++;
        }
    }

    if (controle == 0)
        printf("Nenhum produto possui mais de dez unidades em estoque.");
}