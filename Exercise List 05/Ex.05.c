#include <stdio.h>
/*Escreva um algoritmo que imprima os 100 primeiros números ímpares começando de 1. */
int main(void) {
  int i, num=1;

  printf("Saiba os cem primeiros numeros impares!\n");

  for (i=1;i<=100;i++) {
    printf("%d\n", num);
    num = num + 2; 
  }
      return 0;
}
