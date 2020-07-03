#include <stdio.h>

/* Este codigo nao tem a intencao de ser funcinal para a segunda entrega*/
/*Serve apenas para se dar uma nocao da estrutura do trabalho final*/
//O trabalho final provavelmente nao tera tantas funcoes
//A questao referente ao relogio parecera mais simples do que era. Mais estudo e necessario.

int inicializartabela (int, int, int*);
int distribuirbombas (int);
int gerardicas ();
int start ();
int teladejogo (int*);
int checarcoordenadas (int, int, int, int);
int ranking ();
int exibirmenu ();
int fimpartida (int*);

int main (void) 
{
    int control;

    do {
      int input;

      exibirmenu();

      do 
      {
          scanf("%d", &input);
      }
      while (input > 0 && input < 5);

      switch (input)
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
    while (control != 0) //As funcoes retornarao 1 por padrao. Caso for definido como zero, o jogo encerra.

    return 0; //programa finalizado
}


int inicializartabela (int linha, int coluna, int* matriz[][]) { // Definir a matriz como zero

    int matriz[linha][coluna];

    for (int i=0; i<linha; i++ ){
      for (int j=0; j<coluna; j++ ){
     matriz[i][j]=0}
    }

    /* return matriz[][]; */ 

    //definir se matriz pode ser retornada ou se sera preciso vetor
    //definir se o vetor da

    return 0;
}

int distribuirbombas (int numero, int *matriz[][]) { //[PROTOTIPO] Funcao para aleatoriamente distribuir combas

}

int gerardicas () { // Varrer casas checando se e igual ou maior que dez, e adicionando 1 as vizinhas

}

int checarcoordenadas (int x, int y, int linha, int coluna) { // Ver se coordenadas do usuario sao validas

    if (x < linha && x > 0 && y < coluna && y > 0)
        return 0;
    else 
        return 1;
}

int start () { // Codigo do jogo

    int linha=9, coluna=9, matriz[9][9]; //definido como nove por hora. Planejamos implementar niveis de dificuldade no jogo final
    int linhainput, colunainput, matrizjogador[9][9];
    int tentativas, numbombas=30, bomba=0;  //a definir numero de bombas. Definido temporarioamente como 30
    tentativas = (linha*coluna) - numbombas; 

    inicializartabela(linha, coluna, &matriz[][]); //dar valores zero
    inicializartabelajogo(&matrizjogador);

    do {

        distribuirbombas(((matriz*coluna) / 3), *matriz[][]); //numero a definir 
        gerardicas(); //implementaremos a geracao de dicas juntamente a funcao de distribuicao de bombas

        teladejogo(&matrizjogador[][]); //por hora apenas a matriz sera imprimida
        
        do {
            printf("\nInsira o valor da linha: ");
            scanf ("%d", &linhainput); 
            printf("\nInsira o valor da coluna");
            scanf ("%d", &colunainput);
        } 
        while (checarcoordenadas(linhainput,colunainput, linha, coluna) == 1);

        tentativas--;
        
        if (matriz[linhainput][colunainput] >= 10) //e bomba, perdeu!


        matrizjogador[linhainput][colunainput] = matriz[linhainput][colunainput];

    }
    while(bomba != 0 || tentativas != 0)

    fimpartida();
}

int teladejogo (int *matriz[][]) {

    for ( i=0; i<9; i++ ){
        for ( j=0; j<9; j++ ){
            printf("|%d|" , matriz [i][j]);}
    
    return 0;
            
}

int ranking () { // Armazena o ranking com nomes dos usuarios usando struct
    //A estudar melhor o funcionamento de struct
}

int exibirmenu () { //A parte grafica do menu principal

    printf("Olá, bem vindo ao campo minado!\n\n\n");
    printf("--------------------------------\n\n\n");
    printf("Digite '1' para iniciar o jogo\n\n\n");
    printf("Digite '2' para ver as regras e como jogar\n\n\n");
    printf("Digite '3' para acessar o ranking\n\n\n");
    printf("Digite '4' para sair\n\n\n");

    return 0;
}

int fimpartida (*matriz[][]) { //A tela do fim da partida
    int input, aux;
    //Exibir a tela final e falar se ganhou ou nao
    //Exibir ranking
    //Exibir opcoes e pedir por input

    scanf("%d", &input);
    do {
        switch (input) {
            case 1: return 1; //voltar ao menu principal
                break;
            case 2: return 0;
                break;
            default: aux=5; //qualquer valor diferente 
        }
    }
    while (aux==5) //certamente uma gambiarra

    //Switch
    //Voltar ao menu principal
        //return 1;
    //Sair do jogo
        //return 0;

}