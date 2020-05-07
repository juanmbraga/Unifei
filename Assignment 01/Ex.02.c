#include <stdio.h>
/* Elabore um algoritmo para imprimir os n primeiros termos da sequência definida por recorrência: yi = yi -1 + i, com i = 2, ..., n sendo y1 = 1 Suponha que n = 4, os termos seriam:  y1=1, y2= y1 + 2 = 3, y3= y2 + 3 = 6, y4= y3 + 4 = 10 - (1,3,6,10) */

int main(void) {
  int aux, mem=0, i=1;
  float N;

  printf("Insira o valor de n:");
  scanf("%f", &N);

  //preparando para checar se numero inserido nao foi do tipo float, que atrapalharia nos calculos, ja que C arredondaria. 
  aux = N;

  if (N > 0 && N == aux) //para numeros naturais
    for(i=1; i <= aux; i++)
    {
      mem = mem + i;
      printf("O %do valor de i e igual a %d.\n", i, mem);
    }
  else //para termo zero, abaixo de zero, e numeros com casas decimais. 
    printf("O termo nao existe na sequencia.");
  
  return 0;
}
