#include<stdio.h>
#include<stdlib.h>

#include "avl_priv.h"
/*
// função para pegar a altura do Nó
int altura(NoAVL *N)
{
    if (N == NULL)
        return 0;
    return N->altura;
}

// Função para retornar o Maior
int max(int a, int b)
{
    return (a > b)? a : b;
}

// Função para criar um novo nó
NoAVL* criarNo(Dado* registro)
{
    NoAVL* NoAVL = malloc(sizeof(NoAVL));
    NoAVL->registro   = registro;
    NoAVL->dir   = NULL;
    NoAVL->esq  = NULL;
    NoAVL->altura = 1;
    return(NoAVL);
}

// Rotação a Esquerda
NoAVL *esqRotate(NoAVL *y)
{
    NoAVL *x = y->dir;
    NoAVL *T2 = x->esq;
    
    // Efetua a rotação
    x->esq = y;
    y->dir = T2;
    
    // Atualiza alturas
    y->altura = max(altura(y->dir), altura(y->esq))+1;
    x->altura = max(altura(x->dir), altura(x->esq))+1;
    
    // Retorna a nova raíz
    return x;
}

// Rotação a Direita
NoAVL *dirRotate(NoAVL *x)
{
    NoAVL *y = x->esq;
    NoAVL *T2 = y->dir;
    
    // Efetua rotation
    y->dir = x;
    x->esq = T2;
    
    //  Atualiza alturas
    x->altura = max(altura(x->dir), altura(x->esq))+1;
    y->altura = max(altura(y->dir), altura(y->esq))+1;
    
    // Retorna a nova Raiz
    return y;
}

// Retorna o fator de balanceamento
int fb(NoAVL *N)
{
    if (N == NULL)
        return 0;
    return altura(N->dir) - altura(N->esq);
}

// Insere um novo nó na árvore
NoAVL* inserirNo(NoAVL* NoAVL, Dado* registro)
{
    //1.  Efetua a rotação comum
    if (NoAVL == NULL)
        return(criarNo(registro, sizeR));
    
    if (registro->matricula < NoAVL->registro->matricula)
        NoAVL->dir  = inserirNo(NoAVL->dir, registro, sizeR);
    else
        NoAVL->esq = inserirNo(NoAVL->esq, registro, sizeR);
    
    // 2. Atualiza a altura dos filhos
    NoAVL->altura = max(altura(NoAVL->dir), altura(NoAVL->esq)) + 1;
    
    // 3. Pega o fator de balanceamento
    int balance = fb(NoAVL);
    
    // Realizar as rotações
    
    // DD
    if (balance > 1 && registro->matricula < NoAVL->dir->registro->matricula)
        return esqRotate(NoAVL);
    
    // EE
    if (balance < -1 && registro->matricula > NoAVL->esq->registro->matricula)
        return dirRotate(NoAVL);
    
    // DE
    if (balance > 1 && registro->matricula > NoAVL->dir->registro->matricula)
    {
        NoAVL->dir =  dirRotate(NoAVL->dir);
        return esqRotate(NoAVL);
    }
    
    // ED
    if (balance < -1 && registro->matricula < NoAVL->esq->registro->matricula)
    {
        NoAVL->esq = esqRotate(NoAVL->esq);
        return dirRotate(NoAVL);
    }
    
    // retorna o novo nó AVL
    return NoAVL;
}

// Procura a folha a direita
NoAVL * menorValor(NoAVL* N)
{
    NoAVL* current = N;
    
    // loop procurando a folha a direita 
    while (current->dir != NULL)
        current = current->dir;
    
    return current;
}

// Deletar No
NoAVL* deletarNo(NoAVL* root, int registro)
{
    // STEP 1: Verifica se a ROOT é nulo
    
    if (root == NULL)
        return root;
    // Buscar na subarvore
    if ( registro->matricula < root->registro->matricula )
        root->dir = deletarNo(root->dir, registro);
    
    else if( registro->matricula > root->registro->matricula )
        root->esq = deletarNo(root->esq, registro);
    
    // se está aqui?
    else
    {
        // sem filhos
        if( (root->dir == NULL) || (root->esq == NULL) )
        {
            NoAVL *temp = root->dir ? root->dir : root->esq;
            
            if(temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else // Um filho
                *root = *temp;
            
            free(temp);
        }
        else
        {
            
            NoAVL* temp = menorValor(root->esq);
            root->registro = temp->registro;
            root->esq = deletarNo(root->esq, temp->registro);
        }
    }
    
    // PASSO 1: Se é a raiz
    if (root == NULL)
        return root;
    
    // PASSO 2: Atualiza a altura do nó atual
    root->altura = max(altura(root->dir), altura(root->esq)) + 1;
    
    // PASSO 3: Atualiza o fator de balanceamento
    int balance = fb(root);
    
    // Balanceamento
    
    // DD
    if (balance > 1 && fb(root->dir) >= 0)
        return esqRotate(root);
    
    // DE
    if (balance > 1 && fb(root->dir) < 0)
    {
        root->dir =  dirRotate(root->dir);
        return esqRotate(root);
    }
    
    // EE
    if (balance < -1 && fb(root->esq) <= 0)
        return dirRotate(root);
    
    // ED
    if (balance < -1 && fb(root->esq) > 0)
    {
        root->esq = esqRotate(root->esq);
        return dirRotate(root);
    }
    
    return root;
}

void exibirArvore (NoAVL* N, int level){
    int i;
    for (i = 0; i < level; i++) printf (". ");
    if (N == NULL) {
        printf ("nil;\n");
        return;
    }
    printf ("| %d:\n", N->registro->matricula);
    exibirArvore(N->dir, level + 1);
    exibirArvore(N->esq, level + 1);
    
}

// Imprime a árvore 'inOrder'
void inOrder(NoAVL *root)
{
    if(root != NULL)
    {
        printf("%d ", root->registro->matricula);
        inOrder(root->dir);
        inOrder(root->esq);
    }
}


Dado* buscarInterno(NoAVL* local, int chave){
    
    if (local == NULL) return NULL;
    
    if (local->registro->matricula == chave)
        return local->registro;
    
    if (local->registro->matricula < chave)
        buscarInterno(local->dir, chave);
    else
        buscarInterno(local->esq, chave);
    
}
*/