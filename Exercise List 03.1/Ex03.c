/*
3.Elabore  um  algoritmo  que  transforme  a  temperatura  fornecida   
em   C  para  a correspondente em F, sendo C = (5/9) * (F-32) e retorne o resultado.
*/

//Converter Celsius para Fahrenheit
//Formula isolando a variavel de Fahrenheit:
// ((C*9)/5)-32   OU
// (C/(9/5))-32


#include <stdio.h>

int main (void) {
    
    //declaracao das variaveis
    float celsius;

    //input e interacao com usuario
    printf("\nConverta Celsius em Fahrenheit.\n");
    printf("\nDigite a temperatura em celsius: ");
    scanf("%f", &celsius);

    //Alternativamente:
    /*
        float fahrenheit;
        fahrenheit = ((celsius * 9)/5) - 32;
        printf("\nA temperatura equivalente em Fahrenheit e de %f.", fahrenheit);
    */

    //Calculo e impressão dos resultados
    printf("\nA temperatura equivalente em Fahrenheit e de %f.", ((celsius * 9)/5) - 32);

    return 0;
}