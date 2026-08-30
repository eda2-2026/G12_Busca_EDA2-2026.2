#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <main.h>
#include <hash.h>
#include <binaria.h>

int main() {
    // Talvez seja necessário ajustar caminho
    FILE *file = fopen("ceps/ceps_df.csv", "r");
    
    if (file == NULL) {
        printf("Erro: Nao foi possivel abrir o arquivo ceps/ceps_df.csv\n");
        return 1;
    }

    char linha[256];
    int contador = 0;

    while (fgets(linha, sizeof(linha), file)) {
        contador++;
    }

    printf("Sucesso! O sistema carregou %d enderecos do DF.\n", contador);

    fclose(file);
    return 0;
}