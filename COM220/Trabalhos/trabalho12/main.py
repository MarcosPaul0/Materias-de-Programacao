import tkinter as tk
import aluno as aluno
import disciplina as disciplina
import curso as curso

class View():
    def __init__(self, root, controle):
        self.controle = controle
        self.root = root
        self.root.geometry('400x300')

        self.barraMenu = tk.Menu(self.root)  

        self.alunoMenu = tk.Menu(self.barraMenu)
        self.discipMenu = tk.Menu(self.barraMenu)
        self.cursoMenu = tk.Menu(self.barraMenu)
        self.sairMenu = tk.Menu(self.barraMenu)

        self.alunoMenu.add_command(label="Inserir Aluno", \
                    command=self.controle.insereAlunos)
        self.alunoMenu.add_command(label="Cadastrar Disciplinas Cursadas", \
                    command=self.controle.insereHistoricos)
        self.alunoMenu.add_command(label="Consultar Aluno", \
                    command=self.controle.consultarHistorico)
        self.barraMenu.add_cascade(label="Aluno", \
                    menu=self.alunoMenu)

        self.cursoMenu.add_command(label="Cadastrar Curso", \
                    command=self.controle.insereCursos)
        self.cursoMenu.add_command(label="Consultar Curso", \
                    command=self.controle.consultaCurso)                     
        self.barraMenu.add_cascade(label="Curso", \
                    menu=self.cursoMenu)       

        self.discipMenu.add_command(label="Cadastrar Disciplina", \
                    command=self.controle.insereDisciplinas)   
        self.barraMenu.add_cascade(label="Disciplina", \
                    menu=self.discipMenu)

        self.sairMenu.add_command(label="Salvar", \
                    command=self.controle.salvarDados)
        self.barraMenu.add_cascade(label="Sair", \
                    menu=self.sairMenu)

        self.root.config(menu=self.barraMenu)

      
class ControlePrincipal():       
    def __init__(self):
        self.root = tk.Tk()

        self.ctrlAluno = aluno.CtrlAluno(self)
        self.ctrlCurso = curso.CtrlCurso()
        self.ctrlDisciplina = disciplina.CtrlDisciplina(self)

        self.limite = View(self.root, self) 

        self.root.title("SIGAA Humilde")
        self.root.mainloop()

    def insereDisciplinas(self):
        self.ctrlDisciplina.insereDisciplina()

    def insereCursos(self):
        self.ctrlCurso.insereCurso()

    def consultaCurso(self):
        self.ctrlCurso.consultaCurso()
    
    def insereAlunos(self):
        self.ctrlAluno.insereAluno()

    def insereHistoricos(self):
        self.ctrlAluno.insereHistorico()

    def consultarHistorico(self):
        self.ctrlAluno.consultarHistorico()

    def salvarDados(self):
        self.ctrlAluno.salvaAlunos()
        self.ctrlCurso.salvaCursos()
        self.ctrlDisciplina.salvaDisciplinas()
        self.root.destroy()

if __name__ == '__main__':
    c = ControlePrincipal()