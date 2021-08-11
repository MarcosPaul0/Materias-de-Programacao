import tkinter as tk
from tkinter import ttk
from tkinter import messagebox
import os.path
import pickle

class Aluno:
    def __init__(self, nroMatric, nome, historico, curso):
        self.__nroMatric = nroMatric
        self.__nome = nome
        self.__historico = historico
        self.__curso = curso

    def getNroMatric(self):
        return self.__nroMatric

    def getNome(self):
        return self.__nome

    def getHistorico(self):
        return self.__historico

    def getCurso(self):
        return self.__curso

class Historico:
    def __init__(self):
        self.__disciplinasCursadas = []

    def getDisciplinasCursadas(self):
        return self.__disciplinasCursadas

    def addDisciplinaCursada(self, semestre, disciplina, nota):
        self.__disciplinasCursadas.append([semestre, disciplina, nota])

class ViewInsereAluno(tk.Toplevel):
    def __init__(self, controle, listaCursos):
        tk.Toplevel.__init__(self)
        self.geometry('300x200')
        self.title("Aluno")
        self.controle = controle

        self.frameNroMatricula = tk.Frame(self)
        self.frameNome = tk.Frame(self)
        self.frameCurso = tk.Frame(self)
        self.frameBotao = tk.Frame(self)

        self.frameNroMatricula.pack()
        self.frameNome.pack()
        self.frameCurso.pack()
        self.frameBotao.pack()

        self.labelNroMatricula = tk.Label(self.frameNroMatricula,text="Nro Matrícula: ")
        self.labelNroMatricula.pack(side="left")

        self.labelNome = tk.Label(self.frameNome,text="Nome: ")
        self.labelNome.pack(side="left")  

        self.labelCurso = tk.Label(self.frameCurso,text="Curso: ")
        self.labelCurso.pack(side="left")  

        self.inputNroMatricula = tk.Entry(self.frameNroMatricula, width=20)
        self.inputNroMatricula.pack(side="left")

        self.inputNome = tk.Entry(self.frameNome, width=20)
        self.inputNome.pack(side="left")

        self.escolhaCurso = tk.StringVar()
        self.cursos = ttk.Combobox(self.frameCurso, width = 15 , textvariable = self.escolhaCurso)
        self.cursos.pack(side="left")
        self.cursos['values'] = listaCursos

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

class ViewHistorico(tk.Toplevel):
    def __init__(self, controle, listaAlunos, listaDisciplinas):
        tk.Toplevel.__init__(self)
        self.geometry('300x200')
        self.title("Aluno")
        self.controle = controle

        self.frameAluno = tk.Frame(self)
        self.frameDisciplina = tk.Frame(self)
        self.frameSemestre = tk.Frame(self)
        self.frameNota = tk.Frame(self)
        self.frameBotao = tk.Frame(self)

        self.frameAluno.pack()
        self.frameDisciplina.pack()
        self.frameSemestre.pack()
        self.frameNota.pack()
        self.frameBotao.pack()

        self.labelAluno = tk.Label(self.frameAluno,text="Aluno: ")
        self.labelAluno.pack(side="left")

        self.labelDisciplina = tk.Label(self.frameDisciplina,text="Disciplina Cursada: ")
        self.labelDisciplina.pack(side="left")

        self.labelSemestre = tk.Label(self.frameSemestre,text="Semestre: ")
        self.labelSemestre.pack(side="left")

        self.labelNota = tk.Label(self.frameNota,text="Nota: ")
        self.labelNota.pack(side="left")  

        self.inputSemestre = tk.Entry(self.frameSemestre, width=20)
        self.inputSemestre.pack(side="left")

        self.inputNota = tk.Entry(self.frameNota, width=20)
        self.inputNota.pack(side="left")

        self.escolhaAluno = tk.StringVar()
        self.alunos = ttk.Combobox(self.frameAluno, width = 15 , textvariable = self.escolhaAluno)
        self.alunos.pack(side="left")
        self.alunos['values'] = listaAlunos

        self.escolhaDisciplina = tk.StringVar()
        self.disciplinas = ttk.Combobox(self.frameDisciplina, width = 15 , textvariable = self.escolhaDisciplina)
        self.disciplinas.pack(side="left")
        self.disciplinas['values'] = listaDisciplinas

        self.buttonEnter = tk.Button(self.frameBotao ,text="Enter")      
        self.buttonEnter.pack(side="left")
        self.buttonEnter.bind("<Button>", controle.enterHandlerHist)

        self.buttonLimpar = tk.Button(self.frameBotao ,text="Limpar")      
        self.buttonLimpar.pack(side="left")
        self.buttonLimpar.bind("<Button>", controle.limpaHandlerHist)

        self.buttonFechar = tk.Button(self.frameBotao ,text="Concluído")      
        self.buttonFechar.pack(side="left")
        self.buttonFechar.bind("<Button>", controle.fechaHandlerHist)

    def mostraJanela(self, titulo, msg):
        messagebox.showinfo(titulo, msg)

