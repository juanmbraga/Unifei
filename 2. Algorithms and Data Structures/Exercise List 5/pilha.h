typedef struct descritor Pilha;               


// Funcao para criar uma pilha
Pilha* criarPilha();
//retornos: NULL= erro, !NULL= sucesso

// Funcao para liberar um vetor de tres pilhas
int liberarPilhas(Pilha* pilha[]);

// Retorna o numero de elementos na pilha
int tamanhodaPilha(Pilha* pilha);
//retornos: -1= nao existe, outros: tamanho

// Funcao para inserir na pilha (sem checagem, apenas para o inicio)
int empilhar(Pilha* pilha, char dado);
//retornos: 0= sucesso, 1= fora de ordem, -1= nao existe ou erro ao alocar

// Funcao para retirar o primeiro item da pilha
char desempilhar(Pilha* pilha);
//retornos: 0= vazia ou inexistente, !0= letra retirada (sucesso)

// Consultar o primeiro item da pilha
char consultarTopoPilha(Pilha* pilha);
//retornos: a decidir

// Confere a ordem e tranfere letra de uma pilha para outra
int transferir(Pilha* entrega, Pilha* recebe);
//retornos: 0= sucesso, 1= fora de ordem, 2= mesma pilha, -1= nao existe
//(nao e preciso checar se estiver cheia, uma vez que so existem cinco letras)

// Imprime os elementos de tres pilhas da maneira pedida pelo exercicio
void imprimePilhas(Pilha* pilha);

// simplificar interacao
void pausa();

