//IMPORTANTE

/*
9.O que é impresso nos seguintes códigos?

Código 1
__________________________________________________________
#include<stdio.h>
int x = 0;
int main(){
    int i, x = 1;
    printf("%d\n", x);
    for (i=0;i<4;i++){
        int x = 2;
        printf("%d/ ", x);
        {
            int x = 3;
            printf("%d/ ", x);
        }
    }
    printf("\n%d", x);
}__________________________________________________________



Código 2
___________________________________________________________
#include<stdio.h>
int w = 1, x=2,y=3,z=4;
void foo(int y){
    int z = 6;
    printf("%d %d %d %d \n", w, x, y, z);
}

int main(){
    int x = 7;
    foo(5);
    foo(x);
    printf("%d %d %d %d \n", w, x, y, z);
}__________________________________________________________
*/

//Codigo 1: x sera sempre alterado, pois para o valor ser global o codigo "define" deve ser usado.
//alem disso, a variavel x fora declarada dentro das funções "for()" e "main()", entao pode assumir valores diferentes.
//curioso!

//Codigo 2: a o computador fara uso das variaveis "globais" declaradas fora, mas sempre e possivel
//declarar uma de mesmo nome dentro delas, e esta valera (para a funcao em questao, apenas). 