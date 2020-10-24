#include <stdio.h>
#include <stdlib.h>
#include "listaHeterogenea.h"

struct elemento{
  int tipo;
  void *info;
  struct elemento *prox;  
};

//função para criar a lista a partir de um arquivo
elemento* geralista (){

  //dados temporarios
  int tipo; 
  float a, b, c;  //dados do solido
  char leitura[100];  
  elemento *atual = NULL, *primeiro = NULL, *anterior = NULL;
  char lixo;

  //tentar abrir arquivo
  FILE* arquivo = fopen("lista.txt", "r");
 
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

    fgets(leitura, 100, arquivo);

    //alocar novo item
    atual = (elemento*) malloc(sizeof(elemento));  

    //checar alocacao
    if(atual == NULL) {
      erro(1);
      return NULL;
    }

    //ler do arquivo de leitura pelos dados
    sscanf(leitura, "%c%c%c%c %d %f %f %f", &lixo, &lixo, &lixo, &lixo, &tipo, &a, &b, &c);

    //trabalhar com os dados baseado no tipo
    switch (tipo) {
      case CIL: //cilindro
        atual->tipo = tipo;  //associa o tipo a variavel
        cilindro* cil = (cilindro*) malloc(sizeof(cilindro));
        if (cil == NULL){
          erro(1);
          return NULL;
        }
        cil->r = a;
        cil->h = b;
        atual->info = cil;

      break;
      
      case CUB:
        atual->tipo = tipo;
        cubo* cub = (cubo*) malloc(sizeof(cubo));
        if (cub == NULL){
          erro(1);
          return NULL;
        }
        cub->a = a;
        atual->info = cub;
      break;

      case ESF:
        atual->tipo = tipo;  //associa o tipo a variavel
        esfera* esf = (esfera*) malloc(sizeof(esfera));
        if (esf == NULL){
          erro(1);
          return NULL;
        }
        esf->r = a;
        atual->info = esf;
      break;
      
      case CONE:
        atual->tipo = tipo;  //associa o tipo a variavel
        cone* con = (cone*) malloc(sizeof(cone));
        if (con == NULL){
          erro(1);
          return NULL;
        }
        con->r = a;
        con->h = b;
        atual->info = con;
      break;
      
      case PARA:
        atual->tipo = tipo;  //associa o tipo a variavel
        paral* par = (paral*) malloc(sizeof(paral));
        if (par == NULL){
          erro(1);
          return NULL;
        }
        par->c = a;
        par->l = b;
        par->h = c;
        atual->info = par;
      break;
    }

    atual->prox = NULL;

    //checar se não é o primeiro
    if(primeiro != NULL) {
      anterior->prox = atual;
    }
    
    //checar se for o primeiro item, e colocar no primeiro
    if(primeiro == NULL){
      primeiro = atual;
    }

    anterior = atual; 

  }
  
  fclose(arquivo); //fecha o arquivo

  printf("\n\nLista gerada com sucesso!\nTecle enter para continuar...");
  getchar();
  getchar();
  
  return primeiro;
}

//função para liberar a lista
int liberar_lista (elemento **li) {

  //Se a lista ou o ponteiro da lista for nulo não fazer nada
  if(li == NULL || *li == NULL){
    return 0;
  }

  elemento *atual = *li;
  elemento *prox;

  while (atual != NULL) {
    prox = atual -> prox;
    free(atual->info);  //liberar o struct com os dados
    free (atual);
    atual = prox;
  }

  //libera o ponteiro da lista
  *li = NULL;

  return 1;
}

//funçaõ para o usuário escolher a forma geométrica
int selecionaForma (){
  int control;

  do {
    printf("\n\nSelecione o solido:");
    printf("\n1. Cilindro");
    printf("\n2. Cubo");
    printf("\n3. Esfera");
    printf("\n4. Cone");
    printf("\n5. Paralelepipedo");
    printf("\n\nOpcao: ");
    scanf("%d", &control);
  } while (control != 1 && control != 2 && control != 3 && control != 4 && control != 5);

  control--;

  switch (control) {
    case CIL: 
      return 0;
    break; 
    case CUB:
      return 1;
    break;
    case ESF:
      return 2;
    break;
    case CONE:
      return 3;
    break;
    case PARA:
      return 4;
    break;
    default:
      return -1;

  }
}

