#ifndef BINARIA_H
#define BINARIA_H

#include "../main.h"

typedef struct {
    Endereco* enderecos;
    int tamanho;
    int capacidade;
} ArrayEnderecos;

void inicializarArray(ArrayEnderecos* arr);

void inserirArray(ArrayEnderecos* arr, Endereco endereco);

void liberarArray(ArrayEnderecos* arr);

void ordenarArray(ArrayEnderecos* arr);

Endereco* buscarBinaria(ArrayEnderecos* arr, const char* cep, int* iteracoes);

#endif
