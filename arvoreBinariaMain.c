#include <stdio.h>
#include <stdlib.h>
#include "arvoreBinaria.c"

int main(){
    Arvore* A = NULL;
    int opcao, numero, b;

  do{
        menu();
        printf("Escolha uma das opções:");
        scanf("%d",&opcao);

        switch(opcao){
             case 0:
                 printf("Arvore Finalizada!");
                     break;
             case 1:
                 printf("Digite um valor para a Arvore:");
                 scanf("%d",&numero);
                 A = insere(A,numero); 
                     break;
             case 2:
                 printf("Digite um valor para remover da Arvore:");
                 scanf("%d",&numero);
                 A = remover(A,numero);
                     break; 
             case 3:
                 printf("Digite um valor para a busca na Arvore:");
                 scanf("%d",&numero);
                 busca(A,numero);
                     break;
             case 4:
                 imprime(A); 
                     break;
             case 5:
                 preOrdem(A); 
                     break;
             case 6:
                 emOrdem(A); 
                     break;
             case 7:
                 posOrdem(A); 
                     break;                          
        }
    }while(opcao != 0);

    free(A);
    return 0;
}