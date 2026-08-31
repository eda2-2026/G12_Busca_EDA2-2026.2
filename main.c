#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "BuscaHash/hash.h"

int carregarDadosCSV(TabelaHash tabela, const char* caminhoArquivo) {

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

        inserirHash(tabela, endereco);

    }

    fclose(arquivo);
    return 1;
}

int main(void) {

    TabelaHash tabela;
    inicializarTabela(tabela);

    if (!carregarDadosCSV(tabela, "ceps/ceps_df.csv")) {
        liberarTabela(tabela);
        return EXIT_FAILURE;
    }

    printf("Dados carregados.\n");
    
    Endereco endereco;

    printf("Digite o CEP para buscar: \n");
    if (scanf("%8s", endereco.cep) != 1) {
        fprintf(stderr, "Entrada inválida.\n");
        liberarTabela(tabela);
        return EXIT_FAILURE;
    }

    int comparacoes = 0;

    Endereco* resultado = buscarHash(tabela, endereco.cep, &comparacoes);
    
    if (resultado != NULL) {
        printf("Encontrado: \n"
            "CEP: %s\n"
            "Rua: %s\n"
            "Bairro: %s\n"
            "Complemento: %s\n"
            "ID Cidade: %d\n"
            "ID UF: %d\n"
            "Número de comparações: %d\n",
            resultado->cep, resultado->rua, resultado->bairro, resultado->complemento, resultado->id_cidade, resultado->id_uf, comparacoes);
    } else {
        printf("CEP nao encontrado.\n");
    }

    liberarTabela(tabela);

    return 0;
}