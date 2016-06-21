#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "avl.h"
#include "funcoes_programa.h"
#include "fileManager.h"

int main (void) {
    
    Arvore* arvore = criarArvore();
    FILE *fdm = fopen("Arq.txt","r");
    
    if (!fdm){
        puts("Falha ao abrir arquivo!");
        return 1;
    }
    int mat = 0;
    char nome[256];
    int telefone = 0;
    float salario = 0;
	int codDep = 0;
    char dep[256];
	char c;
	unsigned long long int proxIndex = 0;
	unsigned long long int characteresPassados = 0;
	int i = 0, var = 0;
				// 0 = Matricula
				// 1 = nome;
				// 2 = telefone;
				// 3 = salario
				// 4 = departameto;
				// 5 = #
	
	char buffer[256];
	//int max = 10;
	
    //while ( (fscanf(fdm, "%d %s %d %f %s %c",&mat, &nome, &telefone, &salario, &dep, &c)) != EOF ){
	while ((c = fgetc(fdm)) != EOF){

		if (c == '#'){
			characteresPassados++;
			continue;
		}
		if (c != '\n'){
			if (c == ' '){
				switch (var) {
					case 0:
						mat = atoi(buffer);
						memset(buffer, 0, 256);
						var++;
						i = 0;
						break;
					case 1:
						strcpy(nome, buffer);
						memset(buffer, 0, 256);
						var++;
						i = 0;
						break;
					case 2:
						telefone = atoi(buffer);
						memset(buffer, 0, 256);
						var++;
						i = 0;
						break;
					case 3:
						salario = (float)atof(buffer);
						memset(buffer, 0, 256);
						var++;
						i = 0;
						break;
					case 4:
						codDep = atoi(buffer);
						memset(buffer, 0, 256);
						var++;
						i = 0;
						break;
					case 5:
						memcpy(dep, buffer, strlen(buffer));
						memset(buffer, 0, 256);
						var++;
						i = 0;
						break;
				}
			} else {
				
				buffer[i++] = c;
			}
			
		} else {
			
			Dado* dado = criarDado();
			dado->matricula = mat;
			memcpy(dado->nome, nome, strlen(nome));
			dado->telefone = telefone;
			dado->codDep = codDep;
			dado->salario = salario;
			dado->index = proxIndex;
			memcpy(dado->departamento, dep, strlen(dep));
			
			// Inserir na Arvore
			inserirArvore(arvore, dado);
			proxIndex = characteresPassados;
			var = 0;
		}
		characteresPassados++;
	}
	
MENU:
	printf("O que desejas fazer:\n"
		   "\t1.\tBuscar dado.\n"
		   "\t2.\tInserir dado.\n"
		   "\t3.\tRemover dado.\n"
		   "\t4.\tMostrar posicao inicial do dado no arquivo (Index).\n"
		   "\t5.\tMostrar linha do dado no arquivo.\n"
		   "\t6.\tTamanho do arquivo.\n"
		   "\t7.\tSalvar alterações.\n"
		   "\t8.\tSair do programa\n\t");
	int op;
	scanf("%d", &op);
	switch (op) {
		case 0:
			exit(0);
			break;
		case 1:
			fazerBusca(arvore);
			goto MENU;
			break;
		case 2:
			insereRegistro(arvore);
			goto MENU;
			break;
		case 3:
			removerDado(arvore);
			goto MENU;
			break;
		case 4:
			printaIndex(arvore);
			goto MENU;
			break;
		case 5:
			printLinhaArquivo(arvore);
			goto MENU;
			break;
		case 6:
			printaTamanhoFile("Arq.txt");
			goto MENU;
			break;
		case 7:
			salvarArvore(arvore, "Coisa.txt");
			goto MENU;
			break;
			
  default:
			printf("Opção invalida!\n");
			goto MENU;
			break;
	}
	
    return 0;
}