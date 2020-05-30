#include <stdio.h>

/*
Faça uma função que receba 3 valores inteiros por parâmetro e imprima-os de forma ordenada.
*/

void order (int*, int*, int*);


int main () {

    int a, b, c;

    printf("Insira tres numeros inteiros para ordenar, teclando enter apos cada um:\n");
    scanf("%d%d%d", &a, &b, &c);

    order(&a, &b, &c);
    
    printf("Os numeros ordenados sao %d, %d e %d.", a, b, c);
    return 0;
}


void order (int* a,int* b,int* c) {

    int aux;

    while (*a > *b || *b > *c) {
        if (*a > *b) {
            aux = *b;
            *b = *a;
            *a = aux;
        }
        else
        if (*b > *c) {
            aux = *c;
            *c = *b;
            *b = aux;
        }      
    } 
}