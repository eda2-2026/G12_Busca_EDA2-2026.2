import tkinter as tk
from tkinter import messagebox
import subprocess

janela = tk.Tk()
janela.title("Busca de Endereços DF")
janela.geometry("450x450")
janela.configure(padx=20, pady=20)

titulo = tk.Label(janela, text="Sistema de Logística - DF", font=("Arial", 16, "bold"))
titulo.pack(pady=10)

janela.mainloop()