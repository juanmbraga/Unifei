#include <stdio.h>
#include <stdlib.h>

#include "complex.h"

//////////////////////////////////////////
// criação do registro do tipo complexo /
////////////////////////////////////////

struct complexo {
  float a;
  float b;
};


complex* criarComplexo (float a, float b) {
  complex *numero = NULL;
  numero = (complex*) malloc(sizeof(complex));
  
  //checar se alocacao deu certo
  if (numero == NULL) {
    printf("Memoria insuficiente.\nEncerrando...");
    exit(1);
  }
  
  //se passar do teste, passar os valores
  numero->a = a;
  numero->b = b;
  
  return numero;
}

void liberaComplexo (complex* num){
  free(num);
}

void imprimeComplexo(complex* num) {
  printf("%.3f + %.3fi", num->a, num->b);
}

complex* somaComplexo (complex* num1, complex* num2){

  complex *soma = NULL;
  soma = (complex*) malloc (sizeof(complex));
  
  //checar se alocacao deu certo
  if (soma == NULL) {
    printf("Memoria insuficiente.\nEncerrando...");
    exit(1);  //usar 1 ou 0?
  }
  
  soma->a = num1->a + num2->a;
  soma->b = num1->b + num2->b;

  return soma;
}

complex* subtraiComplexo (complex* num1, complex* num2){

  complex *subtracao = NULL;
  subtracao = (complex*) malloc (sizeof(complex));
  
  //checar se alocacao deu certo
  if (subtracao == NULL) {
    printf("Memoria insuficiente.\nEncerrando...");
    exit(1);  //usar 1 ou 0?
  }
  
  subtracao->a = num1->a - num2->a;
  subtracao->b = num1->b - num2->b;

  return subtracao;
}

complex* multiplicaComplexo (complex* num1, complex* num2){

  complex *multiplicacao = NULL;
  multiplicacao = (complex*) malloc (sizeof(complex));
  
  //checar se alocacao deu certo
  if (multiplicacao == NULL) {
    printf("Memoria insuficiente.\nEncerrando...");
    exit(1);  //usar 1 ou 0?
  }
  
  multiplicacao->a = ((num1->a * num2->a) - (num1->b * num2->b));
  multiplicacao->b = ((num1->b * num2->a) + (num1->a * num2->b));

  return multiplicacao;
}

complex* divideComplexo (complex* num1, complex* num2){
  complex *divisao = NULL;
  divisao = (complex*) malloc (sizeof(complex));
    
  if (divisao == NULL) {
  printf("Memoria insuficiente.\nEncerrando...");
  exit(1);
  }
  
  //((ac - bd) / (cc + dd)) + ((bc - ad) / (cc + dd))
  divisao->a = ((num1->a * num2->a) - (num1->b * num2->b)) / ((num2->a * num2->a) + (num2->b * num2->b));

  divisao->b = ((num1->b * num2->a) - (num1->a * num2->b)) / ((num2->a * num2->a) + (num2->b * num2->b));

  return divisao;
}