from abc import ABC, abstractmethod

class Pessoa(ABC):
    def __init__(self, nome, endereco, idade, listaDisc):
        self.__nome = nome
        self.__endereco = endereco
        self.__idade = idade
        self.__listaDisc = listaDisc

    def getNome(self):
        return self.__nome

    def getEndereco(self):
        return self.__endereco

    def getIdade(self):
        return self.__idade

    def getListaDisc(self):
        return self.__listaDisc

    def insereDisc(self, disc):
        self.__listaDisc.append(disc)

    @abstractmethod
    def printDescricao(self):
        pass

class Professor(Pessoa):
    def __init__(self, nome, endereco, idade, listaDisc, titulacao, ):
        super().__init__(nome, endereco, idade, listaDisc)
        self.__titulacao = titulacao

    def getTitulacao(self):
        return self.__titulacao

    def printDescricao(self):
        print('Nome: {}'.format(self.getNome()))
        print('Endereco: {}'.format(self.getEndereco()))
        print('Idade: {}'.format(self.getIdade()))
        print('Titulação: {}'.format(self.getTitulacao()))
        print('Ministra as Disciplinas:')
        listaDisciplinas = self.getListaDisc()
        for disc in listaDisciplinas:
            print('Nome: {} - Carga Horária {}'.format(disc.getNomeDisc(), disc.getCargaHoraria()))


class Aluno(Pessoa):
    def __init__(self, nome, endereco, idade, listaDisc, curso, ):
        super().__init__(nome, endereco, idade, listaDisc)
        self.__curso = curso

    def getCurso(self):
        return self.__curso

    def printDescricao(self):
        print('Nome: {}'.format(self.getNome()))
        print('Endereco: {}'.format(self.getEndereco()))
        print('Idade: {}'.format(self.getIdade()))
        print('Curso: {}'.format(self.getCurso()))
        print('Cursa as Disciplinas:')
        listaDisciplinas = self.getListaDisc()
        for disc in listaDisciplinas:
            print('Nome: {} - Carga Horária: {} horas'.format(disc.getNomeDisc(), disc.getCargaHoraria()))

class Disciplina():
    def __init__(self, nomeDisc, cargaHoraria):
        self.__nomeDisc = nomeDisc
        self.__cargaHoararia = cargaHoraria
    
    def getNomeDisc(self):
        return self.__nomeDisc

    def getCargaHoraria(self):
        return self.__cargaHoararia

if __name__ == '__main__':
    disc01 = Disciplina('Programação OO', 64)
    disc02 = Disciplina('Algoritmos e Estrutura de Dados', 86)
    disc03 = Disciplina('Programação Web', 48)

    prof = Professor('Baldochi', 'Avenida BPS', 52, [], 'Doutor')
    aluno = Aluno('Marcos', 'Rua Cassiano Pinto', 20, [], 'SIN')

    prof.insereDisc(disc01)
    prof.insereDisc(disc03)

    aluno.insereDisc(disc01)
    aluno.insereDisc(disc02)

    prof.printDescricao()
    print('\n\n')
    aluno.printDescricao()