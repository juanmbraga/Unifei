//Neste arquivo tentarei refazer as funcoes do TAD que a professora apresentou para este conceito. 

//Faco isto pois nao entendi muito bem o porque de ser necessario criar um ponteiro para elemento,
//e depois, ainda por cima, criar um ponteiro para este ponteiro.
//O oitavo slide deste modulo 07, sobre listas dinamicas encadeadas, possui uma imagem que mostra:
//Um ponteiro para ponteiro de elemento; um ponteiro para elemento, e um elemento. 
//Tentarei fazer com apenas um ponteiro para ver se de fato faz algum sentido usar desta maneira. 

//inserirei como comentarios o codigo da implementacao da professora

#include <stdio.h>
#include <stdlib.h>

typedef struct Elemento elemento; //para usar "elemento" como tipo sem "struct" ou maiuscula.

struct Elemento {
    int conteudo;
    elemento* prox;
};

elemento* addElemento(); 


int main (void) {

    elemento* lista;

    //criar
    lista = addElemento();

    //ler
    printf("%d", lista->conteudo);
}

elemento* addElemento()
{
  elemento* teste = (elemento*) malloc(sizeof(elemento));  

  if (teste != NULL)
    teste->prox = NULL;

  return teste;
}

int freeLista(elemento* lista)
{
  if(lista == NULL)  
    return 0;

  // libera todos os nós da lista que foram alocados
  elemento* no;
  while(lista != NULL){
    no = lista;
    lista = lista->prox;
    free(no);
  }

  // libera o ponteiro da lista
  free(lista);

  return 1;  
}