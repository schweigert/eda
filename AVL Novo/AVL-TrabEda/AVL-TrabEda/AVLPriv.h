//
//  AVLPriv.h
//  AVL-TrabEda
//
//  Created by usuario on 6/21/16.
//  Copyright © 2016 Udesc. All rights reserved.
//

#ifndef AVLPriv_h
#define AVLPriv_h

typedef struct dado {
    int matricula;
    char nome[256];
    int telefone;
    float salario;
    int codDep;
    char departamento[256];
} Dado;

typedef struct NoAVL
{
    Dado* registro;
    struct NoAVL *dir;
    struct NoAVL *esq;
    int altura;
    
} NoAVL;

typedef struct arvore {
    NoAVL* root;
} Arvore;

int altura(NoAVL *N);
int max(int a, int b);
NoAVL* criarNo(Dado* registro);
NoAVL *esqRotate(NoAVL *y);
NoAVL *dirRotate(NoAVL *x);
int fb(NoAVL *N);
NoAVL* inserirNo(NoAVL* NoAVL, Dado* registro);
NoAVL * menorValor(NoAVL* N);
NoAVL* deletarNo(NoAVL* root, int registro);
void exibirArvore (NoAVL* N, int level);
void inOrder(NoAVL *root);
Dado* buscarInterno(NoAVL* local, int chave);

#endif /* AVLPriv_h */
