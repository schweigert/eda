#include "ABB.h"
#include "ABB_priv.h"

ABB* cria_abb(){
	ABB* ret = (ABB*)malloc(sizeof(ABB));
	ret->raiz = criar_node();
	return ret;
}