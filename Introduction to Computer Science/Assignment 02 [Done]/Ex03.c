#include <stdio.h>

/* 
Faça  uma  função  que  receba  um  parâmetro  (inteiro  por  valor)  com  o  total  de  minutos 
passados ao longo do dia e receba também dois parâmetros (inteiros por referência) no qual deve preencher 
com o valor da hora e do minuto corrente. Faça um programa que leia  do  teclado  quantos  minutos  
se  passaram  desde  meia-noite  e  imprima  a  hora corrente (use a sua função).

P.S.: Parto do principio de que "ao longo do dia" limita o escopo de tempo para no maximo um dia apos, e nao 
seja necessario calcular o numero de dias passados ou algo assim para evitar um [input/output] do tipo:

[5000/"Sao 83 horas e 20 minutos"]
*/

void isitlate (int total, int *hour, int *minute);

int main () {

    int total, hour, minute;

    printf("Insira os minutos que se passaram desde a meia noite deste dia: ");
    scanf("%d", &total);

    isitlate(total, &hour, &minute);

    printf("Sao %d horas e %d minutos.", hour, minute);
    
    return 0;
}

void isitlate (int total, int *hour, int *minute) {

    *hour = total / 60;
    *minute = total % 60; 
}
