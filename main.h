#ifndef MAIN_H
#define MAIN_H

typedef struct Endereco {
    char cep[9]; 
    char rua[100];
    char complemento[100];
    char bairro[50];
    int id_cidade;         
    int id_uf;             
} Endereco;

#endif