import tkinter as tk
from tkinter import messagebox
import os.path
import pickle

class Produto:
  def __init__(self, codigo, descricao, valor):
    self.__codigo = codigo
    self.__descricao = descricao
    self.__valor = valor

  def getCodigo(self):
    return self.__codigo

  def getDescricao(self):
    return self.__descricao

  def getValor(self):
    return self.__valor

class ViewInsereProduto(tk.Toplevel):
  def __init__(self, controle):
    tk.Toplevel.__init__(self)
    self.geometry('300x200')
    self.title("Produto Cadastro")
    self.controle = controle

    self.frameCodigo = tk.Frame(self, pady=10)
    self.frameDescricao = tk.Frame(self)
    self.frameValor = tk.Frame(self, pady=10)
    self.frameBotao = tk.Frame(self)

    self.frameCodigo.pack()
    self.frameDescricao.pack()
    self.frameValor.pack()
    self.frameBotao.pack()

    self.labelCodigo = tk.Label(self.frameCodigo,text="Código: ")
    self.labelCodigo.pack(side="left")  

    self.inputCodigo = tk.Entry(self.frameCodigo, width=20)
    self.inputCodigo.pack(side="left")

    self.labelDescricao = tk.Label(self.frameDescricao,text="Descrição: ")
    self.labelDescricao.pack(side="left")  

    self.inputDescricao = tk.Entry(self.frameDescricao, width=20)
    self.inputDescricao.pack(side="left")

    self.labelValor = tk.Label(self.frameValor,text="Valor: ")
    self.labelValor.pack(side="left")  

    self.inputValor = tk.Entry(self.frameValor, width=20)
    self.inputValor.pack(side="left")

    self.buttonEnter = tk.Button(self.frameBotao ,text="Registrar")      
    self.buttonEnter.pack(side="left")
    self.buttonEnter.bind("<Button>", controle.enterHandlerIn)
  
    self.buttonLimpar = tk.Button(self.frameBotao ,text="Limpar")      
    self.buttonLimpar.pack(side="left")
    self.buttonLimpar.bind("<Button>", controle.limpaHandlerIn)  

    self.buttonFechar = tk.Button(self.frameBotao ,text="Concluído")      
    self.buttonFechar.pack(side="left")
    self.buttonFechar.bind("<Button>", controle.fechaHandlerIn)

  def mostraJanela(self, titulo, msg):
    messagebox.showinfo(titulo, msg)

class ViewConsultaProduto(tk.Toplevel):
  def __init__(self, controle):
    tk.Toplevel.__init__(self)
    self.geometry('300x200')
    self.title("Produto Consulta")
    self.controle = controle

    self.frameCodigo = tk.Frame(self, pady=10)
    self.frameBotao = tk.Frame(self)

    self.frameCodigo.pack()
    self.frameBotao.pack()

    self.labelCodigo = tk.Label(self.frameCodigo,text="Código: ")
    self.labelCodigo.pack(side="left")  

    self.inputCodigo = tk.Entry(self.frameCodigo, width=20)
    self.inputCodigo.pack(side="left")

    self.buttonEnter = tk.Button(self.frameBotao ,text="Buscar")      
    self.buttonEnter.pack(side="left")
    self.buttonEnter.bind("<Button>", controle.enterHandlerCon)
  
    self.buttonLimpar = tk.Button(self.frameBotao ,text="Limpar")      
    self.buttonLimpar.pack(side="left")
    self.buttonLimpar.bind("<Button>", controle.limpaHandlerCon)  

    self.buttonFechar = tk.Button(self.frameBotao ,text="Concluído")      
    self.buttonFechar.pack(side="left")
    self.buttonFechar.bind("<Button>", controle.fechaHandlerCon)

  def mostraJanela(self, titulo, msg):
    messagebox.showinfo(titulo, msg)

class ControleProduto:
  def __init__(self, controlePrincipal):
    self.controlePrincipal = controlePrincipal
    if not os.path.isfile("produto.pickle"):
      self.listaProduto =  []
    else:
      with open("produto.pickle", "rb") as f:
        self.listaProduto = pickle.load(f)

  def salvarProduto(self):
    if len(self.listaProduto) != 0:
      with open("produto.pickle","wb") as f:
        pickle.dump(self.listaProduto, f)

  #-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= FUNÇÃO AUXILIAR -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
  def getProdutos(self):
    return self.listaProduto

  #-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= FUNÇÕES DE INSERÇÃO -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
  def insereProduto(self):
    self.viewInsereProduto = ViewInsereProduto(self)

  def enterHandlerIn(self, event):
    codigo = self.viewInsereProduto.inputCodigo.get()
    descricao = self.viewInsereProduto.inputDescricao.get()
    valor = self.viewInsereProduto.inputValor.get()

    produto = Produto(codigo, descricao, float(valor.replace(',', '.')))
    self.listaProduto.append(produto)

    self.viewInsereProduto.mostraJanela('Sucesso', 'Produto inserido com sucesso!')
    self.limpaHandlerIn(event)

  def limpaHandlerIn(self, event):
    self.viewInsereProduto.inputCodigo.delete(0, len(self.viewInsereProduto.inputCodigo.get()))
    self.viewInsereProduto.inputDescricao.delete(0, len(self.viewInsereProduto.inputDescricao.get()))
    self.viewInsereProduto.inputValor.delete(0, len(self.viewInsereProduto.inputValor.get()))

  def fechaHandlerIn(self, event):
    self.viewInsereProduto.destroy()

  #-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= FUNÇÕES DE CONSULTA -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
  def consultaProduto(self):
    self.viewConsultaProduto = ViewConsultaProduto(self)

  def enterHandlerCon(self, event):
    codigo = self.viewConsultaProduto.inputCodigo.get()
    resposta = ''

    for produto in self.listaProduto:
      if produto.getCodigo() == codigo:
        resposta += '{}  /  {}  /  {}'.format(produto.getCodigo(), produto.getDescricao(), str(produto.getValor()).replace('.', ','))

    if resposta:
      self.viewConsultaProduto.mostraJanela(str(codigo), resposta)
    else:
      self.viewConsultaProduto.mostraJanela(str(codigo), 'Produto não encontrado!')
    self.limpaHandlerCon(event)

  def limpaHandlerCon(self, event):
    self.viewConsultaProduto.inputCodigo.delete(0, len(self.viewConsultaProduto.inputCodigo.get()))

  def fechaHandlerCon(self, event):
    self.viewConsultaProduto.destroy()