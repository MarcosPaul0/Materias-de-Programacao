import tkinter as tk
from tkinter import messagebox
import os.path
import pickle

class Artista:
  def __init__(self, nome):
    self.__nome = nome
    self.__albuns = []

  def getNome(self):
    return self.__nome

  def getAlbuns(self):
    return self.__albuns

  def addAlbum(self, album):
    self.__albuns.append(album)

class ViewCadastrarArtista(tk.Toplevel):
  def __init__(self, controle):
    tk.Toplevel.__init__(self)
    self.geometry('300x200')
    self.title("Artista")
    self.controle = controle

    self.frameNome = tk.Frame(self, pady=10)
    self.frameBotao = tk.Frame(self)

    self.frameNome.pack()
    self.frameBotao.pack()

    self.labelNome = tk.Label(self.frameNome,text="Nome: ")
    self.labelNome.pack(side="left")  

    self.inputNome = tk.Entry(self.frameNome, width=20)
    self.inputNome.pack(side="left")

    self.buttonEnter = tk.Button(self.frameBotao ,text="Inserir")      
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

class ViewConsultarArtista(tk.Toplevel):
  def __init__(self, controle):
    tk.Toplevel.__init__(self)
    self.geometry('300x200')
    self.title("Artista")
    self.controle = controle

    self.frameNome = tk.Frame(self)
    self.frameBotao = tk.Frame(self)

    self.frameNome.pack()
    self.frameBotao.pack()

    self.labelNome = tk.Label(self.frameNome,text="Nome: ")
    self.labelNome.pack(side="left")  

    self.inputNome = tk.Entry(self.frameNome, width=20)
    self.inputNome.pack(side="left")

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


class ControleAtista:
  def __init__(self, controlePrincipal):
    self.controlePrincipal = controlePrincipal
    if not os.path.isfile("artista.pickle"):
      self.listaArtista =  []
    else:
      with open("artista.pickle", "rb") as f:
        self.listaArtista = pickle.load(f)

  def salvaArtista(self):
    if len(self.listaArtista) != 0:
      with open("artista.pickle","wb") as f:
        pickle.dump(self.listaArtista, f)

  def getListaArtista(self):
    return self.listaArtista

  #-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= FUNÇÕES DE INSERÇÃO -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

  def insereArtista(self):
    self.viewInsereArtista = ViewCadastrarArtista(self)

  def enterHandlerIn(self, event):
    nome = self.viewInsereArtista.inputNome.get()
    aluno = Artista(nome)

    self.listaArtista.append(aluno)
    self.viewInsereArtista.mostraJanela('Sucesso', 'Artista cadastrado com sucesso')
    self.limpaHandlerIn(event)

  def limpaHandlerIn(self, event):
    self.viewInsereArtista.inputNome.delete(0, len(self.viewInsereArtista.inputNome.get()))

  def fechaHandlerIn(self, event):
    self.viewInsereArtista.destroy()

  #-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= FUNÇÕES DE CONSULTA -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

  def consultaArtista(self):
    self.viewConsultaArtista = ViewConsultarArtista(self)

  def enterHandlerCon(self, event):
    nome = self.viewConsultaArtista.inputNome.get()
    print(self.listaArtista)
    resposta = ''

    for artista in self.listaArtista:
      if artista.getNome() == nome:
        for album in artista.getAlbuns():
          resposta += '-=-=- Álbum {} -=-=-\n'.format(album.getTitulo())
          for faixa in album.getFaixas():
            resposta += '{}  /  {}\n'.format(faixa.getNroFaixa(), faixa.getTitulo())
            
    if resposta:
      self.viewConsultaArtista.mostraJanela(str(nome), resposta)
    else:
      self.viewConsultaArtista.mostraJanela(str(nome), 'Artista não encontrado ou não possui álbuns')
    self.limpaHandlerCon(event)

  def limpaHandlerCon(self, event):
    self.viewConsultaArtista.inputNome.delete(0, len(self.viewConsultaArtista.inputNome.get()))

  def fechaHandlerCon(self, event):
    self.viewConsultaArtista.destroy()