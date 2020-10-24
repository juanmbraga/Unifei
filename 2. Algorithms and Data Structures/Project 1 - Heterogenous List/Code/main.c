#include <stdio.h>
#include <stdlib.h>
#include "listaHeterogenea.h"

int main(void) {

  //ponteiro para primeiro elemento
  elemento* lista = NULL;
  int opcao, forma, control, pos;
  
  do {
    system("clear");
    printf("Calcule o volume de solidos geométricos!");
    printf("\n\nMenu de opções:");
    printf("\n1 - Gerar lista a partir de arquivo");
    printf("\n2 - Liberar a lista");
    printf("\n3 - Adicionar item");
    printf("\n4 - Remover item");
    printf("\n5 - Imprimir lista");
    printf("\n6 - Sair.");
    printf("\n\nOpção: ");
    scanf("%d", &opcao);
   
    switch (opcao) {

      case 1:  //criar lista a partir de arquivo

        if (lista != NULL) {    //caso ja exista uma lista 
          erro(3);
          continue; //prosseguir para o menu
        }

        lista = geralista();

        if (lista == NULL)
          erro(2);
          
        
      break;

      case 2: // liberar a lista 

        control = liberar_lista(&lista);

        if (control == 0) {
        printf("Erro ao liberar a lista!\n Tecle enter para continuar...");
        getchar();
        getchar();
        }
        else {
        printf("\nLista liberada com sucesso!\nTecle enter para continuar...");
        getchar();
        getchar();
      }
        continue;

        break;

      case 3:  //inserir objeto

        //nao permitir o usuario de adicionar sem ter gerado uma lista para evitar que a lista sobreescreva e deixe memoria sem desalocar
        if(lista == NULL) {
          printf("\nLista vazia! \nGere uma lista a partir de um arquivo utilizando a opção 1.\nTecle enter para retornar...");
          getchar();
          getchar();
          continue;
        }

        do {    //escolher onde inserir
          printf("\n\nEscolha onde o item sera adicionado:");
          printf("\n1. Inicio da lista");
          printf("\n2. Final da lista");
          printf("\n3. Retornar");
          printf("\n\nOpcao: ");
          scanf("%d", &opcao);          
        } while(opcao != 1 && opcao != 2 && opcao != 3);

          //sair antes para economizar processamento
         if(opcao == 3) {  
            continue;
          }

          //selecionar a forma do solido geometrico
          forma = selecionaForma();   
          
          //inserir no inicio
          if(opcao == 1){ 
            control = inserirInicio(&lista, forma);
          }
          else {
            //inserir no final
            if(opcao == 2)  
              control = inserirfinal(&lista, forma);
          }
        break;

      case 4:  //remover item

        if (lista == NULL) {    //caso lista esteja vazia 
          erro(2);
          continue; //prosseguir para o menu
        }
        
        do{ //escolher onde será removido
          printf("\nEscolha onde  o item será removido:");
          printf("\n1. Início da lista");
          printf("\n2. Fim da lista");
          printf("\n3. Apagar por posicao");
          printf("\n4. Voltar ao menu");
          printf("\n\nOpcao: ");
          scanf("%d",&opcao);
        } while (opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4);
          
          //sair antes para economizar processamento
          if(opcao == 4){ 
            continue;
          }

          if(opcao == 1) {
            control = removeInicio(&lista);
          }
          if(opcao == 2) {
            control = removeFim(&lista);
          }
          if(opcao == 3){

            printf("\nDigite a posição do objeto que deseja remover: ");
            scanf("%d", &pos);
            control = removerposicao(pos, &lista);
            
            if(pos < 1 || pos >3){
              printf("Valor incorreto....");
              getchar();
              getchar();
              continue;
            }
         }
        
      break;

      case 5:  //imprimir lista
        do{
          printf("\nEscolha qual lista será impressa na tela:");
          printf("\n1. Lista completa:");
          printf("\n2. Lista por categoria");
          printf("\n3. Voltar ao menu");
          printf("\n\nOpção: ");
          scanf("%d", &opcao);
        } while (opcao != 1 && opcao != 2 && opcao != 3);
          
        if(opcao == 3) {
          continue;
        } //imprime a lista completa
        if(opcao == 1){
          control = imprimeLista(lista);
        }
        if(opcao == 2){ //imprime a lista de objetos por categoria
          forma = selecionaForma();
          control = imprimelistacategoria(lista, forma);
       }
      break;

      case 6: //sair do programa
      
        liberar_lista(&lista); //antes de finalizar o programa liberamos toda a lista
        printf("\nPrograma finalizado.");
        return 0;
        
      break;
       default:
        printf("\nOpção inválida!");
        break;
      }
    } while (opcao != 6);

  printf("\nPrograma finalizado.");
  return 0;
}