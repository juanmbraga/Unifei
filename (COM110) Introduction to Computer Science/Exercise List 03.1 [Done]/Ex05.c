/*
5. Escreva um algoritmo para ler dois valores inteiros, efetuar e mostrar 
o resultadodas operações de adição, subtração e multiplicação do  primeiro  
número  pelo segundo. Considere que todos os números são diferentes de 0.
*/

//exibir o valor da soma, subtracao e multiplicacao de dois numeros (primeiro pelo segundo)


#include <stdio.h>

int main (void) {
    
    //declaracao das variaveis
    int num1, num2; //variaveis nao podem comecar com numero, mas podem ter em outras posicoes

    //input e interacao com usuario
    printf("\nSaiba a soma, subtracao e multiplicacao do primeiro numero pelo segundo.\n");
    printf("\nInsira o primeiro numero: ");
    scanf("%d", &num1);
    printf("\nAgora, digite o segundo: ");
    scanf("%d", &num2);

    //Calculo e impressão dos resultados
    printf("\nO resultado da soma é %d,", num1 + num2);
    printf("\no da divisao e de %d e", num1 - num2);
    printf("\no da multiplicacao e %d.", num1 * num2);

    //Alternativamente:
    /*
        int temp;
        temp = num1 + num2;
        //imprimir o valor de temp
        temp = num1 - num2;
        //imprimir o valor de temp
        temp = num1 * num2;
        //imprimir o valor de temp
    */

    //Ou ainda tudo de uma vez (mais "eficiente", porem chato de se ver)
    /*
        printf(\nO resultado da soma é %d,\no da divisao e de %d e\no da multiplicacao e %d.", num1+num2, num1-num2, num1*num2);
    */

    return 0;
}
