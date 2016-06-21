//
//  funcoes_programa.h
//  AVL-TrabEda
//
//  Created by usuario on 6/21/16.
//  Copyright © 2016 Udesc. All rights reserved.
//

#ifndef funcoes_programa_h
#define funcoes_programa_h

#include <stdio.h>
#include "AVLPriv.h"
#include "avl.h"

void fazerBusca(Arvore *);
void insereRegistro(Arvore*);
void printLinhaArquivo(Arvore*);
void removerDado(Arvore*);
void printaIndex(Arvore*);
void printaTamanhoFile(const char* f);

void printaDados(Dado*);

#endif /* funcoes_programa_h */
