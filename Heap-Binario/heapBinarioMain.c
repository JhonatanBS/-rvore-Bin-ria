#include <stdio.h>
#include <stdlib.h>
#include "heapBinario.c"

int main(){
    int *vetor,i,opcao=1,valor;
   
    do{
      menu();  
      printf("\nEscolha uma das opcoes:");
      scanf("%d",&opcao);

      switch(opcao){
         case 0:
             printf("\n Heap Finalizado com Sucesso!");
                 break;
         case 1:
             vetor = criaVetor(vetor);
                 break;
         case 2:
             printf("\nDigite o valor para o vetor:");
             scanf("%d",&valor);
  
             vetor = insere(vetor,valor);


                 break;
         case 3:
             vetor = excluir(vetor);
                 break;        
         case 4:
             vetor = heapMax(vetor);
                 break;
         case 5:
             vetor = heapMin(vetor);
                 break;
         case 6:
             for(i=0;i<pos;i++){
                 printf("|%d", vetor[i]);
             }
             //vetor = imprime(vetor);
                 break;                                       
      }
    }while(opcao != 0);

    return 0;
}