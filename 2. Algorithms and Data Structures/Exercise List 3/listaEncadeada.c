// TAD para Lista Dinâmica Encadeada baseado no livro "Estrutura de dados descomplicada em lingugem C (André Backes)"

#include <stdio.h>
#include <stdlib.h>
#include <string.h> //para strcpy()
#include "listaEncadeada.h"


typedef struct aluno{
int matricula;
char nome[30];
float nota;
struct aluno* prox;
} aluno;

// função para alocar memória do tipo Lista
Lista* criar_lista()
{
  Lista *li = (Lista*) malloc(sizeof(Lista));  

  // se a lista foi criada corretamente, indica que ela está vazia
  if(li != NULL){
    *li = NULL;
  } 

  return li;
}


// função para liberar memória
int liberar_lista(Lista *li)
{
  if(li == NULL){
    return 0;
  }

  // libera todos os nós da lista que foram alocados
  aluno* no;
  while(*li != NULL){
    no = *li;
    *li = (*li)->prox;
    free(no);
  }

  // libera o ponteiro da lista
  free(li);

  return 1;  
}

// função para obter o tamanho da lista
int tamanho_lista(Lista* li)
{
  // a lista não foi criada corretamente
  if(li == NULL){
    return 0;
  }

  int cont = 0;
  aluno* no = *li;

  // acrescenta cont até acabar a lista
  while(no != NULL){
    cont++;
    no = no->prox;
  }

  return cont;
}

// função para verificar se a lista está vazia
int lista_vazia(Lista *li)
{
  // verifica se houve problema na criação da lista
  // ou seja, li não é uma lista válida
  if(li == NULL){
    return -1;
  }

  // verifica se a lista foi criada corretamente
  // mas não contém nenhum valor
  if(*li == NULL){
    return 1;
  }

  // se houver elementos, retorna 0
  return 0;
}


// função para verificar se a lista está cheia (não se aplica)
int lista_cheia(Lista *li)
{
  return 0;
}


// função para alocar memória do tipo Elemento
aluno* criar_elemento()
{
  aluno* no = (aluno*) malloc(sizeof(aluno));  

  return no;
}


// função para inserir elemento no início da lista
int inserir_lista_inicio(Lista *li, aluno* elemento)
{
  if(li == NULL){
    return 0;
  }

  // cria um elemento novo
  aluno* no;
  no = criar_elemento();

  if(no == NULL){
    return 0;
  }

  // atribui valores ao elemento novo
  no->matricula = elemento->matricula;
  strcpy(no->nome, elemento->nome); 
  no->nota = elemento->nota;
  no->prox = (*li);

  // insere elemento no início da lista
  *li = no;

  return 1;
}


// função para inserir elemento no final da lista
int inserir_lista_final(Lista *li, aluno* elemento)
{
  if(li == NULL){
    return 0;
  }

  // cria um elemento novo
  aluno* no;
  no = criar_elemento();

  if(no == NULL){
    return 0;
  }

  // atribui valores ao elemento novo
  no->matricula = elemento->matricula;
  strcpy(no->nome, elemento->nome); 
  no->nota = elemento->nota;
  no->prox = NULL;

  // se a lista estiver vazia, insere no início da lista
  if( (*li) == NULL ){
    *li = no;

  }else{

    // senão percorre a lista até o fim e insere no final
    aluno* aux;
    aux = *li;

    while(aux->prox != NULL){
      aux = aux->prox;
    }
    aux->prox = no;
  }

  return 1;
}


// função para inserir elemento na lista de forma ordenada
int inserir_lista_ordenada(Lista *li, aluno* elemento)
{
  if(li == NULL){
    return 0;
  }

  // cria um elemento novo
  aluno* no;
  no = criar_elemento();

  if(no == NULL){
    return 0;
  }

  // atribui valores ao elemento novo
  no->matricula = elemento->matricula;
  strcpy(no->nome, elemento->nome); 
  no->nota = elemento->nota;

  // se a lista estiver vazia, insere no início da lista
  if( (*li) == NULL ){
    no->prox = NULL;
    *li = no;

  }else{

    // senão percorre a lista até achar o local correto e insere
    aluno* anterior; 
    aluno* atual;
    atual = *li;

    while(atual != NULL && atual->matricula < elemento->matricula){
      anterior = atual;
      atual = atual->prox;
    }
    
    // insere na primeira posição
    if( atual == (*li) ){
      no->prox = (*li);
      *li = no;

    }else{
      no->prox = atual;
      anterior->prox = no;
    }
  }

  return 1;
}


