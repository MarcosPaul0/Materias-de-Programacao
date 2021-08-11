import tkinter as tk
from tkinter import ttk
from tkinter import messagebox
import os.path
import pickle

class Playlist:
  def __init__(self, nome, musicas):
    self.__nome = nome
    self.__musicas = musicas

  def getNome(self):
    return self.__nome

  def getMusicas(self):
    return self.__musicas

class ViewCadastrarPlaylist(tk.Toplevel):
  def __init__(self, controle, listaArtista):
    tk.Toplevel.__init__(self)
    self.geometry('320x360')
    self.title("Playlist")
    self.controle = controle

    self.frameNome = tk.Frame(self, pady=10)
    self.frameArtista = tk.Frame(self)
    self.frameMusica = tk.Frame(self, pady=10)
    self.frameBotao = tk.Frame(self)

    self.frameNome.pack()
    self.frameArtista.pack()
    self.frameMusica.pack()
    self.frameBotao.pack()

    self.labelNome = tk.Label(self.frameNome,text="Nome: ")
    self.labelNome.pack(side="left")

    self.inputNome = tk.Entry(self.frameNome, width=20)
    self.inputNome.pack(side="left")

    self.labelArtista = tk.Label(self.frameArtista,text="Artista: ")
    self.labelArtista.pack(side="left")

    self.escolhaArista = tk.StringVar()
    self.artista = ttk.Combobox(self.frameArtista, width = 15 , textvariable = self.escolhaArista)
    self.artista.pack(side="left")
    self.artista['values'] = listaArtista

    self.buttonBuscar = tk.Button(self.frameArtista ,text="Buscar Musicas")      
    self.buttonBuscar.pack(side="left")
    self.buttonBuscar.bind("<Button>", controle.buscaHandler)

    self.labelMusica = tk.Label(self.frameMusica,text="Escolha as Musicas: ")
    self.labelMusica.pack(side="left")
    self.musicas = tk.Listbox(self.frameMusica)
    self.musicas.pack(side="left")

    self.buttonInsereMusica = tk.Button(self.frameMusica ,text="Inserir Música")
    self.buttonInsereMusica.pack(side="left")
    self.buttonInsereMusica.bind("<Button>", controle.insereMusica)

    self.buttonEnter = tk.Button(self.frameBotao ,text="Criar Playlist")      
    self.buttonEnter.pack(side="left")
    self.buttonEnter.bind("<Button>", controle.enterHandlerIn)

    self.buttonFechar = tk.Button(self.frameBotao ,text="Concluído")      
    self.buttonFechar.pack(side="left")
    self.buttonFechar.bind("<Button>", controle.fechaHandlerIn)
  
  def mostraJanela(self, titulo, msg):
    messagebox.showinfo(titulo, msg)

class ViewConsultarPlaylist(tk.Toplevel):
  def __init__(self, controle):
    tk.Toplevel.__init__(self)
    self.geometry('300x200')
    self.title("Playlist")
    self.controle = controle

    self.frameNome = tk.Frame(self, pady=10)
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

    self.buttonFechar = tk.Button(self.frameBotao ,text="Fechar")
    self.buttonFechar.pack(side="left")
    self.buttonFechar.bind("<Button>", controle.fechaHandlerCon)

  def mostraJanela(self, titulo, msg):
    messagebox.showinfo(titulo, msg)

class ControlePlaylist:
  def __init__(self, controlePrincipal):
    self.controlePrincipal = controlePrincipal
    self.listaFaixas = []
    if not os.path.isfile("playlist.pickle"):
      self.listaPlaylist =  []
    else:
      with open("playlist.pickle", "rb") as f:
        self.listaPlaylist = pickle.load(f)

  def salvaPlaylist(self):
    if len(self.listaPlaylist) != 0:
      with open("playlist.pickle","wb") as f:
        pickle.dump(self.listaPlaylist, f)

  #-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= FUNÇÕES DE INSERÇÃO -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

  def inserePlaylist(self):
    listaNomeArtista = []
    for artista in self.controlePrincipal.ctrlArtista.getListaArtista():
      listaNomeArtista.append(artista.getNome())
    self.viewinserePlaylist = ViewCadastrarPlaylist(self, listaNomeArtista)

  def buscaHandler(self, event):
    self.viewinserePlaylist.musicas.delete(0, 'end')

    escolhaArista = self.viewinserePlaylist.escolhaArista.get()
    for album in self.controlePrincipal.ctrlAlbum.getListaAlbuns():
      if album.getArtista() == escolhaArista:
        for faixa in album.getFaixas():
          if faixa not in self.listaFaixas:
            self.viewinserePlaylist.musicas.insert(tk.END, faixa.getTitulo())

  def insereMusica(self, event):
    musicaSlecionada = self.viewinserePlaylist.musicas.get(tk.ACTIVE)
    escolhaArista = self.viewinserePlaylist.escolhaArista.get()

    for album in self.controlePrincipal.ctrlAlbum.getListaAlbuns():
      if album.getArtista() == escolhaArista:
        for faixa in album.getFaixas():
          if faixa.getTitulo() == musicaSlecionada:
            self.listaFaixas.append(faixa)
            break
        break

    self.viewinserePlaylist.mostraJanela('Sucesso', 'Música adicionada')
    self.viewinserePlaylist.musicas.delete(tk.ACTIVE)

  def enterHandlerIn(self,event):
    nome = self.viewinserePlaylist.inputNome.get()
    playlist = Playlist(nome, self.listaFaixas.copy())

    self.listaPlaylist.append(playlist)
    self.viewinserePlaylist.mostraJanela('Sucesso', 'Playlist Criada')
    self.listaFaixas.clear()
    self.fechaHandlerIn(event)

  def fechaHandlerIn(self, event):
    self.viewinserePlaylist.destroy()

  #-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= FUNÇÕES DE CONSULTA -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

  def consultaPlaylist(self):
    self.viewConsultaPlaylist = ViewConsultarPlaylist(self)

  def enterHandlerCon(self, event):
    nome = self.viewConsultaPlaylist.inputNome.get()
    resposta = ''
    for playlist in self.listaPlaylist:
      if playlist.getNome() == nome:
        print(playlist.getMusicas())
        resposta += 'Número da Música  -=-  Título da Música\n'
        for musica in playlist.getMusicas():
          resposta += '{}  /  {}\n'.format(musica.getNroFaixa(), musica.getTitulo())
        break
    
    if resposta:
      self.viewConsultaPlaylist.mostraJanela(str(nome), resposta)
    else:
      self.viewConsultaPlaylist.mostraJanela(str(nome), 'Playlist não encontrada!')

  def limpaHandlerCon(self, event):
    self.viewConsultaPlaylist.inputNome.delete(0, len(self.viewConsultaPlaylist.inputNome.get()))

  def fechaHandlerCon(self, event):
    self.viewConsultaPlaylist.destroy()