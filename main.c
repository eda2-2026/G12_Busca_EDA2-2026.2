#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "BuscaHash/hash.h"

void carregarDadosCSV(TabelaHash tabela, const char* caminhoArquivo) {

    FILE* arquivo = fopen(caminhoArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo CSV!\n");
        return;
    }

    char linha[512]; 
    
    Endereco endereco;

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        
        linha[strcspn(linha, "\n")] = '\0';

        char* linha_ptr = linha;
        char* token;
        
        token = strsep(&linha_ptr, ",");
        if (token != NULL) strcpy(endereco.cep, token);
        
        token = strsep(&linha_ptr, ",");
        if (token != NULL) strcpy(endereco.rua, token);
        
        token = strsep(&linha_ptr, ",");
        if (token != NULL) strcpy(endereco.complemento, token); 
        
        token = strsep(&linha_ptr, ",");
        if (token != NULL) strcpy(endereco.bairro, token);
        
        token = strsep(&linha_ptr, ",");
        if (token != NULL) endereco.id_cidade = atoi(token);
        
        token = strsep(&linha_ptr, ",");
        if (token != NULL) endereco.id_uf = atoi(token);

        inserirHash(tabela, endereco);

    }

    fclose(arquivo);
}

int main(int argc, char *argv[]) {

    TabelaHash tabela;
    inicializarTabela(tabela);

    carregarDadosCSV(tabela, "ceps/ceps_df.csv");

    printf("Dados carregados.\n");
    
    Endereco endereco;

    printf("Digite o CEP para buscar: \n");
    scanf("%s", endereco.cep);

    Endereco* resultado = buscarHash(tabela, endereco.cep);
    
    if (resultado != NULL) {
        printf("Encontrado: \n"
            "CEP: %s\n"
            "Rua: %s\n"
            "Bairro: %s\n"
            "Complemento: %s\n"
            "ID Cidade: %d\n"
            "ID UF: %d\n", 
            resultado->cep, resultado->rua, resultado->bairro, resultado->complemento, resultado->id_cidade, resultado->id_uf);
    } else {
        printf("CEP nao encontrado.\n");
    }

    return 0;
}