// função para remover elemento do início da lista
int remover_lista_inicio(Lista *li)
{
  if(li == NULL){
    return 0;
  }

  // lista vazia, não remove nada
  if((*li) == NULL){
    return 0;
  }

  // muda inicio para o proximo elemento
  aluno* atual;
  atual = *li;
  *li = atual->prox;

  // libera Elemento atual
  free(atual);

  return 1;
}


// função para remover elemento do final da lista
int remover_lista_final(Lista *li)
{
  if(li == NULL){
    return 0;
  }

  // lista vazia, não remove nada
  if((*li) == NULL){
    return 0;
  }

  // percorre lista até o final
  aluno* anterior;
  aluno* atual;
  atual = *li;
  
  while(atual->prox != NULL){
    anterior = atual;
    atual = atual->prox;
  }

  // remove o primeiro elemento, se este for o único da lista
  if(atual == (*li)){ 
    *li = atual->prox;  

  }else{
    anterior->prox = atual->prox;
  }

  //libera Elemento atual
  free(atual);

  return 1;

}


// função para remover elemento do meio da lista
int remover_lista_meio(Lista *li, int matricula)
{
  if(li == NULL){
    return 0;
  }

  // lista vazia, não remove nada
  if((*li) == NULL){
    return 0;
  }

  // percorre a lista até achar o elemento e remove
  aluno* anterior;
  aluno* atual;
  atual = *li;

  while(atual != NULL && atual->matricula != matricula){
    anterior = atual;
    atual = atual->prox;
  }

  // elemento não foi encontrado
  if(atual == NULL){
    return 0;
  }

  // remove o primeiro elemento
  if(atual == (*li)){
    *li = atual->prox;

  }else{
    anterior->prox = atual->prox;
  }

  //libera Elemento atual
  free(atual);
  return 1;

}

int buscar_lista_posicao(Lista *li, int pos)
{
  // verifica se a lista foi criada corretamente, se não está vazia e se a posição é válida (note que é a posição na lista e não o índice do vetor)
  if(li == NULL || (*li) == NULL || pos <= 0){
    printf("\nLista nao existe ou esta vazia!\nTecle enter para retornar...");
    getchar();
    getchar();
    return 0;
  }

  aluno* no = *li;
  int i = 1;

  while(no != NULL && i < pos){
    no = no->prox;
    i++;
  }

  // posição não existe na lista
  if(no == NULL){
    printf("\nPosicao nao encontrada!\nTecle enter para retornar...");
    getchar();
    getchar();
    return 0;
  }

  // imprime as informacoes, uma vez que a struct nao pode ser acessada da main
  printf("\nElemento da posicao %d da lista:", pos);
  printf("\nMatricula: %d", no->matricula);
  printf("\nNome: %s", no->nome);
  printf("\nNota: %f", no->nota);

  printf("\n\nTecle enter para continuar...");
  getchar();
  getchar();

  return 1;
}


int buscar_lista_dado(Lista *li, int matricula)
{
  // verifica se a lista foi criada corretamente
  if(li == NULL || (*li) == NULL){
    printf("\nLista nao existe ou esta vazia!\nTecle enter para retornar...");
    getchar();
    getchar();
    return 0;
  }

  // procura a posição no vetor onde o dado desejado se encontra
  aluno* no = *li;
  int i = 1;

  //varre ate encontrar item com matricula igual
  while(no != NULL && no->matricula != matricula){
    no = no->prox;
    i++;
  }
  
  // verifica se elemento não foi encontrado 
  if(no == NULL){ 
    printf("\nPosicao nao encontrada!\nTecle enter para retornar...");
    getchar();
    getchar();
    return 0;
  }

  // imprime as informacoes, uma vez que a struct nao pode ser acessada da main
  printf("\nElemento encontrado na %da posicao da lista:", i);
  printf("\nMatricula: %d", no->matricula);
  printf("\nNome: %s", no->nome);
  printf("\nNota: %f", no->nota);

  printf("\n\nTecle enter para continuar...");
  getchar();
  getchar();

  return 1;
}



