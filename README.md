# Sistema de Busca de Endereços (CEP) - Distrito Federal

Trabalho prático 1 para a disciplina de Estruturas de Dados 2.

## Equipe
*   [Gabriel Diniz](https://github.com/GabrielDiniz12)
*   [Pedro Americo](https://github.com/dev-americo)

## Descrição do Problema
O objetivo deste projeto é resolver o problema real de localização eficiente de endereços a partir de um CEP ou do nome da rua, simulando o backend de um sistema de logística ou entregas. 

Para tornar o projeto mais próximo da nossa realidade, a base de dados utilizada será focada exclusivamente no **Distrito Federal (DF)**, contendo milhares de registros de CEPs reais.

## Solução Proposta
Desenvolveremos um sistema com arquitetura dividida:
1.  **Backend (C):** Responsável pelo carregamento do arquivo CSV e implementação dos algoritmos de busca de alta performance na memória.
2.  **Frontend (Python/Tkinter):** Uma interface gráfica simples para interação amigável com o usuário.

## Estruturas de Dados e Algoritmos (C)
Para atender aos requisitos de complexidade do Módulo 1, implementaremos:
*   **Struct:** Para representar a entidade Endereço (CEP, logradouro, bairro, cidade, UF).
*   **Tabela Hash:** Para busca instantânea de endereço dado um CEP exato (Complexidade $O(1)$).
*   **Busca Binária:** Para busca de CEPs dado o nome da rua. O vetor de structs será ordenado alfabeticamente pelo logradouro para permitir saltos eficientes (Complexidade $O(\log N)$).

## Organização e Execução
O frontend em Python fará chamadas de sistema (subprocess) para o executável gerado em C, passando os parâmetros de busca via linha de comando e processando o retorno (stdout).

## Check-list de Desenvolvimento
- [X] Configuração do repositório e planejamento inicial (README).
- [ ] Coleta, filtragem e limpeza da base de dados do DF (.csv).
- [ ] `main.c`: Definição da Struct e leitura do arquivo CSV.
- [ ] `backend`: Implementação da Tabela Hash (Busca por CEP).
- [ ] `backend`: Implementação da Busca Binária (Busca por Rua).
- [ ] `frontend`: Criação da interface em Python.
- [ ] Integração e Testes Finais.
- [ ] Gravação do vídeo de apresentação (5 min).