class ViewHistoricoConsulta(tk.Toplevel):
    def __init__(self, controle):
        tk.Toplevel.__init__(self)
        self.geometry('300x200')
        self.title("Histórico")
        self.controle = controle

        self.frameNroMatricula = tk.Frame(self)
        self.frameBotao = tk.Frame(self)

        self.frameNroMatricula.pack()
        self.frameBotao.pack()

        self.labelMatricula = tk.Label(self.frameNroMatricula,text="Matrícula: ")
        self.labelMatricula.pack(side="left")

        self.inputMatricula = tk.Entry(self.frameNroMatricula, width=20)
        self.inputMatricula.pack(side="left")

        self.buttonEnter = tk.Button(self.frameBotao ,text="Enter")      
        self.buttonEnter.pack(side="left")
        self.buttonEnter.bind("<Button>", controle.enterHandlerConsulta)

        self.buttonLimpar = tk.Button(self.frameBotao ,text="Limpar")      
        self.buttonLimpar.pack(side="left")
        self.buttonLimpar.bind("<Button>", controle.limpaHandlerConsulta)

        self.buttonFechar = tk.Button(self.frameBotao ,text="Concluído")      
        self.buttonFechar.pack(side="left")
        self.buttonFechar.bind("<Button>", controle.fechaHandlerConsulta)

    def mostraJanela(self, titulo, msg):
        messagebox.showinfo(titulo, msg)
        
