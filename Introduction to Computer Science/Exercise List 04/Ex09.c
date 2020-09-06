
#include <stdio.h> 

int main(void) {
  //declaracao de variaveis
  float salario, reajustado;

  //insercao de dados
  printf("Por favor, insira o salario e digite enter.\n");
  scanf("%f", &salario);
  
  //checagem
  if (salario < 100 || salario > 4500)
    printf("Salario invalido.");
  
  //avaliacao
  if (salario < 300)
    reajustado = (salario*1.50);
  else
    reajustado = (salario*1.30);
  
  //output
  printf("O valor do salario com o reajuste adequado e de %f", reajustado);
  
  return 0;
}