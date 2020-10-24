#include <stdio.h>
/*Em C, quando dividimos uma variável do tipo inteiro por outro inteiro como no exemplo abaixo (num/2), o resultado é a divisão inteiro de num por 2. Quando for necessário obter o resultado com casas decimais, temos que usar um recurso chamado typecasting. 
O typecasting é usado para moldar um determinado valor, ou alterar o tipo de um determinado valor quando o programa estiver em execução. Como na linha 16 (resultado = (float) num/2;), o tipo da variável num é alterado para float antes de fazer a divisão. Mas esse tipo é alterado somente nessa linha, caso a variável num fosse usada novamente, seria considerada um valor inteiro.
Outro ponto interessante desse exemplo é a formatação do resultado, veja que nas linhas 14 e 17, o .2 antes do f indica que o número deverá ser impresso com somente duas casas decimais
*/

int main(void) {
  int num;
  float resultado;
  printf("Digite o valor de num: ");
  scanf("%d", &num);
  resultado = num/2;
  //se o numero digitado for 5, por exemplo, o resultado sera 2
  printf("\nO resultado sem typecasting e:  %.2f", resultado);
  // agora, como foi usado o typecasting, o resultado será 2,5
  resultado = (float) num/2;
  printf("\nO resultado com typecasting e:  %.2f", resultado);
  return 0;
}

//whaaaaat!?