#include <stdio.h> 
/* Tabela para referencia:
Os codigos dos times sao: A. São Paulo B. Palmeiras C. Flamengo  D. Vasco E. Atlético Mineiro F. Cruzeiro G. Bahia H. Grêmio I. Internacional 
 
Os códigos dos estados são: 1- Minas Gerais 2- São Paulo 3- Rio de Janeiro 4- Bahia 5- Rio Grande do Sul */

int main(void) {
  //declaracao de variaveis
  char letratime;

  //insercao de dados
  printf("Por favor, insira letra correspondente ao time e digite enter.\n");
  scanf(" %c", &letratime);

  //impressao para nao ficar apenas o numero do estado
  printf("O codigo do estado e:\n");

  //tabela de equivalencias com switch
  //para economizar memroria, decidi nao encher de variaveis
  switch (letratime){
    case 'a': case 'A': printf("1"); 
    break;

    case 'b': case 'B': printf("1");
    break;

    case 'c': case 'C': printf("3");
    break;

    case 'd': case 'D': printf("3");
    break;

    case 'e': case 'E': printf("1");
    break;

    case 'f': case 'F': printf("1");
    break;

    case 'g': case 'G': printf("4");
    break;

    case 'h': case 'H': printf("5");
    break;

    case 'i': case 'I': printf("5");
    break;

    default: printf("Letra inserida e invalida.");
  }
  return 0;
}