class CtrlAluno():
    def __init__(self, controlePrincipal):
        self.controlePrincipal = controlePrincipal
        if not os.path.isfile("alunos.pickle"):
            self.listaAlunos =  []
        else:
            with open("alunos.pickle", "rb") as f:
                self.listaAlunos = pickle.load(f)

    def salvaAlunos(self):
        if len(self.listaAlunos) != 0:
            with open("alunos.pickle","wb") as f:
                pickle.dump(self.listaAlunos, f)

    #-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- FUNÇÕES QUE TRABALHAM A INSERÇÃO DE ALUNO -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

    def insereAluno(self):
        listaCursosNomes = self.controlePrincipal.ctrlCurso.getCursosNome()
        self.viewAluno = ViewInsereAluno(self, listaCursosNomes)
    
    def enterHandler(self, event):
        nroMatric = self.viewAluno.inputNroMatricula.get()
        nome = self.viewAluno.inputNome.get()
        cursoEscolha = self.viewAluno.escolhaCurso.get()
        cursoAluno = None

        for curso in self.controlePrincipal.ctrlCurso.getCursos():
            if cursoEscolha == curso.getNome():
                cursoAluno = curso
                break

        aluno = Aluno(nroMatric, nome, Historico(), cursoAluno)
        self.listaAlunos.append(aluno)
        self.viewAluno.mostraJanela('Sucesso', 'Aluno cadastrada com sucesso')
        self.limpaHandler(event)

    def limpaHandler(self, event):
        self.viewAluno.inputNroMatricula.delete(0, len(self.viewAluno.inputNroMatricula.get()))
        self.viewAluno.inputNome.delete(0, len(self.viewAluno.inputNome.get()))

    def fechaHandler(self, event):
        self.viewAluno.destroy()

    #-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- FUNÇÕES QUE TRABALHAM O HISTÓRICO -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

    def insereHistorico(self):
        listaNomeAlunos = []
        for aluno in self.listaAlunos:
            listaNomeAlunos.append(aluno.getNome())

        listaNomeDisciplinas = self.controlePrincipal.ctrlDisciplina.getNomeDisciplinas()

        self.viewHistorico = ViewHistorico(self, listaNomeAlunos, listaNomeDisciplinas)

    def enterHandlerHist(self, event):
        nomeAluno = self.viewHistorico.escolhaAluno.get()
        nomeDisciplina = self.viewHistorico.escolhaDisciplina.get()
        disciplinas = self.controlePrincipal.ctrlDisciplina.getDisciplinas()

        semestre = self.viewHistorico.inputSemestre.get()
        nota = self.viewHistorico.inputNota.get()

        for disciplina in disciplinas:
            if nomeDisciplina == disciplina.getNome():
                for aluno in self.listaAlunos:
                    if nomeAluno == aluno.getNome():
                        aluno.getHistorico().addDisciplinaCursada(semestre, disciplina, nota)
                break
        self.viewHistorico.mostraJanela('Sucesso', 'Histórico alterado com sucesso')
        self.limpaHandlerHist(event)

    def limpaHandlerHist(self, event):
        self.viewHistorico.escolhaAluno.set('')
        self.viewHistorico.escolhaDisciplina.set('')
        self.viewHistorico.inputSemestre.delete(0, len(self.viewHistorico.inputSemestre.get()))
        self.viewHistorico.inputNota.delete(0, len(self.viewHistorico.inputNota.get()))

    def fechaHandlerHist(self, event):
        self.viewHistorico.destroy()

    #-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- FUNÇÕES QUE TRABALHAM A CONSULTA -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

    def consultarHistorico(self):
        self.viewConsulta = ViewHistoricoConsulta(self)

    def enterHandlerConsulta(self, event):
        matricula = self.viewConsulta.inputMatricula.get()
        resposta = ''
        horasObrigatorias = 0
        horasEletivas = 0
        nomesDiscipCursos = []

        for aluno in self.listaAlunos:
            if matricula == aluno.getNroMatric():
                for nomeDicip in aluno.getCurso().getGrade().getDisciplinas():
                    nomesDiscipCursos.append(nomeDicip.getNome())

                resposta += 'Semestre -=- Disciplina -=- Nota -=- Situação\n'
                
                for disciplina in aluno.getHistorico().getDisciplinasCursadas():
                    resposta += '{}  /  {}  /  {}  /  '.format(disciplina[0], disciplina[1].getNome(), disciplina[2])
                    resposta += 'APROVADO\n' if int(disciplina[2]) >= 6 else 'REPROVADO\n'

                    if disciplina[1].getNome() in nomesDiscipCursos:
                        horasObrigatorias += int(disciplina[1].getCargaHoraria())
                    else:
                        horasEletivas += int(disciplina[1].getCargaHoraria())
                break

        resposta += '\n\nHoras Obrigatórias: {}\n'.format(horasObrigatorias)
        resposta += 'Horas Eletivas: {}\n'.format(horasEletivas)

        if resposta:
            self.viewConsulta.mostraJanela('Histórico', resposta)
        else:
            self.viewConsulta.mostraJanela('Histórico', 'Aluno não encontrado')
        self.limpaHandlerConsulta(event)

    def limpaHandlerConsulta(self, event):
        self.viewConsulta.inputMatricula.delete(0, len(self.viewConsulta.inputMatricula.get()))

    def fechaHandlerConsulta(self, event):
        self.viewConsulta.destroy()