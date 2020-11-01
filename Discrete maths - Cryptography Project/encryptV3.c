#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fazer para cada letra individualmente, depois expandir para vetor, depois adicionar manipulacao de arquivo.
// nao estou com muita paciencia hoje para fazer verificacoes e uma interacao com o usuario muito boa.

char* encrypt(char* forecast, char* message);

int main(void) {
  int letra, length, aux=0;
  char* criptografada;

  // alocar dinamicamente
  char* inicio = (char*) malloc(sizeof(char)*400);
  if(inicio==NULL) exit(1);
  char* final = (char*) malloc(sizeof(char)*2000);
  if(final==NULL) exit(1);

  // info
  system("cls");
  printf("Criptografe uma mensagem!");
  printf("\npor Juan Marcos Braga Faria,");
  printf("\n1 de Novembro, 2020.");
  printf("\n\nNote: as mensagens devem conter apenas letras maiusculas (sem numeros ou espacos); O tamanho limite da mensagem e de 2000 letras.\n\nEstrutura:\nDATA MENSAGEM\nMENSAGEMASERCRIPTOGRAFADA");

  // ler a mensagem
  printf("\n\n\nDigite a mensagem a criptografar:\n\n");
  fgets(inicio, 200, stdin);
  fgets(final, 2000, stdin);

  // criptografar a mensagem
  criptografada = encrypt(inicio, final);
  if(criptografada == NULL){
    printf("\nErro de sintaxe ou de alocacao. Tecle enter para sair...");
    getchar();
    getchar();
    return 0;
  }

  // extrair o tamanho da mensagem
  length = strlen(criptografada);

  // imprimir a mensagem criptografada
  printf("\n\nA mensagem criptografada e:\n\n\n");
  printf("%s", criptografada);

  printf("\n\nFim da mensagem. Tecle enter para sair...");
  getchar();
  getchar();

  free(inicio);
  free(final);
  free(criptografada);
  
  return 0;
}

char* encrypt(char* forecast, char* message){
  int key[3], length;

  // extract the date
  sscanf(forecast,"%d/%d/%d", &key[0], &key[1], &key[2]);

  // verify the syntax anf values of date
  if(key[0] < 0 || key[1] < 0 || key[2] < 0 || key[0] > 31 || key[1] > 12 /*leave year in open*/){
    return NULL;
  }

  // get size to verify string
  length = strlen(message);

  // check if characters are between A and Z
  for(int i=0; i<length-1; i++){  //LENGTH-1 PARA REMOVER O \n
    if(65 > (int)message[i] || 90 < (int)message[i]){
      return NULL;
    }
  }

  // (m)allocate new array for encrypted message
  char* encrypted = (char*) malloc((length+1)*sizeof(char));
  if(encrypted == NULL){
    return NULL;
  }

  int i;  // i here is to add EOF (end of file) at the end during the encryption (for)
  int aux=0;  // vary between keys (day/month/year)

  // create new message
  for(i=0; i<length-1; i++){
    encrypted[i] = (char) ((message[i] + key[aux] -64) % 26) + 64;
    if(encrypted[i] == 64) 
      encrypted[i]++;
    aux = (aux + 1) % 3;
  }

  encrypted[i] = message[i];  //for \n
  encrypted[i+1] = message[i+1]; //for EOF

  return encrypted;
}