#include <stdio.h>
/*Criar um algoritmo que leia os limites inferior e superior de um intervalo e imprima todos os números inteiros pares no intervalo aberto e o somatório desses números. Suponha que os números digitados sejam crescentes. */

int main(void) {
  int i, min=0, max, mem, soma=0;

  printf("Insira o valor do limite inferior do intervalo:\n");
  scanf("%d", &min);
  printf("Insira o valor do limite superior do intervalo:\n");
  scanf("%d", &max);

  while (min < max) {
    for (i=min; i<max; i=i+2) {
      if (i % 2 != 0)
        i = i -3;
      else
        printf("%d", i);
        soma = soma + i;
    }
    printf("A soma dos numeros e de %d", soma);
    }
  else
  printf("O limite inferior deve ser menor que o superior.")
  return 0;
}

//verificar se o numero e inteiro?
//verificar se numero e impar ou par
//quando par, adicione dois a cada iteracao com while ate o limite
//qundo impar, adicione um primeiro e depois va adicionando dois

/*para a verificacao de numeros usando divisao inteira 
eu fiquei meio que confuso depois de a melise ter falado de typecasting*/

/*minha preocupacao e entender se um algoritmo de for ira imprimir todos os numeros que eu quero, ou ira imrimir um a mais ou a menos.*/

/* algo me diz que eu poderia ter feito os calculos sem usar "mem", mas eu nao estou conseguindo pensar no momento.*/