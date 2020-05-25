/*
2.Escreva uma função que receba como parâmetro 2 números inteiros e 
positivos e um caractere que deve indicar a operação que deve ser realizada 
entre os dois números seguindo a ordem com que foram digitados. 
Retorne o resultado da operação. Caso o  segundo  número  digitado for igual  a  0
e  a  operação  escolhida  for  a  divisão,a função não deve ser chamada e deve ser 
exibida uma mensagem de erro ao usuário. Utilize a função no programa principal.
*/

float opere (int x, int y, char z) {
    switch (z)
    {
    case 'a':
    case 'A':
        return (x+y);
        break;
    case 's':
    case 'S':
        return (x-y);
        break;
    case 'm':
    case 'M':
        return (x*y);
        break;
    case 'd':
    case 'D':
        if(y==0)
            printf("\nErro.");
        else
            return (x/y);
        break;
    default:
    
        break;
    }
}