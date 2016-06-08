#ifndef __ABB_priv__
#define __ABB_priv__

typedef struct Node {

	void* dado;
	struct Node dir;
	struct Node esq;

} Node;

Node* criar_node();

#endif