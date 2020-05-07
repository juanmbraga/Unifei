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
    if ((aux % 5) == 0)
    printf("O numero e divisivel por cinco.");
  }
  return 0;
}