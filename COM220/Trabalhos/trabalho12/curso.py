import tkinter as tk
from tkinter import messagebox
import os.path
import pickle

class Grade:
    def __init__(self, ano):
        self.__ano = ano
        self.__disciplinas = []

    def getAno(self):
        return self.__ano

    def getDisciplinas(self):
        return self.__disciplinas

    def addDisciplina(self, disciplina):
        self.__disciplinas.append(disciplina)

class Curso:
    def __init__(self, nome, grade):
        self.__nome = nome
        self.__grade = grade

    def getNome(self):
        return self.__nome

    def getGrade(self):
        return self.__grade

class View(tk.Toplevel):
    def __init__(self, controle):
        tk.Toplevel.__init__(self)
        self.geometry('300x200')
        self.title("Curso")
        self.controle = controle

        self.frameNome = tk.Frame(self)
        self.frameGrade = tk.Frame(self)
        self.frameBotao = tk.Frame(self)

        self.frameNome.pack()
        self.frameGrade.pack()
        self.frameBotao.pack()

        self.labelNome = tk.Label(self.frameNome,text="Nome: ")
        self.labelNome.pack(side="left")   
        self.inputNome = tk.Entry(self.frameNome, width=20)
        self.inputNome.pack(side="left")

        self.labelAnoGrade = tk.Label(self.frameGrade,text="Ano da Grade: ")
        self.labelAnoGrade.pack(side="left")   
        self.inputAnoGrade = tk.Entry(self.frameGrade, width=20)
        self.inputAnoGrade.pack(side="left")

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

class ViewConsulta(tk.Toplevel):
    def __init__(self, controle):
        tk.Toplevel.__init__(self)
        self.geometry('300x200')
        self.title("Consulta Curso")
        self.controle = controle

        self.frameConsulta = tk.Frame(self)
        self.frameButton = tk.Frame(self)
        self.frameConsulta.pack()
        self.frameButton.pack()

        self.labelConsulta = tk.Label(self.frameConsulta,text="Digite o código para busca: ")
        self.labelConsulta.pack(side="left")  
        self.inputConsulta = tk.Entry(self.frameConsulta, width=20)
        self.inputConsulta.pack(side="left")

        self.buttonConsult = tk.Button(self.frameButton,text="Buscar")      
        self.buttonConsult.pack(side="left")
        self.buttonConsult.bind("<Button>", controle.resultadoConsulta) 
        
        self.buttonClear = tk.Button(self.frameButton ,text="Limpar")      
        self.buttonClear.pack(side="left")
        self.buttonClear.bind("<Button>", controle.limpaHandlerConsulta)

        self.buttonFecha = tk.Button(self.frameButton ,text="Concluído")      
        self.buttonFecha.pack(side="left")
        self.buttonFecha.bind("<Button>", controle.fechaHandlerConsulta)

    def mostraJanela(self, titulo, msg):
        messagebox.showinfo(titulo, msg)

class CtrlCurso():
    def __init__(self):
        if not os.path.isfile("cursos.pickle"):
            self.listaCursos =  []
        else:
            with open("cursos.pickle", "rb") as f:
                self.listaCursos = pickle.load(f)

    def salvaCursos(self):
        if len(self.listaCursos) != 0:
            with open("cursos.pickle","wb") as f:
                pickle.dump(self.listaCursos, f)

    #-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- FUNÇÕES AUXILIARES -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

    def getCursos(self):
        return self.listaCursos

    def getCursosNome(self):
        listaNomesCursos = []
        for curso in self.listaCursos:
            listaNomesCursos.append(curso.getNome())
        return listaNomesCursos

    #-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- FUNÇÕES QUE TRABALHAM A INSERÇÃO DE CURSO -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

    def insereCurso(self):
        self.viewCurso = View(self)
    
    def enterHandler(self, event):
        nome = self.viewCurso.inputNome.get()
        ano = self.viewCurso.inputAnoGrade.get()

        curso = Curso(nome, Grade(ano))
        self.listaCursos.append(curso)
        self.viewCurso.mostraJanela('Sucesso', 'Curso cadastrada com sucesso')
        self.limpaHandler(event)

    def limpaHandler(self, event):
        self.viewCurso.inputNome.delete(0, len(self.viewCurso.inputNome.get()))
        self.viewCurso.inputAnoGrade.delete(0, len(self.viewCurso.inputAnoGrade.get()))

    def fechaHandler(self, event):
        self.viewCurso.destroy()

    #-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- FUNÇÕES DE CONSULTA DO CURSO -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

    def consultaCurso(self):
        self.viewConsulta = ViewConsulta(self)

    def resultadoConsulta(self, event):
        resposta = ''
        for curso in self.listaCursos:
            if self.viewConsulta.inputConsulta.get() == curso.getNome():
                resposta += 'Código -=- Nome -=- Carga Horária\n'
                for disciplina in curso.getGrade().getDisciplinas():
                    resposta += '{}  -=-  {}  -=-  {}\n'.format(disciplina.getCodigo(), disciplina.getNome(), disciplina.getCargaHoraria())
                break
        if resposta:
            self.viewConsulta.mostraJanela('Grade do Curso', resposta)
        else:
            self.viewConsulta.mostraJanela('Grade do Curso', 'Curso não encontrado')
        self.limpaHandlerConsulta(event)

    def limpaHandlerConsulta(self, event):
        self.viewConsulta.inputConsulta.delete(0, len(self.viewConsulta.inputConsulta.get()))

    def fechaHandlerConsulta(self, event):
        self.viewConsulta.destroy()