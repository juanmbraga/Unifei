#include <stdio.h> 

int main(void) {
  float num;
  int aux;
  printf("Por favor, insira um numero inteiro qualquer, e digite enter em seguida");
  scanf("%f", &num);
  aux=num;
  //inicio da verificacao
  if (aux!=num)
    printf("O numero inserido nao e do tipo inteiro.");
  else {
    if ((aux % 5) == 0 && (aux % 3) == 0)
      printf("O numero e divisivel por cinco e por tres, ao mesmo tempo.");
    else
      printf("O numero nao e divisivel por cinco e/ou tres.");
  }
  return 0;
}