#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct rank {
	int pontos;
	char nome[30], dificuldade[8];
} trank;

void showtab(int campo[][15], int tammaximo);
void construircampo(int tammaximo, int qntbombas, int campo[][15]);
void printcampo (int campo[][15], int tammaximo);
void abrirzero(int campo[][15], int posicao1, int posicao2, int tammaximo, int *numcasas, int *pontuacao);

int main (void) {
  setlocale(LC_ALL, "Portuguese");
	int campo[15][15], tammaximo, qntbombas;
	int numero, dificuldade;
	int posicao1, posicao2, numerocasas=0, pontuacao=0, ganhou;
	int aux, i;
  FILE *ranking;
	trank rank[11];
	int posnovojogador=0, posicaorelativa=1;
	char auxc='a', straux[50];

	srand(time(0)); //Essa é a 'seed' para o número aleatório, pois sem ela os números 'aleatórios' não mudarão. Com a seed no tempo, a cada intervalo de tempo (provavelmente a cada segundo) novos números aleatórios são gerados, e assim o tabuleiro será realmente aleatório.

  do{
    aux=1;
    ganhou=1;

		//Verifica quantas pessoas já estão escritas no rank
		ranking = fopen("ranking.txt", "r");
		fseek(ranking, 0, SEEK_SET);
		while(auxc != EOF){
			auxc = fgetc(ranking);
			if(auxc == '\n')
				posnovojogador++; //O valor do posnovojogador vai ser um a menos que o valor real de pessoas registradas porque a primeira pessoa começa em 1 mas o posnovojogador começa em 0.
		}
		fclose(ranking);
		posnovojogador += 1;

		//Passa os jogadores já registrados para um vetor
		fopen("ranking.txt", "r");
		rewind(ranking);
		for(i=1; i<=posnovojogador; i++){
			fscanf(ranking, " %s %s %d", rank[i].nome, rank[i].dificuldade, &rank[i].pontos);
		}
		fclose(ranking);
		//Mais pra frente, vai ser feita uma verificação no arquivo do ranking para ver se o novo jogador é o jogador de número 11, se for, ele ou vai substituir o de pontuação menor ou vai ser descartado e vai ser falado que ele não conseguiu entrar no "top 10", assim, podemos ter certeza que o vetor rank[] nunca terá mais de 11 elementos, sendo o elemento 0 o novo jogador (volátil) e os outros 10 serão preenchidos usando o arquivo.

		system("clear");
    	printf("------------------- CAMPO MINADO ---------------- \n\n");
      printf("0 - Como jogar\n");
    	printf("1 - Jogar\n");
    	printf("2 - Créditos\n");
    	printf("3 - Ranking\n");
      printf("4 - Sair\n");
    	printf("\n");
    	printf("\nEscolha a opção desejada: ");
    	scanf(" %d", &numero);

    	switch (numero)
      {
        case 0:
      		system("clear");
      		printf("Carregando Regras...\n");
      		printf("-------------------------------------------------------------------------------\n");
      		printf("--------------------------------COMO JOGAR-------------------------------------\n");
      		printf("-------------------------------------------------------------------------------\n");
      		printf("\n");
      		printf("O jogo Campo Minado consiste em um tabuleiro dividido em casas cujo conteúdo\na princípio é secreto. Para jogar, escolha uma casa para revelar seu conteúdo,\nque pode ser:\n");
          printf("\n");
          printf("1) uma mina (representada pelo número 9) que explode ao ser revelada,\nterminando o jogo. Evite as minas a todo custo!\n");
          printf("\n");
          printf("2) um número de 0 a 8, indicando quantas minas existem nas casas adjacentes\nao número em questão. Por exemplo, se uma casa aberta for '3', significa que\ntrês das casas ao redor dela são minas, então cuidado!\nUse os números a seu favor para descobrir onde estão as minas.\n");
          printf("\n");
          printf("Para ganhar o jogo, abra todas as casas de 0 a 8 sem pisar em nenhuma mina.\nBoa sorte!\n");
          printf("\n");
          printf("Pressione qualquer tecla para voltar ao menu principal.\n ");
          printf("\n");
  
					getchar();
					getchar();
          //Como não há system("pause"), deve-se usar getchar, porém como há um scanf antes, o buffer do teclado precisa ser limpo com um getchar "extra" antes de realmente usá-lo.

      		aux=0;
      		break;

          
    		case 1:
        	system("clear");
        	printf("Carregando opções...\n");
        	printf("---------------------------------------------- \n");
        	printf("1 - Fácil \n");
        	printf("2 - Médio \n");
        	printf("3 - Difícil \n");
        	printf("\n");
        	printf("\nEscolha a opção desejada: ");
        	scanf(" %d", &dificuldade);
          
        	//Define o nível de dificuldade do jogo
        	switch (dificuldade){
        		case 1:
            	printf("Dificuldade definida como Fácil!\n\n");
            	tammaximo = 9;
							qntbombas = 6;
							strcpy(rank[0].dificuldade, "Fácil");
            	break;
        		case 2:
            	printf("Dificuldade definida como Médio!\n\n");
            	tammaximo = 12;
							qntbombas = 15;
							strcpy(rank[0].dificuldade, "Médio");
            	break;
        		case 3:
            	printf("Dificuldade definida como Difícil!\n\n");
            	tammaximo = 15;
							qntbombas = 20;
							strcpy(rank[0].dificuldade, "Difícil");
            	break;
						default:
							printf("Opção inválida!\n");
							aux = 0;
							printf("Aperte qualquer tecla para voltar ao menu principal ");
							getchar();
							getchar();
							break;
        	}
        break;

    		case 2:
      		system("clear");
      		printf("Carregando créditos...\n");
      		printf("-------------------------------------------------------------------------------\n");
      		printf("----------------------------------CRÉDITOS-------------------------------------\n");
      		printf("-------------------------------------------------------------------------------\n");
      		printf("\n");
      		printf("Este jogo foi desenvolvido por:\n");
      		printf("\n");
      		printf("- Bruna Rafael Neira Muñoz - Matrícula número 2020003676 \n");
      		printf("\n");
      		printf("- Jennifer Camila Gonçalves - Matrícula número 2018008399 \n");
      		printf("\n");
      		printf("- Marcelo Robert Santos - Matrícula número 2020002777 \n");
      		printf("\n");
      		printf("Notas sobre o jogo: \n");
      		printf("Este jogo foi desenvolvido no ano de 2020 para a aula da Prof. Melise Maria Veiga de Paula,\n");
      		printf("docente do curso de Ciência da Computação na UNIFEI (Universidade Federal de Itajubá),\n");
      		printf("como o trabalho final da matéria de FUNDAMENTOS DA PROGRAMAÇÃO.\n");
      		printf("Tendo em vista a avaliação do aprendizado dos alunos do grupo em questão\n");
      		printf("e da fixação da matéria lecionada durante o decorrer do semestre.\n");
      		printf("\n");
      		printf("Pressione qualquer tecla para voltar ao menu principal. ");

					getchar();
					getchar();	//Como não há system("pause"), deve-se usar getchar, porém como há um scanf antes, o buffer do teclado precisa ser limpo com um getchar "extra" antes de realmente usá-lo.

      		aux=0;
      		break;
        case 3:
          ranking = fopen("ranking.txt", "r");
          for(i=1; i<=posnovojogador; i++){
						fgets(straux, 50, ranking);
						printf("%dº Lugar: %s", i, straux);
					}
					fclose(ranking);

          printf ("\n\nAperte qualquer tecla para voltar ao menu principal ");
          getchar();
          getchar();
          aux = 0;
          fclose(ranking);
          break;				
    		case 4:
      		system("clear");
      		printf("Saindo do jogo ...");
      		aux=0;
					break;
    		default:
      		printf("\nOpção INVÁLIDA\n");
					aux = 0;
					printf("Aperte qualquer tecla para voltar ao menu principal ");
					getchar();
					getchar();
  		}

  	if(aux==1){
 			construircampo(tammaximo, qntbombas, campo);
			while(ganhou==1 && numerocasas <((tammaximo*tammaximo)-qntbombas)){
    		printcampo(campo, tammaximo);
    		printf("\n Digite a linha e a coluna:");
    		scanf("%d %d", &posicao1, &posicao2);
    		if(posicao1 <= tammaximo && posicao1 >= 0 && posicao2 <= tammaximo && posicao2 >= 0){
      		switch(campo[posicao1-1][posicao2-1]-10){
	      		case 0:
            	abrirzero(campo, posicao1-1, posicao2-1, tammaximo, &numerocasas, &pontuacao);
            	break;
        		case 1:
            	campo[posicao1-1][posicao2-1]=campo[posicao1-1][posicao2-1]-10;
            	numerocasas++;
              pontuacao += 2;
            	break;
        		case 2:
            	campo[posicao1-1][posicao2-1]=campo[posicao1-1][posicao2-1]-10;
            	numerocasas++;
              pontuacao += 3;
            	break;
        		case 3:
            	campo[posicao1-1][posicao2-1]=campo[posicao1-1][posicao2-1]-10;
            	numerocasas++;
              pontuacao += 4;
            	break;
						case 4:
            	campo[posicao1-1][posicao2-1]=campo[posicao1-1][posicao2-1]-10;
            	numerocasas++;
              pontuacao += 5;
            	break;
						case 5:
            	campo[posicao1-1][posicao2-1]=campo[posicao1-1][posicao2-1]-10;
            	numerocasas++;
              pontuacao += 6;
            	break;
						case 6:
            	campo[posicao1-1][posicao2-1]=campo[posicao1-1][posicao2-1]-10;
            	numerocasas++;
              pontuacao += 7;
            	break;
						case 7:
            	campo[posicao1-1][posicao2-1]=campo[posicao1-1][posicao2-1]-10;
            	numerocasas++;
              pontuacao += 8;
            	break;
						case 8:
            	campo[posicao1-1][posicao2-1]=campo[posicao1-1][posicao2-1]-10;
            	numerocasas++;
              pontuacao += 9;
            	break;
        		case 9:
          		printf("\n================================\n");
          		printf("\t Você perdeu\n");
          		printf("================================\n\n");
							showtab(campo, tammaximo);
              printf("Sua pontuação foi: %d\n", pontuacao);
          		ganhou=0;
          		break;
      		}
    		}
				else{
					printf("Esse número é inválido.");
				}
  		}
      if(ganhou==1){
				showtab(campo, tammaximo);
        printf("\nVocê ganhou!\n");
        printf("Sua pontuação foi: %d\n", pontuacao);
      }

			//Registra o novo jogador no vetor
      printf("Digite seu nome (sem espaços):\n");
			scanf(" %s", rank[0].nome);
			rank[0].pontos = pontuacao;
			//Define entre quais jogadores está o jogador novo (se está em 1º lugar, 2º lugar...)
			for(i=1; i<=posnovojogador; i++){
				if(rank[i].pontos > rank[0].pontos)
					posicaorelativa++;
			}	//Se a pontuação referência for maior, então o novo jogador aumenta sua posição ordinal (por ex. de 1º lugar vai para o 2º lugar)

			//Se houverem 11 jogadores e ele estiver no último lugar, é porque ele não tem pontos suficientes para entrar no top 10
			if(posnovojogador == 11 && posicaorelativa == 11){
				printf("Infelizmente você não está entre os dez melhores jogadores...");
			}
			else{
				//Se a lista não estiver cheia, apenas coloca ele no lugar certo.
				if(posnovojogador < 11){
					fopen("ranking.txt", "w");
					rewind(ranking);

					if(rank[posnovojogador-1].pontos < pontuacao){ //Esse if e o else em seguida são para debugar, pois ele estava printando no arquivo um jogador repetido ou sobrescrevendo um jogador que já estava registrado
						for(i=1; rank[i].pontos >= pontuacao; i++){
							fprintf(ranking, "%s %s %d\n", rank[i].nome, rank[i].dificuldade, rank[i].pontos);
						}
					}
					else{
						for(i=1; i<posnovojogador; i++){
							fprintf(ranking, "%s %s %d\n", rank[i].nome, rank[i].dificuldade, rank[i].pontos);
						}
					}

					fprintf(ranking, "%s %s %d\n", rank[0].nome, rank[0].dificuldade, rank[0].pontos);

					for(i=i; i<posnovojogador; i++){
						fprintf(ranking, "%s %s %d\n", rank[i].nome, rank[i].dificuldade, rank[i].pontos);
					}
					fclose(ranking);
				}
				//Se a lista estiver cheia, tem que substituir todo o arquivo mas sem o jogador com menor pontuacao, que no caso, SEMPRE vai ser o último jogador, ou seja, sempre vai ser o jogador de elemento 11 (lembrando que 0 é o novo e os jogadores entre 1 e 11 são as posições dos jogadores já registrados)
				else{
					fopen("ranking.txt", "w");
					rewind(ranking);

					if(rank[posnovojogador-1].pontos < pontuacao){
						for(i=1; rank[i].pontos >= pontuacao; i++){
							fprintf(ranking, "%s %s %d\n", rank[i].nome, rank[i].dificuldade, rank[i].pontos);
						}
					}
					else{
						for(i=1; i<posnovojogador; i++){
							fprintf(ranking, "%s %s %d\n", rank[i].nome, rank[i].dificuldade, rank[i].pontos);
						}
					}

					fprintf(ranking, "%s %s %d\n", rank[0].nome, rank[0].dificuldade, rank[0].pontos);

					for(i=i; i<posnovojogador-1; i++){
						fprintf(ranking, "%s %s %d\n", rank[i].nome, rank[i].dificuldade, rank[i].pontos);
					}

					fclose(ranking);
				}
			}

			printf("Aperte qualquer tecla para continuar\n");
    	getchar();
    	getchar();
    }


		//Reseta as variáveis para serem usadas no menu denovo
		aux=0;
		numerocasas=0;
		pontuacao=0;
		posnovojogador=0;
		posicaorelativa=1;
		auxc='a';
	} while (numero!=4);

  return 0;
}


