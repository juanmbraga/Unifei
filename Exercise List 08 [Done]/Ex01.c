/*
1.Escreva um  programa  que  leia  um  conjunto  de  notas  de  10  alunos  
em  um  curso  e retorne a quantidade de alunos que tiraram mais que a média.
*/

//ler dez notas, e retornar o numero de alunos acima da media
//suponto notas entre 0 e 1
//suponto que o "retornar" se referia a imprimir, pois nao foi especificado funcao, mas sim programa

#include <stdio.h>

int main (void) {

    float notas[10], media;
    int total;

    printf("\nSaiba quantos dos dez alunos tiraram mais que a media.\n");

    //receber o input das dez notas
    for (int i=0; i<10; i++) {   

        do {
            printf("Digite a nota do aluno n. %d e tecle enter: ", i+1);
            scanf("%f", &notas[i]);
        }
        while (notas[i] < 0 || notas[i] > 10);

    }

    //calcular a media
    media = 0;
    for (int i=0; i<10; i++) {
        media += notas[i];
    }
    media = media/10;


    //checar numero de alunos que estejam acima dela
    total = 0;
    for(int i=0; i<10; i++) {
        if (notas[i] > media)
            total++;
    }

    printf("\nO total de alunos que estao acima da media e de %d.", total);

    return 0;
}