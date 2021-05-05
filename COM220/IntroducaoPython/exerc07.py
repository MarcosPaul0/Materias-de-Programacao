numberList = []
total = 0

while True:
    try:
        num = float(input('Digite um número (0 para parar): '))
        if num == 0:
            break
        numberList.append(num)
    except:
        print('Número inválido!')

for num in numberList:
    total += num

print('\nA média dos números inseridos é {}'.format(round(total / len(numberList), 1)))