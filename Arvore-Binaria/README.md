# Árvore Binária

 Em estrutura de dados, a **árvore binária** é uma estrutura formada por uma *raiz* e suas *subárvores*. Cada nó é limitado a ter no máximo 2 filhos ou duas folhas na estrutura. Os nós são organizados como subárvore a esquerda e uma subárvore a direita, originados da raiz da árvore.

As três principais operações:

- Inserção
- Remoção
- Busca

Vejo o exemplo a seguir:

 ![arvore binaria](http://www.desafiosdeti.com.br/wp-content/uploads/2017/02/arv1.png)

>**Observação**: Neste código, a implementação da árvore binária é feita de forma dinâmica. Aonde utilizamos um **malloc** para alocação de memória e todo o código é controlado através de ponteiros nas funções, ponteiros auxiliares e ponteiros para apontar para direita e para esquerda.

 ## *Inserção*

 

 ```c
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
 ```

## *Remoção*

```c
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
```

## *Busca*

```c
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
```


