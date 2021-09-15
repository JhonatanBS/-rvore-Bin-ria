#include <stdio.h>
#include <stdlib.h>
#include "heapBinario.h"
#define tam 30

int* criaVetor(int *v){
    int i;
     printf("Digite o tamanho do vetor:");
     scanf("%d",&tamanho);

     v = (int*)calloc(tamanho,sizeof(int));
   
  /* for(i=1;i<tamanho;i++){
       v[i]=i;
   }*/
   return v;
}

int* insere(int *v,int n){
     if(pos < tamanho)
         v[pos++] = n;
     else if(pos >= tamanho-1)
         printf("\nFila cheia!!!"); 
         printf("%d\n",pos); 
 return v;
}

int* excluir(int *v){
    int copia;
    copia = v[1];
    v[1] = v[pos-1];
    v[pos-1] = copia;
    pos--;

    return v;
}

int* heapMax(int* v){
   int i=1,troca,aux=1;

     while(aux != 0){
         aux=1;
             for(i=1;i<tamanho;i++){
                 int filho_esq = 2*i,filho_dir = 2*i+1;
       
                 if(filho_esq < tamanho && filho_dir < tamanho){
                     if(v[filho_esq] > v[filho_dir] && v[i] < v[filho_esq]){
                         troca = v[i];
                         v[i] = v[filho_esq];
                         v[filho_esq] = troca;
                         aux++;
                     }
                     else if(v[filho_esq] < v[filho_dir] && v[i] < v[filho_dir]){
                         troca = v[i];
                         v[i] = v[filho_dir];
                         v[filho_dir] = troca; 
                         aux++; 
                     }
                                                               }
             }//Fim do for
         aux--;
                     }//Fim do While

    return v;
}

int* heapMin(int* v){
   int i=1,troca,aux=1;

     while(aux != 0){
         aux=1;
             for(i=1;i<tamanho;i++){
                 int filho_esq = 2*i,filho_dir = 2*i+1;
       
                 if(filho_esq < tamanho && filho_dir < tamanho){
                     if(v[filho_esq] < v[filho_dir] && v[i] > v[filho_esq]){
                         troca = v[i];
                         v[i] = v[filho_esq];
                         v[filho_esq] = troca;
                         aux++;
                     }
                     else if(v[filho_esq] > v[filho_dir] && v[i] > v[filho_dir]){
                         troca = v[i];
                         v[i] = v[filho_dir];
                         v[filho_dir] = troca; 
                         aux++; 
                     }
                                                               }
             }//Fim do for
         aux--;
                     }//Fim do While

    return v;
}

int* imprime(int* v){
    int i;
    for(i=1;i<tamanho;i++){
       printf("|%d",v[i]);
    }
    return v;
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
   CriarMenu(tam,"MENU ARVORE");
   CriarMenu(tam,"0 - Sair");
   CriarMenu(tam,"1 - Cria o vetor");
   CriarMenu(tam,"2 - Insere");
   CriarMenu(tam,"3 - Excluir");
   CriarMenu(tam,"4 - Heap Maximo");
   CriarMenu(tam,"5 - Heap Minimo");
   CriarMenu(tam,"6 - Imprime");
   criarLinhaRodape(tam);
}