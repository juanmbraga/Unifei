#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Este codigo nao tem a intencao de ser funcinal para a segunda entrega*/
/*Serve apenas para se dar uma nocao da estrutura do trabalho final*/
//O trabalho final provavelmente nao tera tantas funcoes
//A questao referente ao relogio parecera mais simples do que era. Mais estudo e necessario.

int inicializartabela (int*);
int inicializartabelajogo(int*);
int distribuirbombas (int);
int gerardicas ();
int start ();
int imprimirtela (int*);
int checarcoordenadas (int, int);
int ranking ();
int exibirmenu ();
int fimpartida (int, int, int, int*);
int rules ();

int main (void) 
{
    int control;

    do {
      int input;

      system("clear");
      exibirmenu();

      do 
      {
          printf("Digite a opção desejada: ");
          scanf("%d", &input);
      }
      while (input > 0 && input < 5);

      switch (input) {
          case 1: control = start();
              break;
          case 2: control = rules();
              break;
          case 3: control = ranking();
              break;
          case 4: return 0;
              break;

          default: control = 1;
      }
    }
    while (control == 0); //As funcoes retornarao 1 por padrao. Caso for definido como zero, o jogo encerra.

    return 0; //programa finalizado
}


int exibirmenu () { //A parte grafica do menu principal

    printf("Olá, bem vindo ao campo minado!\n\n\n");
    printf("--------------------------------\n\n\n");
    printf("Digite '1' para iniciar o jogo\n\n\n");
    printf("Digite '2' para ver as regras de como jogar\n\n\n");
    printf("Digite '3' para acessar o ranking\n\n\n");
    printf("Digite '4' para sair\n\n\n");

    return 0;
}


int start () { // Codigo do jogo

    int linha=9, coluna=9, matriz[9][9], matrizjogador[9][9]; 
    int linhainput, colunainput;
    int tentativas, numbombas, bomba=0;  //a definir numero de bombas. Definido temporarioamente como 30
    int tempo; //A determinar

    numbombas=11;

    inicializartabela(&matriz[][]); //dar valores zero
    inicializartabelajogo(&matrizjogador[][]);

    do {

        distribuirbombas(numbombas, *matriz[][]); //numero a definir 
        gerardicas(); //implementaremos a geracao de dicas juntamente a funcao de distribuicao de bombas

        system("clear");

        imprimirtela(&matrizjogador[][]); //por hora apenas a matriz sera imprimida
    
        do {
            printf("\nInsira o valor da linha: ");
            scanf ("%d", &linhainput);
            printf("\nInsira o valor da coluna");
            scanf ("%d", &colunainput);
        } 
        while (checarcoordenadas(linhainput, colunainput) == 1);

        tentativas--;

        if (matriz[linhainput][colunainput] >= 10) //é bomba, perdeu!
            bomba = 1;
        else {
            matrizjogador[linhainput][colunainput] = matriz[linhainput][colunainput] + 48; //segundo ASCII
        }

    }
    while(bomba == 0 || tentativas != 0);

    return fimpartida(bomba, tentativas, tempo, &matriz[][]);
    
}


int inicializartabela (int* matriz[][]) { // Definir a matriz como zero

    for (int i=0; i<9; i++ ){
      for (int j=0; j<9; j++ ){
        *matriz[i][j]=0;
     }
    }

    return 0;
}

int inicializartabelajogo (int* matrizjogador[][]) {

    for (int i = 0; i<9; i++) { //inicializar como ?
        
        for (int j=0; j<9; j++) {
            matrizjogador[i][j] == '?';
        }
    }

    return 0;
}

int distribuirbombas (int numero, int *matriz[][]) { //[PROTOTIPO] Funcao para aleatoriamente distribuir combas

}


int gerardicas () { // Varrer casas checando se e igual ou maior que dez, e adicionando 1 as vizinhas

}


int checarcoordenadas (int x, int y) { // Ver se coordenadas do usuario sao validas

    if (x < 9 && x > 0 && y < 9 && y > 0)
        return 0;
    else 
        return 1;

}


int imprimirtela (int* matriz[][]) {
    
    printf("\n");

    for (int i=0; i<9; i++ ){
        for (int j=0; j<9; j++ ){
            printf("|%d| " , *matriz[i][j]);
        }

        printf("\n\n");
    }

    printf("Escolha a coordenada da casa para revelar: \n");

    return 0;
}


int ranking () { // Armazena o ranking com nomes dos usuarios usando struct
    //A estudar melhor o funcionamento de struct
}


int fimpartida (int bomba,int tentativas,int tempo,int *matriz[][]) { //A tela do fim da partida

    int input;

    //Exibir ranking ?
    //exibir pontuação e/ou tempo

    system("clear");

    if (bomba != 0) { //perdeu 
        printf("Que pena!");
        printf("");
    }
    else {            //ganhou
        printf("Parabéns");
        printf("");
    }

    imprimirtela(&matriz[][]);

    printf("Digite '1' para voltar ao menu principal.\n\n\n");
    printf("Digite '2' para sair.\n\n\n");


    do {
        printf("O que deseja fazer?: ");
        scanf("%d", &input);
    }
    while(input != 1 || input != 2);
    
    if (input == 2){
        return 1;
    }
    else{
       return 0; //caso usuario digite o numero, ou de algum problema, retornar ao menu principal
    } 
    
}