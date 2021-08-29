/*Bibliotecas*/
#include <stdio.h>
#include <stdlib.h>
#include "arvoreAVL.h"
#define tam 30/*Constante para o Menu*/

//Função que faz rotação simples à esquerda
Arvore* rotacao_esquerda(Arvore* a){
    Arvore *aux1, *aux2;/*Ponteiros auxiliares*/
    aux1 = a->direita;/*aux1 aponta para o próximo elemento a direita da raiz*/
    aux2 = aux1->esquerda;/*aux2 aponta para o elemento à esquerda de aux1*/
    a->direita = aux2;/*O ponteiro *a na direita, aponta para o aux2*/
    aux1->esquerda = a;/*aux1 aponta para a*/

    if(a->direita == NULL)
        a->alt_dir = 0;/*Se o proximo elemento a direita não tiver nenhum filho, recebe 0 de altura a direita*/
    else if(a->direita->alt_esq > a->direita->alt_dir)
        a->alt_dir = a->direita->alt_esq + 1;
    else
        a->alt_dir = a->direita->alt_dir + 1;

    if(aux1->esquerda->alt_esq > aux1->esquerda->alt_dir)
        aux1->alt_esq = aux1->esquerda->alt_esq + 1;
    else
        aux1->alt_esq = aux1->esquerda->alt_dir + 1;

    return aux1;                
}
//Função que faz rotação simples à direita
Arvore* rotacao_direita(Arvore* a){
    Arvore *aux1, *aux2;/*Ponteiros auxiliares*/
    aux1 = a->esquerda;/*aux1 aponta para o próximo elemento a esquerda da raiz*/
    aux2 = aux1->direita;/*aux2 aponta para o elemento à direita de aux1*/
    a->esquerda = aux2;/*O ponteiro *a na esquerda, aponta para o aux2*/
    aux1->direita = a;/*aux1 aponta para a*/

    if(a->esquerda == NULL)
        a->alt_esq = 0;/*Se o proximo elemento a esquerda não tiver nenhum filho, recebe 0 de altura a direita*/
    else if(a->esquerda->alt_esq > a->esquerda->alt_dir)
        a->alt_esq = a->esquerda->alt_esq + 1;
    else
        a->alt_esq = a->esquerda->alt_dir + 1;

    if(aux1->direita->alt_esq > aux1->direita->alt_dir)
        aux1->alt_dir = aux1->direita->alt_esq + 1;
    else
        aux1->alt_dir = aux1->direita->alt_dir + 1;

    return aux1;                
}
/*Função que faz o balanceamento da árvore*/
Arvore* balanceamento(Arvore* a){
     int d, df;/*Variaveis para receber a diferença de altura da árvore*/
     d = a->alt_dir - a->alt_esq;/*Recebe a diferença da altura entre a subárvore da esquerda e da subárvore direita*/

     if( d == 2){/**/
         /*A diferença de altura do nó a direita da raiz*/
         df = a->direita->alt_dir - a->direita->alt_esq;/*Recebe o resultado da diferença de altura da subárvore a direita*/
         if(df >= 0){/*Se o resultado for positivo ou maior ou igual à zero, temos uma reta a direita*/
             a = rotacao_esquerda(a);/*Rotação simples à esquerda*/
         }
         else{/*Se for menor que zero, temos um joelho e executamos uma rotação dupla à esquerda*/
             a->direita = rotacao_direita(a->direita);/*Avança para o elemento da direita e aplica a rotação simples á direita*/
             a = rotacao_esquerda(a);/*Rotação simples à esquerda*/
         }
     }
     else if(d == -2){/**/
         df = a->esquerda->alt_dir - a->esquerda->alt_esq;/*Recebe o resultado da diferença de altura da subárvore a direita*/
         if(df <= 0){/*Se o resultado for negativo ou menor ou igual que zero, temos uma reta a esquerda*/
             a = rotacao_direita(a);/*Rotação simples à direita*/
         }
         else{
             a->esquerda = rotacao_esquerda(a->esquerda);
             a = rotacao_direita(a);/*Rotação simples à direita*/
         }
     }
     return a;/*Retorna para o ínicio da árvore*/
}
/*Função que atualiza a altura de cada nó na Árvore AVL*/
Arvore* atualiza(Arvore* a){
     if(a != NULL){
         a->esquerda = atualiza(a->esquerda);/*Percorre a subárvore à esquerda*/
         if(a->esquerda == NULL)
            a->alt_esq = 0;
         else if(a->esquerda->alt_esq > a->esquerda->alt_dir) 
            a->alt_esq = a->esquerda->alt_esq + 1;  
         else  
            a->alt_esq = a->esquerda->alt_dir + 1;
         
         a->direita = atualiza(a->direita);/*Percorre a subárvore à direita*/
         if(a->direita == NULL)
            a->alt_dir = 0;
         else if(a->direita->alt_esq > a->direita->alt_dir) 
            a->alt_dir = a->direita->alt_esq + 1;  
         else  
            a->alt_dir = a->direita->alt_dir + 1;
     }
     return a;
}
//Função que insere um elemento na subárvore
Arvore* insere(Arvore* a, int n){
    Arvore* novo = (Arvore*)malloc(sizeof(Arvore));//Retorna uma alocação na memória do tipo struct
    if(a == NULL){
        novo->valor=n;
        novo->alt_dir=0;
        novo->alt_esq=0;
        novo->esquerda=NULL;
        novo->direita=NULL;
        a = novo;
    }
    else if ( n < a->valor){
             a->esquerda = insere(a->esquerda,n);
        if(a->esquerda->alt_dir > a->esquerda->alt_esq)
             a->alt_esq = a->esquerda->alt_dir + 1;
        else
             a->alt_esq = a->esquerda->alt_esq + 1;

        a = balanceamento(a);     
    }
    else{
            a->direita = insere(a->direita,n);
        if(a->direita->alt_dir > a->direita->alt_esq)
             a->alt_dir = a->direita->alt_dir + 1;
        else
             a->alt_dir = a->direita->alt_esq + 1;

        a = balanceamento(a);    
    }
    return a;
}

