word = input('Insira uma palavra: ')

if word == word[::-1]:
    print('{} é um palíndromo!'.format(word))
else:
    print('{} não é um palíndromo!'.format(word))