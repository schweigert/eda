#ifndef __avl__
#define __avl__

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

Dado* buscarDado(Arvore* arvore,int chave);
void mostrarArvore(Arvore* arvore);
void removerArvore(Arvore* arvore, Dado* valor);
void inserirArvore(Arvore* arvore,Dado* valor);
Arvore* criarArvore();
void excluirDado(Dado** dado);
Dado* criarDado();
void inserirArvore(Arvore* arvore,Dado* valor);
void removerArvore(Arvore* arvore, Dado* valor);
void mostrarArvore(Arvore* arvore);
Dado* buscarDado(Arvore* arvore,int chave);

#endif
