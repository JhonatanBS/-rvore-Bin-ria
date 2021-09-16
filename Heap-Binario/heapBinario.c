/*Bibliotecas padrões*/
#include <stdio.h>
#include <stdlib.h>
#include "heapBinario.h"/*Importa o arquivo*/
#define tam 30/*Constante*/
enum raiz {pai = 40};/*Constante*/

/*Função cria um vetor de forma dinâmica*/
int* criaVetor(int *v){
     int i;/*Variavel*/
         printf("Digite o tamanho do vetor:");
         scanf("%d",&tamanho);
     /*Gera um vetor através de alocação dinamica*/
     v = (int*)calloc(tamanho,sizeof(int));
   
   return v;/*Retorna o vetor*/
}
/*Função que insere um valor dentro do vetor*/
int* insere(int *v,int n){
    /*A posição do vetor precisa ser menor que o tamanho do vetor*/
     if(pos < tamanho)/*A posição do vetor tende a incrementanda conforme insere elementos dentro do vetor*/
         v[pos++] = n;/*Insere o valor digitado pelo usuário no índice 1 até o tamanho maximo do vetor*/
     else if(pos >= tamanho-1)/*Vetor cheio*/
         printf("\nFila de Prioridades cheia!!!"); 
 return v;
}
/*Função que exclui o valor dentro do vetor*/
int* excluir(int *v){
    int copia;/*Variavel para guardar o valor do índice 1 do vetor*/
    copia = v[1];/*Guarda o valor do vetor*/
    v[1] = v[pos-1];/*O vetor no índice 1 recebe o valor do último elemento do vetor*/
    v[pos-1] = copia;/*A última posição do vetor recebe a primeira*/
    pos--;/*Diminui o vetor*/

    return v;/*Retorna o vetor*/
}
/*Função que os pais ou subárvores são maiores que seus filhos*/
int* heapMax(int* v){
   int i=1,troca,aux=1;/*variáveis*/

     while(aux != 0){/*Enquanto aux for diferente de 0*/
         aux=1;/*Atualiza a variavel para a quantidade de trocas*/
             for(i=1;i<tamanho;i++){/*Caminha pelo vetor*/
                 int filho_esq = 2*i,filho_dir = 2*i+1;/*Filho esquerdo e Filho direito*/
       
                 if(filho_esq < tamanho && filho_dir < tamanho){/*A relação do indice do vetor não pode ser maior que o tamanho do vetor*/
                     if(v[filho_esq] > v[filho_dir] && v[i] < v[filho_esq]){/*Verifica o maior entre os filhos e o maior entre o pai e o filho maior*/
                         troca = v[i];/*Guarda o valor do vetor analizado*/
                         v[i] = v[filho_esq];/*Recebe o valor do filho da esquerda*/
                         v[filho_esq] = troca;/*Faz o filho da esquerda receber o valor pai*/
                         aux++;/*Incrementa*/
                     }
                     else if(v[filho_esq] < v[filho_dir] && v[i] < v[filho_dir]){/*Verifica o maior entre os filhos e o maior entre o pai e o filho maior*/
                         troca = v[i];/*Guarda o valor do vetor analizado*/
                         v[i] = v[filho_dir];/*Recebe o valor do filho da direita*/
                         v[filho_dir] = troca;/*Faz o filho da direita receber o valor pai*/ 
                         aux++; /*Incrementa*/
                     }
                                                               }
             }//Fim do for
         aux--;/*decremento*/
                     }//Fim do While

    return v;/*Retorna o vetor*/
}
/*Função que os pais ou subárvores são menores que seus filhos*/
int* heapMin(int* v){
   int i=1,troca,aux=1;/*variáveis*/

     while(aux != 0){/*Enquanto aux for diferente de 0*/
         aux=1;/*Atualiza a variavel para a quantidade de trocas*/
             for(i=1;i<tamanho;i++){/*Caminha pelo Vetor*/
                 int filho_esq = 2*i,filho_dir = 2*i+1;/*Filho esquerdo e Filho direito*/
       
                 if(filho_esq < tamanho && filho_dir < tamanho){/*A relação do indice do vetor não pode ser maior que o tamanho do vetor*/
                     if(v[filho_esq] < v[filho_dir] && v[i] > v[filho_esq]){/*Verifica o menor entre os filhos e o menor entre o pai e o filho menor*/
                         troca = v[i];/*Guarda o valor do vetor analizado*/
                         v[i] = v[filho_esq];/*Recebe o valor do filho da esquerda*/
                         v[filho_esq] = troca;/*Faz o filho da esquerda receber o valor pai*/
                         aux++;/*Incremento*/
                     }
                     else if(v[filho_esq] > v[filho_dir] && v[i] > v[filho_dir]){
                         troca = v[i];/*Guarda o valor do vetor analizado*/
                         v[i] = v[filho_dir];/*Recebe o valor do filho da direita*/
                         v[filho_dir] = troca; /*Faz o filho da direita receber o valor pai*/
                         aux++;/*Incrementa*/ 
                     }
                                                               }
             }//Fim do for
         aux--;/*Decrementa*/
                     }//Fim do While

    return v;/*Retorna o vetor*/
}


