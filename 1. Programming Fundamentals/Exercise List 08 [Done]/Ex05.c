/*
5.Elabore  um  programa  que  leia  uma  lista  de  20  códigos  de  produto  
(códigos  são números  inteiros)  e  seus  respectivos  valores  e  guarde  essas  
informações em dois vetores separados, um para os códigos e outro para os valores. 
Depois de preenchidos os dois vetores, retorne o código do produto mais caro. 
Considere que os valores são diferentes um do outro.
*/

//ler vinte codigos e valores

#include <stdio.h>
#include <stdlib.h>

int main (void) {

    int codigo[20], codigoMaior=0;
    float valor[20], valorMaior=0;

    printf("\nSaiba o codigo do produto mais caro, dentre uma lista de 20.\n");

    //receber o input dos 20 codigos e valores
    for (int i=0; i<20; i++) {   

        printf("Digite o codigo do %do produto e tecle enter: ", i+1);
        scanf("%d", &codigo[i]);
        do {
            printf("Agora, insira o valor dele: ");
            scanf("%f", &valor[i]);
        } while (valor[i] < 0);

    }

    

    for (int i=0; i<20; i++) {

        if (valorMaior < valor[i]) {
            valorMaior = valor[i];
            codigoMaior = codigo[i];
        }
        
    }

    printf("\nO codigo do produto de maior valor e %d.", codigoMaior);

    return 0;
}