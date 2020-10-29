/* Resumo:

Todas as adaptacoes foram feitas, contudo as funcoes de concatenar e remover valores repetidos possuem ineficiencias serias. Alem do mais, suas implementacoes na main podem (ou nao) ter algumas deficiencias. 

os problemas:

concatena: 
  .nao consegui implementar direito na main/nao funciona
  .usa a funcao de inserir item no final, o que faz com que ela tenha que percorrer toda a lista para inserir ao inves de se lembrar do ultimo elemento. Listas grandes seriam um pesadelo.
  .a funcao reordena os elementos para uma nova lista, o que inutiliza as anteriores. Possivelmente a professora quis que fizessemos uma copia dos elementos para preservar as outras duas
  .as opcoes de combinacao na implementacao da main ao abrangem todas as possibilidades
  .a maneira com que foram feitas as verificacoes poderia ser mais eficiente (ou a que esta agora e potencialmente errada)
  .so depois que percebi que "concatenar" significa apenas juntar, e nao colocar de maneira alternada.
remover repetidos:
  .usa a funcao de remover um item do meio da lista que ja estava implementada. Contudo, ela percorre toda a lista para procurar o item toda vez, o que e um problemitcho...

inverter lista:
  .funcao apenas reorganiza os ponteiros dos elementos da lista que foi fornecida, e por causa disso ela sera perdida. A professora escreveu para armazenar em L2 e retornar, entao parece que nao era pra L1 ser alterada... 

*/

// bibliotecas do sistema
#include <stdio.h>
#include <stdlib.h>

// bibliotecas do projeto
#include "listaEncadeada.h"


