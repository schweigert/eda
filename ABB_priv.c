#include <stdlib.h>
#include <stdio.h>
#include "ABB.h"
#include "ABB_priv.h"


Node* criar_node(unsigned int tam){
	Node* ret = (Node*)malloc(sizeof(Node));
	ret->dado = malloc(tam);
	ret->dir = NULL;
	ret->esq = NULL;
	return ret;
}

void mostrar_node(Node* node, unsigned int camada, void (*impressao)(void*) ){
	int i = 0;
	
	for ( ; i < camada; i++){
		printf ("      ");
	}
	printf (" |... ");
		
	if (node == NULL) {
		puts("NULL;");
		return;	
	}
	impressao(node->dado);
	printf (":\n");
		mostrar_node(node->dir, camada+1, impressao);
		mostrar_node(node->esq, camada+1, impressao);
}

void inserir_dado(Node* node, void* data, unsigned int tam){
	memcpy((void*) node->dado, (void*)data, (int)tam);
}

void inserir_node(Node* node,Node* local, COMP(*comp)(void*,void*)){

	COMP resp = comp(node->dado, local->dado);
	
	if (resp == GT){
		if (local->dir == NULL){
			local->dir = node;
		} else {
			inserir_node(node, local->dir, comp);
		}
	} else if (resp == LT){
		if (local->esq == NULL){
			local->esq = node;
		} else {
			inserir_node(node, local->esq, comp);
		}
	} else {
		puts("Internal error: EQUAL REGISTER");
		return;
	}

}