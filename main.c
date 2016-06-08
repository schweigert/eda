#include <stdio.h>
#include <stdlib.h>
#include "ABB.h"

void menu();

int main (void){
	const char* file = "Arq.txt";
    
    menu();
    
	return 0;
}

void menu(){
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