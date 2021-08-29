#include <stdio.h>
#include <stdlib.h>
#include "arvoreAVL.c"

int main(){
    Arvore* A = NULL;
    int opcao, numero,valor;

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
                 A = atualiza(A);
                 A = balanceamento(A);
                     break; 
             case 3:
                 printf("Digite um valor para a busca na Arvore:");
                 scanf("%d",&numero);
                 busca(A,numero);
                     break;
             case 4:
                 preOrdem(A); 
                     break;
             case 5:
                 emOrdem(A); 
                     break;
             case 6:
                 posOrdem(A); 
                     break;
             case 7:
                 imprime(A); 
                     break;                
            default:
                 printf("\nERRO:Digite um número do MENU!");
                     break;                                          
        }
    }while(opcao != 0);
    free(A); 
    return 0;
}