#include <stdlib.h>
#include <stdio.h>
#include "ABB.h"
#include "ABB_priv.h"


ABB* cria_abb(int tam){
	// Alocar a raiz
	ABB* ret = (ABB*)malloc(sizeof(ABB));
	ret->tam = tam;
	ret->raiz = NULL;
	return ret;
}

void mostrar_abb(ABB* abb, void(*impressao)(void*)){
	printf ("Arvore:\n");
	mostrar_node(abb->raiz,0,impressao);
}

void inserir_abb(ABB* abb,void* dado, COMP(*comp)(void*,void*) ){
	Node* node = criar_node(abb->tam);
	inserir_dado(node, dado, abb->tam);
	if (abb->raiz == NULL){
		abb->raiz = node;
	} else {
		inserir_node(node, abb->raiz, comp);
	}
    
    fb(abb->raiz);
}