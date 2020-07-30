/*
9.Escreva um algoritmo para calcular e exibir o comprimento de uma circunferência, sendo dado o valor de seu raio.
*/

//calcular o cumprimento de circunferencia a partir do raio
// Comp = 2 x pi x raio


#include <stdio.h>
//#include <math.h>  //poderia usar math.h para um valor de pi mais preciso

int main (void) {
    
    //declaracao das variaveis
    float comprimento, raio; 

    //input e interacao com usuario
    printf("\nCalcule o comprimento a partir do raio.\n");
    printf("\nInsira o valor do raio e tecle enter: ");
    scanf("%f", &raio);

    //calculo
    comprimento = 2 * 3.14159 * raio;

    // impressão dos resultados
    printf("\nO comprimento e de %.3f,", comprimento);
    
    return 0;
}