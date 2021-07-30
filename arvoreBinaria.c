#include <stdio.h>
#include <stdlib.h>
#include "arvoreBinaria.h"
#define tam 30

Arvore* insere(Arvore* a, int n){
    Arvore* novo = (Arvore*)malloc(sizeof(Arvore));
    if(novo == NULL){
        printf("Erro na alocação de Memória!");
        exit(1);
    }
    
    novo->valor = n;
    novo->direita = NULL;
    novo->esquerda = NULL;
    //Inserção na raiz,quando a árvore estiver vazia
    if(a == NULL){
        a = novo;
    //Senão estiver vazia, inserçao das sub-árvores    
    }else{
        Arvore* atual = a, *ant = NULL;
        while(atual != NULL){
            ant = atual;
            //Libera novo, caso tenha um número igual
            if(n == atual->valor){
                free(novo);
                return a;
            }

            if(n > atual->valor)
              atual = atual->direita;
            else
            atual = atual->esquerda;  
        }
        if(n > ant->valor)
          ant->direita = novo;
        else
          ant->esquerda = novo; 
    }
return a;
}
//Função que remove uma folha na árvore
Arvore* remover(Arvore* a, int n){
     if(a == NULL){//Se o ponteiro a for nulo, a árvore está vazia
         printf("\nÁrvore Vazia!\n");
         return a;
                                 }
     //Ponteiros auxiliares do tipo struct
     Arvore* atual = a, *ant = NULL;
     //Estrutura que percorre a árvore
         while(atual != NULL && atual->valor != n){//While é falso quando o número é encontrado
             ant = atual;
         if(n > atual->valor)
          atual = atual->direita;//Percorre à direita
         else
          atual = atual->esquerda;//Percorre à esquerda  
                                                  }
     //O elemento percorreu todas folhas e não foi encontrado
     if(atual == NULL){
       printf("Elemento não encontrado!");
       return a;
                      }
     //Quando o galho não tem folhas
     if(atual->direita == NULL && atual->esquerda == NULL){
         if(n > ant->valor){
             ant->direita = atual->direita;
                 free(atual);}
         else{
             ant->esquerda = atual->esquerda;
                 free(atual);
             }
                                                          }
     //Quando o galho tem apenas uma folha
     else if(atual->direita != NULL && atual->esquerda == NULL || atual->direita == NULL && atual->esquerda != NULL){
         if(n > ant->valor){
             ant->direita = atual->direita;
                 free(atual);}
         else{
             ant->esquerda = atual->esquerda;
                 free(atual);
             }
     //Quando o galho tem duas folhas    
     }else if(atual->esquerda != NULL && atual->direita != NULL){
         //Percorre a àrvore a direita
         while(atual->direita != NULL){
             ant = atual;//Recebe a posição atual da árvore
             atual = atual->direita;//Recebe a próxima a posição
             ant->valor = atual->valor;//O valor atual recebe o próximo valor, e vai realiza cópia
       }
         if(atual->direita == NULL)
             ant->direita = atual->direita;

                 free(atual);
                                                                }
   return a;
}

void busca(Arvore* a, int n){
     if(a == NULL){
         printf("\nA árvore está vazia!\n");
         return;
     }
     Arvore *aux = a;
     while (aux != NULL)
     {
         if( n == aux->valor){
             printf("\nElemento %d encontrado na Árvore!\n\n",aux->valor);
             return;
         }
         else{
             if(n > aux->valor)
             aux = aux->direita;
             else if(n < aux->valor)
             aux = aux->esquerda;

         }
        
     }
     printf("\nElemento não encontrado\n\n");
}

void preOrdem(Arvore* a){
     if(a != NULL){
         printf("%d ",a->valor);
         preOrdem(a->direita);
         preOrdem(a->esquerda);
     }
     
}

void emOrdem(Arvore* a){
     if(a != NULL){
         emOrdem(a->direita);
         printf("%d ",a->valor);
         emOrdem(a->esquerda);
     } 
}

void posOrdem(Arvore* a){
     if(a != NULL){
         posOrdem(a->direita);
         posOrdem(a->esquerda);
         printf("%d ",a->valor);
     } 
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
   CriarMenu(tam,"1 - Insere na Folha");
   CriarMenu(tam,"2 - Remove na Folha");
   CriarMenu(tam,"3 - Busca na Folha");
   CriarMenu(tam,"4 - Pre-Ordem");
   CriarMenu(tam,"5 - Em-Ordem");
   CriarMenu(tam,"6 - Pos-Ordem");
   criarLinhaRodape(tam);
}
