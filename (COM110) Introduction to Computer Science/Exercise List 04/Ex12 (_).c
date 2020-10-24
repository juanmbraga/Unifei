#include <stdio.h> 

int main(void) {
  //declaracao de variaveis
  float lado1, lado2, lado3, memo1, memo2, memo3;

  //insercao de dados
  printf("Por favor, insira as medidas dos lados A B e C, em ordem crescente (hipotenusa, cateto, cateto) do triangulo, digitando enter apos cada uma.\n");
  scanf("%f %f %f", &lado1, &lado2, &lado3);

  //checagem da ordem dos lados para calculo
  if (lado1 >= lado2 && lado2 >= lado3) 
  {

  //checagem para existencia de triangulo com os lados inseridos
  /* a medida de qualquer um dos lados deve ser menor que a soma das medidas dos outros dois e maior que o modulo da diferença entre elas.*/

      //modulos
      //alternativamente, poder-se-ia usar a funcao "abs()" de <math.h>
      memo1 = (lado2-lado3); if (memo1<0) memo1 = memo1*-1;
      memo2 = (lado1-lado3); if (memo2<0) memo2 = memo2*-1;
      memo3 = (lado1-lado2); if (memo3<0) memo3 = memo3*-1;
      
      //condicao de existencia
      if ((lado1>memo1 && lado1<(lado2+lado3)) || (lado2>memo2 && lado2<(lado1+lado3)) || (lado3>memo3 && lado3<(lado1+lado2)))

  //verificacao das regras do exercicio, caso triangulo existir
  {
    memo1 = lado1*lado1; //para A^2
    if (memo1 == ((lado2*lado2) + (lado3*lado3))) // A^2 = B^2 + C^2
      printf("O triangulo e retangulo.");
    else
      if (memo1 > ((lado2*lado2)+(lado3*lado3))) // A^2 > B^2 + C^2
        printf("O triangulo e obtusangulo.");
      else
        printf("Nenhuma das opcoes.");
  }

  //caso triangulo nao se enquadre
  else 
  printf("Triangulo nao existe.");
  }

  //caso a ordem dos lados do triangulo nao esteja adequada
  else 
  printf("Por favor, insira os lados do triangulo em ordem crescente.");
  return 0;
}