#include <stdio.h>

/*
Faça uma função que receba as 3 notas de um aluno por parâmetro e uma letra. 
Se a letra  for  A, calcula  a  média  aritmética  das  notas  do  aluno,  se  for  P,  
a  sua  média ponderada (pesos: 5, 3 e 2). 
Utilize esta função no programa principal para retornar a media ponderada de um aluno.
*/
float media (float a, float b, float c, char tipo);

int main () {

    float a,b,c;
    char tipo;

    printf("Insira as tres notas do aluno, teclando enter apos cada uma:\n");
    scanf("%f%f%f", &a, &b, &c);
    printf("Agora, insira o tipo de media\n('a' para aritmetica e 'p' para ponderada); ");
    scanf(" %c", &tipo);

    printf("A media e de: %f", media(a,b,c,tipo));
}


float media (float a, float b, float c, char tipo) {

    switch (tipo) {
        case 'a':
        case 'A':
            return (a + b + c)/3;
            break;
        case 'p':
        case 'P':
            return (a*5 + b*3 + c*2)/10;
            break;
        default:
            printf("Tipo de media invalida.\nUtilize 'a' para aritmetica, ou 'p' para ponderada.");
            return 0;
            break;
    }
}