void criarLinhaSuperior(int tamx){//Criar linhas duplas em cima do Menu
    int i;
    printf("%c",201);
    for(i = 0;i<tam;i++){
        printf("%c",205);
    }
    printf("%c\n",187);
}

void criarLinhaRodape(int tamx){//Criar linhas duplas em baixo do Menu
    int i;
    printf("%c",200);
    for(i = 0;i<tamx;i++){
        printf("%c",205);
    }
    printf("%c\n",188);
}

void CriarMenu(int tamx,char str[]){//Criar linhas duplas nas laterais do Menu
   int i,contador=0;
   for(i = 0;i<tamx;i++){
       if(str[i] == '\0')
       break;
       else
          contador++;
       }
    printf("%c",186);
        printf("%s",str);
     while(contador<tamx){
         printf("%c",32);
         contador++;
     }
    
    printf("%c\n",186);
}

void menu(){
   system("color F0");//Define a cor do terminal (4->Fundo e 0->Cor das letras)
   printf("\n");
   criarLinhaSuperior(tam);
   CriarMenu(tam,"HEAP SORT");
   criaLinhaHorizontal(tam);
   CriarMenu(tam,"0 - Sair");
   CriarMenu(tam,"1 - Cria o vetor");
   CriarMenu(tam,"2 - Insere");
   CriarMenu(tam,"3 - Excluir");
   CriarMenu(tam,"4 - Heap Maximo");
   CriarMenu(tam,"5 - Heap Minimo");
   CriarMenu(tam,"6 - Imprime o Vetor");
   CriarMenu(tam,"7 - Imprime a arvore");
   criarLinhaRodape(tam);
}

void criaLinhaHorizontal(int tamx){
    int i;
    printf("%c", 204);
    for(i=0;i<tamx;i++){
        printf("%c", 205);
    }
    printf("%c\n", 185);
}

void imprimeVetor(int x,int *v){
    vetorSuperior(x*3);
    printf("%c",186);
    printf("  ");
    printf(" %c",186);
    for(int i=1;i<x;i++){
             printf(" %d",v[i]);
             printf(" %c",186);    
 }
    printf("\n");
    vetorRodape(x*3);
 
}

void vetorSuperior(int tamx){//Criar linhas duplas em cima do Menu
    int i,j=1;
    int tres = 3;
    printf("%c",201);
    for(i = 0;i<tamx;i++){
        if(i == j*tres && i != 0){
            printf("%c",203);
            j++;
        }
        printf("%c",205);
    }
    printf("%c\n",187);
}

void vetorRodape(int tamx){//Criar linhas duplas em baixo do Menu
    int i,j=1;
    int tres = 3;
    printf("%c",200);
    for(i = 0;i<tamx;i++){
        if(i == j*tres && i != 0){
            printf("%c",202);
            j++;
        }
        printf("%c",205);
    }
    printf("%c\n",188);
}

void imprimeArvore(int* v){
    int i;
    
    for(i=1;i<pai;i++){
       if(i == (pai-3)/2)
           printf("\t\t  %d",v[1]);
       else
           printf("%c",32);    
    }
    printf("\n");
    printf("\t");
    arvoreSuperior(pai);
    printf("\n");

     for(i=1;i<pai;i++){
       if(i == 1){
             printf("\t\t");
             printf(" %d",v[2]);
       }
       else if(i == pai-1){ 
             printf("  %d",v[3]); 
       }  
       else
           printf("%c",32);    
    }
    printf("\n");
    arvoreSuperior(pai/2);
    printf("\t\t");
    arvoreSuperior(pai/2);
    printf("\n");
     for(i=1;i<pai;i++){
       if(i == 1){
             printf("  \t %d",v[4]);
             printf("   \t\t     %d",v[5]);
             printf("  \t\t %d",v[6]);
             printf(" \t\t     %d",v[7]);
       }    
    }
}

void arvoreSuperior(int tamx){//Criar linhas duplas em cima do Menu
    int i;
    printf("\t ");
    printf("%c",201);
    for(i = 1;i<tamx;i++){
        printf("%c",205);
    }
    printf("%c",187);
}

