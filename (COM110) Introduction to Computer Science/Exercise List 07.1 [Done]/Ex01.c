/*
1. Elabore uma função que receba uma hora completa (hora/minuto/segundo) e converta para segundo. 
Use a função no programa principal para converter um valor hora completo fornecido pelo usuário.

Dica: um dos parâmetros recebidos pela função deve ser o endereço da variável que deverá guardar 
o resultado da conversão.
*/

//Converter hora/minuto/segundo para segundos usando uma função que receba parâmetro.

#include <stdio.h>

void tosecond(int hour, int minute, int* second);

int main (void) {

    int hour, minute, second;   //me pergunto como ficaria passar um valor "inteiro" com todos os dados...

    do {
        printf("\nDigite a hora, os minutos e segundos, teclando enter apos cada um deles: ");
        scanf("%d %d %d", &hour, &minute, &second);
    }
    while ((hour < 0) && (minute < 0) && (second < 0));  //qualquer quantidade de horas que o usuario quiser

    tosecond(hour, minute, &second);

    printf("\nO tempo digitado convertido para segundos e de %d seg.", second);
    
    return 0;
}

void tosecond(int hour, int minute, int* second) {
    *second += hour*3600;   //1h * 60min * 60seg
    *second += minute*60;
}

