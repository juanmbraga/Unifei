/*#include <stdio.h>
//O exercicio tem tabela, o que deixa dificil colar aqui
//18-24 / 25-40 / 41-70 | 1/2/3
int main (void) {
  int idade, grupo;
  printf("Por favor, insira a idade do cliente:\n");
  scanf("%d", &idade);
  if (idade<18 || idade>70)
    printf("A EMPRESA atende apenas usuarios com mais de 18 e menos de 70 anos.");
  else
    {
      printf("Por favor, escreva o numero do grupo de risco do cliente:\n");
    scanf("%d",&grupo);
    printf("O codigo da categoria do cliente e: ");
    }
    if (idade < 24)
      switch(grupo) {
        case 1:
          printf("A");
          break;
        case 2:
          printf("B");
          break;
        case 3:
        printf("C");
        break;}
    else 
      if (idade > 41) 
      switch (grupo) {
        case 1:
          printf("G");
          break;
        case 2:
          printf("H");
          break;
        case 3:
          printf("I");
          break; }
      else 
      switch (grupo) 
      {
        case 1:
          printf("D");
          break;
        case 2:
          printf("E");
          break;
        case 3:
        printf("F");
      }
        return 0;
}
*/