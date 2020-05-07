#include <stdio.h>

int main(void) {
  int num=1, soma=0;
  
  printf("Insira os numeros a serem somados, e digite zero para pausar a soma.\n\n");
  while (num != 0) {
    printf("Digite um numero ou digite zero para parar a soma:\n");
    scanf("%d", &num);
    soma = soma + num;
  }
  printf("A soma dos numeros e igual a %d\n", soma);
  return 0;
}