//**************************************************************************
// função para imprimir a lista dinâmica
int imprimir_lista(Lista *li)
{

    if(li == NULL || (*li) == NULL){
      return 0;
    }

    aluno* aux = (*li);
    int count = 1;

    while(aux->prox != NULL){
      printf("\n\n%d Aluno", count);
      printf("\nMatricula: %d\nNome: %s\nNota: %.2f", aux->matricula, aux->nome, aux->nota);
      count++;
      aux = aux->prox;
    }

    printf("\n\n%d Aluno", count);
    printf("\nMatricula: %d\nNome: %s\nNota: %.2f", aux->matricula, aux->nome, aux->nota);

    printf("\n\nFim da lista.\n\nTecle enter para retornar...");
    getchar();
    getchar();

    return 1;
}



Lista* concatenaLista(Lista* lista1, Lista* lista2) {

  //#include <inefficiency.h>

  //Checar listas 
  if(lista1 == NULL || (*lista1) == NULL){
    printf("\n\nPrimeira lista nao existe ou esta vazia.\nTecle enter para continuar...");
    getchar();
    getchar();
    return 0;
  }
  if(lista2 == NULL || (*lista2) == NULL){
    printf("\n\nSegunda lista nao existe ou esta vazia.\nTecle enter para continuar...");
    getchar();
    getchar();
    return 0;
  }

  //Alocar a terceira lista
  Lista* terceira = criar_lista();
  if(terceira == NULL){
    printf("Sem memoria.\nTecle enter para continuar...");
    getchar();
    getchar();
    return 0;
  }

  aluno* primeira = *lista1;
  aluno* segunda = *lista2;

  while(primeira != NULL && segunda != NULL) {

    //lembrar de alterar a entrada das listas 
    inserir_lista_final(terceira, primeira);
    inserir_lista_final(terceira, segunda);

    //atualizar
    primeira = primeira->prox;
    segunda = segunda->prox;
  }

  /*Vale lembrar que o uso da funcao de inserir no fim e pratico, mas por ter que percorrer toda a lista, caberia aqui uma implementacao mais eficiente, que armazenasse o ultimo item da lista 3 para continuar as insercoes.*/

  //uma ou ambas as listas atingiram o fim
  //caso uma ianda tiver mais itens, insira o restante
  if(primeira != NULL){
    //inserir o restante
    while(primeira != NULL){
      inserir_lista_final(terceira, primeira);
      primeira = primeira->prox;
    }
    inserir_lista_final(terceira, primeira);
  }
  if(segunda != NULL){
    //inserir o restante
    while(segunda != NULL){
      inserir_lista_final(terceira, segunda);
      segunda = segunda->prox;
    }
    inserir_lista_final(terceira, segunda);
  }

  return terceira;
}



Lista* removeRepetidos(Lista* lista){

  //#include <inefficiency.h>

  //Checar lista 
  if(lista == NULL || (*lista) == NULL){
    printf("\n\nLista nao existe ou esta vazia.\nTecle enter para retornar...");
    getchar();
    getchar();
    return 0;
  }

  //criar nova lista e checar
  Lista* nova = criar_lista();
  if(nova == NULL){
    printf("Sem memoria.\nTecle enter para retornar...");
    getchar();
    getchar();
    return 0;
  }

  aluno* item = *lista;
  aluno* checagem;
  aluno* ultimo;
  int check = 0;

  //dois loops while, o interior compara o atual do exterior com todos os itens
  while(item != NULL){

    //inserir o elemento no final
    if(*nova == NULL){  //se for o primeiro item
      //colocar no inicio
      *nova = item;
      //e salvar o endereco
      ultimo = item;
    }
    else{ //inserir no ultimo item da nova lista
      ultimo->prox = item;
    }

    //comecar a comparar a partir do atual
    checagem = item;

    //checar todos para cada item da lista
    while(checagem != NULL){

      //se houver algum igual dentro da mesma lista
      if(item->matricula == checagem->matricula && item != checagem){

        //remova-o
        remover_lista_meio(lista, item->matricula); //poderia ter feito manualmente aqui...
        check++;  //para determinar se haviam repetidos
      }

      //atualizar para checar todos
      checagem = checagem->prox;
    }

    //avancar para o proximo item
    item = item->prox;
  }

  printf("\n\nLimpeza concluida com sucesso! %d itens removidos.\nTecle enter para continuar...", check);
  getchar();
  getchar();

  return nova;
}


