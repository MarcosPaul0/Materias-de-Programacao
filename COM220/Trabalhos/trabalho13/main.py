import tkinter as tk
import artista as artista
import album as album
import playlist as playlist

class View:
  def __init__(self, root, controle):
    self.controle = controle
    self.root = root
    self.root.geometry('250x100')

    self.barraMenu = tk.Menu(self.root)  

    self.artistaMenu = tk.Menu(self.barraMenu)
    self.albumMenu = tk.Menu(self.barraMenu)
    self.playlistMenu = tk.Menu(self.barraMenu)
    self.sairMenu = tk.Menu(self.barraMenu)

    self.artistaMenu.add_command(label="Cadastrar Artista", \
                command=self.controle.insereArtista)
    self.artistaMenu.add_command(label="Consultar Artista", \
                command=self.controle.consultaArtista)
    self.barraMenu.add_cascade(label="Artista", \
                menu=self.artistaMenu)

    self.albumMenu.add_command(label="Cadastrar Álbum", \
                command=self.controle.insereAlbum)
    self.albumMenu.add_command(label="Consultar Álbum", \
                command=self.controle.consultaAlbum)                     
    self.barraMenu.add_cascade(label="Álbum", \
                menu=self.albumMenu)       

    self.playlistMenu.add_command(label="Cadastrar Playlist", \
                command=self.controle.inserePlaylist)   
    self.playlistMenu.add_command(label="Consultar Playlist", \
                command=self.controle.consultaPlaylist)   
    self.barraMenu.add_cascade(label="Playlist", \
                menu=self.playlistMenu)

    self.sairMenu.add_command(label="Salvar", \
                command=self.controle.salvarDados)
    self.barraMenu.add_cascade(label="Sair", \
                menu=self.sairMenu)

    self.root.config(menu=self.barraMenu)

class ControlePrincipal:
  def __init__(self):
    self.root = tk.Tk()

    self.limite = View(self.root, self)
    self.ctrlArtista = artista.ControleAtista(self)
    self.ctrlAlbum = album.ControleAlbum(self)
    self.ctrlPlaylist = playlist.ControlePlaylist(self)

    self.root.title("Spotfy Humilde")
    self.root.mainloop()

  def teste(self):
    print('ta indo')

  def insereArtista(self):
    self.ctrlArtista.insereArtista()

  def consultaArtista(self):
    self.ctrlArtista.consultaArtista()

  def insereAlbum(self):
    self.ctrlAlbum.insereAlbum()

  def consultaAlbum(self):
    self.ctrlAlbum.consultaAlbum()

  def inserePlaylist(self):
    self.ctrlPlaylist.inserePlaylist()

  def consultaPlaylist(self):
    self.ctrlPlaylist.consultaPlaylist()

  def salvarDados(self):
        self.ctrlArtista.salvaArtista()
        self.ctrlAlbum.salvaAlbum()
        self.ctrlPlaylist.salvaPlaylist()
        self.root.destroy()

if __name__ == '__main__':
    c = ControlePrincipal()