#ifndef __ABB__
#define __ABB__
#include "ABB_priv.h"


// MAIOR
#define GT 1
// MENOR
#define LT -1
// IGUAL
#define IG 0
// COMPARADOR
#define COMP int

typedef struct ABB {
	Node* raiz;
	unsigned int tam;
} ABB;

ABB* cria_abb(int tam);
void mostrar_abb(ABB* abb, void(*impressao)(void*));
void inserir_abb(ABB* abb,void* dado, COMP(*comp)(void*,void*));

#endif