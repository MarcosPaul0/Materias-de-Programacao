try:
    numReptition = int(input('Quantos nomes deseja inserir? '))
except:
    print('Número inválido!')

names = []

for i in range(0, numReptition):
    name = input('Digite o {}° nome: '.format(i + 1)).capitalize()
    names.append(name)

nameSearch = input('Qual nome deseja procurar? ').capitalize()

if nameSearch in names:
    print('O nome {} está na posição {}.'.format(nameSearch, names.index(nameSearch) + 1))
else:
    print('O nome {} não foi encontrado!'.format(nameSearch))