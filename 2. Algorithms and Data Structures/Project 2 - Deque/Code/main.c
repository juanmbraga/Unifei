//bibliotecas do sistema
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dequeDinamico.h"

// protótipo da função que cria um dado 
int criar_dado(char *nome);

int main(void) {
  
  Deque *deq = NULL;
  
  int opcao, ok;
  char nome[50];
  
  do {
    system("clear");
    printf("\n----------Controle de atendimento hospitalar----------");
    printf("\n\nMenu de opções:");
    printf("\n1 - Importar fila de pacientes para atendimento");
    printf("\n2 - Liberar fila");
    printf("\n3 - Adicionar paciente");
    printf("\n4 - Remover paciente");
    printf("\n5 - Imprimir fila de pacientes");
    printf("\n6 - Sair.");
    printf("\n\nOpção: ");
    scanf("%d", &opcao);
   
    switch (opcao) {

      case 1:  //criar deque a partir de arquivo

        if (deq != NULL) {    //caso ja exista uma fila
          printf("\nFila já existe!\n\nTecle enter para retornar...");

          getchar();
          getchar();
          continue; //prosseguir para o menu
        }

        deq = gera_deque();

        if (deq == NULL)
          printf("\nFila está vazia!\nTecle enter para retornar...");
           
      break;
    
      case 2: // libera o deque 

        ok = liberar_deque(&deq);

        if (ok == 0){
          printf("\nErro ao liberar a fila!\n\nTecle enter para continuar...");
          getchar();
          getchar();
        }
        else {
          printf("\nFila liberada com sucesso!\n\nTecle enter para continuar...");
          getchar();
          getchar();
        }

        continue;

        break;

      case 3:  //inserir 
        
         //não permitir o usuario de adicionar sem ter gerado uma fila para evitar que a fila sobreescreva e deixe memoria sem desalocar

        if(deq == NULL) {
          printf("\nFila vazia!\n\nGere uma fila a partir de um arquivo utilizando a opção 1.\n\nTecle enter para retornar...");
          getchar();
          getchar();
          continue;
        }

        do {    //escolher onde inserir
          printf("\n\n Escolha a urgência do atendimento:");
          printf("\n1. Paciente Urgente");
          printf("\n2. Paciente não urgente ");
          printf("\n3. Retornar");
          printf("\n\nOpcao: ");
          scanf("%d", &opcao);          
        } while(opcao != 1 && opcao != 2 && opcao != 3);

          //sair antes para economizar processamento
          if(opcao == 3) {  
            continue;
          }
         
          //inserir no inicio da fila
          if(opcao == 1){ 
            ok = criar_dado(nome);
            ok = insere_inicio_deque(deq, nome);

            printf ("\nHá %d pacientes na fila", tamanho_deque(deq));
            printf("\n\nPressione qualquer tecla para continuar.");

            getchar();
            getchar();

            continue;

          }
  
          //inserir no final da fila
          if (opcao == 2){
            ok = criar_dado(nome);
            ok = insere_fim_deque(deq, nome);

            printf ("\nHá %d pacientes na fila", tamanho_deque(deq));
            printf("\n\nPressione qualquer tecla para continuar.");
            
            getchar();
            getchar();
            continue;
          }
                   
        break;

      case 4:  //remover item

         if (deq == NULL) {    //caso a fila esteja vazia 
          printf("\nFila está vazia!\n\nTecle enter para retornar...");

          getchar();
          getchar();
          continue; //prosseguir para o menu
        }
      
        do{ //escolher onde será removido
          printf("\nEscolha paciente será removido:");
          printf("\n1. Paciente atendido");
          printf("\n2. Último paciente desistiu do atendimento");
          printf("\n3. Voltar ao menu");
          printf("\n\nOpcao: ");
          scanf("%d",&opcao);
        } while (opcao != 1 && opcao != 2 && opcao != 3);
          
          //sair antes para economizar processamento
          if(opcao == 3){ 
            continue;
          }

          if(opcao == 1) {
            ok = remove_inicio_deque(deq);
             printf ("\nHá %d pacientes na fila", tamanho_deque(deq));

            ok = consultar_inicio_deque(deq, nome);

            printf("\n\nPróximo paciente da fila:");
            printf(" %s", nome);

            printf("\n\nPressione qualquer tecla para continuar."); 
            getchar();
            getchar();
            continue;  
         }
        
          if(opcao == 2) {
            ok = remove_fim_deque(deq);
            printf ("\nHá %d pacientes na fila", tamanho_deque(deq));
           
            ok = consultar_fim_deque(deq, nome);

            printf("\n\nÚltimo paciente da fila:");
            printf(" %s", nome);

            printf("\n\nPressione qualquer tecla para continuar."); 
            getchar();
            getchar();
            continue; 
          }
          
      break;

      case 5:  //imprimir deque
       
      imprimir_deque(deq);
       
      break;

      case 6: //sair do programa
            
      printf("\nPrograma finalizado.");

      liberar_deque(&deq); //antes de finalizarmos o programa liberamos a memória alocada para o deque

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

//função para criar o dado do deque
int criar_dado(char *nome)
{
    printf("\nDigite o nome do paciente: ");
    scanf(" %[^\n]", nome); //scanf para ler o nome do paciente até o ENTER
   
    return 1;
}