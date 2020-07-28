/*
5. Usando a estratégia acima, escrever uma função que tem como parâmetros de entrada 
três valores inteiros a, b e c e retorna a posição do maior e a posição do menor valor. 
Exemplo:  Se  a  =  7,  b  =  1  e  c  =  5, o procedimento deve retornar 2 como a posição 
do menor e 1 como a posição do maior.
Use a função no programa principal considerando três valores digitados pelo usuário.
*/

//Funcao para encontrar a posicao do maior e menor numeros a partir de uma sequencia de tres.

#include <stdio.h>

void minmaxposition(int a, int b, int c, int* pmin, int* pmax); //usar um vetor e passalo por parametro tambem daria

int main (void) {

    int a, b, c, pmin, pmax;  
    
    printf("\nEncontre a posicao do menor e maior numeros em uma sequencia de tres.\n\n Insira os tres valores, teclando enter apos cada um: ");
    scanf("%d%d%d", &a, &b, &c);
    
    minmaxposition(a, b, c, &pmin, &pmax);

    printf("\nA posicao do maior numero e %d, e a do menor e %d.", pmax, pmin);
    
    return 0;
}


void minmaxposition(int a, int b, int c, int* pmin, int* pmax) {
    if (a>b && a>c)
        *pmax=1;
    if(b>a && b>c)
        *pmax=2;
    if (c>a && c>b)
        *pmax=3;

    if (a<b && a<c)
        *pmin=1;
    if(b<a && b<c)
        *pmin=2;
    if (c<a && c<b)
        *pmin=3;
}
