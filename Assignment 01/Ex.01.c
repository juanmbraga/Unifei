#include <stdio.h>
/* Escreva um algoritmo para calcular N! (Fatorial de N), sendo que o valor inteiro de N é fornecido pelo usuário.
 Sabe-se que: N! = 1 * 2 * 3 * ... * (N-1) * N; 0! = 1, por definição.*/

int main(void) {
  int N, i, fatorial=1;

  printf("Por favor, insira o numero para calcular seu fatorial: ");
  scanf("%d", &N);
  
  if (N>=0) {

   //para os demais naturais
    if (N != 0) {
      for (i=N;i>0;i--) {
       fatorial = fatorial * i;}
      printf("O fatorial do numero e igual a: %d", fatorial);
      }
    
   //caso N for igual a zero
    else
      printf("O fatorial do numero e igual a: 1\n");
      }

  //caso N estiver abaixo de zero
  else {
  printf("Numeros inteiros menores que zero possuem fatorial indefinido / infinito.");
  }
  return 0;
}

//estrutura basica
//insercao do numero inteiro N
//checar se numero inserido e do tipo inteiro
//se e menor que zero, o fatorial e indeterminado/infinito
//se e igual a zero, ele equivale a um
//se for maior que zero, calcular

//[ignore, irei perguntar depois da data de entrega do exercicio]
/*curiosamente, quando coloquei um if (N==0) antes do for (para o calculo do fatorial maior que zero), ele executou o printf para o valor igual a um, mas por alguma razao ele executou o comando do else tambem (onde estavam os calculos), o que resultou em duas mensagens retornando que N! e igual a 1. Pq?*/