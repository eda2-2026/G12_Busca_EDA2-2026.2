import tkinter as tk
from tkinter import messagebox
import subprocess
import sys

def compilar_backend():
    """Compila o código C automaticamente ao abrir a interface."""
    print("Compilando o backend em C...")
    try:
        comando = [
            "gcc", 
            "back/main.c", 
            "back/BuscaHash/hash.c", 
            "back/BuscaBinaria/binaria.c", 
            "-o", 
            "main.out"
        ]
        
        resultado = subprocess.run(comando, capture_output=True, text=True, check=True)
        print("Backend compilado com sucesso!\n")
        
    except subprocess.CalledProcessError as e:
        print("ERRO DE COMPILAÇÃO NO C:\n")
        print(e.stderr)
        sys.exit(1)

def buscar_endereco():
    termo_digitado = entrada_busca.get().strip()
    tipo_busca = var_tipo_busca.get()
    
    if not termo_digitado:
        messagebox.showwarning("Aviso", "Por favor, digite um termo para busca.")
        return
    
    try:
        resultado = subprocess.run(
            ["./main.out", tipo_busca, termo_digitado],
            capture_output=True,
            text=True,
            check=True
        )
        
        label_resultado.config(text=resultado.stdout.strip())
        
    except Exception as e:
        messagebox.showerror("Erro", f"Falha ao executar o backend em C:\n{e}")

compilar_backend()

# Configuração da Janela Principal
janela = tk.Tk()
janela.title("Busca de Endereços DF")
janela.geometry("450x450")
janela.configure(padx=20, pady=20)

titulo = tk.Label(janela, text="Sistema de Logística - DF", font=("Arial", 16, "bold"))
titulo.pack(pady=10)

frame_seletor = tk.Frame(janela)
frame_seletor.pack(pady=5)

var_tipo_busca = tk.StringVar(value="cep")

rb_cep = tk.Radiobutton(frame_seletor, text="Busca por CEP (Hash)", variable=var_tipo_busca, value="cep")
rb_cep.pack(side=tk.LEFT, padx=10)

rb_rua = tk.Radiobutton(frame_seletor, text="Busca por Rua (Binária)", variable=var_tipo_busca, value="rua")
rb_rua.pack(side=tk.LEFT, padx=10)

# Input da Busca
frame_busca = tk.Frame(janela)
frame_busca.pack(pady=10)

tk.Label(frame_busca, text="Digite o termo:").pack(side=tk.LEFT, padx=5)
entrada_busca = tk.Entry(frame_busca, width=20)
entrada_busca.pack(side=tk.LEFT)

# Botão de Busca
botao_buscar = tk.Button(janela, text="Buscar", command=buscar_endereco, bg="lightblue")
botao_buscar.pack(pady=10)

# Área de Resultados
label_resultado = tk.Label(janela, text="", justify=tk.LEFT, font=("Courier", 10), bg="#f0f0f0", width=50, height=12, anchor="nw")
label_resultado.pack(pady=10)

janela.mainloop()