#ifndef __avl_priv__
#define __avl_priv__

// Arvore
struct NoAVL
{
    Dado* registro;
    struct NoAVL *dir;
    struct NoAVL *esq;
    int altura;
};

int altura(struct NoAVL *N);
int max(int a, int b);
struct NoAVL* criarNo(Dado* registro);
struct NoAVL *esqRotate(struct NoAVL *y);
struct NoAVL *dirRotate(struct NoAVL *x);
int fb(struct NoAVL *N);
struct NoAVL* inserirNo(struct NoAVL* NoAVL, Dado* registro);
struct NoAVL * menorValor(struct NoAVL* N);
struct NoAVL* deletarNo(struct NoAVL* root, Dado* registro);
void exibirArvore (struct NoAVL* N, int level);
void inOrder(struct NoAVL *root);
Dado* buscarInterno(struct NoAVL* local, int chave);

#endif
