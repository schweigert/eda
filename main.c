#include <stdio.h>
#include <stdlib.h>
#include "ABB.h"

typedef struct reg {
	int oi, seila;
} Registro;

void menu();

int main (void){
	const char* file = "Arq.txt";
    
    menu();
    
	return 0;
}

void JustFacaIt(void *data_void){
	Registro* reg = (Registro*)data_void;
	printf("[%d] -> %d", reg->oi, reg->seila);
}
int JustComparaIt(void *a, void *b){
	Registro *regA = (Registro*)a,
		*regB = (Registro*)b;
	
	if (regA->oi == regB->oi)
		return IG;
		
	return (regA->oi > regB->oi) ? GT : LT;
}	

void menu(){
	
	ABB* arvore = cria_abb(sizeof(Registro));
	Registro reg[10];
	int i = 10;
	while (--i){
		reg[i].oi = i;
		reg[i].seila = rand() % 500;
	}
	puts ("Arvore criada!");
MENU:
    printf("Selecione a opcao:\
           \n1.\tCarregar arquivo.\
           \n2.\tBuscar registro.\
           \n3.\tRemover registro\
           \n4.\tInserir registro.\
           \n5.\tTamanho do arquivo.\
           \n6.\tSalvar arquivo\
           \n7.\tRecuperar registro a partir do arquivo.\
           \n0.\tSair do programa.\n\t");
    int opcao;
    scanf("%d", &opcao);
    switch (opcao) {
        case 1:
            
            break;
        case 2:
            
            break;
        case 3:
            
            break;
        case 4:
        	puts("Que numero?");
        	int op;
        	scanf("%d", &op);
        	printf("Iremos inserir o registro de numero %d de %d - %d\n", op, reg[op].oi, reg[op].seila);
            inserir_abb(arvore, &reg[op], JustComparaIt);
            puts("Criado");
            mostrar_abb(arvore, JustFacaIt);
            goto MENU;
            break;
        case 5:
            
            break;
        case 6:
            
            break;
        case 7:
            
            break;
        case 0:
            exit(0);
            break;
            
        default:
            printf("Opcao errada!\n");
            goto MENU;
            break;
    }
           
           
}