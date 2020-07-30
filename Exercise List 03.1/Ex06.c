/*
6.Escreva  um  algoritmo  que  receba  dois  nomes, nome1 e nome2,  e  
realize  a  troca destes nomes. Mostrar o novo valor do nome1 e do nome2 depois de trocados.
*/

//trocar os valores e imprimir a ordem de dois nomes invertida

//seria possivel apenas imprimir os nomes na ordem diferente,
//mas paree que a professora quer que os valores das variaveis sejam trocados.
//NOTA: para armazenar um nome seria preciso uma string (conjunto de caracteres)
//e acho que seria avancado demais para esta parte. Acho que ao escrever
//"mostrar o novo VALOR do nome" ela poderia ter dito apenas um numero.


#include <stdio.h>
#include <string.h> //usado apenas no codigo "correto", como comentario no final

int main (void) {
    
    //declaracao das variaveis
    int primeiro_nome, segundo_nome, variavel_auxiliar; //variaveis podem ter underline

    //input e interacao com usuario
    printf("\nTroque os nomes!\n");
    printf("\nInsira o primeiro nome: ");
    scanf("%d", &primeiro_nome);
    printf("Agora, digite o segundo nome: ");
    scanf("%d", &segundo_nome);

    variavel_auxiliar = primeiro_nome;
    primeiro_nome = segundo_nome;
    segundo_nome = variavel_auxiliar;

    printf("\nOs nomes invertidos sao %d e %d.", primeiro_nome, segundo_nome);

    //Mais avancado, ignore por hora (ou olhe como curiosidade):
    /*
        char nome1[20], nome2[20], auxiliar[20];

        //limite de 19 caracteres, sendo o ultimo o caractere que demarca o final da "string"
        //ao imprimir, se o nome tiver menos caracteres que o limite, o caractere "final" sera
        //colocado logo ao final, permitindo o computador nao imprimir mais coisas alem do que foi inserido.

        printf("\nTroque os nomes!\n");
        printf("\nInsira o primeiro nome: ");
        scanf("%s", nome1);                         //a biblioteca string.h permite usar o tipo %s para vetores de char
        printf("\nAgora, digite o segundo nome: ");
        scanf("%s", &nome2);

        strcpy(auxiliar, nome1); //copiar "string", ou conjunto de caracteres
        strcpy(nome1, nome2);
        strcpy(nome2, auxiliar);

        printf("Os nomes invertidos sao %s e %s.", nome1, nome2);
        
    */
    return 0;
}