//Função que remove uma folha na árvore
Arvore* remover(Arvore* a, int n){
     if(a == NULL){// Se o ponteiro foi nulo, á arvore esta vazia
         printf("\nÁrvore Vazia!\n");
         return a;
                                 }
     else {//Senão
        // Se o valor digitado pelo usuário for igual ao elemento atual
        if(a->valor == n) {
            // remove o nó ou a subárvore que não possui filhos ou folhas
            if(a->esquerda == NULL && a->direita == NULL) {
                free(a);//Libera o nó
                return NULL;//retorna NULL para o nó anterior
            }
            else{//Senão
                // remove o nó ou a subárvore que  possui um filho ou uma folha
                if(a->esquerda == NULL || a->direita == NULL){
                    Arvore *aux;//Ponteiro auxiliar
                    if(a->esquerda != NULL)
                        aux = a->esquerda;// Faz aux percorre a esquerda
                    else//Senão
                        aux = a->direita;// Faz aux percorre a direita
                    free(a);// Libera o nó atual
                    return aux;//Retorna aux para o nó anterior
                }
                else{
                    //Remove o nó ou subárvore que tem dois filhos ou duas folhas
                    Arvore *aux = a->esquerda;
                    while(aux->direita != NULL)
                        aux = aux->direita;//Avança para direita do nó
                    a->valor = aux->valor;// o nó atual recebe o valor do ultomo nó a esquerda
                    aux->valor = n;//Guarda o valor escolhido para remover
                    a->esquerda = remover(a->esquerda, n);//remove o nó na subárvore a esquerda
                    return a;//Retorna o ponteiro 
                }
            }
        } else {
            //Recursividade para percorrer a árvore
            if(n < a->valor)
                a->esquerda = remover(a->esquerda, n);//Percorre o nó a esquerda
            else
                a->direita = remover(a->direita, n);//Percorre o nó a direita
            return a;//Retorna o ponteiro
        }
    }
}
//Função que busca um nó na árvore
void busca(Arvore* a, int n){
     if(a == NULL){//Se o ponteiro for nulo, árvore está vazia
         printf("\nA árvore está vazia!\n");
         return;
     }
     Arvore *aux = a;//Ponteiro auxiliar recebendo o inicio da árvore
     while (aux != NULL){//Percorre a árvore
         if(n > aux->valor)//Se o valor for maior que atual 
             aux = aux->direita;//Percorre o nó a direita
         else if(n < aux->valor)//Se for menor que o atual
             aux = aux->esquerda;//Percorre o nó a esquerda
         else{// O elemento é igual ao digitado pelo o usuário 
             printf("\nElemento %d encontrado na Árvore!\n\n",aux->valor);
             return;
             }
                        }//Fim do While
     //Elemento não encontrado, porque o aux chegou a ser nulo                   
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
/**/
void imprime(Arvore* a){
     if(a != NULL){
         printf("%d->(%d)(%d) ",a->valor,a->alt_esq,a->alt_dir);
         imprime(a->esquerda);
         imprime(a->direita);    
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
   system("color F0");//Define a cor do terminal (F->Fundo e 0->Cor das letras)
   printf("\n");
   criarLinhaSuperior(tam);
   CriarMenu(tam,"MENU ARVORE");
   CriarMenu(tam,"0 - Sair");
   CriarMenu(tam,"1 - Insere na Arvore");
   CriarMenu(tam,"2 - Remove na Arvore");
   CriarMenu(tam,"3 - Busca na Arvore");
   CriarMenu(tam,"4 - Pre-Ordem");
   CriarMenu(tam,"5 - Em-Ordem");
   CriarMenu(tam,"6 - Pos-Ordem");
   CriarMenu(tam,"7 - Imprime");
   criarLinhaRodape(tam);
}
