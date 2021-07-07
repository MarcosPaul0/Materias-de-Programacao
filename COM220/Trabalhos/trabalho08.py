from abc import ABC, abstractmethod

class Pessoa(ABC):
    def __init__(self, nome, cpf, endereco, idade):
        self.__nome = nome
        self.__cpf = cpf
        self.__endereco = endereco
        self.__idade = idade

    def getNome(self):
        return self.__nome

    def getCpf(self):
        return self.__cpf

    def getEndereco(self):
        return self.__endereco

    def getIdade(self):
        return self.__idade

    @abstractmethod
    def printDescricao(self):
        pass

class Professor(Pessoa):
    def __init__(self, nome, cpf, endereco, idade, titulacao):
        super().__init__(nome, cpf, endereco, idade)
        self.__titulacao = titulacao
    
    def getTitulacao(self):
        return self.__titulacao

    def printDescricao(self):
        print('Nome: {}'.format(self.getNome()))
        print('CPF: {}'.format(self.getCpf()))
        print('Endereço {}'.format(self.getEndereco()))
        print('Idade: {}'.format(self.getIdade()))
        print('Titulação: {}'.format(self.__titulacao))

class Aluno(Pessoa):
    def __init__(self, nome, cpf, endereco, idade, curso):
        super().__init__(nome, cpf, endereco, idade)
        self.__curso = curso

    def getCurso(self):
        return self.__curso

    def printDescricao(self):
        print('Nome: {}'.format(self.getNome()))
        print('CPF: {}'.format(self.getCpf()))
        print('Endereço {}'.format(self.getEndereco()))
        print('Idade: {}'.format(self.getIdade()))
        print('Curso: {}'.format(self.__curso))

class TitulacaoInvalida(Exception):
    pass

class CursoInvalido(Exception):
    pass

class IdadeInvalida(Exception):
    pass

class CpfDuplicado(Exception):
    pass

if __name__ == '__main__':
    listaPessoas = [
        Professor('João', 12345678910, 'Itajubá', 30, 'Doutor'),
        Professor('Mário', 23456789102, 'Belo Horizonte', 35, 'Técnico'),
        Professor('Zé', 12345678911, 'Itajubá', 28, 'Doutor'),
        Aluno('Marcos', 12345678913, 'Conceição dos Ouros', 20, 'SIN'),
        Aluno('Paulo', 12345678914, 'São Paulo', 17, 'CCO'),
        Aluno('Maria', 12345678915, 'Rio de Janeiro', 20, 'ADM'),
        Aluno('Ana', 12345678910, 'Itajubá', 20, 'SIN')
    ]

    registro = {}

    for pessoa in listaPessoas:
        try:
            if type(pessoa) == Professor:
                if pessoa.getTitulacao().lower() != 'doutor':
                    raise TitulacaoInvalida()
                if pessoa.getIdade() < 30:
                    raise IdadeInvalida()
            if type(pessoa) == Aluno:
                if pessoa.getCurso().upper() != 'SIN' and pessoa.getCurso().upper() != 'CCO':
                    raise CursoInvalido()
                if Aluno and pessoa.getIdade() < 18:
                    raise IdadeInvalida()
            if pessoa.getCpf() in registro:
                raise CpfDuplicado()
        except TitulacaoInvalida:
            print('A titulação {}, do usuário(a) {} é inválida!'.format(pessoa.getTitulacao(), pessoa.getNome()))
            print()
        except CursoInvalido:
            print('O usuário(a) {}, está realizando o curso {}, que é inválido!'.format(pessoa.getNome(), pessoa.getCurso()))
            print()
        except IdadeInvalida:
            print('O usuário(a) {}, possui idade de {} anos inválida para {}.'.format(pessoa.getNome(), pessoa.getIdade(), 'professores' if type(pessoa) is Professor else 'alunos'))
            print()
        except CpfDuplicado:
            print('O usuário(a) {}, possui CPF duplicado!'.format(pessoa.getNome()))
            print()
        else:
            pessoa.printDescricao()
            registro[pessoa.getCpf()] = pessoa
            print()