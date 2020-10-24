//Definindo os tipos//
#define CIL 0
#define CUB 1
#define ESF 2
#define CONE 3
#define PARA 4
   
//Definindo o Pi
#define Pi 3.1415


//Definir elemento de lista para usar na main
typedef struct elemento elemento;


//Definindo os registros para os solidos geometricos//

//Cilindro (raio e altura)
typedef struct cilindro {
  float r, h;
} cilindro;

//Cubo (aresta)
typedef struct cubo{
  float a;
} cubo;

//Esfera (raio)
typedef struct esfera{
  float r;
} esfera;

//Cone (raio da base e altura)
typedef struct cone {
  float r, h;
} cone;

//Paralelepipedo (comprimento, altura e lagura)
typedef struct paralelepipedo {
  float c, h, l;
} paral;



//Prototipos das funções: 

//Cria a lista a partir de um arquivo:
elemento* geralista();

//Libera a lista:
int liberar_lista(elemento **li);



//Funções para inserir objetos na lista:

// Insere objeto no início da lista:
int inserirInicio(elemento **li, int tipo);

// Insere objeto no final da lista:
int inserirfinal(elemento **li, int tipo);



//Funções para remover objetos da lista:

//Remove objeto do ínicio da lista:
int removeInicio(elemento** li);
//Remove objeto do fim da lista:
int removeFim(elemento** li);
//Remove o objeto por posição na lista completa:
int removerposicao(int pos, elemento **li);



// Funções para imprimir a lista:

//imprime a lista completa
int imprimeLista(elemento* li);
//imprime a lista por busca:
int imprimelistacategoria(elemento* li, int forma);



//Funções para criar os sólidos geométricos do tipo elemento:

//Cria o objeto cilindro:
elemento* cria_cilindro ();

//Cria o objeto cubo:
elemento* cria_cubo ();

//Cria o objeto esfera:
elemento* cria_esfera();

//Cria o objeto cone
elemento* cria_cone();

//Cria o objeto paralelepípedo
elemento* cria_paral ();



//Cria os objetos de acordo com sua forma
elemento* criaElemento(int forma);

//Calcula o volume
float calculaVolume (elemento* li);

//Imprime Volume:
int imprimeVolume(elemento* item);

//Função para o usuário escolher qual sólido geométrico será adicionado nas funções de inserir na lista
int selecionaForma();

//1=sem memoria, 2=lista vazia, 3=lista ja existe, 4= Elemento inválido/vazio
void erro(int tipo);