//função para criar um elemento baseado na forma geométrica
elemento* criaElemento (int forma) {

  elemento* no = (elemento*) malloc(sizeof(elemento));

  if(no == NULL) {
    erro(1);
    return NULL;
  }
      
  switch (forma) {
    case CIL:
      no = cria_cilindro();
      if(no == NULL) {
        erro(1);
        return NULL;
      }
      printf("\nAlocacao bem sucedida!");
      return no;
    break;
    
    case CUB:
      no = cria_cubo(); 
      if(no == NULL) {
        erro(1);
        return NULL;
      }
      printf("\nAlocacao bem sucedida!");
      return no;
    break;

    case ESF:
      no = cria_esfera();
      if(no == NULL) {
        erro(1);
        return NULL;
      }
      printf("\nAlocação bem sucedida!");
      return no;
    break;
    
    case CONE:
      no = cria_cone();
      if(no == NULL) {
        erro(1);
        return NULL;
      }
      printf("\nAlocação bem sucedida!");
      return no;
    break;
    
    case PARA:
      no = cria_paral();
      if(no == NULL) {
        erro(1);
        return NULL;
      }
      printf("\nAlocação bem sucedida!");
      return no;
    break;
    
    default:{ 
      printf("\nOpção inválida.\nTecle enter para continuar...");
      getchar();
      getchar();
      return NULL;
    }
  }
}

//função para inserir o elemento no começo da lista
int inserirInicio(elemento** li, int forma)
{

  //se a lista não existe, não fazer nada
  if(li == NULL){
    erro(2);
    return 0;
  }
  elemento *no;
  no = criaElemento(forma);
  
  //se o ponteiro da lista está vazio, é possivel inserir diretamente
  if(*li == NULL){
    *li = no;
    printf("\nInserção bem sucedida.\nTecle enter para continuar...");
    getchar();
    getchar();
    return 0;
  }

  if(no == NULL){
    return 0;
  }

  no->prox = *li;

  // insere elemento no início da lista
  *li = no;
  printf("\nInserçaõ bem sucedida.\nTecle enter para continuar...");
  getchar();
  getchar();

  return 1;
}

// função para inserir elemento no final da lista
int inserirfinal(elemento** li, int forma)
{
  elemento *item;
  if(item == NULL){
    return 0;
  }

  // cria um elemento novo
  elemento *no;
  no = criaElemento(forma);

  if(no == NULL){
    return 0;
  }

  // atribui valores ao elemento novo
  no-> tipo = forma;
  no->prox = NULL;

  // se a lista estiver vazia, insere no início da lista
  if( *li == NULL ){
    *li = item;
    printf("\nInserção bem sucedida.\nTecle enter para continuar...");
    getchar();
    getchar();

  }else{

    // senão percorre a lista até o fim e insere no final
    elemento *aux;
    aux = *li;

    while(aux->prox != NULL){
      aux = aux->prox;
    }
    aux->prox = no;

    printf("\nInsercao bem sucedida.\nTecle enter para continuar...");
    getchar();
    getchar();
  
  }
  
  return 1;
}

//função para remover elemento do início da lista
int removeInicio(elemento** li){

  // lista vazia, não remove nada
  if(*li == NULL){
    erro(2);
    return 0;
  }

  // muda inicio para o proximo elemento
  elemento *atual;
  atual = *li;
  *li = atual->prox;
    printf("\nRemoção bem sucedida.\nTecle enter para continuar...");
    getchar();
    getchar();

  // libera Elemento atual
  free(atual);

  return 1;
}

//função para remover elemento do fim da lista
int removeFim(elemento** li){
  
  // lista vazia, não remove nada
  if(*li == NULL){
    erro(2);
    return 0;
  }

  // percorre lista até o final
  elemento *anterior, *atual;
  atual = *li;
  
  while(atual->prox != NULL){
    anterior = atual;
    atual = atual->prox;
  }

  // remove o primeiro elemento, se este for o único da lista
  if(atual == (*li)){ 
    *li = atual->prox;  
     printf("\nRemoção bem sucedida.\nTecle enter para continuar...");
    getchar();
    getchar();
  }else{
    anterior->prox = atual->prox;
     printf("\nRemoção bem sucedida.\nTecle enter para continuar...");
    getchar();
    getchar();
  }

  //libera Elemento atual
  free(atual);

  return 1;
}

