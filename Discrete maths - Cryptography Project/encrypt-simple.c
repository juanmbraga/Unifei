#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fazer para cada letra individualmente, depois expandir para vetor, depois adicionar manipulacao de arquivo.
// nao estou com muita paciencia hoje para fazer verificacoes e uma interacao com o usuario muito boa.

//Encode single letter
int encodeL(int, int);

int main(void) {
  int letra, segredo[3], length, aux=0;

  // alocar dinamicamente
  char* inicio = (char*) malloc(sizeof(char));
  if(inicio==NULL) exit(1);
  char* final = (char*) malloc(sizeof(char));
  if(final==NULL) exit(1);

  // info
  system("cls");
  printf("Criptografe uma mensagem!");
  printf("\npor Juan Marcos Braga Faria,");
  printf("\n1 de Novembro, 2020.");
  printf("\n\nNote: as mensagens devem conter apenas letras maiusculas (sem numeros ou espacos);\ne o tamanho limite da mensagem e de 2000 letras.\n\nEstrutura:\nDATA MENSAGEM A SER TRANSMITIDA\nMENSAGEMASERCRIPTOGRAFADA");

  // ler a mensagem
  printf("\n\nDigite a mensagem a criptografar:\n\n");
  scanf(" %[^\n]", inicio);
  scanf(" %[^\n]", final);
  
  // extrair a data
  sscanf(inicio,"%d/%d/%d", &segredo[0], &segredo[1], &segredo[2]);

  // ler o tamanho da mensagem
  length = strlen(final);

  // imprimir a mensagem criptografada
  printf("\n\nA mensagem final e:\n\n");
  
  for(int i=0; i<=length; i++){
    printf("%c", (char) encodeL((int) final[i], segredo[aux]));
    aux = (aux + 1) % 3;
  }

  printf("\n\nFim da mensagem. Tecle enter para sair...");
  getchar();
  getchar();

  free(inicio);
  free(final);
  
  return 0;
}

int encodeL(int letra, int codigo){
  if(letra < 65 || letra > 90 || codigo < 0){
    return 0;
  }

  // para corrigir o problema da divisao inteira ser zero, e o numero ser 64 (@)

  int temp = 64 + ((letra + codigo -64) % 26);
  if(temp == 64) return 65;
  return temp;
}