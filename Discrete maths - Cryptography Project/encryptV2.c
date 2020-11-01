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
  char* inicio = (char*) malloc(sizeof(char)*400);
  if(inicio==NULL) exit(1);
  char* final = (char*) malloc(sizeof(char)*2000);
  if(final==NULL) exit(1);

  // info
  system("clear");
  printf("Criptografe uma mensagem!");
  printf("\npor Juan Marcos Braga Faria,");
  printf("\n1 de Novembro, 2020.");
  printf("\n\nNote: as mensagens devem conter apenas letras maiusculas (sem numeros ou espacos); O tamanho limite da mensagem e de 2000 letras.\n\nEstrutura:\nDATA MENSAGEM\nMENSAGEMASERCRIPTOGRAFADA");

  // ler a mensagem
  printf("\n\nDigite a mensagem a criptografar:\n\n");
  fgets(inicio, 200, stdin);
  fgets(final, 2000, stdin);
  
  // extrair a data
  sscanf(inicio,"%d/%d/%d", &segredo[0], &segredo[1], &segredo[2]);

  // verificar a sintaxe da data
  if(segredo[0] < 0 || segredo[1] < 0 || segredo[2] < 0 || segredo[0] > 31 || segredo[1] > 12 /*deixar ano em branco*/){
    printf("\nSintaxe incorreta. Tecle enter para sair...");
    getchar();
    getchar();
  }

  // liberar memoria extra nao utilizada
  free(inicio);

  // ler o tamanho da mensagem para imprimir e checar
  length = strlen(final);

  // checar se caracteres da mensagem estao entre os numeros da tabela ascii
  for(int i=0; i<length-1; i++){  //LENGTH-1 PARA REMOVER O \n
    if(65 > (int)final[i] || 90 < (int)final[i]){
      printf("\nSintaxe incorreta. Tecle enter para sair...");
      getchar();
      getchar();
    }
  }

  // imprimir a mensagem criptografada
  printf("\n\nA mensagem criptografada e:\n\n");
  
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