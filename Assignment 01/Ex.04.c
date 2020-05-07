#include <stdio.h>

/* 4. Considere um caixa automático com apenas um repositório com capacidade para armazenar 1000 notas de 10 reais.
 Elabore um algoritmo para ler um valor e fornecer a quantidade de notas correspondente a esse valor. 
 O repositório começa sempre com 1000 notas. A cada valor digitado, o seu algoritmo deve manter a quantidade de notas no repositório atualizada. 
 Caso o valor lido não possa ser fornecido por falta de notas, o algoritmo deve imprimir uma mensagem indicando o fato.
 O algoritmo também deve imprimir uma mensagem se o valor não for múltiplo de 10. 
 Após o tratamento do valor lido, com a impressão da mensagem ou o fornecimento da quantidade de notas, o procedimento deve ser repetido solicitando ao usuário que
 digite um novo valor. 
 O algoritmo deve parar quando um valor lido for negativo ou quando não houver mais notas para o saque. 
*/

//O algoritmo esta mais espacado que o normal ja que estou experimentando com algumas outras IDEs, e este exercicio, em particular, foi copiado e colado no repl.it.

int main (void) {
    int caixa, valor;
    float verif;

    caixa = 10000; 
    printf("Obs.: Digite um valor negativo para encerrar o programa.\n");

    do {
        printf("Insira o valor que gostaria de sacar em notas de dez: ");
        scanf("%f", &verif);        

        //numero inserido e inteiro? caso nao fosse, o que quer que tenha sido convertido para inteiro poderia dar problemas depois. 
        valor = verif;
        if(valor == verif) {
    
            if (valor >= 0) //verifificar se usuario deseja finalizar o programa imediatamente. 
            {
                if (valor <= caixa)

                    if (valor % 10 == 0) {
                        caixa = caixa - valor;
                        printf("A quantidade para o saque sera de %d notas de dez reais.\n", valor/10);
                    }
                    else 
                        printf("O valor indicado nao e multiplo de dez.\n");

                else
                    printf("Dinheiro disponivel insuficiente para a quantia inserida.\n");
            }
        }
        else
        printf("O valor inserido nao e inteiro (possui centavos).");
    }
    while (caixa > 0 && valor >= 0);
    
    if (caixa == 0)
    printf("Caixa esvazido. Programa encerrado.");
    else
    printf("Programa encerrado pelo usuario."); //assumi desnecessario imprimir o valor restante no caixa.
}

