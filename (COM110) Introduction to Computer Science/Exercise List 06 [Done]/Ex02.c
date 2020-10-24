#include <stdio.h>
/*
Questão 2.
 Faça um programa que contenha uma função que recebe dois números positivos x e y e retorne a soma 
 dos N números inteiros existentes entre x e y (inclusive). 
 Use a função no programa principal para imprimir a soma dos números inteiros entre dois números
 digitados pelos usuários. A soma só deve ser calculada somente se os números digitados forem diferente.
*/

int sumbetween (int x, int y) {
    int sum=0;
    
    for (int i=x; i<=y;i++) {
        sum = sum + i;
    }
    return sum;

    //printf("A soma e de %d", sum);
    //foi solicitado que a funcao principal imprima.
}

int main () {
    //float a, b; //nao especificou que a entrada era inteira
    //ignorado para simplificar

    int c, d, aux;

    printf("Insira dois numeros inteiros e digite enter apos cada um: ");
    scanf("%d%d", &c, &d);

    //converter para o inteiro mais proximo
    //c = a; d = b; //ignorado para simplificar

    if (c==d) //foi especificado que o numero e positivo
        printf("Os numeros sao iguais.");
    else 
        if (c < d) 
            printf("A soma e de %d", sumbetween(c,d));
        else 
        printf("A soma e de %d", sumbetween(d,c));
    return 0;    
}