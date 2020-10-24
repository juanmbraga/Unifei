//switch-case
#include <stdio.h>
/* escreva um algoritmo que leia o valor do codigo de um funcionario e retorne a sua categoria seguindo a seguinte regra:
0 <= codigo <= 200 : categoria 1
201 <= codigo <= 400 : categoria 2
401 <= codigo <= 600 : categoria 3
qualquer valor diferente: codigo inválido
*/
int main(void) {
  int codigo;
  printf("Digite o codigo: ");
  scanf("%d", &codigo);
  switch ( codigo)
  {
    case 0 ... 200:
      printf("Categoria 1");
    break;
    case 201 ... 400:
      printf("Categoria 2");
    break;
    case 401 ... 600:
      printf("Categoria 3");
    break;
    default: printf("Codigo invalido");
  }
  return 0;
}