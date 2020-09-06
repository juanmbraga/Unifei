/*
5.Ler uma matriz quadrada A de dimensão M (M <= 10) de elementos inteiros. 
Em seguida, obter seu elemento minimax. O minimax é o menor elemento da linha 
que contém o maior elemento da matriz.
*/

//ler matriz quadrada de dimensão até dez, e retornar o menor elemento da linha que contem o maior elemento da matriz.


#include <stdio.h>
#include <stdlib.h>

int buscarMenor(int);

int main (void) {

    int dimensao, maiorElemento, menorElemento, linhaDoMaiorElemento, repeticoes=0;

    printf("Saiba o menor elemento da linha que contem o maior elemento da matriz.\n\n");

    //pedir pelas dimensoes da matriz desejada
    do  {
        printf ("Digite o tamanho da matriz quadrada (ate dez): ");
        scanf("%d", &dimensao);
    } while (dimensao < 1 || dimensao > 10);

    //inicializar matriz do tamanho desejado
    int matriz[dimensao][dimensao];

    //preencher matriz
    for (int i=0; i<dimensao; i++) {
        for (int j=0; j<dimensao; j++) {

            printf("Insira o valor do item (%d,%d) da matriz, e tecle enter: ", i+1, j+1);
            scanf("%d", &matriz[i][j]);

        }
    }

    //buscar maior elemento
    int linhas[10];
    maiorElemento=matriz[0][0];
    for (int i=0; i<dimensao; i++) {
        for (int j=0; j<dimensao; j++) {

            if (matriz[i][j] > maiorElemento)
                maiorElemento = matriz[i][j];
            
        } 
    }


    //buscar repetições
    int linha[10];
    for (int i=0; i<dimensao; i++) {
        for (int j=0; j<dimensao; j++) {

            if (matriz[i][j] == maiorElemento)

        }
    }

    if (repeticoes == 1) {
        
        menorElemento = matriz[linhaDoMaiorElemento][0];
        for (int i=linhaDoMaiorElemento; i<dimensao; i++) {
            for (int j=0; j<dimensao; j++) {

                if (matriz[i][j] < menorElemento) 
                    menorElemento = matriz[i][j];

            }
        }

        printf("O valor do menor elemento da linha com o maior elemento da matriz e igual a %d.", menorElemento);
    }
    else 

}

int buscarMenor(int linha) {

}