//função para remover elemento da lista por posição dada pelo usuário
int removerposicao(int pos, elemento **li){
  //checar se lista passada e vazia
  if (*li == NULL)
  { 
    erro(2);
    return 0; 
  }
  
  elemento* atual = *li; 
  elemento* anterior;

  int counter=1;

  while(atual != NULL && counter < pos){
    anterior=atual;
    atual = atual->prox;
    counter++;
  }

  //se o fim foi atingido
  if (atual== NULL) {
    printf("\nErro! Lista não possui tantos itens.\nTecle enter para retornar...");
      getchar();
      getchar();
      return 1;
  }
  
  // caso for o primeiro elemento
  if(atual == (*li)){
    *li = atual->prox;
    printf("\nRemoção bem sucedida.\nTecle enter para continuar...");
    getchar();
    getchar();
  }

  else{
    anterior->prox = atual->prox;
    free(atual);
    printf("\nRemoção bem sucedida!\nTecle enter para continuar...");
    getchar();
    getchar();
  }
  
  return 0;  
  
}

//função para imprimir a lista
int imprimeLista(elemento* item){

  //caso o item passado seja nulo, pare
  if(item == NULL){
    erro(2);
    return 1;
  }  

  //elemento temporario para nao alterar a lista
  elemento* aux = item;
  int counter = 1;

  printf("\nLista completa:\n\n");

  //imprimir do primeiro ate o item que aponta para NULL (ultimo) 
  while (aux->prox != NULL) {
    //imprimir a posicao do elemento
    printf("\n%d. ", counter);

    imprimeVolume(aux);

    //colocar o endereco da proxima "casa" na auxiliar
    aux = aux->prox;    

    //para imprimir a posicao correta
    counter++;
  }

  printf("\n%d. ", counter);
  
  //imprimir o ultimo item
  imprimeVolume(aux);

  printf("\n\nFim da lista.\nTecle enter para retornar...");
  getchar();
  getchar();

  return 0;
}

int imprimelistacategoria(elemento *item, int forma){
  //caso o item passado seja nulo, pare
  if(item == NULL){
    erro(2);
    return 1;
  }
  //elemento temporario para nao alterar a lista//
  elemento* aux = item;
  switch(forma){
    case 0:printf("\nLista dos Cilindros:\n\n");
    break;
    case 1:printf("\nLista dos Cubos:\n\n");
    break;
    case 2:printf("\nLista das Esferas:\n\n");
    break;
    case 3:printf("\nLista dos Cones:\n\n");
    break;
    case 4:printf("\nLista dos Paralelepipedos:\n\n");
    break;
  }
  
  //imprimir do primeiro ate o item que aponta para NULL (ultimo) 
  while (aux->prox != NULL) {
    if(aux->tipo == forma)
    {  
    imprimeVolume(aux);
    }

    //colocar o endereco da proxima "casa" na auxiliar
    aux = aux->prox;    
    
  }

  //imprimir o ultimo item
  if(aux->tipo == forma)  
  {
    imprimeVolume(aux);
  }

  printf("\n\nFim da lista.\nTecle enter para retornar...");
  getchar();
  getchar();

  return 0;
}

//calcula o volume de acordo com o sólido geometrico
float calculaVolume (elemento* item) {

  float volume;
  
  switch (item->tipo) {
    
    case CIL: {
      cilindro* c = (cilindro*) item->info;
      volume = Pi * c->r * c->r * c->h;
    }
    break;

    case CUB: {
      cubo* c = (cubo*) item->info;
      volume = c->a * c->a * c->a;
    }
    break;
    
    case ESF: {
      
      esfera* e = (esfera*) item->info;
      volume = 4 * Pi * e->r * e->r * e->r / 3;
    }
    break;
    
    case CONE: {
      cone* c = (cone*) item->info;
      volume = Pi * c->r * c->r * c->h / 3;
    }
    break;

    case PARA: {
      paral* p = (paral*) item->info;
      volume = p->c * p->h * p->l;
    }
    break;
  }
    
  return volume;
}

//imprime o volume dos sólidos geométricos
int imprimeVolume (elemento* item) {

  //caso o item passado seja nulo, pare
  if(item == NULL){
    erro(4);
    return 1;
  }

  //autoexplicativa.
  if (item->tipo == CIL){
    printf("Cilindro de %.2f centimetros cubicos de volume.\n", calculaVolume(item));
    return 0;
  }
  if (item->tipo == CUB){
    printf("Cubo de %.2f centimetros cubicos de volume.\n", calculaVolume(item));
    return 0;
  }
  if (item->tipo == ESF){
    printf("Esfera de %.2f centimetros cubicos de volume.\n", calculaVolume(item));
    return 0;
  }
  if (item->tipo == CONE){
    printf("Cone de %.2f centimetros cubicos de volume.\n", calculaVolume(item));
    return 0;
  }
  if (item->tipo == PARA){
      printf("Paralelepipedo de %.2f centimetros cubicos de volume.\n", calculaVolume(item));
    return 0;
  }
  
  return 0;
}



