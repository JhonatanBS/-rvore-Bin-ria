/*Variáveis globais*/
int tamanho,pos=1;
/*Cria um sinonimo para o tipo de dado inteiro*/
typedef int Heap;
/*Minhas funções principais do Heap Sort*/
int* criaVetor(int *v);
int* insere(int *v,int);
int* excluir(int *v);
int* heapMax(int* v);
int* heapMin(int* v);
/*Funçoes para o Menu*/
void criarLinhaSuperior(int tamx);
void criarLinhaRodape(int tamx);
void CriarMenu(int tamx,char str[]);
void menu();
void criaLinhaHorizontal(int tamx);
/*Funções para visualização do Vetor*/
void imprimeVetor(int x,int *v);
void vetorSuperior(int tamx);
void vetorRodape(int tamx);
/*Funções para visualização da árvore Heap*/
void imprimeArvore(int* v);
void arvoreSuperior(int tamx);