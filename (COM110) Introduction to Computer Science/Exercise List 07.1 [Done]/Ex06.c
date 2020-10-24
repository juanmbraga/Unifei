/*
6. Faça uma função que receba um valor inteiro como referência e retorne o resto da divisão
deste número por 10. Altere também o valor da variável passada por referência, dividindo-a por 10.
*/

//Funcao que receba parametro com valor inteiro, e retorne o resto de sua divisão por dez.
//fica a pergunta se o retorno deveria ser de fato por return, ou por parametro.

#include <stdio.h>

int tenremainder (int* num);

int main (void) {

    int num;

    printf("Saiba o resto da divisao de um numero por dez.\n\nDigite um valor: ");
    scanf("%d", &num);

    printf("O resto da divisao por dez do numero e igual a %d.", tenremainder(&num));

    return 0;
}

int tenremainder (int* num) {

    int aux;
    aux=*num;
    *num = *num/10;

    return aux%10;
}