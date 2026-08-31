#ifndef BINARIA_H
#define BINARIA_H

#include "../main.h"

// Estrutura para armazenar o vetor dinâmico de endereços
typedef struct {
    Endereco* enderecos;
    int tamanho;
    int capacidade;
} ArrayEnderecos;

// Funções de gerenciamento do array
void inicializarArray(ArrayEnderecos* arr);
void inserirArray(ArrayEnderecos* arr, Endereco endereco);
void liberarArray(ArrayEnderecos* arr);

// Função para ordenar o array por CEP
void ordenarArray(ArrayEnderecos* arr);

// Algoritmo de Busca Binária
Endereco* buscarBinaria(ArrayEnderecos* arr, const char* cep, int* iteracoes);

#endif
