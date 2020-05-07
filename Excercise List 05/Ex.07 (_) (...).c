#include <stdio.h>
/*Escreva um algoritmo que leia o salário e o código (inteiro) de 20 funcionários 
e retorne o código e o salário do funcionário que ganha mais. Todos os salários são diferentes. Não é necessário validar o código. */

int main(void) {
  int i, codigo, codigomaior;
  float salario=0, salariomaior=0;

  for (i=1;i<=20;i++) {
    printf("\nInsira o codigo do funcionario: ");
    scanf("%d", &codigo);
    printf("Insira o salario do funcionario: ");
    scanf("%f", &salario);
    if (salario > salariomaior) {
      salariomaior = salario;
      codigomaior = codigo;
    }
  }
  printf("O maior salario e de %f reais,\n e o funcionario com ste salario tem o codigo de %d", salariomaior, codigomaior);
      return 0;
}

//como checar se salario > 0 em uma estrutura assim?