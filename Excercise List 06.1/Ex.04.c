#include <stdio.h>

/*
4.Faça  uma função  que  recebe  por  parâmetro  o  raio  de  uma  esfera  e  calcula  o  seu volume (v = 4/3.P .R3).
*/

//Fica um pouco feio nao ter unidade de medida, mas ok.a

float spherevol (float raio);

int main () {
    float raio;

    printf("Digite o raio da esfera: ");
    scanf("%f", &raio);

    printf("O volume da esfera e de %f.", spherevol(raio));
    return 0;
}

float spherevol (float raio) {
    return ((raio*raio*3.14*4)/3);
}