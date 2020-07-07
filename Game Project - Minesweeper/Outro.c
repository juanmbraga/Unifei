#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void coordenadas(int *x,int *y,int *z,int *w){ /*função responsável por receber as coordenadas e modifica-las(atravez de ponteiros) na matriz(tabuleiro)*/
  printf("\nSelecione as coordenadas da peça que deseja mover: ");
  scanf(" %d", &*x);
  printf("\nSelecione as coordenadas da peça que deseja mover: ");
  scanf(" %d", &*y);
  printf("\nSelecione as coordenadas da peça para onde a peça vai ir: ");
  scanf(" %d", &*z);
  printf("\nSelecione as coordenadas da peça para onde a peça vai ir: ");
  scanf(" %d", &*w);
}
int regras(){
  printf("   |-----------------------------------------------------------------------------|");
printf("\n   |                                INSTRUCOES!!!!                               |");
printf("\n   |                                                                             |");
printf("\n   |        *O JOGO CONTEM 32 PEÇAS E UM ESPAÇO VAZIO NO CENTRO.                 |");
printf("\n   |                                                                             |");
printf("\n   |        *O JOGADOR SO DEVE SE MOVER NA HORIZONTAL E VERTICAL, PULANDO UMA    |");
printf("\n   |                      PEÇA E CAINDO EM UM LUGAR VAZIO.                       |"); /*função de impressão das regras do jogo*/
printf("\n   |        *A PEÇA QUE FOI PULADA DEVE SER RETIRADA DO JOGO.                    |");                 
printf("\n   |                                                                             |");
printf("\n   |        *SO E POSSIVEL PULAR UMA PEÇA POR JOGADA.                            |");
printf("\n   |                                                                             |");
printf("\n   |        *O JOGO ACABA QUANDO RESTAR APENAS 1 UMA PEÇA.                       |");
printf("\n   |                                                                             |"); 
printf("\n   |        *CASO QUEIRA SAIR DO JOGO, TECLE 'Q' NO COMECO DE CADA ROUND         |");
printf("\n   |-----------------------------------------------------------------------------|\n");
return 0;
}    
int main(){
  
  char matriz[7][7]= {{'@', '@', '1', '1', '1', '@', '@'},
                     {'@', '@', '1', '1', '1', '@', '@' },                 
                     {'1', '1', '1', '1', '1', '1', '1' },/* declaração da matriz utilizada para o tabuleiro*/
                     {'1', '1', '1', '0', '1', '1', '1' },                         
                     {'1', '1', '1', '1', '1', '1', '1' },
                     {'@', '@', '1', '1', '1', '@', '@' },
                     {'@', '@', '1', '1', '1', '@', '@',}};
  int p,x,y,z,w,m,n,h,pont;
  char nick[15],sair;
printf(" |-----------------------------------------------------------------------------|");
printf("\n |                                   RESTA 1                                   |");
printf("\n |                                                                             |");
printf("\n |                                                                             |");
printf("\n |                                                                             |");
printf("\n |                                                                             |");
printf("\n |                              (1)INICIAR O JOGO                              |");/*Impressão da tela inical do jogo */
printf("\n |                                                                             |");
printf("\n |                              (2)SAIR DO JOGO                                |");
printf("\n |                                                                             |");
printf("\n |                                                                             |");
printf("\n |                                                                             |");
printf("\n |                                                                             |");
printf("\n |                                                                             |");
printf("\n |-----------------------------------------------------------------------------|\n");
scanf(" %d", &p);
system("clear");
  if (p==1){
    printf(" |-----------------------------------------------------------------------------|");
    printf("\n |                                                                             |");
    printf("\n |                                                                             |");
    printf("\n |                                                                             |");
    printf("\n |                                                                             |");
    printf("\n |                              ESCOLHA UM NICK                                |");
    printf("\n |                                                                             |");
    printf("\n |                                                                             |");/*impressão da escolha de nickname*/
    printf("\n |                                                                             |"); 
    printf("\n |                                                                             |");
    printf("\n |                                                                             |");
    printf("\n |                                                                             |");
    printf("\n |                                                                             |"); 
    printf("\n |                                                                             |");
    printf("\n |-----------------------------------------------------------------------------|");
    printf("\nSEU NICK: ");  /*escolha do nickname*/
    scanf(" %s", nick);
  }
  else
  return 0;
system("clear");
regras();
h=0; /* h é a variavel que soma os valores dos caracteres do tabuleiro durante o jogo, se h = 2610 significa que só resta uma peça no tabuleiro.*/ 
pont=0; /*pontuação do jogo que será calculada a cada loop(rodada).*/
while(h!=2610){ /* representa a execução do jogo em sí, que se diferente de 2610 (valor do tabuleiro quano so resta uma peça) continuará apresentando escolhas de ação para o jogador. cada movimento realizado pelo jogador representará uma jogada, que significa um loop realizado pelo while.*/
printf("\n                               0  1  2  3  4  5  6          Pontuacao: %d\n",pont);
  printf("                            ------------------------\n");

for(int z=0;z<7;z++){

    printf("                           %d |", z);
    for(int w=0;w<7;w++){
      h=matriz[z][w]+h; /*atualizacao do valor de H a cada rodada para saber se o jogador zerou ou não o jogo */
      printf(" %c ",matriz[z][w]); /*impressão da matriz(tabuleiro) que será atualizada a cada rodada após a movimentação do jogador*/
    }
    printf("| \n");  
}
printf("Digite 'q' caso queira sair do jogo, caso queira continuar tecle ENTER: ");
setbuf(stdin,NULL);
sair=getchar();
if(sair=='q')
  break;

coordenadas(&x,&y,&z,&w);  

  if(x-z>2||y-w>2||x-z<-2||y-w<-2){
  system("clear");
  regras();
  printf("                               0  1  2  3  4  5  6          Pontuacao: %d\n",pont);
  printf("                            ------------------------\n");    /*um dos tipos de erro que impede a jogada(não permite o jogador pular mais de uma peça) */

    for(int z=0;z<7;z++){

    printf("                           %d |", z);
    for(int w=0;w<7;w++){
      h=matriz[z][w]+h;
      printf(" %c ",matriz[z][w]);
    }
    printf("| \n");  
    }
printf("\nMovimento invalido, tente novamente!\n");
coordenadas(&x,&y,&z,&w); 
  }
  else if(matriz[x][y]!='1'||matriz[z][w]!='0'){
    system("clear");                                                         /*um dos tipos de erro que impede a jogada(erro caso o jogador tente selecionar o '@' ou mover as peças com o '0') */
    regras();
    printf("                               0  1  2  3  4  5  6          Pontuacao: %d\n",pont);
    printf("                            ------------------------\n");

    for(int z=0;z<7;z++){

    printf("                           %d |", z);
    for(int w=0;w<7;w++){
      h=matriz[z][w]+h;
      printf(" %c ",matriz[z][w]);
    }
    printf("| \n");  
    }
printf("\nMovimento invalido, tente novamente!\n");
coordenadas(&x,&y,&z,&w); 
  }
  else if(x>6||y>6||z>6||w>6){
    system("clear");
    regras();                                                                  /*um dos tipos de erro que impede a jogada(não permite que o jogador escolha coordenadas que não estejam no tabuleiro) */
    printf("                               0  1  2  3  4  5  6          Pontuacao: %d\n",pont);
    printf("                            ------------------------\n");

    for(int z=0;z<7;z++){

    printf("                           %d |", z);
    for(int w=0;w<7;w++){
      h=matriz[z][w]+h;
      printf(" %c ",matriz[z][w]);
    }
    printf("| \n");  
    }
printf("\nMovimento invalido, tente novamente!\n");
coordenadas(&x,&y,&z,&w); 
  }    
  else if(x!=z&&y!=w){
    system("clear");
    regras();                                                                  /*um dos tipos de erro que impede a jogada(não permite o jogador andar na diagonal) */
    printf("                               0  1  2  3  4  5  6          Pontuacao: %d\n",pont);
    printf("                            ------------------------\n");
    for(int z=0;z<7;z++){
    printf("                           %d |", z);
    for(int w=0;w<7;w++){
      h=matriz[z][w]+h;
      printf(" %c ",matriz[z][w]);
    }
    printf("| \n");  
    }
printf("\nMovimento invalido, tente novamente!\n");
coordenadas(&x,&y,&z,&w); 
  }

  system("clear");
  regras();
  matriz[z][w] = matriz [x][y];    /*substituição das coordenadas selecionadas para onde o usuario quer ir*/
  matriz[x][y] = '0';             /*define como zero(espaço vazio no tabuleiro)as coordenadas que foram movidas*/
  matriz[(x+z)/2][(y+w)/2]='0'; /*por meio da divisão da soma entre a coordenadas que variaram, obtem-se a coordenada que fica entre o movimento, que será definido como zero pois é considerada uma peça que foi "comida" */
  pont=pont + 1;

}
if(h==2610){
printf(" |-----------------------------------------------------------------------------|");
    printf("\n |                                                                             |");
    printf("\n |                                                                             |");
    printf("\n |                                                                             |");
    printf("\n |                                                                             |");
    printf("\n |                         PARABENS, VOCE GANHOU!                              |");
    printf("\n |                                                                             |");
    printf("\n |                                                                             |"); /*impressão da tela de vitória do jogo */
    printf("\n |                                                                             |");
    printf("\n |                                                                             |");
    printf("\n |                                                                             |");
    printf("\n |                                                                             |");
    printf("\n |                                                                             |"); 
    printf("\n |                                                                             |");
    printf("\n |-----------------------------------------------------------------------------|");
}
else{
  system("clear");
printf(" |-----------------------------------------------------------------------------|");
    printf("\n |                                                                             |");
    printf("\n |                                                                             |");
    printf("\n |                                                                             |");
    printf("\n |                                                                             |");
    printf("\n |                                                                             |");
    printf("\n |                                                                             |");
    printf("\n |                               GAME OVER!                                    |"); /*impressão da tela de derrota do jogo */
    printf("\n |                                                                             |");
    printf("\n |                                                                             |");
    printf("\n |                                                                             |");
    printf("\n |                                                                             |");
    printf("\n |                                                                             |"); 
    printf("\n |                                                                             |");
    printf("\n |-----------------------------------------------------------------------------|");  
} 
 printf("\n        |                             RANKING:                              |");
 
  struct ranking    /* Aqui foi declarada a estrutura "ranking" com as variaveis do nick e pontuação para ficar em forma de estrutura de dados(registro) */
{
  int pont1;      
  char nick1[16];   
};

struct ranking rank;             
rank. pont1= pont;         /*foram declaradas as variaveis do tipo estrutura*/
strncpy(rank.nick1, nick, 15);

printf ("\n                                  NICK/PONTUACAO");    
FILE *file;
    file = fopen("Ranking", "a");    /* Aqui dentro do arquivo "ranking" foi adicionado a estrutura de dados(registro) da pontuação e do nick criado */
    fprintf(file, "*%s %d\n", rank. nick1 , rank. pont1);
    fclose(file);
    file = fopen("Ranking", "r"); 
    char recorde[500];
    while(fgets(recorde, 500, file) != NULL){
    printf("\n                          %s", recorde);/*O conteudo lido no arquivo ranking é impresso no terminal.*/
}
    fclose(file);

}

 