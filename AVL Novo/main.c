#include <stdio.h>
#include <stdlib.h>

#include "avl.h"

int main (void) {
    Arvore* arvore = criaArvore();
    FILE *fdm = fopen("Arq.txt","r");
    int mat;
    char nome[256];
    int telefone;
    float salario;
    char dep[256];
    int i = 0;
    while ( fscanf(fdm, "%d %s %d %f %d %s #",&mat, &nome, &telefone, &salario, &dep) != EOF ){
        Dado* dado = criarDado();
        dado->matricula = mat;
        for (i = 0; nome[i] != '\0'; i++){
            dado->nome[i]=nome[i];
            dado->nome[i+1] = '\0';
        }
        dado->telefone = telefone;
        dado->salario = salario;
        for (i = 0; dep[i] != '\0'; i++){
            dado->departamento[i]=dep[i];
            dado->departamento[i+1] = '\0';
        }

        // Inserir na Arvore
        inserirArvore(arvore, dado);


    }


    return 0;
}