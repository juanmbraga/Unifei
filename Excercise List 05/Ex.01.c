#include <stdio.h>
/*Escreva um algoritmo que leia dez números do teclado e imprima a metade de cada número. */
int main(void) {
  int i;
  float num;

  printf("Saiba a metade de dez numeros.\n");

  for (i=1;i<=10;i++) {
    printf("Digite um numero:\n");
    scanf("%f", &num);
    printf("A metade do numero e %f.\n", num/2);
  }
      return 0;
}
