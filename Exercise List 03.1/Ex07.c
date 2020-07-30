/*
7. Construa um algoritmo que, tendo como dados de entrada dois pontos quaisquer 
do plano, P(x1,y1) e Q(x2, y2), imprima a distância entre eles.
*/

//imprimir a distancia de dois pontos do plano fornecidos pelo usuario
//distancia entre dois pontos quaisquer no mesmo plano pode ser tida omo:
//hipotenusa do triangulo de catetos tidos comoa subtracao dos valores dos pontos (x1-x2) e (y1-y2)

#include <stdio.h>
#include <math.h> //para raiz quadrada

int main (void) {
    
    //declaracao das variaveis
    float x1, y1, x2, y2;

    //input e interacao com usuario
    printf("\nCalcule a distancia entre dois pontos.\n");
    printf("\ninsira as coordenadas do primeiro ponto, teclando enter apos cada uma: ");
    scanf("%f%f", &x1, &y1);
    printf("\nAgora, digite as do segundo, novamente teclando enter apos cada um: ");
    scanf("%f%f", &x2, &y2);

    //a matematica poderia ser feita toda dentro do printf, mas para ficar mais claro farei fora
    float auxiliar;

    auxiliar = sqrt(  ((x2 - x1)*(x2 - x1))  +  ((y2 - y1)*(y2 - y1))  );

    //impressão dos resultados
    printf("\nA distancia entre os pontos e de %f unidades.", auxiliar);

    return 0;
}
    
