

#include <stdio.h> 

int main(void) {
  //declaracao de variaveis
  float altura, ideal;
  char sexo;

  //insercao de dados
  printf("Por favor, insira a altura em metros e digite enter.\n");
  scanf("%f", &altura);
  printf("Por favor, insira a letra correspondente ao sexo (F ou M).\n");
  scanf(" %c", &sexo);
  
  //checagem altura
  if (altura < 0 || altura > 5)
    printf("Altura inadequada.");
  else {

  //calculos baseado no sexo
  switch (sexo){
    //homens
    case 'f':
    case 'F': {
      ideal = ((altura*62.1) - 44.7);
      printf("O peso ideal e igual a %f", ideal);}
    break;

    //mulheres
    case 'm':
    case 'M': {
      ideal = ((altura*72.7) - 58);
      printf("O peso ideal e igual a %f.", ideal);}
    break;

    //caso o valor de sexo esteja incorreto
    default: printf("Sexo invalido, por favor insira as letras F ou M.");}
  }

  return 0;
}