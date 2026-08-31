import tkinter as tk
from tkinter import messagebox
import subprocess

janela = tk.Tk()
janela.title("Busca de Endereços DF")
janela.geometry("450x450")
janela.configure(padx=20, pady=20)

titulo = tk.Label(janela, text="Sistema de Logística - DF", font=("Arial", 16, "bold"))
titulo.pack(pady=10)

# Selecionar o tipo de busca
frame_seletor = tk.Frame(janela)
frame_seletor.pack(pady=5)

var_tipo_busca = tk.StringVar(value="cep")

rb_cep = tk.Radiobutton(frame_seletor, text="Busca por CEP (Hash)", variable=var_tipo_busca, value="cep")
rb_cep.pack(side=tk.LEFT, padx=10)

rb_rua = tk.Radiobutton(frame_seletor, text="Busca por Rua (Binária)", variable=var_tipo_busca, value="rua")
rb_rua.pack(side=tk.LEFT, padx=10)

janela.mainloop()