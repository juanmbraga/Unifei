/*
6.Elabore um programa que leia uma sequencia de caractere digitados pelo 
usuário e em seguida peça ao usuário que digite uma letra e retorne a quantidade 
de vezes que a  letra  aparece  na  sequencia  de   caractere  digitados. 
O  tamanho  máximo  da sequência é 30.
*/

//receber numero de aracteres definido pelo usuario, e retornar a quantidade que um deles aparece (escolhido por usuario)
//nao tenho certeza se "sequencia de caracteres" seria um a um, ou todos escritos como se fosse string


#include <stdio.h>

int main (void) {

    int quantidade, repete=0;
    char buscaChar;

    printf("\nSaiba quantas vezes um caractere se repete na sequencia.\n");

    //definir a quantidade de variaveis a se inicializar os vetores
    do {
        printf("\nDigite a quantidade de caracteres a ser inserida, dentro de um limite de 30: ");
        scanf("%d", &quantidade);
        if(quantidade == 0)
            return 0;       //coloquei por que quiz, e ponto final
    }
    while (quantidade < 0 || quantidade > 30);

    //inicializando os vetores dentro do intervalo 0-50
    char caractere[quantidade];

    //receber o input dos caracteres
    for (int i=0; i<quantidade; i++) {   

        printf("Digite um caractere e tecle enter: ");
        scanf(" %c", &caractere[i]);

    }

    printf("\nAgora, insira um caracter para saber quantas vezes este repete: ");
    scanf(" %c", &buscaChar);

    //checar quantas vezes o numero se repete
    for (int i=0; i<quantidade; i++) {

        if (caractere[i] == buscaChar)
            repete++;
    }

    printf("\nO caractere '%c' repetiu %d vezes.", buscaChar, repete);
    
    return 0;
}