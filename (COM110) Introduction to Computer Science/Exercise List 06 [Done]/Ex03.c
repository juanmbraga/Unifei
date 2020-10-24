#include <stdio.h>
/*
Questão 3. Faça uma função que receba 2 valores inteiros e imprima-os de forma ordenada. 
Utilize a função no programa principal. 
*/

void order (int, int);

int main (void) {
    int um, dois;

    printf("Insira dois valores inteiros, digitando enter apos cada um: ");
    scanf("%d%d", &um, &dois);

    order(um,dois);
}

void order (int x, int y) 
{
    if (x>y)
        printf ("\nOs numeros na ordem crescente sao %d e %d.", y, x);
    else 
        printf ("\nOs numeros na ordem crescente sao %d e %d.", x, y);
}