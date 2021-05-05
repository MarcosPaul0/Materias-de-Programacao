import random

try:
    num1 = int(input('Digite o primeiro número do intervalo: '))
    num2 = int(input('Digite o segundo número do intervalo: '))
    
    result = random.randrange(num1, num2)
    print('O número sorteado foi: {}'.format(result))
except:
    print('Só é aceito valores numéricos!')