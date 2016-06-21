#include <stdio.h>
#include <stdlib.h>
#include "avl.h"
#include "avl_priv.h"

typedef struct {
    NoAVL* root;
} Arvore;

typedef struct {
    int matricula;
    char nome[256];
    int telefone;
    float salario;
    char departamento[256];
} Dado;

Dado* criarDado(){
    return (Dado*)malloc(sizeof(Dado));
}

void excluirDado(Dado** dado){
    free(*dado);
    *dado = NULL;
}

Arvore* criarArvore(){
    Arvore* ret = (Arvore*)malloc(sizeof(Arvore));
    ret->root = NULL;
    return ret;
}

void inserirArvore(Arvore* arvore,Dado* valor){
    arvore->root = inserirNo(arvore->root, valor);
}

void removerArvore(Arvore* arvore, Dado* valor){
    arvore->root = deletarNo(arvore->root, valor);
}

void mostrarArvore(Arvore* arvore){
    exibirArvore(arvore->root, 0);
}

Dado* buscarDado(Arvore* arvore,int chave){
    return buscarInterno(arvore->root, chave);
}

