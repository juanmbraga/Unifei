/*#include <stdio.h>
Uma empresa resolveu dar um abono salarial aos seus funcionários. O abono é definido de acordo com a seguinte regra: 
A) Se quantidade mensal de peças produzida pelo funcionário durante os últimos 12 meses > 120, o funcionário ganha 3% do valor líquido do salário. 
B) Se o funcionário não faltou durante os 12 últimos meses, ganha 2% do valor líquido do salário. 
  Os abonos são acumulativos, ou seja, um funcionário pode estar nas duas categorias e ganhar os dois tipos de abono. 
Elabore um algoritmo que receba o valor líquido do salário, a quantidade de falta de um funcionário e a quantidade de peças produzidas nos últimos 12 meses e retorne o valor do salário mais o abono.
int main(void) {
  int salario,falta,peca,abono;
  printf("Por favor, insira o salario liquido:\n");
  scanf("%d", &salario);
  printf("Agora, digite o numero mensal de pecas produzidos pelo funcionario no ultimo ano:\n");
  scanf("%d", &peca);
  printf("Por ultimo, insira o numero de faltas do funcionario nos ultimos 12 meses:\n");
  scanf("%d", &falta);
  if (peca > 120)
    abono = salario*0.03;
  if (falta == 0) 
    abono = abono+(salario*0.02);
  salario = salario+abono;
  printf("O salario acrescido dos abonos aplicaveis sera de %d", salario);
  return 0;
}
*/