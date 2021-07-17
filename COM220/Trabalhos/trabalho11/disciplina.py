import tkinter as tk
from tkinter import messagebox

class Disciplina:

    def __init__(self, codigo, nome):
        self.__codigo = codigo
        self.__nome = nome

    def getCodigo(self):
        return self.__codigo
    
    def getNome(self):
        return self.__nome

class LimiteInsereDisciplinas(tk.Toplevel):
    def __init__(self, controle):

        tk.Toplevel.__init__(self)
        self.geometry('250x100')
        self.title("Disciplina")
        self.controle = controle

        self.frameNome = tk.Frame(self)
        self.frameCodigo = tk.Frame(self)
        self.frameButton = tk.Frame(self)
        self.frameCodigo.pack()
        self.frameNome.pack()
        self.frameButton.pack()
      
        self.labelCodigo = tk.Label(self.frameCodigo,text="Código: ")
        self.labelNome = tk.Label(self.frameNome,text="Nome: ")
        self.labelCodigo.pack(side="left")
        self.labelNome.pack(side="left")  

        self.inputCodigo = tk.Entry(self.frameCodigo, width=20)
        self.inputCodigo.pack(side="left")
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

class LimiteMostraDisciplinas():
    def __init__(self, str):
        messagebox.showinfo('Lista de disciplinas', str)

class LimiteConsultaDisciplina(tk.Toplevel):
    def __init__(self, controle):

        tk.Toplevel.__init__(self)
        self.geometry('250x100')
        self.title("Consulta Disciplina")
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

class CtrlDisciplina():       
    def __init__(self):
        self.listaDisciplinas = [
            Disciplina('COM220', 'Programação OO'),
            Disciplina('COM222', 'Programação Web'),
            Disciplina('COM111', 'Estruturas de Dados')
        ]

    def getListaDisciplinas(self):
        return self.listaDisciplinas

    def getDisciplina(self, codDisc):
        discRet = None
        for disc in self.listaDisciplinas:
            if disc.getCodigo() == codDisc:
                discRet = disc
        return discRet

    def getListaCodDisciplinas(self):
        listaCod = []
        for disc in self.listaDisciplinas:
            listaCod.append(disc.getCodigo())
        return listaCod

    def insereDisciplinas(self):
        self.limiteIns = LimiteInsereDisciplinas(self) 

    def mostraDisciplinas(self):
        str = 'Código -- Nome\n'
        for disc in self.listaDisciplinas:
            str += disc.getCodigo() + ' -- ' + disc.getNome() + '\n'
        self.limiteLista = LimiteMostraDisciplinas(str)

    def consultaDisciplina(self):
        self.limitConsult = LimiteConsultaDisciplina(self)

    def resultadoConsulta(self, event):
        data = ''
        for disciplina in self.listaDisciplinas:
            if self.limitConsult.inputSearch.get() == disciplina.getCodigo():
                data += '{} - {}'.format(disciplina.getCodigo(), disciplina.getNome())
        if data:
            self.limitConsult.mostraJanela('Disciplina', data)
        else:
            self.limitConsult.mostraJanela('Disciplina', 'Disciplina não encontrada')
        self.clearHandlerConsult(event)

    def enterHandler(self, event):
        nroMatric = self.limiteIns.inputCodigo.get()
        nome = self.limiteIns.inputNome.get()
        disciplina = Disciplina(nroMatric, nome)
        self.listaDisciplinas.append(disciplina)
        self.limiteIns.mostraJanela('Sucesso', 'Disciplina cadastrada com sucesso')
        self.clearHandler(event)

    def clearHandler(self, event):
        self.limiteIns.inputCodigo.delete(0, len(self.limiteIns.inputCodigo.get()))
        self.limiteIns.inputNome.delete(0, len(self.limiteIns.inputNome.get()))

    def clearHandlerConsult(self, event):
        self.limitConsult.inputSearch.delete(0, len(self.limitConsult.inputSearch.get()))

    def fechaHandler(self, event):
        self.limiteIns.destroy()

    def fechaHandlerConsult(self, event):
        self.limitConsult.destroy()