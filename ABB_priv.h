#ifndef __ABB_priv__
#define __ABB_priv__


// MAIOR
#define GT 1
// MENOR
#define LT -1
// IGUAL
#define IG 0
// COMPARADOR
#define COMP int

typedef struct Node {

	void* dado;
	struct Node* dir;
	struct Node* esq;

} Node;

Node* criar_node(unsigned int tam);
void mostrar_node(Node* node, unsigned int camada, void (*impressao)(void*) );
void inserir_dado(Node* node, void* data, unsigned int tam);
void inserir_node(Node* node,Node* local, COMP(*comp)(void*,void*));

#endif