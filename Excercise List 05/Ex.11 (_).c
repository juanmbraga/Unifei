#include <stdio.h>
/*exercicio 11 */
int main(void) {
  char cat='a';
  int soma=0;

  printf("Digite a letra x na categoria para finalizar e receber a soma.\n\n");

  while (cat != 'x') {
    printf("Insira a letra da categoria: ");
    scanf(" %c", &cat);

    switch (cat) {
      case 'x':
      case 'X':
      break;

      case 'a':
      case 'A':
        printf("\nO salario do funcionario e de 10000 reais.\n\n");
        soma = soma + 10000;
      break;

      case 'b':
      case 'B':
        printf("\nO salario do funcionario e de 5000 reais.\n\n");
        soma = soma + 5000;
      break;

      default: 
         printf("\nCategoria invalida\n\n");
  }}

  //
    printf("A soma dos salarios digitados e igual a %d", soma);      
      return 0;
}

//por que nao posso colocar (cat != 'X' || cat != 'x') em while?

//por que switch tem apenas as funcoes de igual para os cases?

//existe alguma outra funcao que permita fazer o comando if em cada?