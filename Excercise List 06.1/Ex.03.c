/* 3.Leia os códigos abaixo e responda as perguntas associadas:*/
//___________________________________________________________________________________________________________________________
/*
//Código 1
#include<stdio.h>
int abs(int n){
    if  (n>=0) 
        return n;
    else 
        return -n;
}

int main(){
    int n, absn;
    printf("Digite um numero: ");
    scanf(" %d", &n);
    absn = abs(n);
    printf("\nO valor de n e %d e o valor de abs(n)e %d\n", n, abs(n));
}

a) Para os valores de n listadosn o Código 1, escreva a saída: 5, -5, 10, -45, 0
    5, 5, 10, 45, 0.
b) O valor de n pode ser alterado na função  abs do Código 1, explique porque este valor não éalterado na função principal.
    Pois o espaco de memoria usado para a variavel n na funcao main e diferente daquele usado para a funcao abs. Isso
    se da em decorrencia da natureza de C, onde as variaveis declaradas sao "compartimentalizadas", e portanto isoladas
    a sua respectiva funcao. Um contorno a isto seria o uso de ponteiros. 
*/

//_____________________________________________________________________________________________________________________________

/*
//Código 2
#include<stdio.h>
#include<stdlib.h>
int param(int x){
    x = x + 10;
    return x;
}

int main(){
    int x, y;
    printf("Digite um numero: ");
    scanf(" %d", &x);
    y = param(x);
    printf("\nO valor de y e %d \n", y);
    printf("\nO valor de x e %d \n", x);
    system("pause");
}

c) Supondo  que  seja  digitado  o  número  25,  quais  valores  serão  impressos no Código 2?
    "O valor de y e 35"
    "O valor de x e 25"
d) O valor de x na função param do Código 2 foi alterado, explique porque este valor não é alterado na função principal
    Pela mesma razao que a alternativa b), isto e, os calculos e manipulacoes foram feitas na variavel x de dentro da funcao,
    que possuem enderecos de memoria diferentes daqueles da funcao principal.
*/

//_____________________________________________________________________________________________________________________________

/*
//Código 3
#include<stdio.h>
#include<stdlib.h>
int x;
int param(){
    x = x + 10;
    return x;
}

int main(){
    int y;
    printf("Digite um numero: ");
    scanf(" %d", &x);
    y = param();
    printf("\nO valor de y e %d \n", y);
    printf("\nO valor de x e %d \n", x);
    system("pause");
}

e) Supondo  que  seja  digitado  o  número  48,  quais  valores  serão  impressos no Código 3?
    Me parece que x e y, caso o programa rode sem problemas no compilador, terao valores aleatorios. A variavel y e
    dependente de x, que nao fora declaada dentro de nenhuma funcao.
    CORRECAO: x e y tem o valor de 58. 
f) O valor de x na função param do Código 3 foi alterado, explique porque este valor foi alterado na função principal.
    O valor foi alterado pois a variavel fora declarada fora das funcoes, e portanto pode ser alterada tanto na funcao
    main quanto na param. 
*/
