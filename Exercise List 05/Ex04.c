#include <stdio.h>
/*Escreva um algoritmo que leia 15 números e imprima a média dos números digitados.*/
int main(void) {
  float i, num, media=0;
  for (i=1;i<=15;i++){
    printf("Digite um numero:\n");
    scanf("%f", &num);
    media = media + num ;
  }
  media = media/15 ;
  printf("A media aritmetica dos numeros digitados e igual a %f", media);
    return 0;
}
