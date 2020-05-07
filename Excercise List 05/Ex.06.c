#include <stdio.h>
/*Calcular a soma dos números pares de 100 até 200, inclusive.*/

int main(void) {
  int i, num=100, soma=100;

  printf("Saiba a soma dos numeros pares de 100 a 200!\n");

  for (i=1;i<=50;i++) {
    num = num + 2;
    soma = soma + num;
  }
  printf("A soma dos numeros e de %d", soma);
      return 0;
}
