#include <stdio.h>
#include <math.h>

/* 
Dado qualquer N, se você aplicar repetidas vezes a seguinte função:

f(N)= N / 2 , se N e par.
f(N)= 3 * N + 1, se N for impar.

o valor eventualmente será igual a 1. 
Agora faça um programa que diz o número de vezes que a função é chamada antes que o valor de N seja igual a 1.

Obs.: 1 <= N <= 100000
*/

//todas as interacoes com o usuario foram removidas, visto que o "juiz" da Neps Academy as classificou como "erradas". 

int collatz (int a);

int main () {

    int i, num;

    scanf("%d", &num);

    if (num >= 1 && num <= 100000) {

        for (i=0; num != 1; i++){
            num = collatz (num);
        }

        printf ("%d", i);
    }

}


int collatz (int a) {
    if (a % 2 == 0)
        return a/2;
    else
        return (a*3)+1;
}