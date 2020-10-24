#include <stdio.h>
/*Escreva um algoritmo que leia o código do funcionário (inteiro), o salário bruto, o valor do desconto e a gratificação do funcionário e escreva na tela o código e o valor do salário líquido (salário líquido = bruto – desconto + gratificação) de cada funcionário lido. Os dados devem ser lidos até que o código 0 seja digitado. Se o código for menor que 0 ou maior que 999, imprimir a mensagem: código inválido.*/

int main(void) {
  int codigo=1;
  float bruto, desconto, gratifica, liquido;

  printf("Para parar o programa, basta digitar o valor zero para o codigo.\n");

  //parto do principio que os valores de desconto e grat. serao dados
  //por extenso, e nao algo como 20% ou 0.20
  while (codigo != 0) {
    printf("\nInsira o codigo do funcionario:\n");
    scanf("%d", &codigo);

    //checar validade do codigo
    if (codigo < 0 || codigo > 999) 
      printf("codigo invalido.");
    
    //se codigo nao e zero, continuar com o programa
    else      
      if (codigo != 0) {
        printf("Agora, insira o salario bruto (sem descontos ou gratificacoes):\n");
        scanf("%f", &bruto);
        printf("Insira o valor a ser descontado:\n");
        scanf("%f", &desconto);
        printf("Insira o valor da gratificacao:\n");
        scanf("%f", &gratifica);
        liquido = bruto + gratifica - desconto ;
        printf("\nO codigo do funcionario e %d e seu salario e de %f reais.\n", codigo, liquido);
        //caso for zero, retorne ao "while" para finalizar
      }
      }
      return 0;
}
