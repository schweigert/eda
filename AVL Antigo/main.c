#include <stdio.h>
#include <stdlib.h>
#include "ABB.h"

#define tamString 100

typedef struct {
    int matricula;
    char nome[tamString];
    int telefone;
    float salario;
    int idade;
    char departamento[tamString];
} Registro;

Registro* registros;

void menu();
void JustFacaIt(void*);

int main (void){
	const char* file = "Arq.txt";
    FILE *fd = fopen("coisa.txt", "w");
    fprintf(fd, "Wooooooo");
    fclose(fd);
    FILE *f = fopen(file, "r");
    
    registros = (Registro*) malloc(10000 * sizeof &registros);
    
    if (!f){
        printf("Falha ao ler o arquivo %s\n", file);
        return 1;
    }
    int i = 10000;
    while (i--){
        Registro tmp;
        fscanf(f, "%d", &tmp.matricula);
        fscanf(f, "%s", &tmp.nome);
        fscanf(f, "%d", &tmp.telefone);
        fscanf(f, "%f", &tmp.salario);
        fscanf(f, "%d", &tmp.idade);
        fscanf(f, "%s", &tmp.departamento);
        char * lixo;
        fscanf(f, "%s", &lixo);
        JustFacaIt(&tmp);
        puts("");
        registros[i] = tmp;
    }
    
    menu();
    
	return 0;
}

void JustFacaIt(void *data_void){
	Registro* reg = (Registro*)data_void;
	printf("[%d] -> {Nome: %s, Dep: %s, Fone: %d, Salario: %f, Idade: %d}", reg->matricula,
           reg->nome,
           reg->departamento,
           reg->telefone,
           reg->salario,
           reg->idade);
}
int JustComparaIt(void *a, void *b){
	Registro *regA = (Registro*)a,
		*regB = (Registro*)b;
	
	if (regA->matricula == regB->matricula)
		return IG;
		
	return (regA->matricula > regB->matricula) ? GT : LT;
}	

void menu(){
	
	ABB* arvore = cria_abb(sizeof(Registro));

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
        	printf("Iremos inserir o registro de numero %d de [%d] - %s\n", op, registros[op].matricula, registros[op].nome);
            inserir_abb(arvore, &registros[op], JustComparaIt);
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