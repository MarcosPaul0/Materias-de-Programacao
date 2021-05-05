from datetime import datetime

date = input('Digite uma data qualquer dd/mm/AA: ')

try:
    date = datetime.strptime(date, '%d/%m/%Y').strftime('%A')
except:
    print('Data inválida!')

if date == 'Sunday':
    print('A data corresponde a Domingo')
elif date == 'Monday':
    print('A data corresponde a Segunda-Feira')
elif date == 'Tuesday':
    print('A data corresponde a Terça-Feira ')
elif date == 'Wednesday':
    print('A data corresponde a Quarta-Feira ')
elif date == 'Thursday':
    print('A data corresponde a Quinta-Feira ')
elif date == 'Friday':
    print('A data corresponde a Sexta-Feira ')
elif date == 'Saturday':
    print('A data corresponde a Sábado ')