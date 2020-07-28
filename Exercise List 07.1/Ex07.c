/*
7.Faça uma função que receba um parâmetro (inteiro por valor) com o total de minutos 
passados ao longo do dia e receba também dois parâmetros (inteiros por referência) no 
qual deve preencher com o valor da hora e do minuto corrente. Faça um programa que leia 
do teclado quantos minutos se passaram desde meia-noite e imprima a hora corrente (use a sua função).
*/

//funcao para dizer hora e minutos, quando lhe e fornecido o total em minutos.
//fica a divida se a funcao deve imprimir ou apenas fornecer os dados.

#include <stdio.h>

void minuteconvert(int minute, int* hournow, int* minutenow);

int main (void) {

    int minute, hournow, minutenow;

    printf("Saiba as horas e minutos a partir do total de minutos desde a meia noite.\n\nInsira o tempo total em minutos e tecle enter: ");
    scanf("%d", &minute);

    //pulando checagem de numeros negativos
    
    printf("Se passaram: ");

    if(minute>1439) {
        int day = minute/1440;
        printf("%d dia(s) ", day);
        minute = minute%1440;    
    }

    minuteconvert(minute, &hournow, &minutenow);

    printf("%d hora(s) e %d minuto(s).", hournow, minutenow);

    return 0;
}

void minuteconvert (int minute, int* hournow, int* minutenow) {

    *hournow = minute/60;
    *minutenow = minute%60;
}