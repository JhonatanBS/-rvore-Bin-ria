#include <stdio.h>
#include <stdlib.h>
#include "arvoreBinaria.h"

Arvore* insere(Arvore* a, int n){
    Arvore* novo = (Arvore*)malloc(sizeof(Arvore));
    if(novo == NULL){
        printf("Erro na alocação de Memória!");
        exit(1);
    }
    
    novo->valor = n;
    novo->direita = NULL;
    novo->esquerda = NULL;

    if(a == NULL){
        a = novo;
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

void imprime (Arvore* a) { 
    if (a == NULL) 
    return a;

    printf("%d\n", a->valor); 
    imprime(a->direita);
    imprime(a->esquerda);
}

void menu(){
    printf("\nMENU ARVORE\n 0 - Sair\n 1 - Insere na Folha\n 2 - Remove na folha\n 3 - Imprime\n");
}