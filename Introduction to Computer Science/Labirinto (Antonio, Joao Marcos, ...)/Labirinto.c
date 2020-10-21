#include <stdio.h>
#include <stdlib.h>

int n, m, i, j;
char mapa[30][30];

// Definição das funções que serão utilizadas no código:
void printMap();
int find_pos_linha_P();
int find_pos_coluna_P();
int is_not_finished();
int is_inside(int x, int y);
void get_move(int dificulty);
int showMenu();
int showMenuRanking();
void playGame(int);
void openEasy();
void openMedium();
void openHard();
int addScore(int atualScore, char *filename);
void showScore(char *filename);
void main_loop();

/* Definição dos elementos dos mapas:
"espaço" - caminho livre para andar dentro do labirinto
  - parede
F - saida/final do labirinto
* - player
*/

void printMap() { //Função que imprime um mapa de tamanho nxm na tela.
  for (i = 0; i < n; ++i) {
    for (j = 0; j < m; ++j) {
     printf("%c", mapa[i][j]);
    }
    printf("\n");
  }
}

int find_pos_linha_P() { //Função que procura a linha da matriz em que o jogador está.
  for (i = 0; i < n; ++i) {
    for (j = 0; j < m; ++j) {
      if (mapa[i][j] == '*') {
        return i;
      }
    }
  }
}

int find_pos_coluna_P() { //Função que procura a coluna da matriz em que o jogador está.
  for (i = 0; i < n; ++i) {
    for (j = 0; j < m; ++j) {
      if (mapa[i][j] == '*') {
        return j;
      }
    }
  }
}

int is_not_finished() { //Função para verificar se o mapa do labirinto foi finalizado. Retorna 1 como valor se o jogo ainda não foi finalizado. Ela é utilizada para fazer o loop do jogo executar até o jogador encontrar a saída do labirinto.
  for (i = 0; i < n; ++i) {
    for (j = 0; j < m; ++j) {
      if (mapa[i][j] == '*') {
        return 1;
      }
    }
  }
  return 0;
}

int is_inside(int x, int y) { //Função que verifica se o jogador continua dentro do labirinto. Ela retorna 1 se o jogador está dentro do mapa do labirinto.
  return x >= 0 && x < n && y >= 0 && y < m;
}

void get_move(int dificulty) { //Função para controlar o movimento do jogador dentro do labirinto 
  char tecla;
  printf("Entre com o movimento: (w - cima, s - baixo, a - esquerda, d - direita): ");
  scanf(" %c", &tecla);
  int a= find_pos_linha_P();
  int b= find_pos_coluna_P();
  int linhaP = find_pos_linha_P();
  int colunaP = find_pos_coluna_P();
  int linha_apos_movimento = linhaP;
  int coluna_apos_movimento = colunaP;
  if (tecla == 'w') {
    linha_apos_movimento--;
  }
  else if (tecla == 's') {
    linha_apos_movimento++;
  }
  else if (tecla == 'a') {
    coluna_apos_movimento--;
  }
  else if (tecla == 'd') {
    coluna_apos_movimento++;
  }
  else {
    printf("Tecla Inválida\n");
  }
  if (is_inside(linha_apos_movimento, coluna_apos_movimento)) {
    if (mapa[linha_apos_movimento][coluna_apos_movimento] == ' ') {
      //movimento é possível
      mapa[linha_apos_movimento][coluna_apos_movimento] = '*'; //atualizo a nova posição da pessoa
      mapa[linhaP][colunaP] = ' '; //ultima posição que a pessoa estava fica vazia
    }
    else if (mapa[linha_apos_movimento][coluna_apos_movimento] == 'F') {
      mapa[linhaP][colunaP] = ' ';
    }
    else if (mapa[linha_apos_movimento][coluna_apos_movimento] == '|'){
      printf("Movimento inválido, tente novamente!\n");
    if (dificulty == 0) {
              linha_apos_movimento=7;
              coluna_apos_movimento=7;
              mapa[linha_apos_movimento][coluna_apos_movimento] = '*';
              mapa[linhaP][colunaP] = ' ';
            }
            if (dificulty == 1){
              linha_apos_movimento=17;
              coluna_apos_movimento=2;
              mapa[linha_apos_movimento][coluna_apos_movimento] = '*';
              mapa[linhaP][colunaP] = ' ';}
            if (dificulty == 2){
                linha_apos_movimento=27;
              coluna_apos_movimento=27;
              mapa[linha_apos_movimento][coluna_apos_movimento] = '*';
              mapa[linhaP][colunaP] = ' ';}
        }
      }
   else {
    printf("Voce tentou sair do mapa!!!\n");
    if (dificulty == 0) {
            linha_apos_movimento=7;
            coluna_apos_movimento=7;
            mapa[linha_apos_movimento][coluna_apos_movimento] = '*';
            mapa[linhaP][colunaP] = ' ';
          }
          if (dificulty == 1){
            linha_apos_movimento=17;
            coluna_apos_movimento=2;
            mapa[linha_apos_movimento][coluna_apos_movimento] = '*';
            mapa[linhaP][colunaP] = ' ';}
          if (dificulty == 2){
              linha_apos_movimento=27;
            coluna_apos_movimento=27;
            mapa[linha_apos_movimento][coluna_apos_movimento] = '*';
            mapa[linhaP][colunaP] = ' ';}
    }
  }

