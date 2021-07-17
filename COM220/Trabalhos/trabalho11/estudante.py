import tkinter as tk
from tkinter import messagebox

class Estudante:

    def __init__(self, nroMatric, nome):
        self.__nroMatric = nroMatric
        self.__nome = nome

    def getNroMatric(self):
        return self.__nroMatric
    
    def getNome(self):
        return self.__nome

class LimiteInsereEstudantes(tk.Toplevel):
    def __init__(self, controle):

        tk.Toplevel.__init__(self)
        self.geometry('250x100')
        self.title("Estudante")
        self.controle = controle

        self.frameNro = tk.Frame(self)
        self.frameNome = tk.Frame(self)
        self.frameButton = tk.Frame(self)
        self.frameNro.pack()
        self.frameNome.pack()
        self.frameButton.pack()
      
        self.labelNro = tk.Label(self.frameNro,text="Nro Matrícula: ")
        self.labelNome = tk.Label(self.frameNome,text="Nome: ")
        self.labelNro.pack(side="left")
        self.labelNome.pack(side="left")  

        self.inputNro = tk.Entry(self.frameNro, width=20)
        self.inputNro.pack(side="left")
        self.inputNome = tk.Entry(self.frameNome, width=20)
        self.inputNome.pack(side="left")             
      
        self.buttonSubmit = tk.Button(self.frameButton ,text="Enter")      
        self.buttonSubmit.pack(side="left")
        self.buttonSubmit.bind("<Button>", controle.enterHandler)
      
        self.buttonClear = tk.Button(self.frameButton ,text="Clear")      
        self.buttonClear.pack(side="left")
        self.buttonClear.bind("<Button>", controle.clearHandler)  

        self.buttonFecha = tk.Button(self.frameButton ,text="Concluído")      
        self.buttonFecha.pack(side="left")
        self.buttonFecha.bind("<Button>", controle.fechaHandler)

    def mostraJanela(self, titulo, msg):
        messagebox.showinfo(titulo, msg)

class LimiteMostraEstudantes():
    def __init__(self, str):
        messagebox.showinfo('Lista de alunos', str)

class LimiteConsultaEstudante(tk.Toplevel):
    def __init__(self, controle):

        tk.Toplevel.__init__(self)
        self.geometry('250x100')
        self.title("Consulta Estudante")
        self.controle = controle

        self.frameConsult = tk.Frame(self)
        self.frameButton = tk.Frame(self)
        self.frameConsult.pack()
        self.frameButton.pack()

        self.labelSearch = tk.Label(self.frameConsult,text="Digite o código para busca: ")
        self.labelSearch.pack(side="left")  
        self.inputSearch = tk.Entry(self.frameConsult, width=20)
        self.inputSearch.pack(side="left")

        self.buttonConsult = tk.Button(self.frameButton,text="Buscar")      
        self.buttonConsult.pack(side="left")
        self.buttonConsult.bind("<Button>", controle.resultadoConsulta) 
        
        self.buttonClear = tk.Button(self.frameButton ,text="Limpar")      
        self.buttonClear.pack(side="left")
        self.buttonClear.bind("<Button>", controle.clearHandlerConsult)

        self.buttonFecha = tk.Button(self.frameButton ,text="Concluído")      
        self.buttonFecha.pack(side="left")
        self.buttonFecha.bind("<Button>", controle.fechaHandlerConsult)

    def mostraJanela(self, titulo, msg):
        messagebox.showinfo(titulo, msg)

class CtrlEstudante():       
    def __init__(self):
        self.listaEstudantes = [
            Estudante('1001', 'Joao Santos'),
            Estudante('1002', 'Marina Cintra'),
            Estudante('1003', 'Felipe Reis'),
            Estudante('1004', 'Ana Souza')
        ]

    def getEstudante(self, nroMatric):
        estRet = None
        for est in self.listaEstudantes:
            if est.getNroMatric() == nroMatric:
                estRet = est
        return estRet

    def getListaNroMatric(self):
        listaNro = []
        for est in self.listaEstudantes:
            listaNro.append(est.getNroMatric())
        return listaNro

    def insereEstudantes(self):
        self.limiteIns = LimiteInsereEstudantes(self) 

    def mostraEstudantes(self):
        str = 'Nro Matric. -- Nome\n'
        for est in self.listaEstudantes:
            str += est.getNroMatric() + ' -- ' + est.getNome() + '\n'       
        self.limiteLista = LimiteMostraEstudantes(str)

    def consultaEstudante(self):
        self.limitConsult = LimiteConsultaEstudante(self)

    def resultadoConsulta(self, event):
        data = ''
        for estudante in self.listaEstudantes:
            if self.limitConsult.inputSearch.get() == estudante.getNroMatric():
                data += '{} - {}'.format(estudante.getNroMatric(), estudante.getNome())
        if data:
            self.limitConsult.mostraJanela('Estudante', data)
        else:
            self.limitConsult.mostraJanela('Estudante', 'Estudante não encontrado')
        self.clearHandlerConsult(event)

    def enterHandler(self, event):
        nroMatric = self.limiteIns.inputNro.get()
        nome = self.limiteIns.inputNome.get()
        estudante = Estudante(nroMatric, nome)
        self.listaEstudantes.append(estudante)
        self.limiteIns.mostraJanela('Sucesso', 'Estudante cadastrado com sucesso')
        self.clearHandler(event)

    def clearHandler(self, event):
        self.limiteIns.inputNro.delete(0, len(self.limiteIns.inputNro.get()))
        self.limiteIns.inputNome.delete(0, len(self.limiteIns.inputNome.get()))

    def clearHandlerConsult(self, event):
        self.limitConsult.inputSearch.delete(0, len(self.limitConsult.inputSearch.get()))

    def fechaHandler(self, event):
        self.limiteIns.destroy()

    def fechaHandlerConsult(self, event):
        self.limitConsult.destroy()