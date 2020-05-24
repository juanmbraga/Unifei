#include <stdio.h>

/* 
Escrever uma função que tem como parâmetros de entrada três valores inteiros (a, b, c)
e retorna a posição do maior e a posição do menor valor. 
Exemplo: Se a = 7, b = 1 e c = 5, a função deve retornar 2 como a posição do menor e 1 como a posição do maior.
Use a função no programa principal considerando três valores digitados pelo usuário.
*/

//Segundo o que pude ler de funcoes (Stephen Prata), funcoes nao sao capazes de "retornar" mais de um valor. 
//"a função deve retornar" aqui pode ser tomado como "imprimir", ou algo que abra a possibilidade do uso de ponteiros como saida.
//aparentemente usar ponteiros nao e possivel, visto que o enunciado solicita explicitamente que a entrada seja de apenas tres inteiros.

void order (int a, int b, int c);

int main () {

    int a,b,c;

    printf("Digite tres numeros inteiros, teclando enter apos cada um deles: ");
    scanf("%d%d%d", &a, &b, &c);



}

void order (int a, int b, int c) {

}