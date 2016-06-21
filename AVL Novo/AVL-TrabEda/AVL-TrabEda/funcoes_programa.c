//
//  funcoes_programa.c
//  AVL-TrabEda
//
//  Created by usuario on 6/21/16.
//  Copyright © 2016 Udesc. All rights reserved.
//

#include "funcoes_programa.h"

void fazerBusca(Arvore* arv){
    
    printf("Digite a matricula que desejas buscar\t");
    int mat;
    scanf("%d", &mat);
    
    Dado *resultado = buscarDado(arv, mat);
    
    if (resultado == NULL){
        printf("Nao existe esse registro!\n");
        return;
    }
    printf("Dado encontrado:\t");
    printaDados(resultado);
}

void insereRegistro(Arvore* arv){
    Dado* d = criarDado();
    printf("Digite a matricula\t");
    scanf("%d", &d->matricula);
    //if (bus)
    printf("Digite o nome\t");
    scanf("%256s", &d->nome);
    printf("Digite o telefone\t");
    scanf("%d", &d->telefone);
    printf("Digite o salario\t");
    scanf("%f", &d->salario);
    printf("Digite o codigo de departamento\t");
    scanf("%d", &d->codDep);
    printf("Digite o departamento\t");
    scanf("%256s", &d->departamento);
    printf("Inserindo ");
    printaDados(d);
    inserirArvore(arv, d);
    
}

void removerDado(Arvore* arv){
    printf("Digite a matricula que desejas remover\t");
    int mat;
    scanf("%d", &mat);
    
    Dado *resultado = buscarDado(arv, mat);
    
    if (resultado == NULL){
        printf("Nao existe esse registro!\n");
        return;
    }
    printf("Dado removido:\t");
    printaDados(resultado);
    removerArvore(arv, resultado);
}
void printaIndex(Arvore* arv){
    printf("Digite a matricula que desejas buscar o index\t");
    int mat;
    scanf("%d", &mat);
    
    Dado *resultado = buscarDado(arv, mat);
    
    if (resultado == NULL){
        printf("Nao existe esse registro!\n");
        return;
    }
    printf("Index: %lld\n", resultado->index);
}

void printLinhaArquivo(Arvore* arv){
    printf("Digite a matricula que desejas buscar\t");
    int mat;
    scanf("%d", &mat);
    
    Dado *resultado = buscarDado(arv, mat);
    
    if (resultado == NULL){
        printf("Nao existe esse registro!\n");
        return;
    }
    printf("%lld\t", resultado->index);
    FILE *f = fopen("Arq.txt", "r");
    fseek(f, resultado->index, SEEK_SET);
    char buff[1000];
    fscanf(f, "%[^#]s", buff);
    printf("%s\n", buff);
}

void printaTamanhoFile(const char* f){
    FILE *fdm = fopen(f,"r");
    
    if (!fdm){
        puts("Falha ao abrir arquivo!");
        return;
    }
    fseek(fdm, 0, SEEK_END);
    unsigned long long int sz = ftell(fdm);
    printf("Tamanho: %lld bytes\n", sz);
    fclose(fdm);
}

void printaDados(Dado *dado){
    printf("[%d] = %s, telefone: %d, salario: %.2lf, do departamento %s [ %d ]\n",
           dado->matricula,
           dado->nome,
           dado->telefone,
           dado->salario,
           dado->departamento,
           dado->codDep);
}

