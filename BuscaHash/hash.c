#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

void inicializarTabela(TabelaHash tabela) {
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        tabela[i] = NULL;
    }
}

unsigned long calcularHash(const char *cep) {
    
    unsigned long hash = 5381;
    int caractere;

    while ((caractere = *cep++)) {
        hash = hash * 33 + caractere;
    }

    return hash % TAMANHO_TABELA;
}