int showMenu() { //Função para mostrar o menu do jogo
  printf("----- LABIRINTO ------\n");
  printf("1. Jogo fácil\n");
  printf("2. Jogo médio\n");
  printf("3. Jogo difícil\n");
  printf("4. Ver classificação\n");
  printf("5. Regras do jogo\n");
  printf("6. Sair\n\n\n");
  printf("Entre com a opção desejada: ");
  int option;
  scanf(" %d", &option);
  return option;
}

int showMenuRanking(){ //Função para mostrar o menu dos rankings de cada dificuldade após selecionar a opção 4//
  printf("1. Classificação do labirinto fácil\n");
  printf("2. Classificação do labirinto médio \n");
  printf("3. Classificaçaõ do labirinto difícil\n\n\n");
  printf("Entre com a opção desejada: ");
  int option;
  scanf(" %d", &option);
  return option;
}

void playGame(int dificulty) { //Função que executa o loop do jogo e registra o score do jogador. Enquanto o jogo não é finalizado, o mapa é impresso na tela e é obtido um movimento do jogador, e o score é decrementado em uma unidade.
  int atualScore;
  if (dificulty==0) atualScore=1025;
  if (dificulty==1) atualScore=1076;
  if(dificulty==2) atualScore=1187;
    while (is_not_finished()) {
    system("clear"); //Limpa a tela e atualiza o mapa do labirinto com o movimento do jogador
    printMap();
    get_move(dificulty);
    atualScore--;
    if (dificulty==0) {
      if (atualScore<0) atualScore = 0;
    }
    if (dificulty==1) {
      if (atualScore<0) atualScore = 0;
    }
    if (dificulty==2) {
      if (atualScore<0) atualScore = 0;
    }
  }
  printf("Você ganhou! Seu score foi: %d\n\n\n", atualScore);
  if (dificulty == 0) addScore(atualScore, "scoreEasy.txt");
  if (dificulty == 1) addScore(atualScore, "scoreMedium.txt");
  if (dificulty == 2) addScore(atualScore, "scoreHard.txt");
}

char mapaEasy[10][10] = //Matriz da dificuldade fácil//
{{'|','F','|','|','|','|','|','|','|','|'},
{'|',' ','|',' ',' ',' ',' ',' ',' ','|'},
{'|',' ','|',' ','|','|','|','|',' ','|'},
{'|',' ','|',' ','|',' ','|','|',' ','|'},
{'|',' ','|',' ','|',' ',' ','|',' ','|'},
{'|',' ','|',' ','|','|',' ','|',' ','|'},
{'|',' ',' ',' ','|','|',' ',' ',' ','|'},
{'|','|','|','|','|',' ',' ','*',' ','|'},
{'|',' ',' ',' ',' ',' ','|',' ','|','|'},
{'|','|','|','|','|','|','|','|','|','|'}};


