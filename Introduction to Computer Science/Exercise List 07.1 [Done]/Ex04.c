/*
4. Usando a estratégia acima, escrever uma função que retorne o valor mínimo e 
máximo de uma sequência de n valores fornecidos pelo usuário. A leitura dos valores 
digitados no teclado deve ser feita dentro da função. Contudo, a quantidade de 
valores a ser lido (n) deve ser um parâmetro de entrada da função.
*/

//função que retorna o valor mínimo e máximo de uma sequencia definida pelo usuario
//e passada por parametro

#include <stdio.h>

void minmax(int size, int* min, int* max);

int main (void) {

    int size, min, max;   //me pergunto como ficaria passar um valor "inteiro" com todos os dados...
    
    printf("\nEncontre o menor e maior numeros em uma sequencia.\n\n Insira o tamanho da sequencia: ");
    scanf("%d", &size);
    
    minmax(size, &min, &max);

    printf("\nO maior numero e %d, e o menor e %d.", max, min);
    
    return 0;
}


void minmax(int size, int* min, int* max) {

    int sequence[size];

    printf("\nDigite a sequencia de %d numeros, teclando enter apos cada um.\n", size);

    for (int i=0; i<size; i++) {
        scanf("%d", &sequence[i]);
        
    }

    *min = sequence[0];
    *max = sequence[0];

    for (int i = 0; i < size; i++) {
        if (sequence[i] < *min)
            *min = sequence[i];
        if (sequence[i] > *max)
            *max = sequence[i];
    }
}
