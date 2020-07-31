/*
3.Elabore um programa que leia uma lista de notas de N alunos 
(N <= 50 e deve ser digitado pelo usuário) e retorne a quantidade de notas 
maiores que a média.
*/

//ler quantidade de notas fornecida por usuario, e retornar aquelas maiores que a media
//copiando e colando os codigos anteriores poupa trabalho

#include <stdio.h>

int main (void) {

    int quantidade, total;
    float media;

    printf("\nSaiba quantos alunos tiraram mais que a media.\n");

    //definir a quantidade de variaveis a se inicializar os vetores
    do {
        printf("Digite a quantidade de notas a ser inserida, dentro de um limite de 50: ");
        scanf("%d", &quantidade);
    }
    while (quantidade < 0 || quantidade > 50);

    //inicializando os vetores dentro do intervalo 0-50
    float nota[quantidade];
    char codigo[quantidade];

    //receber o input das dez notas e codigos
    for (int i=0; i<quantidade; i++) {   

        do {
            printf("Digite a nota do aluno n. %d e tecle enter: ", i+1);
            scanf("%f", &nota[i]);
        }
        while (nota[i] < 0 || nota[i] > 10);

    }

    //calcular a media
    media = 0;
    for (int i=0; i<quantidade; i++) {
        media += nota[i];
    }
    media = media/quantidade;

    //checar e imprimir quantos alunos estao acima da media
    total = 0;
    for (int i=0; i<quantidade; i++) {
        if (nota[i] > media)
            total++;
    }
    printf("\nUm total de %d alunos passaram acima da media.", total);
    
    return 0;
}