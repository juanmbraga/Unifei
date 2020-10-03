#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Enquanto testo alguns codigos ou conceitos sobre TAD do livro de C do Stephen Prata.

int main (void) {

    system("cls");
    printf("\n\nO tamanho de uma variavel de inteiro e de %d bytes.", sizeof(int));

    //puts()
    puts("\n\nImprimindo qualquer coisa com a funcao puts()...\nQual seria a diferenca desta para printf()?");
    char string[20];
    //puts("Imprimindo texto com uma variavel com lixo -- %s", string[20]);
    puts("\nImprimindo apenas a variavel, pois nao e possivel imprimi-la juntamente com o texto.");
    puts("string");
    puts("Digite o valor para colocar na variavel com scanf: ");
    scanf("%s", string);
    printf("O que esta armazenado na string e: %s.\nDigite o valor para armazenar com gets: ", string);
    gets(string); //hum... nao funciona
    printf("O que esta na variavel: ");
    puts(string);
    puts("\nDigite texto para inserir com s_gets(): ");
    //s_gets(string, 20);
    printf("\nPelo visto a bendita da funcao nao existe...? Vi na pagina 782 do livro C primer Plus de Stephen Prata, 6a Edicao.");

    printf("\n\nPrograma encerrado.\n");
    

}