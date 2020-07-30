/*
8.Escreva  um  algoritmo  para  calcular  e  exibir  a  média  
ponderada  de  2  notas  dadas. (nota 1 tem peso 6 e nota 2 tem peso 4). 
Considere que as duas notas são diferentes de 0.
*/

//calcular a media ponderada de notas fornecidas


#include <stdio.h>

int main (void) {
    
    //declaracao das variaveis
    float nota1, nota2;

    //input e interacao com usuario
    printf("\nSaiba a media ponderada da nota.\n");
    printf("\nInsira a primeira nota e tecle enter: ");
    scanf("%f", &nota1);
    printf("\nAgora, digite a segunda: ");
    scanf("%f", &nota2);

    //Calculo e impressão dos resultados
    printf("\nA media ponderada da nota e de %.1f,", ((nota1*6) + (nota2*4)) / 10);
    
    return 0;
}
