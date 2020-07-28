#include <stdio.h>
/*Se o processo é do tipo A e possui valor maior que R$12000, então deve ser escrito “Processo em andamento com custo alto”.
Se o processo tem prazo maior que 12 meses (o prazo é sempre dado em quantidade de meses) ou o cliente é do tipo E (especial), deve ser escrito
“Processo crítico*/

//Codigo do aluno: Getulio Victor Faustino Moreira

int main(void) {
  int valor, prazo;
  char processo, cliente;

  printf("\ndigite o tipo de processo e o valor : ");
  scanf ("%c %d" , &processo , &valor);

  if (processo == 'A' && valor > 12000) {
  printf ("\nProcesso em andamento com custo elevado"); 
  }
  else {

  printf("\nDigite o prazo e o tipo de cliente: ");
  scanf ("%d %c" , &prazo, &cliente);
  
  if (prazo > 12 || cliente == 'E') {
    printf("\nProcesso Crítico");
  }
 else {
   printf("Processo normal");
 } 
  }
  
  return 0;
}