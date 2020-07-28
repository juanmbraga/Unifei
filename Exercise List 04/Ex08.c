/*
8.Elabore um algoritmo que escreva informações sobre um processo considerando as seguintes regras:

Se o processo é do tipo A e possui valor maior que R$12000,00, então deve ser escrito “Processo em 
andamento com custo alto”.

Se o processo tem prazo maior que 12 meses (o prazo é sempre dado em quantidade  de  meses) ou  o 
cliente é do tipo E (especial), deve ser escrito “Processo crítico”.
*/

#include <stdio.h> 

int main(void) {
  //declaracao de variaveis
  float valor, prazo; //considerando que 1.5 meses seja valido
  char processo, cliente;

  //insercao de dados
  printf("Por favor, insira o tipo do processo e digite enter.\n");
  scanf(" %c", &processo);
  printf("Por favor, insira valor do processo e digite enter.\n");
  scanf("%f", &valor);
  printf("Por favor, insira o prazo do processo e digite enter.\n");
  scanf("%f", &prazo);
  printf("Por favor, insira o tipo do cliente e digite enter.\n");
  scanf("%c", &cliente);  

  //checagem
  if (prazo < 0 || valor < 0) {
    printf("\nDados incorretos.");
    return 0;
  }

  //classificacao
  if ((processo == 'A' || processo == 'a') && valor > 12000) {
    printf("\nProcesso em andamento de alto custo.");
  }
  else {
    if (prazo > 12 || cliente == 'E' || cliente == 'e')
      printf("\nProcesso critico.");
  }

  //seguindo a ordem do que a professora pediu
  //considerando que ambas as possibilidades nao possam ocorrer ao mesmo tempo
  //desconsiderando que caso ambas condicoes nao sejam atendidas, nao haja outro output e o usuario nao receba nada.
  return 0;
}