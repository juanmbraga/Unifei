/*
2. Elabore uma função que receba dois números inteiros e positivos e calcule a soma 
dos números no intervalo fechado definido entre o primeiro e o segundo número. Use a 
função no programa principal para calcular a soma entre dois números fornecidos pelo usuário. 
A função só deverá ser executada caso o primeiro valor seja maior ou igual ao segundo. 
Dica: um dos parâmetros recebidos pela função deve ser o endereço da variável que deverá guardar o valor da soma.
*/

//programa que usa função para somar sumeros entre dois valores fornecidos, com uso de parâmetro

#include <stdio.h>

void sumbetween(int num1, int num2, int*sum);

int main (void) {

    int num1, num2, sum;

    printf("\nSaiba a soma dos numeros inteiros entre dois numeros fornecidos.\n\nDigite o maior numero: ");
    scanf("%d", &num1);
    printf("\nAgora, insira o segundo numero: ");
    scanf("%d", &num2);

    if (num1 < num2) {
        printf("\nO valor do primeiro numero deve ser maior ou igual ao segundo.\nPrograma encerrado.");
        return 0;
    }
    
    sumbetween(num1, num2, &sum);

    printf("A soma dos valores inteiros entre os dois numeros e de %d.", sum);
    
    return 0;
}

void sumbetween (int num1, int num2, int* sum) {     //sem saco para pensar se e o melhor meio de fazer (ferias)

    *sum=0;

    if (num1 != num2 || (num1+1) != num2)
        for (int i=num2+1; i<num1; i++) {
            *sum += i;
        }
        
}