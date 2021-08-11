import tkinter as tk
import produto as produto
import cupomFiscal as cupomFiscal

class View:
  def __init__(self, root, controle):
    self.controle = controle
    self.root = root
    self.root.geometry('250x100')

    self.barraMenu = tk.Menu(self.root)  

    self.produtoMenu = tk.Menu(self.barraMenu)
    self.cupomFiscalMenu = tk.Menu(self.barraMenu)
    self.sairMenu = tk.Menu(self.barraMenu)

    self.produtoMenu.add_command(label="Cadastrar Produto", \
                command=self.controle.insereProduto)
    self.produtoMenu.add_command(label="Consultar Produto", \
                command=self.controle.consultaProduto)
    self.barraMenu.add_cascade(label="Produto", \
                menu=self.produtoMenu)

    self.cupomFiscalMenu.add_command(label="Cadastrar Cupom Fiscal", \
                command=self.controle.insereCupomFiscal)
    self.cupomFiscalMenu.add_command(label="Consultar Cupom Fiscal", \
                command=self.controle.consultaCupomFiscal)
    self.barraMenu.add_cascade(label="Cupom Fiscal", \
                menu=self.cupomFiscalMenu)

    self.sairMenu.add_command(label="Salvar", \
                command=self.controle.salvarDados)
    self.barraMenu.add_cascade(label="Sair", \
                menu=self.sairMenu)

    self.root.config(menu=self.barraMenu)

class ControlePrincipal:
  def __init__(self):
    self.root = tk.Tk()

    self.limite = View(self.root, self)
    self.ctrlProduto = produto.ControleProduto(self)
    self.ctrlCupomFiscal = cupomFiscal.ControleCupomFiscal(self)

    self.root.title("Cumpom Fiscal")
    self.root.mainloop()

  def teste(self):
    print('ta indo')

  def insereProduto(self):
    self.ctrlProduto.insereProduto()

  def consultaProduto(self):
    self.ctrlProduto.consultaProduto()

  def insereCupomFiscal(self):
    self.ctrlCupomFiscal.insereCupomFiscal()

  def consultaCupomFiscal(self):
    self.ctrlCupomFiscal.consultaCupomFiscal()

  def salvarDados(self):
    self.ctrlProduto.salvarProduto()
    self.ctrlCupomFiscal.salvarCupomFiscal()
    self.root.destroy()

if __name__ == '__main__':
    c = ControlePrincipal()