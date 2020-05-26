#include <stdio.h>

/* 
Escrever uma função que tem como parâmetros de entrada três valores inteiros (a, b, c)
e retorna a posição do maior e a posição do menor valor. 
Exemplo: Se a = 7, b = 1 e c = 5, a função deve retornar 2 como a posição do menor e 1 como a posição do maior.
Use a função no programa principal considerando três valores digitados pelo usuário.
*/

//Desconsidere os comentarios abaixo, a Melise tirou a duvida durante a aula. 
    //Segundo o que pude ler de funcoes (Stephen Prata), elas nao sao capazes de literalmente "retornar" mais de um valor. 
    //"a função deve retornar" aqui pode ser tomado como "imprimir", ou algo que abra a possibilidade do uso de ponteiros como saida.
    //aparentemente usar ponteiros nao e possivel, visto que o enunciado solicita explicitamente que a entrada seja de apenas tres inteiros.


void order (int a, int b, int c, int* maior, int* menor);

int main () {
    int maior, menor;
    int a,b,c;

    printf("Digite tres numeros inteiros, teclando enter apos cada um deles: ");
    scanf("%d%d%d", &a, &b, &c);

    order (a, b, c, &maior, &menor);

    printf("O maior numero e o %d, e o menor e %d.", maior, menor);
}

void order (int a, int b, int c, int* maior, int* menor) {
    if (a>b)
        if (a>c) 
        {
            *maior = 1;
            *menor = 2;
        }
        else 
        {
            *maior = 3;
            *menor = 2;
        }
    else
        if (b>c) 
        {
            *maior = 2;
            *menor = 1;
        }
        else
        {
            *maior = 3;
            *menor = 1;
        }    
}       