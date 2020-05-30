#include <stdio.h>

/* 
Faça uma função que receba, por parâmetro, a altura (alt) e o sexo de uma pessoa e retorna o seu peso ideal.
 Para homens, calcular o peso ideal usando a fórmula peso ideal  =  72.7  x  alt -58  e,  para  mulheres,  
 peso  ideal  =  62.1  x  alt -44.7. Utilize  esta função no programa principal para retornar o peso ideal 
 de uma lista de pessoas. O programa deve ser finalizado quando a altura digitada for menor ou igual a 0.
*/

float amifat (float height, float sex);

float amifat (float height, float sex) {
    switch (sex)
        case 'm':
        case 'M':
            return (72.7 * height)-58;
        case 'f':
        case 'F':
            return (62.1 * height)-44.7;
        default:
            printf("O sexo inserido nao e valido. Utilize m ou f.");
            return 0;          

}
