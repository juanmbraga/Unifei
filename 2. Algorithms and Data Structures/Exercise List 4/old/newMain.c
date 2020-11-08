
// bibliotecas do sistema
#include <stdio.h>
#include <stdlib.h>

// biblioteca do projeto
#include "banco.h"


int main(void) {

    // Declaracao e inicializacao das listas para senhas e as de espera
    Fila* fila[5];
    for(int i=0; i<5; i++){
        fila[i] = criaFila(i);
    }

    /* Nota:
        Aqui, optei por usar um vetor de ponteiros para as filas, que, apesar de sacrificar claridade de leitura,
      se prova util ao usar lacos para acoes repetidas entre as filas, o que 
      a maneira que eu estava fazendo anteriormente (filaXP, filaXC, ...) nao me permitia.
    */

    int ok, tamanho, opcao, opcao2, estado = 0, contador[6], atendimentos[5] /*para coincidir com numeros*/, perfil;
    char opcao3;

    // verificar a inicializacao das filas
    for(int i=0; i<5; i++){

        // caso algo de errado aconteceu, libere tudo saia. 
        if(fila[i] == NULL){
            printf("\nErro na alocacao das filas na memoria!\nEncerrando o programa. Tecle enter para sair...");
            getchar();
            getchar();
            for(int j=0; j<5; j++){
                free(fila[j]);
            }
        }
    }

    // menu com opcoes para cliente (retirar) e atendentes (inicializar e chamar)
    do{
        system("clear");
        printf("\n\nMenu de opções");
        printf("\n1 - Iniciar atendimento");
        printf("\n2 - Iniciar retirada de senhas");
        printf("\n3 - Chamar proxima senha");
        printf("\n4 - Sair");
        printf("\nOpção: ");
        scanf("%d", &opcao);

        switch(opcao){

        // Iniciar atendimento (gerar senhas)
        case 1:

            // verificar se senhas ja foram geradas anteriormente
            if(estado != 0){
                printf("\nAs senhas ja foram geradas. Para criar mais reinicie o programa.\nTecle enter para retornar...");
                getchar();
                getchar();
                break;
            }

            // receber a entrada de atendimentos do usuario
            do{
                printf("\n Insira o limite de atendimentos do dia: ");
                scanf("%d", &tamanho);
            } while(tamanho < 1);

            // gerar uma fila de senhas com o numero atendimentos
            ok = geraSenhas(fila[0], tamanho);

            // verificar saida (como a alocacao da fila e entrada de atendimentos foi verificada, nao e preciso ver os retornos (1)(-1)(2))
            if(ok == 0){
                printf("\nSenhas geradas com sucesso!");
                estado = 1; 
            }
            else {
                printf("\nErro ao gerar a fila.");
            }

            printf(" Tecle ENTER para continuar...");
            getchar();
            getchar();

        break;

        // Retirar senha
        case 2:

            // verificar se senhas ja foram geradas
            if(estado != 1){
                printf("\nAs senhas ainda nao foram geradas.\nTecle ENTER para continuar...");
                getchar();
                getchar();
                break;
            }

            // solicitar e armazenar todas as senhas de acordo com perfil dos clientes
            ok = retirarSenhas(fila, atendimentos);

            estado == 2;

            // caso algum erro grave tenha acontecido, saia
            if(ok == -1){
                printf("\n\nErro em passagem das filas. O programa sera encerrado...");
                getchar(); 
                getchar();
                opcao = 4; 
            }

        break;

        // chamar a proxima senha
        case 3:
            
            if(estado != 2){
                printf("\nAs senhas ainda nao foram retiradas. Tecle ENTER para continuar...");
                getchar();
                getchar();
                break;
            }

            for(int i=0; i < tamanho; i++){

                // definir valor para chamada de perfil (0-> convencional, 1-> preferencial, 2-> pref.)
                perfil = (perfil + 1) % 3;

                
            }


            //a fazer...

            // verificar se senhas ja foram geradas e retiradas

            // loop que repete seguindo o total de senhas inseridas:

                // melhor denfinir preferencial ou convencional primeiro 
                // duas chamadas preferenciais + 1 convencional:
                // somar 1 ao numero, e salvar o resultado da divisao inteira (mais eficiente que usar um if para zerar toda vez)
                // counter = (counter + 1) % 3
                // (1, 2, 0, 1, 2, 0, 1, ...)
                // iniciando em um, se counter for igual a zero, chama-se convencional, senao, chame preferencial

                // definido o tipo de atendimento, comecar a checar as listas por disponibilidade de senhas

                // chamada aleatoria dos tipos (negocial ou caixa): 
                // gerar numero aleatorio e verificar o resultado de divisao inteira por dois. 
                // se for 1 chame um deles, se for zero chame outro. 1= negocial 0=caixa

                // verificacao (EXEMPLO): convencional (perfil definido) e negocial (tipo aleatorio)
                // Fila "negocial convencional" possui elementos? se sim chame dai
                // senao, veja se a fila "caixa convencional" possui senhas. Se sim chame dai
                // senao, (produzir um aviso? e) veja o outro tipo (preferencial) no tipo sorteado (caixa), e caso tiver chame dai 
                // senao, chame do ultimo remanescente (caixa preferencial)

                // como chamar a senha: 
                // usar funcao de consulta do inicio para imprimir
                // desenfileirar (pensar em como usar o indice numerico para nao ficar enorme)
                // reduzir um do numero de senhas restantes 
                
            // nao e preciso se preocupar com nenhuma das verificacoes resultarem em alguma chamada
            // uma vez que o numero de senhas adicionadas definira as repeticoes do laco. 

        break;

        // verificar senhas remanescentes, liberar filas e encerrar programa
        case 4:
            
            // inicializar variavel que determina se ha qualquer fila nao vazia
            contador[5] = 0;

            // verificar a existencia de senhas nas filas
            for(int i=0; i<5; i++){
                // se a fila nao estiver vazia
                if(tamanhoFila(fila[i]) != 0){
                    // adicione um ao contador
                    contador[i] = 1;
                    // adicione a casa que sinaliza a existencia de senhas remanescentes
                    contador[5]++;
                } else {
                    // se nao, adicione zero (assim evita ter que inicializar "contador" toda vez que chegar ao fim)
                    contador[i] = 0;
                }
            }

            // caso ainda existirem senhas remanescentes, mostreas e pergunte se deseja limpar e sair
            if(contador[5] != 0){

                // informe o usuario de quais ainda possuem senhas
                printf("\nAinda existem %d filas com itens:", contador[5]); 
                if(contador[0]==1){
                    printf(" ainda ha senhas disponiveis para retirada,");
                }
                if(contador[1]==1){
                    printf(" no Caixa Preferencial,");
                }
                if(contador[2]==1){
                    printf(" no Caixa Convencional,");
                }
                if(contador[3]==1){
                    printf(" no Negocial Preferencial,");
                }
                if(contador[4]==1){
                    printf(" no Negocial Convencional,");
                }

                // pergunte se deseja continuar
                printf(" gostaria de continuar e sair? (S para sim e N para nao)\n");
                do{
                    scanf("%c", &opcao3);
                } while(opcao3 == 'n' && opcao3 == 'N' && opcao3 == 's' && opcao3 == 'S');

                // retornar ao menu caso usuario tenha optado.
                if(opcao3 == 'n' || opcao3 == 'N'){
                    opcao = 1; // diferente de '4'
                    continue;   //ir para proxima iteracao
                }
            }

            // imprimir o numero de atendimentos 
            printf("\nTotal de atendimentos de cada mesa:");
            printf("\nCaixa - %d atendidos", atendimentos[0]);
            printf("\nNegocial- %d atendidos", atendimentos[1]);

            // libera todas as filas
            for(int i=0; i<5; i++){
                liberaFila(fila[i]);
            }

        break;

        default:
            printf("\nOpção inválida!");
            opcao = 1; //caso o usuario digite '4' acidentalmente
        break;
        }
    } while(opcao != 4);

    // libera todas as filas apos saida do loop
    for(int i=0; i<5; i++){
        liberaFila(fila[i]);
    }

    printf("\nEncerrando programa...");
    getchar();
    getchar();

    return 0;
}
