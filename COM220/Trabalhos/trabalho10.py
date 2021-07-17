import tkinter as tk
from tkinter import messagebox

class ModelCliente():
    def __init__(self, codigo, nome, email):
        self.__codigo = codigo
        self.__nome = nome
        self.__email = email

    def getCodigo(self):
        return self.__codigo

    def getNome(self):
        return self.__nome

    def getEmail(self):
        return self.__email

class View():
    def __init__(self, master, controller):
        self.controller = controller
        self.janela = tk.Frame(master)
        self.janela.pack()
        self.frame0 = tk.Frame(self.janela)
        self.frame1 = tk.Frame(self.janela)
        self.frame2 = tk.Frame(self.janela)
        self.frame0.pack()
        self.frame1.pack()
        self.frame2.pack()
      
        self.labelInfo0 = tk.Label(self.frame0,text="Código: ")
        self.labelInfo1 = tk.Label(self.frame1,text="Nome: ")
        self.labelInfo2 = tk.Label(self.frame2,text="Email: ")
        self.labelInfo0.pack(side="left")
        self.labelInfo1.pack(side="left")
        self.labelInfo2.pack(side="left")  

        self.inputText0 = tk.Entry(self.frame0, width=20)
        self.inputText0.pack(side="left")
        self.inputText1 = tk.Entry(self.frame1, width=20)
        self.inputText1.pack(side="left")
        self.inputText2 = tk.Entry(self.frame2, width=20)
        self.inputText2.pack(side="left")             
      
        self.frame3 = tk.Frame(self.janela)
        self.frame3.pack()

        self.buttonSubmit = tk.Button(self.frame3,text="Enter")      
        self.buttonSubmit.pack(side="left")
        self.buttonSubmit.bind("<Button>", controller.enterHandler)
      
        self.buttonClear = tk.Button(self.frame3,text="Clear")      
        self.buttonClear.pack(side="left")
        self.buttonClear.bind("<Button>", controller.clearHandler)

        self.clientList = tk.Button(self.frame3,text="Listar Clientes")      
        self.clientList.pack(side="left")
        self.clientList.bind("<Button>", controller.clientesHandler)  
 
        self.frame4 = tk.Frame(self.janela)
        self.frame4.pack()

        self.labelSearch = tk.Label(self.frame4,text="Digite o código para busca: ")
        self.labelSearch.pack(side="left")  
        self.inputSearch = tk.Entry(self.frame4, width=20)
        self.inputSearch.pack(side="left")

        self.searchClient = tk.Button(self.frame4,text="Buscar")      
        self.searchClient.pack(side="left")
        self.searchClient.bind("<Button>", controller.handleClient)  
 

    def mostraJanela(self, titulo, mensagem):
        messagebox.showinfo(titulo, mensagem)
      
class Controller():       
    def __init__(self):
        self.root = tk.Tk()
        self.root.geometry('350x150')
        self.listaClientes = []

        # Cria a view passando referência da janela principal e
        # de si próprio (controlador)
        self.view = View(self.root, self) 

        self.root.title("Exemplo MVC")
        # Inicia o mainloop
        self.root.mainloop()

    def enterHandler(self, event):
        codigoCli = self.view.inputText0.get()
        nomeCli = self.view.inputText1.get()
        emailCli = self.view.inputText2.get()
        cliente = ModelCliente(codigoCli, nomeCli, emailCli)
        self.listaClientes.append(cliente)
        self.view.mostraJanela('Sucesso', 'Cliente cadastrado com sucesso')
        self.clearHandler(event)

    def clearHandler(self, event):
        self.view.inputText0.delete(0, len(self.view.inputText0.get()))
        self.view.inputText1.delete(0, len(self.view.inputText1.get()))
        self.view.inputText2.delete(0, len(self.view.inputText2.get()))
    
    # Ex2: implementar função para listar os clientes cadastrados
    def clientesHandler(self, event):
        clientes = ''
        for cliente in self.listaClientes:
            clientes += '{} - {} - {}\n'.format(cliente.getCodigo(), cliente.getNome(), cliente.getEmail())
        self.view.mostraJanela('Clientes', clientes)

    def handleClient(self, event):
        data = ''
        for client in self.listaClientes:
            if self.view.inputSearch.get() == client.getCodigo():
                data += '{} - {} - {}'.format(client.getCodigo(), client.getNome(), client.getEmail())
        if data:
            self.view.mostraJanela('Cliente', data)
        else:
            self.view.mostraJanela('Cliente', 'Cliente não encontrado')

if __name__ == '__main__':
    c = Controller()