/*
10.Faça um algoritmo que receba o peso de uma pessoa, calcule e mostre:

a.O novo peso quando a pessoa engorda 15% do peso digitado
b.O novo peso quando apessoa engorda 20% do peso digitado
*/

//calcular peso quando engorda 15% e 20%


#include <stdio.h>

int main (void) {
    
    //declaracao das variaveis
    float peso;

    //input e interacao com usuario
    printf("\nCalcule seu peso apos engordar 15%% e 20%%.\n"); 
    //caso queira imprimir % (usado para imprimir valores), basta colocar dois %%
    printf("\nInsira o peso e tecle enter: ");
    scanf("%f", &peso);

    //Calculo e impressão dos resultados
    printf("\nO novo peso apos engordar 15%% e de %.2f Kg e\no novo peso ao engordar 20%% e de %.2f Kg.", peso*1.15, peso*1.2);

    return 0;
}