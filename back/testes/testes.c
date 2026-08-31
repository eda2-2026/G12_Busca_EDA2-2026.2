#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../BuscaBinaria/binaria.h"
#include "../BuscaHash/hash.h"


void exibir_resultado(const char* nome_teste, int passou) {
    if (passou) {
        printf("[ OK ] %s\n", nome_teste);
    } else {
        printf("[ERRO] %s\n", nome_teste);
    }
}

void rodar_testes_binaria() {
    ArrayEnderecos arr;
    inicializarArray(&arr);

    Endereco e1 = {"73000000", "Rua C", "", "Bairro C", 3, 3};
    Endereco e2 = {"71000000", "Rua A", "", "Bairro A", 1, 1};
    Endereco e3 = {"72000000", "Rua B", "", "Bairro B", 2, 2};

    inserirArray(&arr, e1);
    inserirArray(&arr, e2);
    inserirArray(&arr, e3);

    printf("-------------------------------------------------\n");
    printf("   BATERIA DE TESTES - BUSCA BINARIA (EDA 2)     \n");
    printf("-------------------------------------------------\n");

    ordenarArray(&arr);
    int ordenou_certo = (strcmp(arr.enderecos[0].cep, "71000000") == 0 && 
                         strcmp(arr.enderecos[2].cep, "73000000") == 0);
    exibir_resultado("Ordenacao (qsort) - O menor CEP foi para o inicio e o maior pro fim?", ordenou_certo);

    int interacoes = 0;
    Endereco* resultado;

    resultado = buscarBinaria(&arr, "71000000", &interacoes);
    exibir_resultado("Busca Binaria - Encontrar o PRIMEIRO elemento do array.", resultado != NULL);

    resultado = buscarBinaria(&arr, "73000000", &interacoes);
    exibir_resultado("Busca Binaria - Encontrar o ULTIMO elemento do array.", resultado != NULL);

    resultado = buscarBinaria(&arr, "72000000", &interacoes);
    int rua_certa = (resultado != NULL && strcmp(resultado->rua, "Rua B") == 0);
    exibir_resultado("Busca Binaria - Validar se os dados do struct retornado estao corretos.", rua_certa);

    resultado = buscarBinaria(&arr, "99999999", &interacoes);
    exibir_resultado("Busca Binaria - Retornar NULL ao buscar um CEP que NAO EXISTE.", resultado == NULL);
    
    liberarArray(&arr);
}

void rodar_testes_hash() {
    TabelaHash tabela;
    inicializarTabela(tabela);

    printf("\n-------------------------------------------------\n");
    printf("   BATERIA DE TESTES - BUSCA HASH (EDA 2)        \n");
    printf("-------------------------------------------------\n");

    int inicializou_certo = 1;
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        if (tabela[i] != NULL) {
            inicializou_certo = 0;
            break;
        }
    }
    exibir_resultado("Busca Hash - Tabela inicializada 100% com ponteiros nulos (sem lixo).", inicializou_certo);

    Endereco e1 = {"71000000", "Rua A", "", "Bairro A", 1, 1};
    Endereco e2 = {"72000000", "Rua B", "", "Bairro B", 2, 2};
    inserirHash(tabela, e1);
    inserirHash(tabela, e2);

    int interacoes = 0;
    Endereco* resultado;

    resultado = buscarHash(tabela, "71000000", &interacoes);
    exibir_resultado("Busca Hash - Encontrar um elemento recem-inserido.", resultado != NULL);

    int rua_certa = (resultado != NULL && strcmp(resultado->rua, "Rua A") == 0);
    exibir_resultado("Busca Hash - Validar se os dados do struct retornado estao corretos.", rua_certa);

    resultado = buscarHash(tabela, "99999999", &interacoes);
    exibir_resultado("Busca Hash - Retornar NULL ao buscar um CEP que NAO EXISTE.", resultado == NULL);

    liberarTabela(tabela);
    printf("-------------------------------------------------\n\n");
}

int main(void) {
    rodar_testes_binaria();
    rodar_testes_hash();
    return 0;
}
