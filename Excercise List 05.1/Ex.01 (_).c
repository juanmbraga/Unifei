 #include <stdio.h>
/*Faça um programa que receba a idade e o peso de quinze pessoas, calcule e mostre as médias dos pesos das pessoas da mesma faixa etária. As faixas etárias são: 
de 1 a 10 anos, 
de 11 a 20 anos, 
de 21 a 30 anos e 
acima de 31 anos.*/

int main(void) {
  int i, age, numten=0, numtwenty=0, numthirty=0, numremainder=0;
  float wheigh, ten=0, twenty=0, thirty=0, remainder=0;

  //pra que serve o programa.
  printf("Saiba a media dos pesos de quinze pessoas de diferentes faixas etarias.");

  for (i=0;i<5;i++) {

    //insercao dos dados
    printf("Insira a idade: ");
    scanf("%d", &age);
    printf("Insira o peso: ");
    scanf("%f", &wheigh);

    //se peso e valido, execute while
    if (wheigh > 0 && wheigh < 635) //"List of heaviest people" -Wiki

      //categorizacao
      switch (age) {
        case 1 ... 10:
          ten = ten + wheigh;
          numten++;
          break; 
        case 11 ... 20:
          twenty = twenty + wheigh;
          numtwenty++;
          break;
        case 21 ... 30:
          thirty = thirty + wheigh;
          numthirty++;
          break;
        case 31 ... 122: //"List of the verified oldest people" -Wiki
          remainder = remainder + wheigh;
          numremainder++;
          break;
        //idade e automaticamente verificada pela funcao while  
        default: {
          printf("Idade invalida.\n"); 
          i--;
          }} 

    //se peso e invalido, reduza uma iteracao para repetir as acoes
    else 
    i--;
  }

  printf("A media dos pesos para cada faixa etaria e: \n\n Ate dez anos: %f. \n\nDe onze ate vinte anos: %f.\n\nDe vinte e um ate trinta anos: %f.\n\nAcima de trinta anos: %f.", ten/numten, twenty/numtwenty, thirty/numthirty, remainder/numremainder);

  return 0;
}

//e preciso que eu SEMPRE verifique se o numero inserido na variavel inteiro e de fato inteiro? pois pode causar problema, mas e consideravelmente chatinho...