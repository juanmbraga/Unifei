/*
//system("clear");
void novoabrirzero(int campo[][15], int tammaximo, int linha, int coluna, int *numerocasas, int *pontuacao){
	if(linha != 0){ //Para ir para esquerda não pode estar na borda
		if(campo[linha-1][coluna] >= 10){ //Se a casa da esquerda estiver fechada
			campo[linha-1][coluna] -= 10; //Abre a casa à esquerda
			(*numerocasas)++;
			(*pontuacao)++;
		}
		if(campo[linha-1][coluna] == 0){ //Se a casa à esquerda for um 0, deve passar pra ele
			novoabrirzero(campo, tammaximo, linha-1, coluna, numerocasas, pontuacao);
		}
		//Se a casa à esquerda não for igual à 0, ele simplesmente vai pular a parte da esquerda e passar pras outras direções.
	}

	if(linha != tammaximo-1){ //Para ir para direita não pode estar na borda
		if(campo[linha+1][coluna] >= 10){ //Se a casa da direita estiver fechada
			campo[linha+1][coluna] -= 10; //Abre a casa à direita
			(*numerocasas)++;
			(*pontuacao)++;
		}
		if(campo[linha+1][coluna] == 0){ //Se a casa à direita for um 0, deve passar pra ele
			novoabrirzero(campo, tammaximo, linha+1, coluna, numerocasas, pontuacao);
		}
		//Se a casa à direita não for igual à 0, ele simplesmente vai pular a parte da direita e passar pras outras direções.
	}

	if(coluna != 0){ //Para ir para cima não pode estar na borda
		if(campo[linha][coluna-1] >= 10){
			campo[linha][coluna-1] -= 10;
			(*numerocasas)++;
			(*pontuacao)++;
		}
		if(campo[linha][coluna-1] == 0){
			novoabrirzero(campo, tammaximo, linha, coluna-1, numerocasas, pontuacao);
		}
	}

	if(coluna != tammaximo-1){ //Para ir para baixo não pode estar na borda
		if(campo[linha][coluna+1] >= 10){
			campo[linha][coluna+1] -= 10;
			(*numerocasas)++;
			(*pontuacao)++;
		}
		if(campo[linha][coluna+1] == 0){
			novoabrirzero(campo, tammaximo, linha, coluna+1, numerocasas, pontuacao);
		}
	}	
}
*/