#include <stdio.h> //for printf()
#include <stdlib.h> //for malloc

#include "complex.h"

struct complexo {
    float a;
    float b;
};

complex* makeComplex(float a, float b){

    complex* variable;
    variable = (complex*) malloc(sizeof(complex));

    if (variable == NULL) {
        printf("Memoria insuficiente.\n\nPrograma Encerrado.");
        exit(1); //faz diferenca 1 ou 0?
    }

    variable->a = a;
    variable->b = b;

    return variable;
}

void printComplex(complex* number){

    printf("%.3f + %.3fi", number->a, number->b);
}

void sumComplex(complex* num1, complex* num2, complex* result){
    
    result->a = num1->a + num2->a;
    result->b = num1->b + num2->b;
}

void subtractComplex(complex* num1, complex* num2, complex* result){

    result->a = num1->a - num2->a;
    result->b = num1->b - num2->b;
}

void multiplyComplex(complex* num1, complex* num2, complex* result){

    result->a = ((num1->a * num2->a) - (num1->b * num2->b));
    result->b = ((num1->b * num2->a) + (num1->a * num2->b));
}

void divideComplex(complex* num1, complex* num2, complex* result){

    result->a = ((num1->a * num2->a) - (num1->b * num2->b)) / ((num2->a * num2->a) + (num2->b * num2->b));
    result->b = ((num1->b * num2->a) - (num1->a * num2->b)) / ((num2->a * num2->a) + (num2->b * num2->b));
}

void freeComplex(complex* num){
    free(num);
}


