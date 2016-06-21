#include <stdio.h>
#include <stdlib.h>
#include "avl.h"
#include "avl_priv.h"

void escreverBudega(struct node*, FILE*);

void salvarArvore (Arvore* arvere, char* nome){

    FILE* fp = fopen(nome, "w");
    escreverBudega(arvere->root, fp);

}

void escreverBudega (struct node* local, FILE* fp){

    if (local == NULL) return;
    fprintf(fp, "%d %s %d %f %d %s #\n", matricula, nome, telefone, salario, coddep, dep);
    escreverBudega(node->esq, fp);
    escreverBudega(node->dir, fp);


}