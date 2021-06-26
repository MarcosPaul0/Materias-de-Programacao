from abc import ABC, abstractmethod

class Funcionario(ABC):
    def __init__(self, codigo, nome):
        self.__codigo = codigo
        self.__nome = nome
        self.__pontoMensalFunc = []

    def getCodigo(self):
        return self.__codigo

    def getNome(self):
        return self.__nome

    def getPontoMensalFunc(self):
        return self.__pontoMensalFunc

    def adicionaPonto(self, mes, ano, faltas, atraso):
        self.__pontoMensalFunc.append(PontoFunc(mes, ano, faltas, atraso))

    def lancaFaltas(self, mes, ano, faltas):
        for ponto in self.__pontoMensalFunc:
            if(ponto.getMes() == mes and ponto.getAno() == ano):
                ponto.lancaFaltas(faltas)
                break

    def lancaAtrasos(self, mes, ano, atarasos):
        for ponto in self.__pontoMensalFunc:
            if(ponto.getMes() == mes and ponto.getAno() == ano):
                ponto.lancaAtrasos(atarasos)
                break

    def imprimeFolha(self, mes, ano):
        for ponto in self.__pontoMensalFunc:
            if(ponto.getMes() == mes and ponto.getAno() == ano):
                print('Código: {}'.format(self.__codigo))
                print('Nome: {}'.format(self.__nome))
                print('Salário Líquido: {:.2f}'.format(self.calculaSalario(mes, ano)))
                print('Bonus: {:.2f}'.format(self.calculaBonus(mes, ano)))

    @abstractmethod
    def calculaSalario(self, mes, ano):
        pass

    @abstractmethod
    def calculaBonus(self, mes, ano):
        pass

class Professor(Funcionario):
    def __init__(self, codigo, nome, titulacao, salarioHora, nroAulas):
        super().__init__(codigo, nome)
        self.__titulacao = titulacao
        self.__salarioHora = salarioHora
        self.__nroAulas = nroAulas

    def getTitutlacao(self):
        return self.__titulacao

    def getSalarioHora(self):
        return self.__salarioHora
    
    def getNroAulas(self):
        return self.__nroAulas

    def calculaSalario(self, mes, ano):
        for ponto in self.getPontoMensalFunc():
            if(ponto.getMes() == mes and ponto.getAno() == ano):
                return (self.__salarioHora * self.__nroAulas) - (self.__salarioHora * ponto.getNroFaltas())

    def calculaBonus(self, mes, ano):
        bonus = 10
        for ponto in self.getPontoMensalFunc():
            if(ponto.getMes() == mes and ponto.getAno() == ano):
                if(bonus - ponto.getNroAtrasos() > 0):
                    return (bonus - ponto.getNroAtrasos())/100 * self.calculaSalario(mes, ano)
                else:
                    return 0

class TecAdmin(Funcionario):
    def __init__(self, codigo, nome, funcao, salarioMensal):
        super().__init__(codigo, nome)
        self.__funcao = funcao
        self.__salarioMensal = salarioMensal

    def getFuncao(self):
        return self.__funcao

    def getSalarioMensal(self):
        return self.__salarioMensal

    def calculaSalario(self, mes, ano):
        for ponto in self.getPontoMensalFunc():
            if(ponto.getMes() == mes and ponto.getAno() == ano):
                return self.__salarioMensal - ((self.__salarioMensal/30) * ponto.getNroFaltas())
    
    def calculaBonus(self, mes, ano):
        bonus = 8
        for ponto in self.getPontoMensalFunc():
            if(ponto.getMes() == mes and ponto.getAno() == ano):
                if(bonus - ponto.getNroAtrasos() > 0):
                    return (bonus - ponto.getNroAtrasos())/100 * self.calculaSalario(mes, ano)
                else:
                    return 0

class PontoFunc:
    def __init__(self, mes, ano, nroFaltas, nroAtrasos):
        self.__mes = mes
        self.__ano = ano
        self.__nroFaltas = nroFaltas
        self.__nroAtrasos = nroAtrasos

    def getMes(self):
        return self.__mes
    
    def getAno(self):
        return self.__ano

    def getNroFaltas(self):
        return self.__nroFaltas

    def getNroAtrasos(self):
        return self.__nroAtrasos

    def lancaFaltas(self, nroFaltas):
        self.__nroFaltas += nroFaltas

    def lancaAtrasos(self, nroAtrasos):
        self.__nroAtrasos += nroAtrasos

if __name__ == "__main__":
    funcionarios = []

    prof = Professor(1, "Joao", "Doutor", 45.35, 32) 
    prof.adicionaPonto(4, 2021, 0, 0)
    prof.lancaFaltas(4, 2021, 2)
    prof.lancaAtrasos(4, 2021, 3)
    funcionarios.append(prof) #Adiciona o professor aos funcionários

    tec = TecAdmin(2, "Pedro", "Analista Contábil", 3600)
    tec.adicionaPonto(4, 2021, 0, 0)
    tec.lancaFaltas(4, 2021, 3)
    tec.lancaAtrasos(4, 2021, 4)
    funcionarios.append(tec) #Adiciona o técnico aos funcionários

    for func in funcionarios:
        func.imprimeFolha(4, 2021)
        print()