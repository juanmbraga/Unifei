#include <stdio.h>
#include <stdlib.h>

#include "pilha.h"


int main (void) {

    Pilha* pilha[3];
    int retira, recebe, controle, movimentos=0;

    // Alocar as pilhas
    for(int i=0; i<3; i++){

        pilha[i] = criarPilha();

        // em caso de erro, avise e encerre o programa
        if(pilha[0] == NULL){
            printf("\nErro na alocacao de memoria. \nO programa ira encerrar.");
            pausa();
            liberarPilhas(pilha);
            return -1;
        }
    }

    // inicializar a primeira pilha 
    // (uma vez que a distancia das letras nao e a mesma, nao e possivel evitar a repetitividade)
    empilhar(pilha[0], 'U');
    empilhar(pilha[0], 'O');
    empilhar(pilha[0], 'I');
    empilhar(pilha[0], 'E');
    empilhar(pilha[0], 'A');

    do{
        system("clear");
        printf("\nPseudo-Torre-de-Hanoi com letras!");
        printf("\nTransfira todos os itens para a pilha 3...");
        printf("\n... Mas sem alterar a ordem alfabetica!");

        // Imprime todos os elementos da pilha
        imprimePilhas(pilha);

        // Solicita entrada do usuario de onde tirar 
        printf("\n\nDe qual pilha gostaria de retirar um cubo? ");
        do{
            scanf("%d", &retira);
        } while(retira < 1 && retira > 3);

        retira--;   //corrige para coincidir com o indice do vetor de pilhas

        // Socilita para onde transferir
        printf("\nPara qual pilha gostaria de transferi-lo?");
        do{
            scanf("%d", &recebe);
        } while(recebe < 1 && recebe > 3);

        recebe--;   //corrige para coincidir com o indice do vetor de pilhas
        
        // Chama a funcao para transferir e salva a saida em controle
        controle = transferir(pilha[retira], pilha[recebe]);

        // Da ao usuario a mensagem de acordo com o resultado da transferencia
        switch (controle) {
            // Sucesso
            case 0:
                printf("\nInsercao realizada com sucesso!");
                movimentos++;
            break;

            // Itens fora de ordem
            case 1: 
                printf("\nOs itens nao ficariam em ordem! Tente novamente.");
            break;

            // Fila sem elementos
            case 2: 
                printf("\nA fila nao possui elementos! Tente novamente.");
            break;

            // Mesma pilha selecionada
            case 3: 
                printf("\nMesma pilha selecionada! Tente novamente.");
            break;

            // Qualquer tipo de problema que impedira a execucao do programa
            case -1:
                printf("Erro de memoria na alocacao! Encerrando o programa.");
                pausa();
                retira = 33;
                continue;
            break;            
        }

        pausa();

    // Executar enquanto a terceira pilha nao tiver todas as letras ou o usuario nao pedir para sair
    } while(tamanhodaPilha(pilha[2]) != 5 || retira != 33);

    // Caso o usuario tenha saido e nao solicitado o fim do jogo
    if (retira != 33){
        system("clear");
        printf("\n\nParabens! Voce Ganhou o jogo em %d movimentos!", movimentos);
        imprimePilhas(pilha);
    }

    // Mensagem de finalizacao e liberacao das pilhas.
    printf("\n\nEncerrando o jogo.");
    pausa();
    liberarPilhas(pilha);

    return 0;
}