//Função para construir o campo, a base do jogo
void construircampo(int tammaximo, int qntbombas, int campo[][15]){
	int i, linha, coluna;
	int blinha, bcoluna;

	//Inicializar todos os valores como 0
	for(linha=0;linha<tammaximo;linha++){
		for(coluna=0;coluna<tammaximo;coluna++){
			campo[linha][coluna] = 0;
		}
	}

	//Gera bombas aleatórias
	for(i=0;i<qntbombas;i++){
		blinha = rand()%tammaximo;
		bcoluna = rand()%tammaximo;
		campo[blinha][bcoluna] = 9;
	}

	//Colocar os números em volta
	for(linha=0;linha<tammaximo;linha++){
		for(coluna=0;coluna<tammaximo;coluna++){
			if(campo[linha][coluna]>9)
				campo[linha][coluna] = 9;
			if(campo[linha][coluna] == 9){
				if(linha != tammaximo-1){
					campo[linha+1][coluna] = campo[linha+1][coluna] + 1;			//baixo
					if(coluna != tammaximo-1)
						campo[linha+1][coluna+1] = campo[linha+1][coluna+1] + 1;			//baixo-direita
					if(coluna != 0)
						campo[linha+1][coluna-1] = campo[linha+1][coluna-1] + 1;			//baixo-esquerda
				}
				if(linha != 0){
					campo[linha-1][coluna] = campo[linha-1][coluna] + 1;			//cima
					if(coluna != tammaximo-1)
						campo[linha-1][coluna+1] = campo[linha-1][coluna+1] + 1;			//cima-direita
					if(coluna != 0)
						campo[linha-1][coluna-1] = campo[linha-1][coluna-1] + 1;			//cima-esquerda
				}
				if(coluna != tammaximo-1)
					campo[linha][coluna+1] = campo[linha][coluna+1] + 1;			//direita
				if(coluna != 0)
					campo[linha][coluna-1] = campo[linha][coluna-1] + 1;			//esquerda
			}
		}
	}
	//Nessa função anterior, deve haver as restrições, senão o programa tenta definir valores para um elemento que não existe no vetor (por exemplo campo[-1][-1] ou campo[13][13]).

	//Esconde os valores
	for(linha=0;linha<tammaximo;linha++){
		for(coluna=0;coluna<tammaximo;coluna++){
			if(campo[linha][coluna]>9)
				campo[linha][coluna] = 9;
			campo[linha][coluna] = campo[linha][coluna] + 10;
		}
	}


	//A partir daqui, todos os valores serão dez a mais que o valor real; caso na hora de printar o valor do campo seja maior que 10 (em primeiro caso, todos os valores), será impresso apenas um '- '. Quando o usuário escolher uma casa para abrir, simplesmente se subtrai o valor daquela casa por 10; se a casa[linha][coluna] - 10 for igual à 9, então é uma bomba, e o usuário perdeu, senão, será exibido o valor real daquela casa.
}

