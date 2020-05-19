#include <stdio.h>

/*
Questão 6. Faça um programa que utilize as funções dos exercícios 4 e 5 para:  
 Imprimir o cabeçalho definido na função 4. 
 Imprimir a matrícula e o conceito de uma lista de alunos cuja média e a matrícula serão digitadas pelo usuário. 
    Utilize a função do exercício 5. A quantidade de alunos da lista dever ser digitada pelo usuário. 
*/

int marcaunifei (void);
char conceitoaluno (float);

int main (void) {
    int quantidade, matricula, media;
    char conceito;

    marcaunifei (); //imprimir o cabecalho

    do {
    printf("Insira a nota do aluno: ");
    scanf("%f", &media);

    conceito = conceitoaluno (media);

    if (conceito == 'X') 
        printf("A media inserida nao e valida.");
    else
        printf("O conceito do aluno e %c.", conceito);
    }
    while ();
        
}

char conceitoaluno (float media)
{
    if (media >= 0 && media < 5) //se esta entre zero e cinco
        return 'R';
    else if (media >= 5 && media < 7) //se esta entre cinco e sete
        return 'E';
    else if (media > 7) //se e maior que sete (o exercicio nao afirma que o limite e dez)
        return 'A';
    else 
        return 'X';
}

int marcaunifei (void) {
    printf("\nCurso Ciência da Computacao\nDisciplina - Fundamentos de Programação\nUniversidade Federal de Itajubá\n");
}