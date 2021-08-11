import tkinter as tk
from tkinter import ttk
from tkinter import messagebox
import os.path
import pickle

class Disciplina:
    def __init__(self, codigo, nome, cargaHoraria):
        self.__codigo = codigo
        self.__nome = nome
        self.__cargaHoraria = cargaHoraria

    def getCodigo(self):
        return self.__codigo

    def getNome(self):
        return self.__nome

    def getCargaHoraria(self):
        return self.__cargaHoraria

class View(tk.Toplevel):
    def __init__(self, controle, listaNomeCurso):
        tk.Toplevel.__init__(self)
        self.geometry('300x200')
        self.title("Disciplinas")
        self.controle = controle

        self.frameNome = tk.Frame(self)
        self.frameCodigo = tk.Frame(self)
        self.frameCargaHoraria = tk.Frame(self)
        self.frameGrade = tk.Frame(self)
        self.frameBotao = tk.Frame(self)

        self.frameCodigo.pack()
        self.frameNome.pack()
        self.frameCargaHoraria.pack()
        self.frameGrade.pack()
        self.frameBotao.pack()

        self.labelCodigo = tk.Label(self.frameCodigo,text="Código: ")
        self.labelCodigo.pack(side="left")
        
        self.labelNome = tk.Label(self.frameNome,text="Nome: ")
        self.labelNome.pack(side="left")  

        self.labelCargaHoraria = tk.Label(self.frameCargaHoraria,text="Carga Horária: ")
        self.labelCargaHoraria.pack(side="left")

        self.labelGrade = tk.Label(self.frameGrade,text="Escolha o Curso: ")
        self.labelGrade.pack(side="left")

        self.inputCodigo = tk.Entry(self.frameCodigo, width=20)
        self.inputCodigo.pack(side="left")

        self.inputNome = tk.Entry(self.frameNome, width=20)
        self.inputNome.pack(side="left")

        self.inputCargaHoraria = tk.Entry(self.frameCargaHoraria, width=20)
        self.inputCargaHoraria.pack(side="left")

        self.escolhaCombo = tk.StringVar()
        self.combobox = ttk.Combobox(self.frameGrade, width = 15 , textvariable = self.escolhaCombo)
        self.combobox.pack(side="left")
        self.combobox['values'] = listaNomeCurso

        self.buttonEnter = tk.Button(self.frameBotao ,text="Enter")      
        self.buttonEnter.pack(side="left")
        self.buttonEnter.bind("<Button>", controle.enterHandler)
      
        self.buttonLimpar = tk.Button(self.frameBotao ,text="Clear")      
        self.buttonLimpar.pack(side="left")
        self.buttonLimpar.bind("<Button>", controle.limpaHandler)  

        self.buttonFechar = tk.Button(self.frameBotao ,text="Concluído")      
        self.buttonFechar.pack(side="left")
        self.buttonFechar.bind("<Button>", controle.fechaHandler)

    def mostraJanela(self, titulo, msg):
        messagebox.showinfo(titulo, msg)

class CtrlDisciplina():
    def __init__(self, controlePrincipal):
        self.controlePrincipal = controlePrincipal
        if not os.path.isfile("discilinas.pickle"):
            self.listaDisciplinas =  []
        else:
            with open("discilinas.pickle", "rb") as f:
                self.listaDisciplinas = pickle.load(f)

    def salvaDisciplinas(self):
        if len(self.listaDisciplinas) != 0:
            with open("discilinas.pickle","wb") as f:
                pickle.dump(self.listaDisciplinas, f)

    #-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- FUNÇÕES AUXILIARES -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

    def getDisciplinas(self):
        return self.listaDisciplinas

    def getNomeDisciplinas(self):
        nomeDisciplinas = []
        for disciplinas in self.listaDisciplinas:
            nomeDisciplinas.append(disciplinas.getNome())
        return nomeDisciplinas

    #-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- FUNÇÕES QUE TRABALHAM A INSERÇÃO DE DISCIPLINA -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

    def insereDisciplina(self):
        listaNomeCurso = self.controlePrincipal.ctrlCurso.getCursosNome()
        self.viewDisciplina = View(self, listaNomeCurso)
    
    def enterHandler(self, event):
        codigo = self.viewDisciplina.inputCodigo.get()
        nome = self.viewDisciplina.inputNome.get()
        cargaHoraria = self.viewDisciplina.inputCargaHoraria.get()
        disciplina = Disciplina(codigo, nome, cargaHoraria)
        
        nomeCurso = self.viewDisciplina.escolhaCombo.get()
        listaCurso = self.controlePrincipal.ctrlCurso.getCursos()
        for curso in listaCurso:
            if nomeCurso == curso.getNome():
                curso.getGrade().addDisciplina(disciplina)
                break

        self.listaDisciplinas.append(disciplina)
        self.viewDisciplina.mostraJanela('Sucesso', 'Disciplina cadastrada com sucesso')
        self.limpaHandler(event)

    def limpaHandler(self, event):
        self.viewDisciplina.inputCodigo.delete(0, len(self.viewDisciplina.inputCodigo.get()))
        self.viewDisciplina.inputNome.delete(0, len(self.viewDisciplina.inputNome.get()))
        self.viewDisciplina.inputCargaHoraria.delete(0, len(self.viewDisciplina.inputCargaHoraria.get()))

    def fechaHandler(self, event):
        self.viewDisciplina.destroy()