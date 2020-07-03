#include <stdio.h> 

int main(void) {
  //declaracao de variaveis
  float valor, prazo; //considerando que 1.5 meses seja valido
  char tipo;

  //insercao de dados
  printf("Por favor, insira o tipo do processo e digite enter.\n");
  scanf(" %c", &tipo);
  printf("Por favor, insira valor do processo e digite enter.\n");
  scanf("%f", &valor);
  printf("Por favor, insira o prazo do processo e digite enter.\n");
  scanf("%f", &prazo);
  
  //checagem
  if (prazo < 0 || valor < 0)
    printf("Dados incorretos.");
  
  //classificacao
  if ((tipo == 'A' || tipo == 'a') && valor > 12000) {
    printf("Processo em andamento de alto custo.");
  }
  else {
    if (prazo > 12 || tipo == 'E' || tipo == 'e')
      printf("Processo critico.");
  }

  return 0;
}