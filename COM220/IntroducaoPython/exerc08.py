names = []
heights = []

repetition = int(input('Quantas pessoas deseja cadastrar: '))

for i in range(0, repetition):
    name = input('Digite seu nome: ').capitalize()
    height = float(input('Digite sua altura: '))
    names.append(name)
    heights.append(height)

maxHeight = max(heights)
minHeight = min(heights)
heightPeople = names[heights.index(maxHeight)]
lowerPeople = names[heights.index(minHeight)]

print('\nA pessoa mais alta é {} com {} m'.format(heightPeople, round(maxHeight, 2)))
print('A pessoa mais baixa é {} com {} m'.format(lowerPeople, round(minHeight, 2)))