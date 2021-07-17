from random import randint

class Produto():
    def __init__(self, codigo, descricao, valor):
        self.__codigo = codigo
        self.__descricao = descricao
        self.__valor = valor

    def getCodigo(self):
        return self.__codigo

    def getDescricao(self):
        return self.__descricao

    def getValor(self):
        return self.__valor
#Eu teria declarado uma lista e dicionário de forma global, porém como este exercício é baseado na aula 09 acabei fazendo dessa forma
class ListaProdutos():
    def __init__(self):
        self.__produtos = []

    def getProdutos(self):
        return self.__produtos
    
    def adiciona(self, item):
        self.__produtos.append(item)

class Estoque():
    def __init__(self):
        self.__produtos = {}

    def getProdutos(self):
        return self.__produtos

    def adiciona(self, codigo, qtd):
        self.__produtos[str(codigo)] = qtd

    def retiraVenda(self, nota):
        itensNota = nota.getItem()[0].getCodigo()
        qtdNota = nota.getItem()[1]
        while self.__produtos[str(itensNota)] != 0 and qtdNota != 0:
            self.__produtos[str(itensNota)] -= 1
            qtdNota -= 1
        return qtdNota

    def imprimeEstoque(self):
        for produto in self.__produtos:
            print('Código {} - Estoque {}'.format(produto, self.__produtos[produto]))
            

class NotaFiscal():
    def __init__(self, nroNF, nomeCliente, itensNF):
        self.__nroNF = nroNF
        self.__nomeCliente = nomeCliente
        self.__itensNF = itensNF

    def getNro(self):
        return self.__nroNF

    def getNome(self):
        return self.__nomeCliente

    def getItem(self):
        return self.__itensNF

def validaNota(nota, estoque):
    produto = estoque.getProdutos()[str(nota.getItem()[0].getCodigo())]
    if produto != 0 and not produto:
        print('Este produto não existe')
        return

    qtdInicial = nota.getItem()[1]
    qtdFinal = estoque.retiraVenda(nota)

    if qtdFinal > 0 and qtdInicial != qtdFinal:
        print('Pedido atendido parcialmente')
    elif qtdFinal > 0 and qtdInicial == qtdFinal:
        print('Não possui estoque')
    else:
        print('Nota atendida')

if __name__ == '__main__':
    listaItens = ListaProdutos()
    listaItens.adiciona(Produto(1, 'Calça Jeans', 80))
    listaItens.adiciona(Produto(2, 'Camisa', 50))
    listaItens.adiciona(Produto(3, 'Blusa', 120))
    listaItens.adiciona(Produto(4, 'Tênis', 140))
    listaItens.adiciona(Produto(5, 'Óculos', 100))
    listaItens.adiciona(Produto(6, 'Meia', 15))

    estoque = Estoque()

    for item in listaItens.getProdutos():
        estoque.adiciona(item.getCodigo(), randint(0, 6)) #Randomiza o número de produtos no estoque para gerar casos diferentes

    validaNota(NotaFiscal(123, 'Marcos', [Produto(1, 'Calça Jeans', 80), 3]), estoque)
    validaNota(NotaFiscal(456, 'Paulo', [Produto(2, 'Camisa', 50), 6]), estoque)
    validaNota(NotaFiscal(789, 'Pereira', [Produto(5, 'Óculos', 100), 2]), estoque)

    print()
    estoque.imprimeEstoque()