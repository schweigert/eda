//
//  fileManager.h
//  AVL-TrabEda
//
//  Created by usuario on 6/21/16.
//  Copyright © 2016 Udesc. All rights reserved.
//

#ifndef fileManager_h
#define fileManager_h

#include <stdio.h>
#include <stdlib.h>
#include "AVLPriv.h"
#include "avl.h"

void salvarArvore (Arvore* arvere, char* nome);
void escreverBudega (NoAVL* local, FILE* fp);

#endif /* fileManager_h */
