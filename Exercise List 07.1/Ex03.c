/*
3.Elabore uma função que troca os valores de duas variáveis inteiras. Use a função no programa
principal para trocar dois valores digitados pelo usuário.
*/

//função para trocar de lugar duas variáveis, usano parâmetro.

#include <stdio.h>

void swap(int* num1, int* num2);

int main (void) {

    int num1, num2;   //me pergunto como ficaria passar um valor "inteiro" com todos os dados...

    
    printf("\nDigite dois valores, teclando enter apos cada um: ");
    scanf("%d %d", &num1, &num2);
    
    swap(&num1, &num2);

    printf("\nA ordem dos valores foi alterada: %d e %d", num1, num2);
    
    return 0;
}

void swap(int* num1, int* num2) {

    int aux;

    aux = *num1;
    *num1 = *num2;
    *num2 = aux;
}
