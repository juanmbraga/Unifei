/*#include <stdio.h>
Considere que a empresa mencionada no exercício anterior tenha decidido mudar a regra da seguinte maneira. 
a. Se quantidade mensal de peças produzida pelo funcionário durante os últimos 12 meses > 120, o funcionário ganha 5% do valor líquido do salário. 
b. Senão, se o funcionário não faltou durante os 12 últimos meses, ganha 2% do valor líquido do salário. 
  Elabore um algoritmo que receba o valor do salário líquido, a quantidade de falta de um funcionário e a quantidade de peças produzidas nos últimos 12 meses e retorne o valor do salário mais o abono considerando a nova regra.

Eu pensei em colocar uma funcao "if" depois de o usuario ter inserido o numero de pecas, para facilitar as coisas, mas ja que o problema exigiu que se tenha que receber as faltas, nao o fiz.

int main (void) {
int salario,falta,peca;
  printf("Por favor, insira o salario liquido:\n");
  scanf("%d", &salario);
  printf("Agora, digite o numero mensal de pecas produzidos pelo funcionario no ultimo ano:\n");
  scanf("%d", &peca);
  printf("Por ultimo, insira o numero de faltas do funcionario nos ultimos 12 meses:\n");
  scanf("%d", &falta);
  if (peca > 120)
    salario = salario*1.05;
  else
    if (falta == 0) 
    salario = salario*1.02;
  printf("O salario acrescido do abonos aplicaveis do funcionario sera de %d", salario);
  return 0;
}*/