char mapaMedium[20][20] =  //Matriz da dificuldade média//
{{'|', 'F', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|'},
{'|', ' ', '|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
{'|', ' ', ' ', '|', ' ', '|', '|', '|', '|', '|', '|', '|', '|', '|', ' ', '|', '|', '|', ' ', '|'},
{'|', '|', ' ', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', ' ', '|', '|', '|', ' ', '|'},
{'|', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', '|', '|', '|', ' ', '|'},
{'|', ' ', '|', '|', '|', ' ', '|', '|', '|', '|', '|', ' ', '|', ' ', '|', '|', '|', '|', ' ', '|'},
{'|', ' ', ' ', '|', '|', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', '|', ' ', ' ', ' ', ' ', '|'},
{'|', '|', ' ', ' ', '|', ' ', '|', ' ', '|', '|', '|', '|', '|', ' ', '|', ' ', '|', '|', ' ', '|'},
{'|', '|', '|', ' ', '|', ' ', '|', ' ', '|', '|', ' ', ' ', ' ', ' ', '|', ' ', '|', '|', ' ', '|'},
{'|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', '|', '|', '|', '|', '|', '|', ' ', '|', ' ', ' ', '|'},
{'|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', '|', '|', '|', '|'},
{'|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', '|', '|', ' ', '|', ' ', '|', '|', '|', '|'},
{'|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', '|', '|', '|', ' ', '|', ' ', ' ', ' ', ' ', '|'},
{'|', ' ', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', ' ', '|', '|', '|', '|', ' ', '|'},
{'|', '|', '|', '|', '|', '|', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', '|', '|', ' ', '|', ' ', '|'},
{'|', ' ', '|', '|', '|', '|', '|', ' ', '|', '|', '|', ' ', '|', ' ', '|', '|', ' ', '|', ' ', '|'},
{'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', ' ', '|', ' ', '|', '|', ' ', '|', ' ', '|'},
{'|', ' ', '*', ' ', '|', ' ', '|', '|', '|', '|', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
{'|', '|', ' ', '|', '|', ' ', ' ', ' ', ' ', ' ', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|'},
{'|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|'}};

char mapaHard [30][30]= //Matriz do mapa da dificuldade difícil
{{'|', 'F', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|','|','|','|','|','|','|','|','|','|','|'},
{'|', ' ', '|', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|', '|', '|', '|', '|', '|', '|', '|',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
{'|', ' ', ' ', '|', ' ', '|', ' ', ' ', ' ', '|', '|', ' ', ' ', ' ', ' ', '|', '|', '|', ' ', ' ',' ','|','|','|','|','|','|','|',' ','|'},
{'|', '|', ' ', '|', ' ', '|', '|', '|', '|', '|', '|', '|', '|', '|', ' ', ' ', ' ', ' ', ' ', '|','|','|',' ',' ',' ',' ',' ','|',' ','|'},
{'|', '|', ' ', '|', ' ', '|', '|', '|', '|', ' ', ' ', '|', '|', '|', '|', '|', '|', '|', '|', '|','|','|',' ','|','|','|',' ','|',' ','|'},
{'|', ' ', ' ', '|', ' ', ' ', ' ', ' ', '|', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ','|','|',' ','|','|','|',' ',' ',' ','|'},
{'|', ' ', '|', '|', '|', '|', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', '|', '|', ' ','|','|',' ','|','|','|','|','|','|','|'},
{'|', ' ', '|', '|', '|', '|', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', ' ', '|', '|', ' ',' ',' ',' ','|','|','|','|','|','|','|'},
{'|', ' ', ' ', '|', '|', '|', '|', ' ', '|', ' ', ' ', ' ', '|', ' ', '|', '|', ' ', '|', '|', '|','|','|','|','|',' ',' ',' ',' ',' ','|'},
{'|', '|', ' ', '|', '|', '|', '|', ' ', '|', '|', '|', '|', '|', ' ', ' ', '|', ' ', ' ', '|', '|','|','|','|','|',' ','|','|','|',' ','|'},
{'|', '|', ' ', '|', '|', '|', '|', ' ', ' ', '|', '|', '|', '|', '|', ' ', '|', '|', ' ', '|', '|','|','|',' ',' ',' ','|','|','|',' ','|'},
{'|', '|', ' ', ' ', ' ', '|', '|', '|', ' ', '|', '|', '|', '|', '|', ' ', ' ', '|', ' ', ' ', ' ',' ',' ',' ','|','|','|',' ',' ',' ','|'},
{'|', '|', '|', '|', ' ', '|', '|', '|', ' ', '|', ' ', ' ', ' ', '|', '|', ' ', '|', '|', '|', '|','|','|','|','|',' ',' ',' ','|',' ','|'},
{'|', ' ', '|', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', '|', ' ', '|', '|', ' ', '|', '|', '|', '|','|','|','|','|','|','|','|','|',' ','|'},
{'|', ' ', ' ', '|', '|', '|', '|', '|', '|', '|', ' ', '|', ' ', ' ', ' ', ' ', '|', '|', ' ', ' ',' ',' ',' ',' ',' ',' ',' ','|',' ','|'},
{'|', '|', ' ', ' ', '|', '|', '|', ' ', ' ', ' ', ' ', '|', '|', '|', '|', '|', '|', '|', ' ', '|','|','|','|','|','|','|',' ','|',' ','|'},
{'|', '|', '|', ' ', '|', '|', '|', ' ', '|', ' ', '|', '|', '|', '|', '|', '|', '|', ' ', ' ', '|','|','|','|','|','|','|',' ',' ',' ','|'},
{'|', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', '|', '|', '|', '|', '|', '|', '|', ' ', '|', '|',' ',' ',' ','|','|','|','|','|','|','|'},
{'|', ' ', '|', '|', '|', '|', '|', '|', '|', ' ', '|', '|', '|', '|', '|', '|', '|', ' ', '|', '|',' ','|',' ','|','|','|','|','|','|','|'},
{'|', ' ', ' ', '|', '|', '|', '|', '|', '|', ' ', ' ', '|', '|', '|', '|', '|', '|', ' ', '|', ' ',' ','|',' ','|','|','|',' ',' ',' ','|'},
{'|', '|', ' ', '|', '|', '|', '|', '|', '|', '|', ' ', '|', '|', '|', ' ', ' ', ' ', ' ', '|', ' ','|','|',' ',' ',' ',' ',' ','|',' ','|'},
{'|', ' ', ' ', '|', '|', '|', '|', '|', '|', '|', ' ', '|', '|', '|', ' ', '|', '|', '|', '|', ' ','|','|','|','|','|','|','|','|',' ','|'},
{'|', ' ', '|', '|', '|', '|', '|', '|', '|', '|', ' ', '|', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ','|',' ',' ',' ',' ',' ',' ',' ',' ','|'},
{'|', ' ', '|', ' ', ' ', ' ', '|', '|', '|', ' ', ' ', '|', ' ', '|', '|', '|', ' ', '|', '|', '|','|',' ','|','|','|','|','|',' ',' ','|'},
{'|', ' ', '|', ' ', '|', ' ', '|', '|', '|', ' ', '|', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', '|','|',' ','|','|','|','|','|','|',' ','|'},
{'|', ' ', '|', ' ', '|', ' ', '|', '|', '|', ' ', '|', '|', '|', '|', '|', '|', '|', ' ', ' ', '|','|',' ','|',' ',' ',' ',' ','|',' ','|'},
{'|', ' ', '|', ' ', '|', ' ', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|', '|', '|', ' ', '|','|','|','|',' ',' ',' ',' ',' ',' ','|'},
{'|', ' ', ' ', ' ', '|', ' ', '|', ' ', '|', '|', '|', '|', '|', '|', ' ', '|', '|', ' ', ' ', ' ',' ',' ',' ',' ','|','|',' ','*',' ','|'},
{'|', '|', '|', '|', '|', ' ', ' ', ' ', '|', '|', '|', '|', '|', '|', ' ', ' ', ' ', ' ', '|', '|','|','|','|',' ','|','|',' ',' ',' ','|'},
{'|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|', '|','|','|','|','|','|','|','|','|','|','|'}};;


 void openEasy() { ////Função para exportar para a variável mapa[][] o mapa fácil do jogo
  n = m = 10;
  for (i = 0; i < n; ++i) {
    for (j = 0; j < m; ++j) {
      mapa[i][j] = mapaEasy[i][j];
    }
  }
  playGame(0);
}

void openMedium() { //Função para exportar para a variável mapa[][] o mapa médio do jogo
  n = m = 20;
  for (i = 0; i < n; ++i) {
    for (j = 0; j < m; ++j) {
      mapa[i][j] = mapaMedium[i][j];
    }
  }
  playGame(1);
}

void openHard() { //Função para exportar para a variável mapa[][] o mapa dificil do jogo
  n= m = 30;
  for (i = 0; i < n; ++i) {
    for (j = 0; j < m; ++j) {
      mapa[i][j] = mapaHard[i][j];
    }
  }
  playGame(2);
}

typedef struct { //Struct para armazenar o nome do jogador e a pontuação ao final de um mapa
 char name[123];
 int score;
}pontuacao;

int addScore(int atualScore, char *filename){
  printf("Deseja adicionar seu score no placar? (s/n)\n");
  char option;
  scanf(" %c", &option);
  if (option == 's') {
    printf("Entre com o nome do jogador: ");
    char name[123];
    scanf(" %s", name);
    FILE *f = fopen(filename, "a");
    fprintf(f, "%s %d\n", name, atualScore);
    fclose(f);
  }
  main_loop();
}

void showScore(char *filename) {
  FILE *f = fopen(filename, "r");
  pontuacao ranking[123];
  int nr = 0;
  while (fscanf(f, " %s %d", ranking[nr].name, &ranking[nr].score) != EOF) {
    nr++;
  }
  for (i = 0; i < nr; ++i) {
    for (j = i + 1; j < nr; ++j) {
      if (ranking[i].score < ranking[j].score) {
        pontuacao aux = ranking[i];
        ranking[i] = ranking[j];
        ranking[j] = aux;
      }
    }
  }
  if (nr > 10) nr = 10; //Setar o arquivo com no máximo 10 jogadores para criar o top 10 de cada nível de dificuldade do labirinto//
  printf("!!!!!!!!!!!!!!!!!!TOP 10 JOGADORES DESTE NÍVEL!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n");
  for (i = 0; i < nr; ++i) {
    printf("%s %d\n", ranking[i].name, ranking[i].score);
  }
}

void main_loop() { //Função que executa o loop responsável pela impressão do menu do jogo na tela. É executado enquanto o jogo inteiro não é finalizado, ou seja, até o usuário digitar a opção 6.
  while (1) {
    int option = showMenu();
    if (option == 1) {
      openEasy();
    }
    else if (option == 2) {
      openMedium();
    }
    else if (option == 3) {
      openHard();
    }
    else if (option == 4) {
      int option = showMenuRanking();
      if (option == 1) 
        showScore("scoreEasy.txt");
      if (option == 2) 
        showScore("scoreMedium.txt");
      if (option == 3)
        showScore("scoreHard.txt");
      }
    else if (option ==5) {
      printf("\n\nRegras do jogo: \n\n 1- Utilize somente as teclas a, w, s e d para se movimentar dentro do labirinto\n 2- Caso bata em alguma parede você retornará ao começo do labirinto\n 3- O jogo acaba quando chegar no fim do labirinto, caracterizado pelo caracter 'F'\n\n\n");
    }
    else if (option ==6) {
      printf("Muito obrigado por jogar!\n\n\n");
      exit(0);
      break;
    }
    else {
      printf("Opção inválida\n");
    }
  }
}
int main() { //Função principal apenas para iniciar o programa
  main_loop();
  return 0;
}