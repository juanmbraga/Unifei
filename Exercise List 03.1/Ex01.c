/*
1.Escreva um algoritmo para calcular e escrever a área de um triângulo, 
sendo dados a sua base e a sua altura (Área = (base X altura) / 2)
*/

//Calcular area de triangulo


#include <stdio.h>

int main (void) {

    int base, altura;

    printf("\nDigite o valor da base do triangulo: ");
    scanf("%d", &base);
    printf("\nAgora, digite o valor da altura: ");
    scanf("%d", &altura);

//  Alternativamente:
//  int area;
//  area = base*altura/2;

    printf("O valor da area deste triangulo e de %d.", base*altura/2);

    return 0;
}