def mdc(m, n):
    while m%n != 0:
        oldm = m
        oldn = n
        m = oldn
        n = oldm%oldn
    return n

def mesmaFracao(f1, f2):
    return (f1.getNum() == f2.getNum()) and (f1.getDen() == f2.getDen())    

class Fracao:
    
    def __init__(self, num, den):

        self.__num = num        
        self.__den = den     

    def __str__(self):
        return str(self.__num) + "/" + str(self.__den)

    def getNum(self):
        return self.__num

    def getDen(self):
        return self.__den

    def simplifica(self):
        divComum = mdc(self.__num, self.__den)
        self.__num = self.__num // divComum
        self.__den = self.__den // divComum   

    def __add__(self, outraFrac):
        novoNum = self.__num * outraFrac.getDen() + self.__den * outraFrac.getNum()
        novoDen = self.__den * outraFrac.getDen()
        divComum = mdc(novoNum, novoDen)
        novaFracao = Fracao(novoNum // divComum, novoDen//divComum)
        if novaFracao.getNum() % novaFracao.getDen() == 0:
            return int(novaFracao.getNum() / novaFracao.getDen())
        elif novaFracao.getNum() / novaFracao.getDen() < 1:
            return novaFracao
        else:
            parteInt = novaFracao.getNum() // novaFracao.getDen()
            novoNum = novaFracao.getNum() - parteInt * novaFracao.getDen()
            fracMista = FracaoMista(parteInt, novoNum, novaFracao.getDen())
            return fracMista

class FracaoMista(Fracao):
    def __init__(self, parteInteira, num, den):
        super().__init__(num, den)
        self.__parteInteira = parteInteira

    def getParteInteira(self):
        return self.__parteInteira

    def __str__(self):
        return str(self.__parteInteira) + ' ' + str(self.getNum()) + '/' + str(self.getDen())

    def __add__(self, outraFrac):
        parteInt = self.getParteInteira() + outraFrac.getParteInteira() #Soma da parte inteira das frações

        novoNum = self.getNum() * outraFrac.getDen() + self.getDen() * outraFrac.getNum() 
        novoDen = self.getDen() * outraFrac.getDen()
        divComum = mdc(novoNum, novoDen)
        novaFracao = FracaoMista(parteInt, novoNum // divComum, novoDen//divComum) #Soma da parte fracionária

        if novaFracao.getNum() % novaFracao.getDen() == 0:
            return int(novaFracao.getNum() / novaFracao.getDen()) + parteInt
        elif novaFracao.getNum() / novaFracao.getDen() < 1:
            return novaFracao
        else:
            novaParteInt = novaFracao.getNum() // novaFracao.getDen()
            novoNum = novaFracao.getNum() - novaParteInt * novaFracao.getDen()
            fracMista = FracaoMista(novaParteInt + parteInt, novoNum, novaFracao.getDen())
            return fracMista

if __name__ == "__main__":
    frac1 = Fracao(7, 6)  # 7/6 + 13/7 = 3 1/42 
    frac2 = Fracao(13, 7)
    print('Fração 01 = {}'.format(frac1))
    print('Fração 02 = {}'.format(frac2))
    print('Soma = {}'.format(frac1 + frac2))
    
    print("\n-=-=-=-=-=-=-=-=-=-=-=-\n")

    frac1 = Fracao(1, 3)   # 1/3 + 2/3 = 1 
    frac2 = Fracao(2, 3)
    print('Fração 01 = {}'.format(frac1))
    print('Fração 02 = {}'.format(frac2))
    print('Soma = {}'.format(frac1 + frac2))

    print("\n-=-=-=-=-=-=-=-=-=-=-=-\n")

    frac1 = FracaoMista(3, 1, 2)   # 3 1/2 + 4 2/3 = 8 1/6
    frac2 = FracaoMista(4, 2, 3)
    print('Fração 01 = {}'.format(frac1))
    print('Fração 02 = {}'.format(frac2))
    print('Soma = {}'.format(frac1 + frac2))