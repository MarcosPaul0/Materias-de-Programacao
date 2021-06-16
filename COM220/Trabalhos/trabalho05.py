from abc import ABC, abstractmethod

class EmpDomestica(ABC):
    def __init__(self, nome, telefone):
        self.__nome = nome
        self.__telefone = telefone

    def getNome(self):
        return self.__nome

    def getTelefone(self):
        return self.__telefone

    @abstractmethod
    def getSalario(self):
        pass

class Horista(EmpDomestica):
    def __init__(self, nome, telefone, horasTrab, valorHora):
        super().__init__(nome, telefone)
        self.__horasTrab = horasTrab
        self.__valorHora = valorHora

    def getSalario(self):
        return self.__horasTrab * self.__valorHora

class Diarista(EmpDomestica):
    def __init__(self, nome, telefone, diasTrab, valorDia):
        super().__init__(nome, telefone)
        self.__diasTrab = diasTrab
        self.__valorDia = valorDia

    def getSalario(self):
        return self.__diasTrab * self.__valorDia

class Mensalista(EmpDomestica):
    def __init__(self, nome, telefone, valorMes):
        super().__init__(nome, telefone)
        self.__valorMes = valorMes

    def getSalario(self):
        return self.__valorMes

if __name__ == '__main__':
    empDomesticas = []

    empDomesticas.append(Horista('Maria', 997565778, 160, 10))
    empDomesticas.append(Diarista('Sônia', 998523641, 20, 55))
    empDomesticas.append(Mensalista('Leila', 999267543, 1000))

    maisBarata = empDomesticas[0]
    for emp in empDomesticas:
        print('{} - {} - R${:.2f}'.format(emp.getNome(), emp.getTelefone(), emp.getSalario()))
        if(emp.getSalario() < maisBarata.getSalario()):
            maisBarata = emp

    print('\n\nA mais barata é [ {} - {} - R${} ]'.format(
        maisBarata.getNome(), 
        maisBarata.getTelefone(), 
        str(format(maisBarata.getSalario(), '.2f')).replace('.', ',')))