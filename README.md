# Sistema de Busca de Endereços (CEP) - Distrito Federal

Trabalho prático 1 para a disciplina de Estruturas de Dados 2.

## 📹 Apresentação
* **Assista ao Vídeo:** [Apresentação da dupla](https://youtu.be/1C0pOiptocI)

## Equipe
*   [Gabriel Diniz](https://github.com/GabrielDiniz12) - 241025630
*   [Pedro Americo](https://github.com/dev-americo) - 241025980

## Descrição do Problema
O objetivo deste projeto é resolver o problema real de localização eficiente de endereços a partir de um CEP, simulando o backend de um sistema de logística ou entregas. 

Para tornar o projeto mais próximo da nossa realidade, a base de dados utilizada é focada exclusivamente no **Distrito Federal (DF)**, contendo milhares de registros de CEPs reais.
* **Fonte da Base de Dados:** [Cep Aberto](https://www.cepaberto.com/). É necessário fazer login para baixar os dados.

## Arquitetura da Solução
Desenvolvemos um sistema com arquitetura dividida:
1.  **Backend (C):** Responsável pelo carregamento do arquivo CSV e implementação dos algoritmos de busca de alta performance na memória.
2.  **Frontend (Python/Tkinter):** Uma interface gráfica simples para interação amigável com o usuário.

## Estruturas de Dados e Algoritmos (C)
Para atender aos requisitos de complexidade da disciplina, implementamos:
*   **Tabela Hash:** Busca de endereços pelo CEP com tratamento de colisões via encadeamento (Complexidade média $O(1)$).
*   **Busca Binária (Vetor Dinâmico):** Os dados são carregados em um Array dinâmico e ordenados com `qsort`. A busca é feita dividindo o vetor pela metade sucessivamente (Complexidade $O(\log N)$).

Ambos os métodos possuem **contadores de iteração**, permitindo ao usuário comparar a performance de cada estrutura em tempo de execução.

---

## 🚀 Como Executar o Projeto

### Pré-requisitos
* Compilador **GCC** (para o código C).
* **Python 3** e biblioteca **Tkinter** (para a Interface Gráfica).
  * *No Windows:* O Tkinter já vem instalado por padrão com o Python.
  * *No Ubuntu:* `sudo apt install python3-tk`

### Rodando a Aplicação (Interface Gráfica)
O script Python compila o código C automaticamente. Basta rodar o comando abaixo na raiz do projeto:
```bash
python3 front/interface.py
```
A janela se abrirá. Digite o CEP, escolha o motor de busca desejado e clique em "Buscar".

### Rodando a Suíte de Testes (Backend)
Para garantir a qualidade do software, implementamos Testes Unitários mockados para validar as condições de contorno (início, fim e elementos inexistentes) dos algoritmos.
Para rodar os testes, acesse a pasta `back` e compile os módulos:

```bash
cd back
gcc -Wall -Wextra testes/testes.c BuscaBinaria/binaria.c BuscaHash/hash.c -o rodar_testes
./rodar_testes
```

## Check-list de Desenvolvimento
- [X] Configuração do repositório e planejamento inicial.
- [X] Coleta, filtragem e limpeza da base de dados do DF (.csv).
- [X] `main.c`: Definição da Struct e leitura do arquivo CSV.
- [X] `backend`: Implementação da Tabela Hash (Busca por CEP).
- [X] `backend`: Implementação da Busca Binária com Array Dinâmico.
- [X] `backend`: Implementação de Testes Unitários Isolados.
- [X] `frontend`: Criação da interface em Python (Tkinter).
- [X] Integração entre Python e C.
- [X] Gravação do vídeo de apresentação (5 min).

