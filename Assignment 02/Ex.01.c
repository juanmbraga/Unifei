#include <stdio.h>
#include <math.h>

/* 
Dado qualquer N, se você aplicar repetidas vezes a seguinte função:

f(N)= N / 2 , se N e par.
f(N)= 3 * N + 1, se N for impar.

o valor eventualmente será igual a 1. 
Agora faça um programa que diz o número de vezes que a função é chamada antes que o valor de N seja igual a 1.

Obs.: 1 <= N <= 100000
*///pode ser possivel fazer com do/while -1

int collatz (int a);

int main () {
    int i, num;
    printf("Insira um numero qualquer: ");
    scanf("%d", &num);

    if (num >= 1 && num <= 100000) {

        for (i=0; num != 1; i++){
            num = collatz (num);
        }

        printf ("O numero de operacoes necessarias e igual a %d.", i);
    }
    else
    printf("Numero nao permitido, deve estar entre 1 e 100000.");    
}

int collatz (int a) {
    if (a % 2 == 0)
        return a/2;
    else
        return (a*3)+1;
}