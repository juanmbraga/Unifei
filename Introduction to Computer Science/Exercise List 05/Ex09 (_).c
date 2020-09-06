#include <stdio.h>
/*Escreva um algoritmo que leia os dados de funcionários de uma empresa, salário e o código (inteiro), e retorne o código e o salário do funcionário que ganha mais. Todos os salários são diferentes. Não é necessário validar a entrada de dados. A lista termina quando for digitado o código 0.  */

int main(void) {
  int codigo=1, mcodigo;
  float salario, msalario=0;
  
  printf("Nota: para finalizar as comparacoes, insira o valor 0 (zero) para o codigo e qualquer coisa para o salario.\n\n");
  while (codigo != 0) {
    printf("Digite o codigo do funcionario:\n");
    scanf("%d", &codigo);
    printf("Digite o salario:");
    scanf("%f", &salario);
    if (salario > msalario)
      msalario = salario;
      mcodigo = codigo;
  }
  printf("O codigo do funcionario com o maior salario e %d,\ne seu salario e de %f.", mcodigo, msalario);
  return 0;
}

//o que ha de errado aqui?