#ifndef __avl__
#define __avl__

//#include "avl_priv.h"
#include "AVLPriv.h"

typedef struct arvore {
    NoAVL* root;
} Arvore;

Dado* buscarDado(Arvore* arvore,int chave);
void mostrarArvore(Arvore* arvore);
void removerArvore(Arvore* arvore, Dado* valor);
void inserirArvore(Arvore* arvore, Dado* valor);
Arvore* criarArvore();
void excluirDado(Dado** dado);
Dado* criarDado();

#endif
