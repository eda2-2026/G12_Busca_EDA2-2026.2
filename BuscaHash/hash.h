#ifndef HASH_H
#define HASH_H
#include "../main.h"
#define TAMANHO_TABELA 10007

typedef struct NoHash {
    Endereco info;
    struct NoHash *prox;
} NoHash;

typedef  NoHash* TabelaHash[TAMANHO_TABELA];

void inicializarTabela(TabelaHash tabela);

unsigned long calcularHash(const char *cep);

void inserirHash(TabelaHash tabela, Endereco endereco);

Endereco* buscarHash(TabelaHash tabela, const char *cep);

#endif