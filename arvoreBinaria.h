struct arvore{
   int valor;
   struct arvore* direita;
   struct arvore* esquerda;
};

typedef struct arvore Arvore;

Arvore* insere(Arvore* a, int);
void imprime(Arvore* a);
//Funções protótipas para o menu
void menu();
void criarLinhaSuperior(int tamx);
void criarLinhaRodape(int tamx);
void CriarMenu(int tamx,char str[]);

