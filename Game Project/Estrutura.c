#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* Este codigo nao tem a intencao de ser funcinal para a segunda entrega*/
/*Serve apenas para se dar uma nocao da estrutura do trabalho final*/
//O trabalho final provavelmente nao tera tantas funcoes
//A questao referente ao relogio parecera mais simples do que era. Mais estudo e necessario.

int inicializartabela (int matriz[][9]);
int inicializartabelajogo(char matrizjogador[][9]);
int bombasedicas(int, int matriz[][9]);
int start ();
int imprimirtela (int matriz[][9]);
int imprimirtelajogo(char matriz[][9]);
int checarcoordenadas (int, int);
int ranking ();
int exibirmenu ();
int fimpartida (int, int, int, int matriz[][9]);
int rules ();

int main (void) {

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
      while (input < 0 && input > 5);

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

    int linha=9, coluna=9, matriz[9][9];
    char matrizjogador[9][9]; 

    int linhainput, colunainput;
    int tentativas, numbombas, bomba;  //a definir numero de bombas. Definido temporariamente como 11
    int tempo; //A determinar

    numbombas=11;
    tentativas = ((linha*coluna) - numbombas);

    inicializartabela(matriz); //dar valores zero
    inicializartabelajogo(matrizjogador);

    do {

        bombasedicas(numbombas, matriz); //numero a definir 

        system("clear");

        imprimirtelajogo(matrizjogador); //por hora apenas a matriz sera imprimida
        printf("Escolha a coordenada da casa para revelar: \n");
        
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
            bomba = 0;
            matrizjogador[linhainput][colunainput] = matriz[linhainput][colunainput] + 48; //segundo ASCII
        }

    }
    while(bomba == 0 || tentativas != 0);

    return fimpartida(bomba, tentativas, tempo, matriz);
    //bomba para saber se ganhou ou perdeu; 
    //tentativas para ranking; 
    //tempo para ranking; 
    //matriz para exibir.
}


int rules () { //escrever a tela para as regras

    int matrizint[9][9];
    char matrizchar[9][9];

    system("clear");

    printf("\t\t\tRegras do Campo Minado\n");
    printf("A tabela a seguir representa um campo minado.\n");
    printf("\n instruções...");

    //Mostrar como será o tabuleiro de jogo
    inicializartabelajogo(matrizchar); 
    imprimirtelajogo(matrizchar);

    printf("\nAperte qualquer tecla e tecle enter para seguir.\n\t");

    getchar();
    getchar(); //Gambiarra aprovada pelo Monitor©

    system("clear");

    printf("Sobre a tabela escondida e como aparecerão as bombas e dicas...");

    inicializartabela(matrizint);
    imprimirtela(matrizint);
    
    printf("Aperte qualquer tecla para voltar ao menu.");
    
    getchar();
    getchar();

    return 0;
}


int inicializartabela (int matriz[][9]) { // Definir a matriz como zero

    for (int i=0; i<9; i++ ){

        for (int j=0; j<9; j++ ){
            matriz[i][j]=0;
        }
    }

    return 0;
}


int inicializartabelajogo (char matrizjogador[][9]) {

    for (int i = 0; i<9; i++) { //inicializar como ?
        
        for (int j=0; j<9; j++) {
            matrizjogador[i][j] = ' ';
        }
        
    }

    return 0;
}


int bombasedicas (int numbombas, int matriz[][9]) {

    int bombai, bombaj;

    for(int auxiliar=0; auxiliar<numbombas; auxiliar++){

        bombai=rand() % 7;
        bombaj=rand() % 7;

        if(bombai==0 || bombaj==0 || matriz[bombai][bombaj] >= 10){ 
            auxiliar--;
        }
        else{
        matriz[bombai][bombaj]+=10;

        //aqui comeca a distribuir as dicas nesse local de bomba//
        bombai=bombai+1;
        matriz[bombai][bombaj]++;
        bombaj=bombaj+1;
        matriz[bombai][bombaj]++;
        bombai=bombai-1;
        matriz[bombai][bombaj]++;
        bombai=bombai-1;
        matriz[bombai][bombaj]++;
        bombaj=bombaj-1;
        matriz[bombai][bombaj]++;
        bombaj=bombaj-1;
        matriz[bombai][bombaj]++;
        bombai=bombai+1;
        matriz[bombai][bombaj]++;
        bombai=bombai+1;
        matriz[bombai][bombaj]++;
    }
  }
}


int checarcoordenadas (int x, int y) { // Ver se coordenadas do usuario sao validas

    if (x < 9 && x > 0 && y < 9 && y > 0)
        return 0;
    else 
        return 1;
    
    //Seria interessante passar o valor das linhas e colunas de maneira variavel, mas ok
}


int imprimirtela (int matriz[][9]) {
    
    printf("\n\n    1    2    3    4    5    6    7    8    9\n\n");

    for (int i=0; i<9; i++ ){

        printf("%d  ", i+1);

        for (int j=0; j<9; j++ ){
            printf("|%d|  " , matriz[i][j]);
        }

        printf("\n\n");
    }

    return 0;
}


int imprimirtelajogo (char matriz[][9]) {

    printf("\n\n    1    2    3    4    5    6    7    8    9\n\n");

    for (int i=0; i<9; i++ ){

        printf("%d  ", i+1);

        for (int j=0; j<9; j++ ){
            printf("|%c|  " , matriz[i][j]);
        }

        printf("\n\n");
    }

    return 0;
}


int ranking () { // Armazena o ranking com nomes dos usuarios usando struct
    //A estudar melhor o funcionamento de struct
    system("clear");

    printf("qualquercoisa");
    
    return 0;
}


int fimpartida (int bomba, int tentativas, int tempo, int matriz[][9]) { //A tela do fim da partida

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

    imprimirtela(matriz);

    printf("Digite '1' para voltar ao menu principal.\n\n\n");
    printf("Digite '2' para sair.\n\n\n");

    do {
        printf("O que deseja fazer?: ");
        scanf("%d", &input);
    }
    while(input != 1 || input != 2);
    
    if (input == 2) {
        return 1;
    }
    else {
       return 0; //caso usuario digite o numero, ou de algum problema, retornar ao menu principal
    } 
}