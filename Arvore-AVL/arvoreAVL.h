struct arvore{/*Registro que armazena os dados da árvore binária AVL*/
   int valor, alt_dir,alt_esq;/*Nó: dados que armazena o valor, altura esquerda e altura direita*/
   struct arvore* direita;/*Ponteiro que aponta para direita*/
   struct arvore* esquerda;/*Ponteiro que aponta para esquerda*/
};

typedef struct arvore Arvore;/*Minha struct recebe um sinônimo para ser chamada*/

//Funções protótipas para a Árvore AVL
Arvore* insere(Arvore* a, int);
Arvore* remover(Arvore* a, int);
void busca(Arvore* a, int);
void preOrdem(Arvore* a);
void emOrdem(Arvore* a);
void posOrdem(Arvore* a);
void imprime(Arvore* a);
//Funções para fb(Fator de Balanceamento)
Arvore* rotacao_esquerda(Arvore* a);
Arvore* rotacao_direita(Arvore* a);
Arvore* balanceamento(Arvore* a);
Arvore* atualiza(Arvore* a);
//Funções protótipas para o menu
void menu();
void criarLinhaSuperior(int tamx);
void criarLinhaRodape(int tamx);
void CriarMenu(int tamx,char str[]);