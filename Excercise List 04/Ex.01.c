#include <stdio.h>
//Qual e o maior numero?
int main(void) {
  int val1, val2;
  //Insercao dos dados
  printf("Por favor, insira dois valores inteiros quaisquer, digitando enter apos cada um deles.\n");
  scanf("%d %d", &val1, &val2);
  //inicio algoritmo
  printf("O maior numero entre os inseridos e o ");
  if (val1 > val2)
    printf("%d.", val1);
  else
    printf("%d.", val2);
  return 0;
}