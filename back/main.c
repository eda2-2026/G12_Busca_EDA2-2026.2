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

    if (argc < 3) {
        printf("Erro: Parametros insuficientes.\n");
        return 1;
    }

    char* tipoBusca = argv[1];
    char* valorBusca = argv[2];

    TabelaHash tabela;
    inicializarTabela(tabela);
    carregarDadosCSV(tabela, "back/ceps/ceps_df.csv");

    if (strcmp(tipoBusca, "cep") == 0) {
        int iteracoes = 0;
        Endereco* resultado = buscarHash(tabela, valorBusca, &iteracoes);

        if (resultado != NULL) {
            printf("CEP: %s\n", resultado->cep);
            printf("Rua: %s\n", resultado->rua);
            printf("Bairro: %s\n", resultado->bairro);
            printf("Complemento: %s\n", resultado->complemento);
            printf("Comparacoes: %d\n", iteracoes);
        } else {
            printf("CEP nao encontrado.\n");
        }
    } else if (strcmp(tipoBusca, "rua") == 0) {
        printf("Busca por rua nao implementada.\n");
    } else {
        printf("Tipo de busca invalido. Use 'cep' ou 'rua'.\n");
    }

    return 0;
}