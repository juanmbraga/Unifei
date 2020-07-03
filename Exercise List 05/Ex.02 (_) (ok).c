#include <stdio.h>

int main(void) {
  int i, num, soma=0;
  for (i=1;i<=10;i++) {
    printf("Digite o numero a ser somado:\n");
    scanf("%d", &num);
    soma = soma + num;
  }
  printf("A soma parcial dos numero e igual a %d\n", soma);
  return 0;
}

//por que razao i se inicia no 1 e nao no zero? desse modo o exercicio ira ate o 11 para totalizar as dez execucoes. 

//a explicacao poderia estar na pagina 98 no livro da Ascencio. no caso para x <= 5, ele realiza o calculo uma outra vez, ate ele ficar maior. 

//outra exemplificacao e o caso de calcular os numeros pares entre 100 e 200.

//os slides da melise ajudaram, ao dar um outro exemplo que engloba o mesmo numero de repeticoes: (i=0;i<10,i++)

//a funcao "for" em C, adiciona *um* a variavel de iteracoes (quando i++) assim que o for e inicializado, ou ela adiciona o numero um depois da execucao de cada uma das execucoes? 

//Eu pude de fato entender que a soma do valor ocorre depois da execucao das instrucoes na funcao FOR, atraves desse video https://www.youtube.com/watch?v=dodjd3Flh1I 