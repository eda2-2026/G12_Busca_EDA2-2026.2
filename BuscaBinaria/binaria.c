#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binaria.h"

// Inicializa o array dinâmico com capacidade inicial de 1000
void inicializarArray(ArrayEnderecos* arr) {
    arr->capacidade = 1000;
    arr->tamanho = 0;
    arr->enderecos = (Endereco*)malloc(arr->capacidade * sizeof(Endereco));
    
    if (arr->enderecos == NULL) {
        fprintf(stderr, "Erro de alocação de memória para o array binário.\n");
        exit(EXIT_FAILURE);
    }
}

// Insere um endereço, dobrando a capacidade se faltar espaço
void inserirArray(ArrayEnderecos* arr, Endereco endereco) {
    if (arr->tamanho >= arr->capacidade) {
        arr->capacidade *= 2;
        Endereco* temp = (Endereco*)realloc(arr->enderecos, arr->capacidade * sizeof(Endereco));
        
        if (temp == NULL) {
            fprintf(stderr, "Erro ao expandir memória do array binário.\n");
            free(arr->enderecos);
            exit(EXIT_FAILURE);
        }
        arr->enderecos = temp;
    }
    arr->enderecos[arr->tamanho++] = endereco;
}

// Função auxiliar exigida pelo qsort para saber como comparar dois Endereços
int compararEnderecos(const void* a, const void* b) {
    Endereco* endA = (Endereco*)a;
    Endereco* endB = (Endereco*)b;
    return strcmp(endA->cep, endB->cep);
}

// Ordena todos os endereços do vetor crescentemente pelo CEP
void ordenarArray(ArrayEnderecos* arr) {
    qsort(arr->enderecos, arr->tamanho, sizeof(Endereco), compararEnderecos);
}

// A busca binária clássica, com contador de interações
Endereco* buscarBinaria(ArrayEnderecos* arr, const char* cep, int* iteracoes) {
    int inicio = 0;
    int fim = arr->tamanho - 1;
    
    if (iteracoes != NULL) {
        *iteracoes = 0;
    }

    while (inicio <= fim) {
        if (iteracoes != NULL) {
            (*iteracoes)++;
        }

        int meio = inicio + (fim - inicio) / 2;
        int cmp = strcmp(arr->enderecos[meio].cep, cep);

        if (cmp == 0) {
            return &(arr->enderecos[meio]); // Achou
        } else if (cmp < 0) {
            inicio = meio + 1; // O CEP procurado é maior, vai pra metade superior
        } else {
            fim = meio - 1;    // O CEP procurado é menor, vai pra metade inferior
        }
    }

    return NULL; // CEP não encontrado
}

// Libera a memória alocada
void liberarArray(ArrayEnderecos* arr) {
    if (arr->enderecos != NULL) {
        free(arr->enderecos);
        arr->enderecos = NULL;
    }
    arr->tamanho = 0;
    arr->capacidade = 0;
}
