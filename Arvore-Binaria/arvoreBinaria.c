#include <stdio.h>
#include <stdlib.h>
#include "arvoreBinaria.h"
#define tam 30
//Função que insere um elemento na subárvore
Arvore* insere(Arvore* a, int n){
    Arvore* novo = (Arvore*)malloc(sizeof(Arvore));//Retorna uma alocação na memória do tipo struct
    if(novo == NULL){//Verica se alocação foi feita, senão encerra o programa
        printf("Erro na alocação de Memória!");
        exit(1);
    }
    novo->valor = n;//insere o valor do usuário no elemento
    novo->direita = NULL;//Faz o nó direito apontar para NULL
    novo->esquerda = NULL;//Faz o nó esquerdo apontar para NULL
    //Inserção na raiz,quando a árvore estiver vazia
    if(a == NULL){
        a = novo;
    //Senão estiver vazia, inserçao das subárvores    
    }else{
        Arvore* atual = a, *ant = NULL;//Cria ponteiros auxiliares
        while(atual != NULL){//Avança enquanto atual for diferente de NULL
            ant = atual;
            //Libera novo, caso tenha um número igual
            if(n == atual->valor){
                free(novo);
                return a;
            }
            //Percorre a árvore 
            if(n > atual->valor)
              atual = atual->direita;//Anda para direita
            else
            atual = atual->esquerda;//Anda para esquerda  
        }
        //Se o elemento inserido for maior que o atual, é inserido a direita,
        //Se for menor, é inserido na esquerda
        if(n > ant->valor)
          ant->direita = novo;//Faz o último elemento a direita apontar para o novo elemento
        else
          ant->esquerda = novo;//Faz o último elemento a esquerda apontar para o novo elemento 
    }
return a;//retorna o ponteiro
}
//Função que remove uma folha na árvore
Arvore* remover(Arvore* a, int n){
     if(a == NULL){//Se o ponteiro a for nulo, a árvore está vazia
         printf("\nÁrvore Vazia!\n");
         return a;
                                 }
     else {
        if(a->valor == n) {
            // remove nós folhas (nós sem filhos)
            if(a->esquerda == NULL && a->direita == NULL) {
                free(a);
                return NULL;
            }
            else{
                // remover nós que possuem apenas 1 filho
                if(a->esquerda == NULL || a->direita == NULL){
                    Arvore *aux;
                    if(a->esquerda != NULL)
                        aux = a->esquerda;
                    else
                        aux = a->direita;
                    free(a);
                    return aux;
                }
                else{
                    Arvore *aux = a->esquerda;
                    while(aux->direita != NULL)
                        aux = aux->direita;
                    a->valor = aux->valor;
                    aux->valor = n;
                    a->esquerda = remover(a->esquerda, n);
                    return a;
                }
            }
        } else {
            if(n < a->valor)
                a->esquerda = remover(a->esquerda, n);
            else
                a->direita = remover(a->direita, n);
            return a;
        }
    }
}

void busca(Arvore* a, int n){
     if(a == NULL){
         printf("\nA árvore está vazia!\n");
         return;
     }
     Arvore *aux = a;
     while (aux != NULL){
         if(n > aux->valor)
             aux = aux->direita;
         else if(n < aux->valor)
             aux = aux->esquerda;
         else{ 
             printf("\nElemento %d encontrado na Árvore!\n\n",aux->valor);
             return;
             }
                        }
     printf("\nElemento não encontrado\n\n");
}

void preOrdem(Arvore* a){
     if(a != NULL){
         printf("%d ",a->valor);
         preOrdem(a->esquerda);
         preOrdem(a->direita);
         
     }
     
}

void emOrdem(Arvore* a){
     if(a != NULL){
         emOrdem(a->esquerda);
         printf("%d ",a->valor);
         emOrdem(a->direita);
     } 
}

void posOrdem(Arvore* a){
     if(a != NULL){
         posOrdem(a->esquerda);
         posOrdem(a->direita);
         printf("%d ",a->valor);
     } 
}

int tamanho(Arvore* a){
   if( a == NULL)
     return 0;
   else
     return 1 + tamanho(a->esquerda) + tamanho(a->direita); 
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
   CriarMenu(tam,"7 - Tamanho da Arvore");
   criarLinhaRodape(tam);
}
