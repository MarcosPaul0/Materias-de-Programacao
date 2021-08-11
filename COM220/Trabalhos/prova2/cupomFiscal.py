import tkinter as tk
from tkinter import ttk
from tkinter import messagebox
import os.path
import pickle

class CupomFiscal:
  def __init__(self, nroCupom, itensCupom):
    self.__nroCupom = nroCupom
    self.__itensCupom = itensCupom

  def getNroCupom(self):
    return self.__nroCupom

  def getItensCupom(self):
    return self.__itensCupom

class ViewInsereCupomFiscal(tk.Toplevel):
  def __init__(self, controle, listaProdutos):
    tk.Toplevel.__init__(self)
    self.geometry('320x360')
    self.title("Cupom Fiscal Cadastro")
    self.controle = controle

    self.frameNroCupom = tk.Frame(self, pady=10)
    self.frameProdutos = tk.Frame(self)
    self.frameBotao = tk.Frame(self, pady=10)

    self.frameNroCupom.pack()
    self.frameProdutos.pack()
    self.frameBotao.pack()

    self.labelNroCupom = tk.Label(self.frameNroCupom,text="Número do Cupom: ")
    self.labelNroCupom.pack(side="left")

    self.inputNroCupom = tk.Entry(self.frameNroCupom, width=20)
    self.inputNroCupom.pack(side="left")

    self.labelProdutos = tk.Label(self.frameProdutos,text="Produtos: ")
    self.labelProdutos.pack(side="left")

    self.escolhaProdutos = tk.StringVar()
    self.produtos = ttk.Combobox(self.frameProdutos, width = 15 , textvariable = self.escolhaProdutos)
    self.produtos.pack(side="left")
    self.produtos['values'] = listaProdutos

    self.buttonInserir = tk.Button(self.frameProdutos ,text="Inserir Produto")      
    self.buttonInserir.pack(side="left")
    self.buttonInserir.bind("<Button>", controle.insereHandlerIn)

    self.buttonEnter = tk.Button(self.frameBotao ,text="Cadastrar Cupom")      
    self.buttonEnter.pack(side="left")
    self.buttonEnter.bind("<Button>", controle.enterHandlerIn)

    self.buttonFechar = tk.Button(self.frameBotao ,text="Concluído")      
    self.buttonFechar.pack(side="left")
    self.buttonFechar.bind("<Button>", controle.fechaHandlerIn)
  
  def mostraJanela(self, titulo, msg):
    messagebox.showinfo(titulo, msg)

class ViewConsultaCupomFiscal(tk.Toplevel):
  def __init__(self, controle):
    tk.Toplevel.__init__(self)
    self.geometry('300x200')
    self.title("Cupom Fiscal Consulta")
    self.controle = controle

    self.frameNroCupom = tk.Frame(self, pady=10)
    self.frameBotao = tk.Frame(self)

    self.frameNroCupom.pack()
    self.frameBotao.pack()

    self.labelNroCupom = tk.Label(self.frameNroCupom,text="Código: ")
    self.labelNroCupom.pack(side="left")  

    self.inputNroCupom = tk.Entry(self.frameNroCupom, width=20)
    self.inputNroCupom.pack(side="left")

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

class ControleCupomFiscal:
  def __init__(self, controlePrincipal):
    self.controlePrincipal = controlePrincipal
    if not os.path.isfile("cupomFiscal.pickle"):
      self.listaCupomFiscal =  []
    else:
      with open("cupomFiscal.pickle", "rb") as f:
        self.listaCupomFiscal = pickle.load(f)
    self.listaProdutos = []

  def salvarCupomFiscal(self):
    if len(self.listaCupomFiscal) != 0:
      with open("cupomFiscal.pickle","wb") as f:
        pickle.dump(self.listaCupomFiscal, f)

  #-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= FUNÇÕES DE INSERÇÃO -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
  def insereCupomFiscal(self):
    listaDescricaoProduto = []
    for produto in self.controlePrincipal.ctrlProduto.getProdutos():
      listaDescricaoProduto.append(produto.getDescricao())
    self.viewInsereCupomFiscal = ViewInsereCupomFiscal(self, listaDescricaoProduto)

  def insereHandlerIn(self, event):
    escolhaProduto = self.viewInsereCupomFiscal.escolhaProdutos.get()

    for produto in self.controlePrincipal.ctrlProduto.getProdutos():
      if produto.getDescricao() == escolhaProduto:
        self.listaProdutos.append(produto)
        break

    self.viewInsereCupomFiscal.mostraJanela('Sucesso', 'Produto inserido ao cupom!')

  def enterHandlerIn(self, event):
    nroCupom = self.viewInsereCupomFiscal.inputNroCupom.get()

    cupomFiscal = CupomFiscal(nroCupom, self.listaProdutos.copy())
    self.listaCupomFiscal.append(cupomFiscal)

    self.viewInsereCupomFiscal.mostraJanela('Sucesso', 'Cupom fiscal registrado!')
    self.listaProdutos.clear()
    self.fechaHandlerIn(event)

  def fechaHandlerIn(self, event):
    self.viewInsereCupomFiscal.destroy()

  #-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= FUNÇÕES DE CONSULTA -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
  def consultaCupomFiscal(self):
    self.viewConsultaCupomFiscal = ViewConsultaCupomFiscal(self)
  
  def enterHandlerCon(self, event):
    nroCupom = self.viewConsultaCupomFiscal.inputNroCupom.get()
    resposta =''
    listaProdutoUnicos = []

    for cupomFiscal in self.listaCupomFiscal:
      if cupomFiscal.getNroCupom() == nroCupom:
        for produto in cupomFiscal.getItensCupom():
          if produto not in listaProdutoUnicos:
            listaProdutoUnicos.append(produto)

        resposta += 'Código -=- Descrição -=- Valor -=- Qtd\n'
        for produtoUnico in listaProdutoUnicos:
          resposta += '{}  /  {}  /'.format(produtoUnico.getCodigo(), produtoUnico.getDescricao())
          resposta += '  {}  /  {}\n'.format(cupomFiscal.getItensCupom().count(produtoUnico) * produtoUnico.getValor(), cupomFiscal.getItensCupom().count(produtoUnico))



    if resposta:
      self.viewConsultaCupomFiscal.mostraJanela(str(nroCupom), resposta)
    else:
      self.viewConsultaCupomFiscal.mostraJanela(str(nroCupom), 'Cupom não encontrado!')
    self.limpaHandlerCon(event)

  def limpaHandlerCon(self, event):
    self.viewConsultaCupomFiscal.inputNroCupom.delete(0, len(self.viewConsultaCupomFiscal.inputNroCupom.get()))

  def fechaHandlerCon(self, event):
    self.viewConsultaCupomFiscal.destroy()