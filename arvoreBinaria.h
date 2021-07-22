struct arvore{
   int valor;
   struct arvore* direita;
   struct arvore* esquerda;
};

typedef struct arvore Arvore;

Arvore* insere(Arvore* a, int);
void imprime(Arvore* a);
void menu();

