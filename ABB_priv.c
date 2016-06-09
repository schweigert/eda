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
	char lado = ' ';
	if (resp == GT){
		if (local->dir == NULL){
			local->dir = node;
			return;
		} else {
			inserir_node(node, local->dir, comp);
			lado = 'd';
		}
	} else if (resp == LT){
		if (local->esq == NULL){
			local->esq = node;
			return;
		} else {
			inserir_node(node, local->esq, comp);
			lado = 'e';
		}
	} else {
		puts("Internal error: EQUAL REGISTER");
		return;
	}
	int FB = fb(local->esq) - fb(local->dir);
	
	Node* temp;
	
	if((FB == 2 || FB == -2) && lado == 'd'){
		temp = swapRR(local);
		local->dir = temp->dir;
		local->esq = temp->esq;
		local->dado = temp->dado;
	}
	
	if((FB == 2 || FB == -2) && lado == 'e'){
		temp = swapLL(local);
		local->dir = temp->dir;
		local->esq = temp->esq;
		local->dado = temp->dado;
	}
	
	if((FB == 2 || FB == -2) && lado == 'd'){
		temp = swapRR(local);
		local->dir = temp->dir;
		local->esq = temp->esq;
		local->dado = temp->dado;
	}
	
	
}

Node* swapRR (Node* p){
	Node* q = p->dir,
		  temp = q->esq;
		  
	q->esq = p;
	p->dir = temp;
	return (q);
}

Node* swapLL (Node* p){
	Node* q = p->esq,
		  tmp = q->dir;
		  
	q->dir = p;
	p->esq = temp;
	
	return (q);
}

Node* swapRL (Node* p){
	Node* q = p->dir;
	swapLL(q);
	Node* raiz = swapRR(p);
	return (raiz);
}

Node* swapLR(p){
	Node* q=p->esq;
	swapRR(q);
	Node* raiz = swapLL(p);
	return (raiz);
}

int fb (Node* node) {
	
	int dir = 0, esq = 0;
	
	if (node->dir != NULL)
		dir = 1 + fb(node->dir);
	if (node->esq != NULL)
		esq = 1 + fib(node->esq);
		
	return (dir > esq) ? dir : esq;
	
}

