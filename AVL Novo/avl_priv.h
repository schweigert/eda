

// Arvore
struct NoAVL
{
    int registro;
    struct NoAVL *dir;
    struct NoAVL *esq;
    int altura;
};
int altura(struct NoAVL *N);
int max(int a, int b);
struct NoAVL* criarNo(int registro);
struct NoAVL *esqRotate(struct NoAVL *y);
struct NoAVL *dirRotate(struct NoAVL *x);
int fb(struct NoAVL *N);
struct NoAVL* inserirNo(struct NoAVL* NoAVL, int registro);
struct NoAVL * menorValor(struct NoAVL* N);
struct NoAVL* deletarNo(struct NoAVL* root, int registro);
void exibirArvore (struct NoAVL* N, int level);
void inOrder(struct NoAVL *root);
