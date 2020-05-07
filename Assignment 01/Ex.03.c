#include <stdio.h>
/*Elabore um programa em C que calcule e imprima a seguinte soma
1/1 + 3/2 + 5/3 + ... + 99/50 = S*/

int main(void) {
  int num=99; 
  float soma=0;

  for (int i=50; i>0;i--)
  {
    soma = soma + ((float)num / i);
    num = num - 2;
  }
  printf("A soma e igual a: %f", soma);
  return 0;
}
