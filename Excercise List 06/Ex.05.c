#include <stdio.h>

/*
Questão 5. Faça uma função que recebe a média final de um aluno e retorne o seu conceito, conforme a regra abaixo: 
o 0 <= media < 5, aluno reprovado (retorne R) 
o 5 <=  media < 7, aluno em exame (retorne E) 
o media >= 7, aluno aprovado (retorne A) 
*/

void marcaunifei (void);
char conceitoaluno (float);

int main (void) {
    marcaunifei ();

    float media;
    char conceito;

    printf("Insira a nota do aluno: ");
    scanf("%f", &media);

    conceito = conceitoaluno (media);

    if (conceito == 'X') 
        printf("A media inserida nao e valida.");
    else
        printf("O conceito do aluno e %c.", conceito);
        
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