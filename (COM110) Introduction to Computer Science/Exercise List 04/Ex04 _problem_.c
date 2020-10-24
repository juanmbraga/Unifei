#include <stdio.h> 

int main(void) {
  //declaracao de variaveis
  char A;
  float salary;

  //insercao de dados
  printf("Por favor insira o codigo da funcao do funcionario, e tecle enter.\n");
  scanf("%c", &A);
  printf("Agora, insira o salario dele(a).\n");
  scanf("%f", &salary);

  //funcioanrio e gerente?
  if ((A == "G") || (A == "g")) 
  {
    if (salary > 5000) 
      printf("Reajuste de salario.");
    else 
      printf("Salario compativel.");      
  }

  //caso nao for
  else
    printf("Nao e gerente.");
  return 0;
}