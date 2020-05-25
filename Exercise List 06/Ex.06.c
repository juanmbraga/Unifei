#include <stdio.h>

/*
Questão 6. Faça um programa que utilize as funções dos exercícios 4 e 5 para:  
 Imprimir o cabeçalho definido na função 4. 
 Imprimir a matrícula e o conceito de uma lista de alunos cuja média e a matrícula serão digitadas pelo usuário. 
    Utilize a função do exercício 5. A quantidade de alunos da lista dever ser digitada pelo usuário. 
*/

void marcaunifei (void);
char conceitoaluno (float);

int main (void) {
    int quantidade;
    long  matricula; //usando dez numeros, como na unifei
    float media;
    char conceito;

    marcaunifei (); //imprimir o cabecalho
    printf("Para finalizar o programa, insira um valor negativo na nota.\n");

    printf("Insira a quantidade de alunos e tecle enter: ");
    scanf("%d", &quantidade);
    

    do {
    printf("\nInsira a nota do aluno e tecle enter: ");
    scanf("%f", &media);
    printf("Agora, insira o numero de matricula: "); 
    scanf("%ld", &matricula);

    conceito = conceitoaluno (media);

    if (conceito == 'X') 
        printf("A media inserida nao e valida.");
    else
        printf("O conceito do aluno de numero %ld e de %c.", matricula, conceito);
        quantidade--;
    }
    while (quantidade > 0);

    printf("\nPrograma finalizado.");    
}

char conceitoaluno (float media)
{
    if (media >= 0 && media < 5) //se esta entre zero e cinco
        return 'R';
    else if (media >= 5 && media < 7) //se esta entre cinco e sete
        return 'E';
    else if (media >= 7) //se e maior que sete (o exercicio nao afirma que o limite e dez)
        return 'A';
    else 
        return 'X';
}

void marcaunifei (void) {
    printf("Curso Ciência da Computacao\nDisciplina - Fundamentos de Programação\nUniversidade Federal de Itajubá\n\n");
}