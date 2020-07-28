/*
8. Faça um programa que imprima invertidos os nomes dos algarismos de um número inteiro de três dígitos. 
Use a sua função no programa principal. Não é necessário validar a entrada do número. 
Ex: 234 saída: quatro três dois.
*/

//funcao que imprima os nomes dos algarismos de um numero de tres digitos ao contrario.

#include <stdio.h>

int names(int num);

int main (void) {

    int num;

    printf("Digite um numero de tres digitos: ");
    scanf("%d", &num);

    names(num);

    return 0;
}

int names(int num) {
    int list[3];

    list[2] = num/100;
    num = num%100;
    list[1] = num/10;
    num = num%10;
    list[0] = num;

    for( int i=0; i<3; i++) {
        switch (list[i]) {

            case 0: printf("zero ");
                break;
            case 1: printf("um ");
                break;
            case 2: printf("dois ");
                break;
            case 3: printf("tres ");
                break;
            case 4: printf("quatro ");
                break;
            case 5: printf("cinco ");
                break;
            case 6: printf("seis ");
                break;
            case 7: printf("sete ");
                break;
            case 8: printf("oito ");
                break;
            case 9: printf("nove ");
                break;

            default:
                return 1;
        }
    }
}