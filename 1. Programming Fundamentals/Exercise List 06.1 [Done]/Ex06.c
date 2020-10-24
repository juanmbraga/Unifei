#include <stdio.h>

/* 
Faça uma função que receba, por parâmetro, a altura (alt) e o sexo de uma pessoa e retorna o seu peso ideal.
 Para homens, calcular o peso ideal usando a fórmula peso ideal  =  72.7  x  alt -58  e,  para  mulheres,  
 peso  ideal  =  62.1  x  alt -44.7. Utilize  esta função no programa principal para retornar o peso ideal 
 de uma lista de pessoas. O programa deve ser finalizado quando a altura digitada for menor ou igual a 0.
*/

float amifat (float height, float sex);

int main () {
    
    float height;
    char sex;

    printf("Calcule o peso ideal.\n(digite um valor menor ou igual a zero para finalizar o programa)");
    

    do {

        printf("\n\nInsira a altura em metros: ");
        scanf("%f", &height);

        if (height > 0) {

            printf("Agora, insira o sexo (f ou m): ");
            scanf(" %c", &sex);

            printf("O peso ideal para a altura e sexo digitados e igual a %f kg.", amifat(height, sex));
        }
    }
    while (height > 0);

    printf("Programa finalizado.");       
}

float amifat (float height, float sex) {

    if (sex == 'm' || sex == 'M')
        return (72.7 * height)-58;

    if (sex == 'f' || sex == 'F')
        return (62.1 * height)-44.7;  

    else return 0;  
}
