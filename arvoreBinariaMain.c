#include <stdio.h>
#include <stdlib.h>
#include "arvoreBinaria.c"

int main(){
    Arvore* A = NULL;
    int opcao, numero;

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

                     break; 
             case 3:
                 imprime(A);
                     break;               
        }
    }while(opcao != 0);

    free(A);
    return 0;
}