class Historico:
    def __init__(self):
        self.__discCursadas = [] #Lista de disciplinas que foi cursada

    def getDiscCursadas(self):
        return self.__discCursadas

    def addDiscCursada(self, disciplina):
        self.__discCursadas.append(disciplina)

    def imprimeDiscCursadas(self):
        for disciplina in self.__discCursadas:
            print("{} - {} - {} horas".format(disciplina.getCodigo(), disciplina.getNome(), disciplina.getCargaHora()))
        
class Aluno:
    def __init__(self, nome, numMatricula):
        self.__nome = nome
        self.__numMatricula = numMatricula
        self.__curso = None
        self.__historico = Historico()

    def getNome(self):
        return self.__nome
    
    def getMatricula(self):
        return self.__numMatricula

    def setCurso(self, curso):
        self.__curso = curso

    def getCurso(self):
        return self.__curso

    def getHistorico(self):
        return self.__historico

    def imprimeHorasObgEle(self):
        horasObg = 0
        horasEle = 0

        for disciplina in self.__historico.getDiscCursadas():
            if(disciplina in self.__curso.getGrade().getDisciplinas()):
                horasObg += disciplina.getCargaHora()
            else:
                horasEle += disciplina.getCargaHora()
        print('Horas obrigatórias: {}'.format(horasObg))
        print('Horas eletivas: {}'.format(horasEle))

class Disciplina:
    def __init__(self, codigo, nome, cargaHoraria):
        self.__codigo = codigo
        self.__nome = nome
        self.__cargaHoraria = cargaHoraria

    def getCodigo(self):
        return self.__codigo

    def getNome(self):
        return self.__nome
    
    def getCargaHora(self):
        return self.__cargaHoraria

class Grade:
    def __init__(self, ano):
        self.__ano = ano
        self.__disciplinas = [] #Lista de disciplinas da grade

    def getAno(self):
        return self.__ano

    def addDisciplina(self, disciplina):
        self.__disciplinas.append(disciplina)

    def getDisciplinas(self):
        return self.__disciplinas

class Curso:
    def __init__(self, nome):
        self.__nome = nome
        self.__grade = None
    
    def getNome(self):
        return self.__nome

    def setGrade(self, grade):
        self.__grade = grade

    def getGrade(self):
        return self.__grade

if __name__ == '__main__':
    disciplina01 = Disciplina(1, 'Computação OO', 64) #Instância das disciplinas
    disciplina02 = Disciplina(2, 'Fundamentos de Programação', 80)
    disciplina03 = Disciplina(3, 'Engenharia de Software', 62)
    disciplina04 = Disciplina(4, 'Recursos Humanos', 54)
    disciplina05 = Disciplina(5, 'Contabilidade', 60)
    disciplina06 = Disciplina(6, 'Empreendedorismo', 46)

    gradeSin = Grade(2020) #Instância das grades e adição das disciplinas nas grades
    gradeSin.addDisciplina(disciplina01)
    gradeSin.addDisciplina(disciplina02)
    gradeSin.addDisciplina(disciplina03)

    gradeAdm = Grade(2018)
    gradeAdm.addDisciplina(disciplina04)
    gradeAdm.addDisciplina(disciplina05)
    gradeAdm.addDisciplina(disciplina06)

    sin = Curso('Sistemas de Informação') #Instância dos cursos e a definição da grade
    sin.setGrade(gradeSin)
    adm = Curso('Administração')
    adm.setGrade(gradeAdm)

    aluno = Aluno('Marcos', 1) #Instância do aluno

    aluno.setCurso(sin) #Definição do curso e histórico do aluno
    
    aluno.getHistorico().addDiscCursada(disciplina01) #Adiciona as disciplinas cursadas pelo aluno
    aluno.getHistorico().addDiscCursada(disciplina02)
    aluno.getHistorico().addDiscCursada(disciplina03)
    aluno.getHistorico().addDiscCursada(disciplina06)

    curso = aluno.getCurso() #Curso do aluno
    print('O aluno {}, que cursa {} ({}) já terminou as disciplinas de:'.format(aluno.getNome(), curso.getNome(), curso.getGrade().getAno()))
    aluno.getHistorico().imprimeDiscCursadas()
    print()
    aluno.imprimeHorasObgEle()