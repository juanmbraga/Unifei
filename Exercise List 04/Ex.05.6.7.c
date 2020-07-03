#include <stdio.h> 

int main(void) {
  //declaracao de variaveis
  float nota, exam;

  //insercao de dados
  printf("Por favor, insira a media do usuario, e digite enter.\n");
  scanf("%f", &nota);
  
  //checar se a nota inserida e valida
  if (nota > 10 || nota < 0)
    printf("Nota invalida.");
  else {
  
  //nao precisou de exame?
    if ((nota < 3) || (nota >= 6)) 
    {
      if (nota >= 6)
        printf("Aluno aprovado.");
      else
        printf("Aluno Reprovado.");
    }

    //avaliacao do exame
    else {
    printf("Aluno em recuperacao. Digite o resultado do exame.\n");
    scanf("%f", &exam);

    //checagem da nota do exame
    if (exam > 10 || exam < 0)
      printf("Nota invalida.");
    else 
    {
    if (exam >= 6)
      printf("Aluno aprovado.");
    else
      printf("Aluno reprovado");
    }}}
  return 0;
}