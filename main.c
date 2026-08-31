#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "BuscaHash/hash.h"
#include "BuscaBinaria/binaria.h"

int carregarDadosCSV(TabelaHash tabela, ArrayEnderecos* arrayBinario, const char* caminhoArquivo) {

    FILE* arquivo = fopen(caminhoArquivo, "r");
    if (arquivo == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo CSV: %s\n", caminhoArquivo);
        return 0;
    }

    char linha[512]; 
    
    Endereco endereco;

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        
        linha[strcspn(linha, "\r\n")] = '\0';
        memset(&endereco, 0, sizeof(Endereco));

        char* linha_ptr = linha;
        char* token;
        
        token = strsep(&linha_ptr, ",");
        if (token != NULL) snprintf(endereco.cep, sizeof(endereco.cep), "%s", token);
        
        token = strsep(&linha_ptr, ",");
        if (token != NULL) snprintf(endereco.rua, sizeof(endereco.rua), "%s", token);
        
        token = strsep(&linha_ptr, ",");
        if (token != NULL) snprintf(endereco.complemento, sizeof(endereco.complemento), "%s", token); 
        
        token = strsep(&linha_ptr, ",");
        if (token != NULL) snprintf(endereco.bairro, sizeof(endereco.bairro), "%s", token);
        
        token = strsep(&linha_ptr, ",");
        if (token != NULL) endereco.id_cidade = atoi(token);
        
        token = strsep(&linha_ptr, ",");
        if (token != NULL) endereco.id_uf = atoi(token);

        if (tabela != NULL) inserirHash(tabela, endereco);
        if (arrayBinario != NULL) inserirArray(arrayBinario, endereco);

    }

    fclose(arquivo);
    return 1;
}

int main(void) {

    TabelaHash tabela;
    inicializarTabela(tabela);

    ArrayEnderecos arrayBinario;
    inicializarArray(&arrayBinario);

    // Carrega tudo
    if (!carregarDadosCSV(tabela, &arrayBinario, "ceps/ceps_df.csv")) {
        liberarTabela(tabela);
        liberarArray(&arrayBinario);
        return EXIT_FAILURE;
    }

    printf("Ordenando os dados para a busca binária...\n");
    ordenarArray(&arrayBinario);
    printf("Dados carregados e ordenados.\n");

    Endereco endereco;

    printf("Digite o CEP para buscar: \n");
    if (scanf("%8s", endereco.cep) != 1) {
        fprintf(stderr, "Entrada inválida.\n");
        liberarTabela(tabela);
        liberarArray(&arrayBinario);
        return EXIT_FAILURE;
    }

    int comparacoesHash = 0;
    int comparacoesBinaria = 0;

    // Roda ambas as buscas para que vocês possam testar e ver as interações
    Endereco* resultado = buscarHash(tabela, endereco.cep, &comparacoesHash);
    buscarBinaria(&arrayBinario, endereco.cep, &comparacoesBinaria);
    
    if (resultado != NULL) {
        printf("\nEncontrado: \n"
            "CEP: %s\n"
            "Rua: %s\n"
            "Bairro: %s\n"
            "Complemento: %s\n"
            "ID Cidade: %d\n"
            "ID UF: %d\n"
            "Número de interações na Hash: %d\n"
            "Número de interações na Binária: %d\n",
            resultado->cep, resultado->rua, resultado->bairro, resultado->complemento, 
            resultado->id_cidade, resultado->id_uf, comparacoesHash, comparacoesBinaria);
    } else {
        printf("\nCEP nao encontrado.\n");
    }

    liberarTabela(tabela);
    liberarArray(&arrayBinario);

    return 0;
}