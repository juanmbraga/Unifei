/*
2.Considere  um  número  de  3  dígitos,  usando  os  operadores \(divisão  inteira)  
e  % (resto  da  divisão),  imprima  o  algarismo  correspondente  à  centena  e  o  
algarismo correspondente à dezena. Veja o exemplo abaixo:
350/100 = 3,5
350\100 = 3 (somente o valor inteiro da divisão)
350%100 = 50 (resto da divisão de 350 por 100)
*/

//O operando \ (divisao inteira) não existe em C, como em Visualg (que estavamos a usar)
//Quando se faz uma divisão com o valor de duas variaveis inteiras, o resultado ja e inteiro
//semelhantemente, quando se faz uma divisao qualquer e atribui o valor a uma variavel inteira,
//o valor e salvo como inteiro (o que vem depois da virgula e ignorado)


#include <stdio.h>

int main (void) {
    
    //declaracao das variaveis
    int numero;

    //input e interacao com usuario
    printf("\nDigite um numero de tres digitos: ");
    scanf("%d", &numero);

//  Alternativamente:
//  printf("\nO algarismo da centena e o %d", numero/100);
//  printf("\nE o da dezena e %d.", (numero%100)/10);

    printf("\nO algarismo da centena e o %d\nE o da dezena e o %d.", (numero/100), (numero%100)/10);

    return 0;
}