//Criar Nó do Cilindo//
elemento* cria_cilindro(){
  cilindro* ci = (cilindro*) malloc(sizeof(cilindro));
  elemento* p = (elemento*) malloc(sizeof(elemento));
  float r, h;
  
  //solicitar os dados
  do {  
    printf("\nDigite o valor para o raio da base: ");
    scanf("%f", &r);
    printf("Agora, digite o valor da altura: ");
    scanf("%f", &h);
  } while (r <= 0 || h <= 0);

  //checar alocacao
  if(ci == NULL || p == NULL) {  
    erro(1);
    return NULL;
  }

  //associar os dados
  ci->r = r;
  ci->h = h;

  //unir o dado ao no
  p->tipo = CIL;
  p->info = ci;
  p->prox = NULL;
  
  return p;
}

//Criar nó do cubo//
elemento* cria_cubo (){
  cubo* cub = (cubo*) malloc(sizeof(cubo));
  elemento* p = (elemento*) malloc(sizeof(elemento));
  float a;
  
  //solicitar os dados
  do {  
    printf("\nDigite o valor para a aresta: ");
    scanf("%f", &a);
    
  } while (a <= 0);

  //checar alocacao
  if(cub == NULL || p == NULL) {  
    erro(1);
    return NULL;
  }

  //associar os dados
  cub->a = a;
  
  //unir o dado ao no
  p->tipo = CUB;
  p->info = cub;
  p->prox = NULL;
  
  return p;
}

//Criar nó da esfera//
elemento* cria_esfera() {
  esfera* esf = (esfera*) malloc(sizeof(esfera));;
  elemento* p = (elemento*) malloc(sizeof(elemento));;
  float r;
  
  //solicitar os dados
  do {  
    printf("\nDigite o valor para o raio: ");
    scanf("%f", &r);
  } while (r <= 0);
 
  //checar alocacao
  if(esf == NULL || p == NULL) {  
    erro(1);
    return NULL;
  }

  //associar os dados
  esf->r = r;
  
  //unir o dado ao no
  p->tipo = ESF;
  p->info = esf;
  p->prox = NULL;
  
  return p;

}

//Criar nó do cone//
elemento* cria_cone(){
  cone* con = (cone*) malloc(sizeof(cone));
  elemento* p = (elemento*) malloc(sizeof(elemento));
  float r, h;
  
  //solicitar os dados
  do {  
    printf("\nDigite o valor para o raio da base: ");
    scanf("%f", &r);
    printf("Agora, digite o valor da altura: ");
    scanf("%f", &h);
  } while (r <= 0 || h <= 0);

  //checar alocacao
  if(con == NULL || p == NULL) {  
    erro(1);
    return NULL;
  }

  //associar os dados
  con->r = r;
  con->h = h;

  //unir o dado ao no
  p->tipo = CONE;
  p->info = con;
  p->prox = NULL;
  
  return p;
}

//Criar nó do paralelepipedo//
elemento* cria_paral () {
  paral* para;
  elemento* p;
  float c, l, h;
  
  //solicitar os dados
  do {  
    printf("\nDigite o valor para o comprimento: ");
    scanf("%f", &c);
    printf("Digite o valor para a largura: ");
    scanf("%f", &l);
    printf("Agora, digite o valor da altura: ");
    scanf("%f", &h);
  } while (c <= 0 || l <= 0 || h <= 0);

  //alocar paralelepipedo//
  para = (paral*) malloc(sizeof(paral));
  //alocar o Nó
  p = (elemento*) malloc(sizeof(elemento));

  //checar alocacao
  if(para == NULL || p == NULL) {  
    erro(1);
    return NULL;
  }

  //associar os dados
  para->c = c;
  para->l = l;
  para->h = h;

  //unir o dado ao no
  p->tipo = PARA;
  p->info = para;
  p->prox = NULL;
  
  return p;
}



void erro(int tipo) {

  switch (tipo) {
    case 1: printf("\nSem memoria!\nTecle enter para retornar.");
    break;
    case 2: printf("\nLista está vazia!\nTecle enter para retornar...");
    break; 
    case 3: printf("Lista já existe!\nTecle enter para retornar...");
    case 4: printf("\nElemento inválido/vazio.\nTecle enter para retornar...");
    break;
  }  

  getchar();
  getchar();
}
