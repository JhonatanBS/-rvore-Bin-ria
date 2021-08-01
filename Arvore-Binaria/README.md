# Árvore Binária

 Em estrutura de dados, a árvore binária é uma estrutura formada por uma raiz e suas subárvores. Cada nó é limitado a ter no máximo 2 filhos ou duas folhas na estrutura. Os nós são organizados como subárvore a esquerda e uma subárvore a direita, originados da raiz da árvore.

As três principais operações:

- Inserção
- Remoção
- Busca

Vejo o exemplo a seguir:

 ![arvore binaria](http://www.desafiosdeti.com.br/wp-content/uploads/2017/02/arv1.png)

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



