#include <stdio.h>
#include <stdlib.h>
#include <time.h>//necessário para chamar aleatoriamente as senhas
#include "atendimento.h"

int main(void) {

  srand(time(NULL));//serve para gerar numeros aleatorios

  Fila *SE = NULL;
  Fila *XP = NULL;
  Fila *XC = NULL;
  Fila *NP = NULL;
  Fila *NC = NULL;

  int ok, n, atendidos=0, menu2, dado=1, menu1, menu3, numAleatorio, tamanho, atendidosC=0, atendidosN=0;
  printf("Insira o número máximo de atendimentos: "); 
  do{
    scanf("%d", &n);
  } while(n < 0);

  SE = criar_fila();
  XP = criar_fila();
  XC = criar_fila();
  NP = criar_fila();
  NC = criar_fila();

  if(SE != NULL || XP != NULL || XC!= NULL || NP!= NULL || NC != NULL){
          printf("\nFilas criadas com sucesso!\n\n");
        }else{
          printf("\nFilas não criadas!\n\n");
        }
  do{
    enfileirar(SE, dado);
    dado++;
  }while(dado<=n);

  do{
  
  system("clear");
  printf("---------------- Selecione o que deseja fazer ----------------\n1-Abrir o menu de retiradas de senhas e atendimento\n2-Abrir o menu de chamada de senha (funcionários)\n3-Sair\n");
  scanf("%d", &menu1);

  if(menu1==1){
    
    printf("\nBem vindo. Qual tipo de atendimento gostaria de solicitar?\n1-Caixa Preferencial\n2-Caixa Convencional\n3-Negocial Preferencial\n4-Negocial Convencional\nOpcao: ");

    do{
      scanf("%d", &menu2);
    } while(menu2 < 1 && menu2 > 4);
    

    if(atendidos<n){

    switch(menu2){
      case 1:
      consultar_inicio_fila(SE, &dado);
      printf("\n-----------------\nSua senha é: XP%d\n-----------------\n", dado);
      desenfileirar(SE);
      enfileirar(XP, dado);
      break;

      case 2:
      consultar_inicio_fila(SE, &dado);
      printf("\n-----------------\nSua senha é: XC%d\n-----------------\n", dado);
      desenfileirar(SE);
      enfileirar(XC, dado);
      break;

      case 3:
      consultar_inicio_fila(SE, &dado);
      printf("\n-----------------\nSua senha é: NP%d\n-----------------\n", dado);
      desenfileirar(SE);
      enfileirar(NP, dado);
      break;

      case 4:
      consultar_inicio_fila(SE, &dado);
      printf("\n-----------------\nSua senha é: NC%d\n-----------------\n", dado);
      desenfileirar(SE);
      enfileirar(NC, dado);
      break;


    }
    printf("\n\nTecle ENTER para continuar...");
    getchar();
    getchar();
  
    atendidos++;
    }else{
      printf("O numero maximo de clientes por dia foi atingido!\nTecle ENTER para continuar...");
      getchar();
      getchar();
      }
  }

  if (menu1==2){

    if(tamanho_fila(XP) == 0 && tamanho_fila(XC) == 0 && tamanho_fila(NP) == 0 && tamanho_fila(NC) == 0){
      printf("\nNenhuma senha foi retirada!\nTecle ENTER para continuar...");
      getchar();
      getchar();
      continue;
    }
    
    system("clear");
    printf("\n\n------------------- O que deseja fazer? ------------------\nVocê está prestes a chamar aleatoriamente um tipo de atendimento (Negocial ou Caixa)\n*(Isso fará com que todas as senhas do item sorteado sejam retiradas e, consequentemente, quando o sorteado acabar, as senhas do outro também serão retiradas)*\n*(Isso ocorrerá na ordem correta, 2 Preferenciais e 1 Convencional, porém quando um desses acaba, o outro continuará a ser chamado)*\n\n");

    printf("\nTecle ENTER para iniciar a chamada...\n\n");
    getchar();
    getchar();

    // definine aleatoriamente o tipo: negocial(1) ou caixa(0)
    numAleatorio = rand() % 2;

    // retira todas as senhas para um tipo, depois retira do outro
    for(int i=0; i<2; i++){

      // para Caixa
      if(numAleatorio == 0){

        //definir tamanho das filas do caixa
        tamanho = tamanho_fila(XC) + tamanho_fila(XP);

        do{

          // Preferencial (2x)
          for(int j=0; j<2; j++){
            
            if(tamanho_fila(XP) != 0){

              // consulta a primeira senha
              consultar_inicio_fila(XP, &dado);
              // avisa o usuario
              printf("-----------------\nA senha retirada é: XP%d\n-----------------\n", dado);
              // remove a senha
              desenfileirar(XP);
              // caso senha foi retirada, reduza o numero da checagem
              tamanho--;
              atendidosC++;
            }
          }

          // Convencional
          if(tamanho_fila(XC) != 0){
            
            // consulta a primeira senha
            consultar_inicio_fila(XC, &dado);
            // avisa o usuario
            printf("-----------------\nA senha retirada é: XC%d\n-----------------\n", dado);
            // remove a senha
            desenfileirar(XC);
            // caso senha foi retirada, reduza o numero da checagem
            tamanho--;
            atendidosC++;
          }

        // enquanto todas as senhas do tipo nao tiverem sido chamadas
        }while(tamanho > 0);

        // atualizar o valor para a proxima iteracao
        numAleatorio = 1;

      // para Negocial 
      }else{
        
        //definir tamanho das filas do caixa
        tamanho = tamanho_fila(NC) + tamanho_fila(NP);
        
        do {
          // Preferencial (2x)
          for (int j=0; j<2; j++){
            if(tamanho_fila(NP) != 0){
              consultar_inicio_fila(NP, &dado);
              printf("-----------------\nA senha retirada é: NP%d\n-----------------\n", dado);
              desenfileirar(NP);
              tamanho--;
              atendidosN++;
            }
          }

          // Convencional
          if(tamanho_fila(NC) != 0){
            consultar_inicio_fila(NC, &dado);
            printf("-----------------\nA senha retirada é: NC%d\n-----------------\n", dado);
            desenfileirar(NC);
            tamanho--;
            atendidosN++;
          }

          // enquanto todas as senhas do tipo nao tiverem sido chamadas
        }while(tamanho > 0);

        // atualizar o valor para a proxima iteracao
        numAleatorio = 0;
      }
    }

    if((atendidosC+atendidosN)==n){
        menu1=3;
    } else {
      printf("\nTodas as senhas retiradas foram chamadas. Tecle ENTER para retornar...");
      getchar();
      getchar();
    }
  }

  if(menu1 == 3){

    
    // ver se tudo foi atendido
    if((atendidosN + atendidosC) == n){
      printf("\nTodos os %d clientes do dia já foram atendidos.", n);
    } else {
    // caso nem todos tenham sido atendidos (redundante)
      printf("\nNem todos os clientes foram atendidos.\nGostaria de continuar e fechar (1)? Ou retornar (2)? ");

      do{
        scanf("%d", &menu3);
      } while(menu3 != 1 && menu3 != 2);
      
      if(menu3 == 2){
        menu1 = 0;
      }

    }
  }
  }while(menu1 != 3);

  // liberar todas as filas
  liberar_fila(SE);
  liberar_fila(XP);
  liberar_fila(XC);
  liberar_fila(NP);
  liberar_fila(NC);

  printf("\n\nTotal de atendimentos:");
  printf("\nCaixa: %d", atendidosC);
  printf("\nNegocial: %d", atendidosN);
  printf("\n\nEncerrando programa...");
  
  return 0;
}