// funcao principal
int main(void) {

  // no início a lista está vazia, logo, o ponteiro inicio tem valor NULL
  //o ponteiro inicio conterá o endereço do primeiro elemento da lista
  Lista* lista1 = NULL;
  Lista* lista2 = NULL;
  Lista* lista3 = NULL;

  int opcao, opcao2, ok, pos, matricula;
  
  aluno* elemento = NULL;

  // menu de opções para execuções de operações sobre a lista
  do
  {
    system("clear");
    printf("\n_____________________________");
    printf("\n\n\nMenu de opções:\n");
    printf("\n 1 - Criar lista");
    printf("\n 2 - Liberar lista");
    printf("\n 3 - Inserir aluno no início");
    printf("\n 4 - Inserir aluno no final");
    printf("\n 5 - Inserir aluno por ordem de matricula");
    printf("\n 6 - Remover aluno do início");
    printf("\n 7 - Remover aluno do final");
    printf("\n 8 - Remover aluno (por numero de matricula)");
    printf("\n 9 - Buscar aluno pela posição na lista");
    printf("\n10 - Buscar aluno por matricula");
    printf("\n11 - Imprimir lista");
    printf("\n12 - Concatena duas listas");
    printf("\n13 - Remover valores repetidos");
    printf("\n14 - Inverter uma lista");
    printf("\n15 - Verificar se lista esta ordenada");
    printf("\n16 - Calcular o tamanho de uma lista");
    printf("\n17 - Calcular o tamanho com outra funcao");
    printf("\n18 - Sair");
    printf("\n\nOpção: ");
    scanf("%d", &opcao);

    switch(opcao){

      case 1: // inicializar uma lista

        //usuario escolhe qual lista quer inicializar
        do{
          printf("\nEscolha qual das tres listas gostaria de inicializar (1, 2 ou 3): ");
          scanf("%d", &opcao);
        }while(opcao != 1 && opcao != 2 && opcao != 3);

        //cheque e crie uma lista de acordo com a escolha
        switch (opcao) {
          case 1:

            if(lista1 != NULL){
              printf("\nLista ja existe!");
              break;
            }

            lista1 = criar_lista();
            
            if(lista1 != NULL){
              printf("\n Lista criada com sucesso!");
            }else{
              printf("\n Lista não criada!");
            }
          break;
          case 2:

            if(lista2 != NULL){
              printf("\nLista ja existe!");
              break;
            }

            lista2 = criar_lista();

            if(lista2 != NULL){
              printf("\n Lista criada com sucesso!");
            }else{
              printf("\n Lista não criada!");
            }
            break;
          case 3:

            if(lista3 != NULL){
              printf("\nLista ja existe!");
              break;
            }

            lista3 = criar_lista();

            if(lista3 != NULL){
              printf("\n Lista criada com sucesso!");
            }else{
              printf("\n Lista não criada!");
            }
            break;
        }
      break;

      case 2: // limpar lista(s)

        //usuario escolhe qual lista quer liberar
        do{
          printf("\nEscolha qual das tres listas gostaria de limpar: ");
          printf("\n1. Lista 1");
          printf("\n2. Lista 2");
          printf("\n3. Lista 3");
          printf("\n4. Todas\n");
          scanf("%d", &opcao);
        }while(opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4);

        switch (opcao){
          case 1: //libera lista1
            ok = liberar_lista(lista1);
              if(ok)
                {printf("\n Lista 1 liberada com sucesso!");}
              else
                {printf("\n Lista 1 ainda não foi criada!");}
            break;
          case 2: //libera lista2
            ok = liberar_lista(lista2);
              if(ok)
                {printf("\n Lista 2 liberada com sucesso!");}
              else
                {printf("\n Lista 2 ainda não foi criada!");}
            break;
          case 3: //liberar lista3
            ok = liberar_lista(lista3);
              if(ok)
                {printf("\n Lista 3 liberada com sucesso!");}
              else
                {printf("\n Lista 3 ainda não foi criada!");}
            break;
          case 4: //liberar todas
            ok = liberar_lista(lista1);
              if(ok)
                {printf("\n Lista 1 liberada com sucesso!");}
              else
                {printf("\n Lista 1 ainda não foi criada!");}
            ok = liberar_lista(lista2);
              if(ok)
                {printf("\n Lista 2 liberada com sucesso!");}
              else
                {printf("\n Lista 2 ainda não foi criada!");}
            ok = liberar_lista(lista3);
              if(ok)
                {printf("\n Lista 3 liberada com sucesso!");}
              else
                {printf("\n Lista 3 ainda não foi criada!");}

            printf("\nTecle enter para retornar...");
            getchar();
            getchar();
            break;
        }
      break;   

      case 3: // inserir elemento o inicio

        //usuario escolhe em qual lista quer inserir
        do{
          printf("\nEscolha em qual das tres listas gostaria de inserir: ");
          scanf("%d", &opcao);
        }while(opcao != 1 && opcao != 2 && opcao != 3);

        //insere de acordo com a escolha
        if(opcao == 1) {
          if(lista1 == NULL){
            printf("\nLista vazia!");
            break;
          }
          elemento = criar_dado(elemento);
          ok = inserir_lista_inicio(lista1, elemento);
        }

        if(opcao == 2) {
          if(lista2 == NULL){
            printf("\nLista vazia!");
            break;
          }
          elemento = criar_dado(elemento);
          ok = inserir_lista_inicio(lista2, elemento);
        }

        if(opcao == 3){
          if(lista3 == NULL){
            printf("\nLista vazia!");
            break;
          }
          elemento = criar_dado(elemento);
          ok = inserir_lista_inicio(lista3, elemento);
        }
        
        if(ok == 1){
          printf("\n Inserção realizada com sucesso!");
        }else{
          printf("\n Falha na inserção!");
        }
      break;

      case 4: // inserir no final

        //usuario escolhe em qual lista quer inserir
        do{
          printf("\nEscolha em qual das tres listas gostaria de inserir: ");
          scanf("%d", &opcao);
        }while(opcao != 1 && opcao != 2 && opcao != 3);

        //insere de acordo com a escolha
        if(opcao == 1) {
          if(lista1 == NULL){
            printf("\nLista vazia!");
            break;
          }
          elemento = criar_dado(elemento);
          ok = inserir_lista_final(lista1, elemento);
        }

        if(opcao == 2) {
          if(lista2 == NULL){
            printf("\nLista vazia!");
            break;
          }
          elemento = criar_dado(elemento);
          ok = inserir_lista_final(lista2, elemento);
        }

        if(opcao == 3){
          if(lista3 == NULL){
            printf("\nLista vazia!");
            break;
          }
          elemento = criar_dado(elemento);
          ok = inserir_lista_final(lista3, elemento);
        }
        
        if(ok == 1){
          printf("\n Inserção realizada com sucesso!");
        }else{
          printf("\n Falha na inserção!");
        }
      break;

      case 5: // inserir elemento de forma ordenada

        //usuario escolhe em qual lista quer inserir
        do{
          printf("\nEscolha em qual das tres listas gostaria de inserir: ");
          scanf("%d", &opcao);
        }while(opcao != 1 && opcao != 2 && opcao != 3);

        //insere de acordo com a escolha
        if(opcao == 1) {
          if(lista1 == NULL){
            printf("\nLista vazia!");
            break;
          }
          elemento = criar_dado(elemento);
          ok = inserir_lista_ordenada(lista1, elemento);
        }

        if(opcao == 2) {
          if(lista2 == NULL){
            printf("\nLista vazia!");
            break;
          }
          elemento = criar_dado(elemento);
          ok = inserir_lista_ordenada(lista2, elemento);
        }

        if(opcao == 3){
          if(lista3 == NULL){
            printf("\nLista vazia!");
            break;
          }
          elemento = criar_dado(elemento);
          ok = inserir_lista_ordenada(lista3, elemento);
        }
        
        if(ok == 1){
          printf("\n Inserção realizada com sucesso!");
        }else{
          printf("\n Falha na inserção!");
        }
      break;

      case 6: // remover elemento do início

        //usuario escolhe de qual lista quer remover
        do{
          printf("\nEscolha de qual das tres listas gostaria de remover: ");
          scanf("%d", &opcao);
        }while(opcao != 1 && opcao != 2 && opcao != 3);

        //remove de acordo com a escolha
        if(opcao == 1) {
          if(lista1 == NULL){
            printf("\nLista vazia!");
            break;
          }
          ok = remover_lista_inicio(lista1);
        }

        if(opcao == 2) {
          if(lista2 == NULL){
            printf("\nLista vazia!");
            break;
          }
          ok = remover_lista_inicio(lista2);
        }

        if(opcao == 3){
          if(lista3 == NULL){
            printf("\nLista vazia!");
            break;
          }
          ok = remover_lista_inicio(lista3);
        }
       
        if(ok == 1){
          printf("\n Remoção realizada com sucesso!");
        }else{
          printf("\n Falha na remoção!");
        }
      break;

      case 7: // remover elemento do final

        //usuario escolhe de qual lista quer remover
        do{
          printf("\nEscolha de qual das tres listas gostaria de remover: ");
          scanf("%d", &opcao);
        }while(opcao != 1 && opcao != 2 && opcao != 3);

        //remove de acordo com a escolha
        if(opcao == 1) {
          if(lista1 == NULL){
            printf("\nLista vazia!");
            break;
          }
          ok = remover_lista_final(lista1);
        }

        if(opcao == 2) {
          if(lista2 == NULL){
            printf("\nLista vazia!");
            break;
          }
          ok = remover_lista_final(lista2);
        }

        if(opcao == 3){
          if(lista3 == NULL){
            printf("\nLista vazia!");
            break;
          }
          ok = remover_lista_final(lista3);
        }
       
        if(ok == 1){
          printf("\n Remoção realizada com sucesso!");
        }else{
          printf("\n Falha na remoção!");
        }

      break;

      case 8: // remover elemento do meio

        printf("\n Matricula do aluno a ser removido: ");
        scanf("%d", &matricula);

        //usuario escolhe de qual lista quer remover
        do{
          printf("\nEscolha de qual das tres listas gostaria de remover: ");
          scanf("%d", &opcao);
        }while(opcao != 1 && opcao != 2 && opcao != 3);

        //remove de acordo com a escolha
        if(opcao == 1) {
          if(lista1 == NULL){
            printf("\nLista vazia!");
            break;
          }
          ok = remover_lista_meio(lista1, matricula);
        }

        if(opcao == 2) {
          if(lista2 == NULL){
            printf("\nLista vazia!");
            break;
          }
          ok = remover_lista_meio(lista2, matricula);
        }

        if(opcao == 3){
          if(lista2 == NULL){
            printf("\nLista vazia!");
            break;
          }
          ok = remover_lista_meio(lista3, matricula);
        }

        if(ok == 1){
          printf("\n Remoção realizada com sucesso!");
        }else{
          printf("\n Falha na remoção!");
        }
      break;

      case 9: // busca elemento pela posicao

        printf("\n Posição do aluno na lista a ser buscado: ");
        scanf("%d", &pos);

        //usuario escolhe em qual lista procurar
        do{
          printf("\nEscolha em qual das tres listas gostaria de buscar: ");
          scanf("%d", &opcao);
        }while(opcao != 1 && opcao != 2 && opcao != 3);


        //busca de acordo com a escolha
        // variavel matricula foi utilizada pois nao e possivel acessar os dados de struct declarada em outro arquivo .c
        if(opcao == 1) {
          if(lista1 == NULL){
            printf("\nLista vazia!");
            break;
          }
          buscar_lista_posicao(lista1, pos);
        }

        if(opcao == 2) {
          if(lista2 == NULL){
            printf("\nLista vazia!");
            break;
          }
          buscar_lista_posicao(lista2, pos);
        }

        if(opcao == 3){
          if(lista2 == NULL){
            printf("\nLista vazia!");
            break;
          }
          buscar_lista_posicao(lista3, pos);
        }

      break;

      case 10:  // busca elemento pelo dado

        printf("\n Matricula do aluno: ");
        scanf("%d", &matricula);

        //usuario escolhe em qual lista procurar
        do{
          printf("\nEscolha em qual das tres listas gostaria de buscar: ");
          scanf("%d", &opcao);
        }while(opcao != 1 && opcao != 2 && opcao != 3);


        //busca de acordo com a escolha e imprime
        if(opcao == 1) {
          if(lista1 == NULL){
            printf("\nLista vazia!");
            break;
          }
          buscar_lista_dado(lista1, matricula);
        }

        if(opcao == 2) {
          if(lista2 == NULL){
            printf("\nLista vazia!");
            break;
          }
          buscar_lista_dado(lista2, matricula);
        }

        if(opcao == 3){
          if(lista3 == NULL){
            printf("\nLista vazia!");
            break;
          }
          buscar_lista_dado(lista3, matricula);
        }
      break;

      case 11:  // imprime a lista

        //usuario escolhe qual lista imprimir
        do{
          printf("\nEscolha qual das tres listas gostaria de imprimir: ");
          scanf("%d", &opcao);
        }while(opcao != 1 && opcao != 2 && opcao != 3);


        //imprime de acordo com a escolha
        printf("\n Lista encadeada: ");

        if(opcao == 1) {
          ok = imprimir_lista(lista1);
        }

        if(opcao == 2) {
          ok = imprimir_lista(lista2);
        }

        if(opcao == 3){
          ok = imprimir_lista(lista3);
        }


        if(!ok){
          printf("\n Lista não encontrada!");
        }

      break;

      case 12:  // concatena duas listas 

        printf("\n#include <inefficiency.h>\n");

        //usuario escolhe quais listas concatenar
        do{
          printf("\nQual das listas gostaria de concatenar?");
          printf("\n1. listas 1 e 2");
          printf("\n2. listas 1 e 3");
          printf("\n3. listas 2 e 3\n");
          scanf("%d", &opcao);
        }while(opcao != 1 && opcao != 2 && opcao != 3);

        //sera que existe um meio mais eficiente de fazer isto? talvez sem duas variaveis?
        
        //uma vez que as listas anteriores serao perdidas, a nova pode ser salva em uma das selecionadas ou em uma nao usada.

        //printf("\nAs listas a serem concatenadas serao perdidas. A resultante deve ser armazenada em uma das concatenadas ou em uma lista limpa.");
        
        do{
          printf("\nEm qual lista vazia gostaria de salvar a nova concatenada?");
          if(lista1==NULL /* || opcao == 1 || opcao == 2*/) {printf("\n1. lista 1");}
          if(lista2==NULL /* || opcao == 1 || opcao == 3*/) {printf("\n2. lista 2");}
          if(lista3==NULL /* || opcao == 2 || opcao == 3*/) {printf("\n1. lista 3");}
          scanf("%d", &opcao2);
        }while(opcao2 != 1 && opcao2 != 2 && opcao2 != 3);

        //se lista destino da opcao ja estiver em uso
        if((opcao2 == 1 && lista1 != NULL) || (opcao2 == 2 && lista2 != NULL) || (opcao2 == 3 && lista3 != NULL)){
            printf("\nA lista destino ja esta alocada!\nLibere-a antes de concatenar.");
            getchar();
            getchar();
            break;
        }

        
        if(opcao == 1) {
          if(opcao2 == 1){
            lista1 = concatenaLista(lista1, lista2);
            break;
          }
          if(opcao2 == 2){
            lista2 = concatenaLista(lista1, lista2);
            break;
          }
          if(opcao2 == 3){
            lista3 = concatenaLista(lista1, lista2);
            break;
          }          
        }

        if(opcao == 2) {
          if(opcao2 == 1){
            lista1 = concatenaLista(lista1, lista3);
            break;
          }
          if(opcao2 == 2){
            lista2 = concatenaLista(lista1, lista3);
            break;
          }
          if(opcao2 == 3){
            lista3 = concatenaLista(lista1, lista3);
            break;
          }
          
        }

        if(opcao == 3){
          if(opcao2 == 1){
            lista1 = concatenaLista(lista2, lista3);
            break;
          }
          if(opcao2 == 2){
            lista2 = concatenaLista(lista2, lista3);
            break;
          }
          if(opcao2 == 3){
            lista3 = concatenaLista(lista2, lista3);
            break;
          }
          
        }
        
        //nao sao todas as possibilidades uma vez que a funcao so concatena uma depois da outra, mas as combinacoes inversas tambem resultariam em algo diferente...
        //como (1,2)(2,1)
      break;

      case 13:  // remover valores repetidos

        printf("\nA revisar o codigo por ineficiencias. Favor conferir comentario no codigo!");

        //usuario escolhe qual lista checar
        do{
          printf("\nQual das listas gostaria de checar? ");
          scanf("%d", &opcao);
        }while(opcao != 1 && opcao != 2 && opcao != 3);

        if(opcao == 1) {
          removeRepetidos(lista1);
        }

        if(opcao == 2) {
          removeRepetidos(lista1);
        }

        if(opcao == 3){
          removeRepetidos(lista1);
        }

      break;

      case 14:  // inverter lista
        
        printf("\nAtencao! Esta acao nao pode ser desfeita!");

        //usuario escolhe qual lista inverter
        do{
          printf("\nQual das listas gostaria de inverter? ");
          scanf("%d", &opcao);
        }while(opcao != 1 && opcao != 2 && opcao != 3);
        
        if(opcao == 1) {
          lista1 = inverteLista(lista1);
          if(lista1 != NULL){
            printf("Inversao bem sucedida!");
            break;
          }
          //pode nao ser um indicativo real sobre o sucesso da inversao...
        }

        if(opcao == 2) {
          lista2 = inverteLista(lista2);
          if(lista2 != NULL){
            printf("Inversao bem sucedida!");
            break;
          }
        }

        if(opcao == 3){
          lista3 = inverteLista(lista3);
          if(lista1 != NULL){
            printf("Inversao bem sucedida!");
            break;
          }
        }


      break;

      case 15:  // verificar ordenacao

        printf("#include <inefficiency.h>");

        //usuario escolhe qual lista inverter
        do{
          printf("\nQual das listas gostaria de checar? ");
          scanf("%d", &opcao);
        }while(opcao != 1 && opcao != 2 && opcao != 3);

        if(opcao == 1) {
          checaOrdenacao(lista1);
        }

        if(opcao == 2) {
          checaOrdenacao(lista1);
        }

        if(opcao == 3){
          checaOrdenacao(lista1);
        }

      break;

      case 16:  // calcula tamanho de lista recursivamente

        //usuario escolhe qual lista calcular o tamanho
        do{
          printf("\nQual das listas gostaria de checar? ");
          scanf("%d", &opcao);
        }while(opcao != 1 && opcao != 2 && opcao != 3);

        if(opcao == 1) {
          printf("O tamanho da lista e de %d alunos.", calculaTamanho(*lista1));
        }

        if(opcao == 2) {
          printf("O tamanho da lista e de %d alunos.", calculaTamanho(*lista2));
        }

        if(opcao == 3){
          printf("O tamanho da lista e de %d alunos.", calculaTamanho(*lista1));
        }

      break;

      case 17:  // calculaTamanho segunda edicao

        //usuario escolhe qual lista calcular o tamanho
        do{
          printf("\nQual das listas gostaria de checar? ");
          scanf("%d", &opcao);
        }while(opcao != 1 && opcao != 2 && opcao != 3);

        if(opcao == 1) {
          printf("O tamanho da lista e de %d alunos.", calculaTamanhoMindBlownEdition(lista1));
        }

        if(opcao == 2) {
          printf("O tamanho da lista e de %d alunos.", calculaTamanhoMindBlownEdition(lista2));
        }

        if(opcao == 3){
          printf("O tamanho da lista e de %d alunos.", calculaTamanhoMindBlownEdition(lista1));
        }
      break;

      case 18:  // libera memória e finaliza programa

        liberar_lista(lista1);
        liberar_lista(lista2);
        liberar_lista(lista3);
        printf("\nFinalizando...");
        break;        

      default:
        printf("\nOpção inválida!");
        break;
    }

  } while(opcao != 18);

  return 0;
}

