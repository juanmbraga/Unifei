/*
2.Escreva um programa que leia um conjunto de notas de 10 alunos e o código 
desses alunos (cada código é uma letra) e imprima o código e a nota dos alunos 
que tiraram mais que a média.
*/

//ler notas e codigo de cada aluno, e imprimir o cod e nota daqueles que tiraram mais que a media


#include <stdio.h>

int main (void) {

    float nota[10], media;
    char codigo[10];

    printf("\nSaiba quais dos dez alunos tiraram mais que a media.\n");

    //receber o input das dez notas e codigos
    for (int i=0; i<10; i++) {   

        do {
            printf("Digite a nota do aluno n. %d e tecle enter: ", i+1);
            scanf("%f", &nota[i]);
            printf("Agora, digite seu codigo: ");
            scanf(" %c", &codigo[i]);
        }
        while (nota[i] < 0 || nota[i] > 10);

    }

    //calcular a media
    media = 0;
    for (int i=0; i<10; i++) {
        media += nota[i];
    }
    media = media/10;

    //checar quais alunos estao acima da media
    printf("\nOs alunos que passaram foram:");
    for(int i=0; i<10; i++) {
        if (nota[i] > media)
            printf("\n%c   %.2f", codigo[i], nota[i]);
    }

    return 0;
}
