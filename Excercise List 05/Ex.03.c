#include <stdio.h>

int main(void) {
  int i, num, soma=0, repete;
  
  printf("Por favor, digite o numero de valores que sera somado, e tecle enter.\n");
  scanf("%d", &repete);

  if (repete >= 2) {
  for (i=1;i<=repete;i++) {
    printf("Digite o numero a ser somado:\n");
    scanf("%d", &num);
    soma = soma + num;
  }
  printf("A soma parcial dos numero e igual a %d\n", soma);
  }
  else
  printf("O numero de valores deve ser no minimo dois.");
  return 0;
}