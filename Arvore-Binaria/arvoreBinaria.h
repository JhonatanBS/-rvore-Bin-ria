struct arvore{
   int valor;
   struct arvore* direita;
   struct arvore* esquerda;
};

typedef struct arvore Arvore;

//Funções protótipas para a Árvore
Arvore* insere(Arvore* a, int);
Arvore* remover(Arvore* a, int);
void busca(Arvore* a, int);
void preOrdem(Arvore* a);
void emOrdem(Arvore* a);
void posOrdem(Arvore* a);

//Funções protótipas para o menu
void menu();
void criarLinhaSuperior(int tamx);
void criarLinhaRodape(int tamx);
void CriarMenu(int tamx,char str[]);

