#include <stdio.h>
#include <stdlib.h>

#include "complex.h"

int main (void) {

    complex *num1 = NULL, *num2=NULL, *result=NULL;
    float real, imaginary;

    system("cls");
    printf("Realize operacoes com numeros complexos (a + bi).");

    printf("\nPrimeiro numero.\nDigite o valor da parte real: ");
    scanf("%f", &real);
    printf("Agora, digite o valor da parte imaginaria: ");
    scanf("%f", &imaginary);
    num1 = makeComplex(real, imaginary);

    printf("\nSegundo numero.\nDigite o valor da parte real: ");
    scanf("%f", &real);
    printf("Agora, digite o valor da parte imaginaria: ");
    scanf("%f", &imaginary);
    num2 = makeComplex(real, imaginary);

    result = makeComplex(0,0);

    sumComplex(num1, num2, result);
    printf("\nO valor da soma dos numeros e de ");
    printComplex(result);

    subtractComplex(num1, num2, result);
    printf(",\nA subtracao deles resulta em ");
    printComplex(result);

    multiplyComplex(num1, num2, result);
    printf(",\nA multiplicacao deles e de ");
    printComplex(result);

    divideComplex(num1, num2, result);
    printf(",\nE sua divisao e de ");
    printComplex(result);

    freeComplex(num1);
    freeComplex(num2);
    freeComplex(result);

    printf("\n\nPrograma encerrado.");
    system("pause");
    return 0;
}