//Exibe o tabuleiro com a verificação de se o campo está escondido ou não.
void printcampo (int campo[][15], int tammaximo)
{
	int i, linha, coluna;

	system("clear");

	//Esse primeiro for printa o número das colunas
	printf("\n\n    ");
	for(i=0; i<tammaximo; i ++)
    {
		printf("%d ", i+1);
		if(i<9 && tammaximo>9) //Ajusta o espaçamento dependendo do tabuleiro
			printf(" ");
	}
	printf("\n\n");

	//Esse segundo for printa o número das linhas
	for(linha=0;linha<tammaximo;linha++){
		printf("%d  ", linha+1);
		if(linha<9) //Ajusta o espaçamento dependendo do tabuleiro
			printf(" ");
		//Esse terceiro for printa os elementos
		for(coluna=0;coluna<tammaximo;coluna++){
			if(campo[linha][coluna]>=10)
				printf("- ");
       else
				printf("%d ", campo[linha][coluna]);
			if(tammaximo>9) //Ajusta o espaçamento dependendo do tabuleiro
				printf(" ");
			if(coluna == tammaximo-1)
				printf("\n");
		}
	}
}


//Função para mostrar todo o tabuleiro quando o jogador perder, mostrando os valores
//para chamar a função, use showtab(campo, tammaximo);
void showtab(int campo[][15], int tammaximo)
{
	int linha, coluna, i;
	printf("\n\n    ");

	//Esse primeiro for printa o número das colunas
	for(i=0; i<tammaximo; i++){
		printf("%d ", i+1);
		if(i<9 && tammaximo>9) //Ajusta o espaçamento dependendo do tabuleiro
			printf(" ");
	}
	printf("\n\n");

	//Esse segundo for printa o número das linhas
	for(linha=0;linha<tammaximo;linha++){
		printf("%d  ", linha+1);
		if(linha<9)
			printf(" ");
		//Esse terceiro for printa os elementos
		for(coluna=0;coluna<tammaximo;coluna++){
			//Se o campo não foi aberto ainda, será aberto agora:
			if(campo[linha][coluna]>9)
				campo[linha][coluna] = campo[linha][coluna] - 10;
			//Se for 0 printa '-', se não for, printa o elemento
			if(campo[linha][coluna] == 0)
				printf("- ");
			else
				printf("%d ", campo[linha][coluna]);
			if(tammaximo>9)	//Ajusta o espaçamento dependendo do tabuleiro
				printf(" ");
			if(coluna == tammaximo-1)
				printf("\n");
		}
	}
	printf("\n");
}


