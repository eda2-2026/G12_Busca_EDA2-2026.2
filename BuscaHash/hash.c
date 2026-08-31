#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

void inicializarTabela(TabelaHash tabela) {
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        tabela[i] = NULL;
    }
}