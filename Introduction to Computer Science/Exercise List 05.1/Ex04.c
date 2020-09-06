#include <stdio.h>
/*Foi feita uma pesquisa entre os habitantes de uma região. Foram coletados os dados de idade,
   sexo  (M/F)  e  salário.  Faça  um  algoritmo  que  informe: a  média  de  salário  do grupo;
   maior  e  menor  idade  do  grupo  e  aquantidade  de  mulheres  com  salário  até R$100,00. 
   Encerre a entrada de dados quando for digitada uma idade negativa.
*/

int main(void) {
    int idade, nhomens=0, nmulheres=0, sexismo=0, maiorhomens=0, menorhomens=maiorhomens, maiormulheres=0, menormulheres=maiormulheres;
    float salario, somahomens=0, somamulheres=0;
    char sexo;
 
    printf("Obs. Digite um valor negativo na idade para encerrar o programa.\n");

    do {
        printf("Insira a idade da pessoa e tecle enter: ");
        scanf("%d", &idade);

        if (idade >= 0) {

            printf("Agora, insira o sexo (F ou M): ");
            scanf(" %c", &sexo);
            printf("Por fim, insira o salario: \n");
            scanf("%f", &salario);
            printf("\n");
        
            switch (sexo) {
                case 'm':
                case 'M':
                    nhomens++;
                    somahomens = somahomens + salario;
                    if (idade > maiorhomens)
                        maiorhomens = idade;
                    if (idade < menorhomens)
                        menorhomens = idade;
                break;

                case 'f':
                case 'F':
                    nmulheres++;
                    somamulheres = somamulheres + salario;
                    if (idade > maiormulheres)
                        maiormulheres = idade;
                    if (idade < menormulheres)
                        menormulheres = idade;
                    if (salario < 100)
                        sexismo++;
                break; 

                default:
                    printf("O sexo inserido e invalido.\nUtilize f para feminino, e m para masculino.\n");
            } 
        }
    }
    while (idade >= 0);

    somahomens = somahomens / nhomens;
    somamulheres = somamulheres / nmulheres;

    printf("\nPara o grupo do sexo feminino:\nA media dos salarios e igual a %.2f.\nA maior idade e %d anos.\nA menor e de %d anos.\nO numero de mulheres que recebem menos de 100 reais e de %d.\n\nPara o grupo do sexo masculino:\nA media dos salarios e igual a %.2f.\nA menor idade e igual a %d.\nA maior e igual a %d.", somamulheres, maiormulheres, menormulheres, sexismo, somahomens, menorhomens, maiorhomens);

  //como calcular a menor das idades? se idade e menor que o que?
  //nao consigo pensar em algo alem da gambiarra :(
  //eu poderia inicializar a idade no inicio, e ja iguala-la a menor antes de entrar na estrutura de repeticao, mas isso nao seria nada elegante.
}
