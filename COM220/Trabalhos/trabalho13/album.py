import tkinter as tk
from tkinter import ttk
from tkinter import messagebox
import os.path
import pickle

class Album:
  def __init__(self, titulo, artista, ano, faixas):
    self.__titulo = titulo
    self.__artista = artista
    self.__ano = ano
    self.__faixas = faixas

  def getTitulo(self):
    return self.__titulo

  def getArtista(self):
    return self.__artista

  def getAno(self):
    return self.__ano

  def getFaixas(self):
    return self.__faixas

class Musica:
  def __init__(self, titulo, nroFaixa):
    self.__titulo = titulo
    self.__nroFaixa = nroFaixa

  def getTitulo(self):
    return self.__titulo

  def getNroFaixa(self):
    return self.__nroFaixa

class ViewCadastrarAlbum(tk.Toplevel):
  def __init__(self, controle):
    tk.Toplevel.__init__(self)
    self.geometry('420x200')
    self.title("Álbum")
    self.controle = controle

    self.frameTitulo = tk.Frame(self, pady=10)
    self.frameArtista = tk.Frame(self)
    self.frameAno = tk.Frame(self, pady=10)
    self.frameIncluiFaixa = tk.Frame(self)
    self.frameFaixa = tk.Frame(self, pady=10)
    self.frameBotao = tk.Frame(self)

    self.frameTitulo.pack()
    self.frameArtista.pack()
    self.frameAno.pack()
    self.frameFaixa.pack()
    self.frameBotao.pack()

    self.labelTitulo = tk.Label(self.frameTitulo,text="Título: ")
    self.labelTitulo.pack(side="left")  
    self.inputTitulo = tk.Entry(self.frameTitulo, width=20)
    self.inputTitulo.pack(side="left")

    self.labelArtista = tk.Label(self.frameArtista,text="Artista: ")
    self.labelArtista.pack(side="left")  
    self.inputArtista = tk.Entry(self.frameArtista, width=20)
    self.inputArtista.pack(side="left")

    self.labelAno = tk.Label(self.frameAno,text="Ano: ")
    self.labelAno.pack(side="left")  
    self.inputAno = tk.Entry(self.frameAno, width=20)
    self.inputAno.pack(side="left")

    self.labelFaixa = tk.Label(self.frameFaixa,text="Faixa: ")
    self.labelFaixa.pack(side="left")  
    self.inputFaixa = tk.Entry(self.frameFaixa, width=20)
    self.inputFaixa.pack(side="left")
    self.labelNroFaixa = tk.Label(self.frameFaixa,text="Número: ")
    self.labelNroFaixa.pack(side="left")  
    self.inputNroFaixa = tk.Entry(self.frameFaixa, width=20)
    self.inputNroFaixa.pack(side="left")
    self.buttonIncluir = tk.Button(self.frameFaixa, text="Incluir")
    self.buttonIncluir.pack(side="left")
    self.buttonIncluir.bind("<Button>", controle.incluirHandler)

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

class ViewConsultarAlbum(tk.Toplevel):
  def __init__(self, controle):
    tk.Toplevel.__init__(self)
    self.geometry('300x200')
    self.title("Álbum")
    self.controle = controle

    self.frameTitulo = tk.Frame(self, pady=10)
    self.frameBotao = tk.Frame(self)

    self.frameTitulo.pack()
    self.frameBotao.pack()

    self.labelTitulo = tk.Label(self.frameTitulo,text="Nome: ")
    self.labelTitulo.pack(side="left")  

    self.inputTitulo = tk.Entry(self.frameTitulo, width=20)
    self.inputTitulo.pack(side="left")

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

class ControleAlbum:
  def __init__(self, controlePrincipal):
    self.controlePrincipal = controlePrincipal
    self.listaFaixas = []
    if not os.path.isfile("album.pickle"):
      self.listaAlbum =  []
    else:
      with open("album.pickle", "rb") as f:
        self.listaAlbum = pickle.load(f)

  def salvaAlbum(self):
    if len(self.listaAlbum) != 0:
      with open("album.pickle","wb") as f:
        pickle.dump(self.listaAlbum, f)

  def getListaAlbuns(self):
    return self.listaAlbum

  #-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= FUNÇÕES DE INSERÇÃO -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

  def insereAlbum(self):
    self.viewInsereAlbum = ViewCadastrarAlbum(self)

  def incluirHandler(self, event):
    faixa = self.viewInsereAlbum.inputFaixa.get()
    nroFaixa = self.viewInsereAlbum.inputNroFaixa.get()

    musica = Musica(faixa, nroFaixa)
    self.listaFaixas.append(musica)
    self.viewInsereAlbum.inputFaixa.delete(0, len(self.viewInsereAlbum.inputFaixa.get()))
    self.viewInsereAlbum.inputNroFaixa.delete(0, len(self.viewInsereAlbum.inputNroFaixa.get()))

  def enterHandlerIn(self, event):
    titulo = self.viewInsereAlbum.inputTitulo.get()
    ano = self.viewInsereAlbum.inputAno.get()
    artistaNome = self.viewInsereAlbum.inputArtista.get()
    insere = False

    album = Album(titulo, artistaNome, ano, self.listaFaixas.copy())
    for artista in self.controlePrincipal.ctrlArtista.getListaArtista():
      if artista.getNome() == artistaNome:
        insere = True
        artista.addAlbum(album)
        self.listaAlbum.append(album)
        break

    if insere:
      self.viewInsereAlbum.mostraJanela('Inserção', 'Álbum inserido com sucesso!')
    else:
      self.viewInsereAlbum.mostraJanela('Inserção', 'Artista não encontrado!\nÁlbum não inserido.')

    self.listaFaixas.clear()
    self.limpaHandlerIn(event)

  def limpaHandlerIn(self, event):
    self.viewInsereAlbum.inputTitulo.delete(0, len(self.viewInsereAlbum.inputTitulo.get()))
    self.viewInsereAlbum.inputArtista.delete(0, len(self.viewInsereAlbum.inputArtista.get()))
    self.viewInsereAlbum.inputAno.delete(0, len(self.viewInsereAlbum.inputAno.get()))
    self.viewInsereAlbum.inputFaixa.delete(0, len(self.viewInsereAlbum.inputFaixa.get()))
    self.viewInsereAlbum.inputNroFaixa.delete(0, len(self.viewInsereAlbum.inputNroFaixa.get()))

  def fechaHandlerIn(self, event):
    self.viewInsereAlbum.destroy()

  #-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= FUNÇÕES DE CONSULTA -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

  def consultaAlbum(self):
    self.viewConsultaAlbum = ViewConsultarAlbum(self)

  def enterHandlerCon(self, event):
    titulo = self.viewConsultaAlbum.inputTitulo.get()
    resposta = ''

    for album in self.listaAlbum:
      if album.getTitulo() == titulo:
        resposta += 'Número da Música  -=-  Título da Música\n\n'
        for faixa in album.getFaixas():
          resposta += '{}  /  {}\n'.format(faixa.getNroFaixa(), faixa.getTitulo())
        break

    if resposta:
      self.viewConsultaAlbum.mostraJanela(str(titulo), resposta)
    else:
      self.viewConsultaAlbum.mostraJanela(str(titulo), 'Álbum não encontrado')
    self.limpaHandlerCon(event)

  def limpaHandlerCon(self, event):
    self.viewConsultaAlbum.inputTitulo.delete(0, len(self.viewConsultaAlbum.inputTitulo.get()))

  def fechaHandlerCon(self, event):
    self.viewConsultaAlbum.destroy()