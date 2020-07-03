#include <stdio.h>
/*
a) Elabore uma função que receba dois números inteiros (a e b) e retorne a soma desses valores.  
b) Elabore uma função para imprimir a seguinte cadeia de caracter na tela 
        A soma {a,b} =  
    A cadeia de caracter acima deve obrigatoriamente começar em uma nova linha. 
    Contudo, o cursor não deve pular de linha depois de imprimir a cadeia. 
c) Elabore um programa que leia dois valores digitados no teclado e utilize as duas funções criadas
    para imprimir o valor da soma na tela da seguinte forma:  
        A soma {a,b} = valor da soma 
*/

int fsum (int x, int y) {
    return x+y;
}

void fprintsum () {
    printf("\nA soma {a, b} = ");
}

int main () {
    int a, b;

    printf("Insira dois numeros inteiros, teclando enter apos cada um: ");
    scanf("%d%d", &a, &b);

    fprintsum(); //imprimir a cadeia
    printf("%d", fsum(a,b)); //imprimir o valor, usando uma funcao
    
    return 0;
}


