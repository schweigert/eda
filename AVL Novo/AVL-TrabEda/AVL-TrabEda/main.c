#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "avl.h"

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
		if (c == '#')
			continue;
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
			memcpy(dado->departamento, dep, strlen(dep));
			
			// Inserir na Arvore
			printf("Addado: %s %d %d %s %.2lf %d\n", dado->departamento, dado->codDep, dado->matricula, dado->nome, dado->salario, dado->telefone);
			inserirArvore(arvore, dado);
			
			var = 0;
		}
		
	}
	
	mostrarArvore(arvore);
	
MENU:
	
	
    return 0;
}