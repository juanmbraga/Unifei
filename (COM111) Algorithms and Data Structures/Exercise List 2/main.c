#include <stdio.h>
#include <stdlib.h>
#include "complex.h"

//passar variavel resultado por parametro poderia economizar um "liberaComplexo" por operacao, mas optamos por manter anecessidade do programador de colocar a variavel para receber o ponteiro.

int main(void) {
  complex *num1 = NULL, *num2 = NULL, *resultado = NULL;
  float a, b;

  system("clear");
  printf("Realize operacoes com numeros inteiros no formato (a + bi).\n\n");

  //receber primeiro numero
  printf("Primeiro numero.\n");
  printf("Digite o numero para a parte real: ");
  scanf("%f", &a);
  printf("Digite o numero para a parte imaginaria: ");
  scanf("%f", &b);
  num1 = criarComplexo(a, b);

  //receber segundo numero
  printf("\nSegundo numero.");
  printf("\nDigite o numero para a parte real: ");
  scanf("%f", &a);
  printf("Digite o numero para a parte imaginaria: ");
  scanf("%f", &b);
  num2 = criarComplexo(a, b);

  //operacoes:
  //variavel recebe ponteiro com valores calculados
  //precedido da mensagem, o numero e impresso
  //a variavel alocada na funcao e liberada

  //Soma
  resultado = somaComplexo(num1, num2);
  printf("\nA soma dos numeros e de: ");
  imprimeComplexo(resultado);
  liberaComplexo(resultado);

  //Subtracao
  resultado = subtraiComplexo(num1, num2);
  printf("\nA subtracao deles e de: ");
  imprimeComplexo(resultado);
  liberaComplexo(resultado);
  
  //Multiplicacao
  resultado = multiplicaComplexo(num1, num2);
  printf("\nSua multiplicacao e de: ");
  imprimeComplexo(resultado);
  liberaComplexo(resultado);
  
  //Divisao
  resultado = divideComplexo(num1, num2);
  printf("\nE sua divisao e: ");
  imprimeComplexo(resultado);
  liberaComplexo(resultado);

  liberaComplexo(num1);
  liberaComplexo(num2);

  printf("\n\nPrograma encerrado.");

  return 0;
}