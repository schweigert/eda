//
//  fileManager.c
//  AVL-TrabEda
//
//  Created by usuario on 6/21/16.
//  Copyright © 2016 Udesc. All rights reserved.
//

#include "fileManager.h"


void salvarArvore (Arvore* arvere, char* nome){
    
    FILE* fp = fopen(nome, "w");
    escreverBudega(arvere->root, fp);
    fclose(fp);
    
}

void escreverBudega (NoAVL* local, FILE* fp){
    
    if (local == NULL) return;
    fprintf(fp, "%d %s %d %g %d %s #\n", local->registro->matricula, local->registro->nome, local->registro->telefone,
            local->registro->salario, local->registro->codDep, local->registro->departamento);
    escreverBudega(local->dir, fp);
    escreverBudega(local->esq, fp);
    
    
}
