#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dequeDinamico.h"

// Registro de cada paciente 
typedef struct elemento{
  struct elemento *ant;
  struct elemento *prox;
  char dado[50];
}Elemento;

// Registro do no descritor do Deque
struct deque{
  struct elemento *inicio;
  struct elemento *fim;
  int quant;
};

// função para alocar memória do tipo Elemento
Elemento* criar_elemento()
{
    return (Elemento*) malloc(sizeof(Elemento));
}

//função para liberar a memória alocada para o deque
int liberar_deque(Deque **deq){
  
  // Checar se a variavel na main possui algum deque salvo
  if(*deq==NULL){
    return 0;
  }
  
  // Liberar todos os elementos
  Deque* deque = *deq;
  Elemento *no;

  while(deque -> inicio != NULL) {
    no = deque -> inicio;
    deque -> inicio = deque -> inicio -> prox;
    free(no);
  }
  
  // Liberar no descritor
  free(*deq);

  // Definir variavel na função principal como vazia
  *deq = NULL;
    
  return 1;
}

//função para verificar o tamanho do deque
int tamanho_deque(Deque* deq){
  // Se deque nao estiver alocado
  if (deq == NULL){
    return -1;
  }  
  // Retorna a quantidade
  return deq->quant;
}

//função para consultar o início da fila
int consultar_inicio_deque(Deque *deq, char *nome){
  // Se deque não existir
  if (deq == NULL){
    return 0;
  }

  // Se deque estiver vazio
  if (deq->inicio == NULL){
    return 0;
  }

  // Consulta o primeiro valor
  strcpy(nome, deq->inicio->dado);
  return 1;
}

//função para consultar o fim da fila
int consultar_fim_deque(Deque *deq, char *nome){
  // Se deque não existir
  if (deq == NULL){
    return 0;
  }

  // Se deque estiver vazio
  if (deq->fim == NULL){
    return 0;
  }

  // Consulta o último valor
  strcpy(nome, deq->fim->dado);
  return 1;
}

//função para inserir paciente no início da fila
int insere_inicio_deque(Deque* deq, char *nome){

  // Verifica se o deque existe
  if (deq == NULL){
    return 0;
  }

  Elemento *no;
  no = criar_elemento();
  
  if(no == NULL){
    return 0;
  }

  strcpy(no->dado, nome);
  no->prox = deq->inicio;
  no->ant = NULL;

  //se não houver elementos no deque
  if(deq->inicio == NULL){
    deq->fim = no;

  }else{

    deq->inicio->ant = no;
  }

  deq->inicio = no;
  deq->quant++;
  
  return 1;
  }

//função para inserir paciente no fim do deque
int insere_fim_deque(Deque *deq, char *nome){

  //Verifica se o deque existe
  if (deq == NULL)
    return 0;

    Elemento *no;

    no = criar_elemento();

    if (no == NULL) {
      return 0;
    }
    
    strcpy(no->dado, nome);
    no -> prox = NULL;
    
    if (deq -> fim == NULL) {
      no -> ant = NULL;
      deq -> inicio = no;
    }
    else{
    no -> ant = deq -> fim;
    deq -> fim -> prox = no;
  }

    deq -> fim = no;
    deq -> quant ++;

    return 1;
  
}

//função para remover paciente no início do deque
int remove_inicio_deque(Deque* deq){

  // Checa se deque existe
  if(deq == NULL){
    return 0;
  }

  // Checa se está vazio
  if(deq->quant == 0){
    return 0;
  }

  // Busca o segundo elemento e libera o primeiro
  Elemento* elemento = deq->inicio;
  deq->inicio = deq->inicio->prox;

  if(deq->inicio == NULL){
    // Torna nulos os ponteiros do descritor
    deq->fim = NULL;
  }
  else {
    // Indica o ponteiro para anterior como NULL
    deq->inicio->ant = NULL;
  }

  // Libera a memoria e diminui a quantidade
  free(elemento);
  deq->quant--;

  return 1;  
}

//função para remover paciente do fim da fila
int remove_fim_deque(Deque *deq){

  //Checa se o deque existe
  if (deq == NULL)
    return 0;

  //Checa se o deque está vazio
   if (deq -> inicio == NULL) {
      return 0;
    }

    Elemento *no = deq -> fim;
    
    if (no == deq -> inicio) {
      deq -> inicio = NULL;
      deq -> fim = NULL;
    }
    else{
    no -> ant -> prox = NULL;
    deq -> fim = no -> ant;
  }

    //Libera a memória do nó e diminui a quantidade do deque
    free(no);
    deq->quant--;

    return 1;
}

//função para imprimir a fila
void imprimir_deque(Deque* deq){

  int counter = 1;
  
  printf("\n");

  // Checa se o deque existe
  if(deq == NULL){
    printf("Fila não existe!");
    printf("\n\nPressione enter para continuar.");
    getchar();
    getchar();
    return;
  }

  // Checa se está vazia
  if(deq->quant == 0){
    printf("Fila está vazia!");
    printf("\n\nPressione enter para continuar.");
    getchar();
    getchar();
    return;
  }

  // Imprime os elementos ate atingir o final
  Elemento* atual = deq->inicio;

  while(atual != NULL){
    printf("\n%d- ", counter);
    printf("%s", atual->dado);
    atual = atual->prox;

    //para imprimir a posição do paciente na fila
    counter++;
  }
  
  printf("\n\nFim da fila.");
  printf("\n\nPressione enter para continuar.");
  getchar();
  getchar();


  return;
}

//função para criar a lista a partir de um arquivo
Deque* gera_deque (){

  Deque* deq = (Deque*) malloc(sizeof(Deque));
  if (deq != NULL){
    deq->fim=NULL;
    deq->inicio=NULL;
    deq->quant=0;
  }
  
  //dados temporarios
  char leitura[50];  
  Elemento *atual = NULL;
  int aux;

  //tentar abrir arquivo
  FILE* arquivo = fopen("fila.txt", "r");
 
  //checar se o arquivo foi aberto corretamente
  if (arquivo == NULL){
    printf("Erro na abertura do arquivo.\nTecle enter para continuar...");
    getchar();
    getchar();
    return NULL;
  }

  //checar se arquivo existe
  if(feof(arquivo)){
    printf("Arquivo está vazio.\nTecle enter para retornar...");
    getchar();
    getchar();
    return 0;
  }

  //enquanto não atingir o fim do arquivo
  while (!feof(arquivo)) {
    
    //Lemos uma linha do arquivo (no maximo 50 caracteres)
    fgets(leitura, 50, arquivo);
    
    //Como a função fgets() faz com que o '\n' faça parte da string, usamos a função abaixo para localizar a posição dele na string.
    aux = strcspn(leitura, "\n");
    
    //Excluimos o '\n', substituindo-o por um caractere nulo
    leitura[aux] = 0;

    //alocar novo item
    atual = (Elemento*) malloc(sizeof(Elemento));  

    //checar alocacao
    if(atual == NULL) {
      printf("\nErro de alocação");
      return NULL;
    }

    insere_fim_deque(deq, leitura);

  }
  
  fclose(arquivo); //fecha o arquivo

  printf("\nFila de atendimento gerada com sucesso!\n\nTecle enter para continuar...");
  getchar();
  getchar();
  
  return deq;
}