void abrirzero(int campo[][15], int linhai, int colunai, int tammaximo, int *numcasas, int *pontuacao){
  int i, j, k;
	int pararc=0, pararl=0, parark=0;
  //Abre as casas ao redor da posição escolhida


	//Para baixo e direita
	for(i=linhai; pararl == 0; i++){

		for(j=colunai; pararc == 0; j++){

			for(k=i; parark == 0; k++){
				if(campo[k][j] >= 10){
					campo[k][j] -= 10;
					(*numcasas)++;
					(*pontuacao)++;
          
				}
				if(k == tammaximo-1)
					parark = 1;
				if(campo[k][j] < 10 && campo[k][j] > 0)
					parark = 1;
			}

			parark = 0;
			if(j == tammaximo-1)
				pararc = 1;
			if(campo[i][j] > 0 && campo[i][j] < 10)
				pararc = 1;
		}

		parark = 0;
		pararc = 0;
		if(i == tammaximo-1)
			pararl = 1;
		if(campo[i+1][colunai] > 0 && campo[i+1][colunai] != 10){
			pararl = 1;
    }
	}

	pararl = 0;
	pararc = 0;
	parark = 0;
	//Para baixo e esquerda
	for(i=linhai; pararl == 0; i++){

		for(j=colunai; pararc == 0; j--){

			for(k=i; parark == 0; k++){
				if(campo[k][j] >= 10){
					campo[k][j] -= 10;
					(*numcasas)++;
          (*pontuacao)++;
				}
				if(k == tammaximo-1)
					parark = 1;
				if(campo[k][j] < 10 && campo[k][j] > 0)
					parark = 1;
			}

			parark = 0;
			if(j == 0)
				pararc = 1;
			if(campo[i][j] > 0 && campo[i][j] < 10)
				pararc = 1;
		}

		parark = 0;
		pararc = 0;
		if(i == tammaximo-1)
			pararl = 1;
		if(campo[i+1][colunai] > 0 && campo[i+1][colunai] != 10)
			pararl = 1;
	}

	pararl = 0;
	pararc = 0;
	parark = 0;
	//Para cima e direita
	for(i=linhai; pararl == 0; i--){

		for(j=colunai; pararc == 0; j++){

			for(k=i; parark == 0; k--){
				if(campo[k][j] >= 10){
					campo[k][j] -= 10;
					(*numcasas)++;
          (*pontuacao)++;
				}
				if(k == 0)
					parark = 1;
				if(campo[k][j] < 10 && campo[k][j] > 0)
					parark = 1;
			}

			parark = 0;
			if(j == tammaximo-1)
				pararc = 1;
			if(campo[i][j] > 0 && campo[i][j] < 10)
				pararc = 1;
		}

		parark = 0;
		pararc = 0;
		if(i == 0)
			pararl = 1;
		if(campo[i-1][colunai] > 0 && campo[i-1][colunai] != 10)
			pararl = 1;
	}

	pararl = 0;
	pararc = 0;
	parark = 0;
	//Para cima e direita
	for(i=linhai; pararl == 0; i--){

		for(j=colunai; pararc == 0; j--){

			for(k=i; parark == 0; k--){
				if(campo[k][j] >= 10){
					campo[k][j] -= 10;
					(*numcasas)++;
          (*pontuacao)++;
				}
				if(k == 0)
					parark = 1;
				if(campo[k][j] < 10 && campo[k][j] > 0)
					parark = 1;
			}

			parark = 0;
			if(j == 0)
				pararc = 1;
			if(campo[i][j] > 0 && campo[i][j] < 10)
				pararc = 1;
		}

		parark = 0;
		pararc = 0;
		if(i == 0)
			pararl = 1;
		if(campo[i-1][colunai] > 0 && campo[i-1][colunai] != 10)
			pararl = 1;
	}
}