//recebe lista e retorna nova invertida
Lista* inverteLista(Lista* lista){

  //Checar lista 
  if(lista == NULL || (*lista) == NULL){
    printf("\n\nLista nao existe ou esta vazia.\nTecle enter para continuar...");
    getchar();
    getchar();
    return 0;
  }

  //alocar a nova lista e checar
  Lista* nova = criar_lista();
  if(nova == NULL){
      printf("Sem memoria.\nTecle enter para continuar...");
      getchar();
      getchar();
      return 0;
  }

  //declarar variaveis temporarias
  aluno* velha = *lista;
  aluno* temp;

  //enquanto nao atingir o fim da velha lista, insira no inicio da nova
  while(velha != NULL){
   
    temp = velha->prox; //para nao perder o endereco do proximo na lista 1
    velha->prox = *nova;
    *nova = velha;
    velha = temp;
  }

  //a funcao reposiciona os enderecos de proximo dos itens ja existentes, e portanto a lista original fica inutilizada
  free(lista);


  return nova; 
}



int checaOrdenacao(Lista* lista){

  //Checar lista 
  if(lista == NULL || (*lista) == NULL){
    printf("\n\nLista nao existe ou esta vazia.\nTecle enter para continuar...");
    getchar();
    getchar();
    return 0;
  }
  
  //perguntar se deve checar se e crescente ou decrescente
  int escolha;

  do{
  printf("\nGostaria de checar por:");
  printf("\n1. Lista crescente");
  printf("\n2. Lista decrescente");
  printf("\nEscolha: ");
  scanf("%d", &escolha);
  }while(escolha != 1 && escolha != 2);

  //checar se e decrescente
  if(escolha == 2) {
    //comparar a lista par a par se ha uma desigualdade do tipo nao desejado
    for(aluno*atual = *lista; atual->prox != NULL; atual = atual->prox){
      
      //se houver, nao esta ordenada
      if(atual->matricula < atual->prox->matricula){
        printf("\nA lista nao esta ordenada decrescentemente.\nTecle enter para retornar...");
        getchar();
        getchar();
        return 1;
      }
    }

    //se o fim do loop foi atingido, esta ordenada
    printf("\nA lista esta ordenada decrescentemente.\nTecle enter para retornar...");
    getchar();
    getchar();
    return 1;
    
  } else {
    //checar se e decrescente
    if(escolha == 1){
      
      for(aluno*atual = *lista; atual->prox != NULL; atual = atual->prox){

        if(atual->matricula > atual->prox->matricula){
          printf("\nA lista nao esta ordenada crescentemente.\nTecle enter para retornar...");
          getchar();
          getchar();
          return 1;
        }
      }
      printf("\nA lista esta ordenada crescentemente.\nTecle enter para retornar...");
      getchar();
      getchar();
      return 1;

    }
  }

  //caso de algo der errado (para evitar o warning do compilador)
  return -1;
}


//calcula o tamanho de uma lista recursivamente
int calculaTamanho(aluno* atual){
  //deve receber o primeiro elemento para facilitar a recursao

  //Checar lista 
  if(atual == NULL){
    printf("\n\nLista esta vazia.\nTecle enter para continuar...");
    getchar();
    getchar();
    return 0;
  }

  //condicao de parada
  if(atual->prox == NULL){
    return 1;
  }

  //se nao for o ultimo, passe o proximo
  return 1 + calculaTamanho(atual->prox);

  //aqui nao sei se "1+calc" ou "calc+1" faria muita diferenca
}



int calculaTamanhoMindBlownEdition(Lista* lista){

  //Se lista nao existe, o tamanho e zero
  //o mesmo vale para uma lista existente, mas vazia
  if(lista == 0 || *lista == 0){
    return 0;
  }

  aluno* temp = *lista;

  //total mind blown ("&temp->prox" equivale ao tipo Lista*)
  return 1 + calculaTamanhoMindBlownEdition(&temp->prox);
}

aluno* criar_dado(aluno* elemento){

    elemento = (aluno*) malloc(sizeof(aluno));

    if(elemento == NULL){
      return 0;
    }

    printf("\nDigite a matricula do aluno: ");
    scanf("%d", &elemento->matricula);
    printf("\nAgora insira o nome do aluno: ");
    scanf(" %[^\n]", elemento->nome);
    printf("\nPor fim, digite a nota: ");
    scanf("%f", &elemento->nota);

    return elemento;
}
