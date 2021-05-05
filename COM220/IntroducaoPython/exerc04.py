try:
    wage = float(input('Digite seu salário: ').replace(',', '.'))
except:
    print('Salário inválido!')

if wage < 1903.99:
    print('Não possuí alíquota')
elif wage < 2826.65:
    print('O valor da alíquota é R${}'.format(str(round(wage * 0.075, 2)).replace('.', ',')))
elif wage < 3751.05:
    print('O valor da alíquota é R${}'.format(str(round(wage * 0.15, 2)).replace('.', ',')))
elif wage < 4664.68:
    print('O valor da alíquota é R${}'.format(str(round(wage * 0.225, 2)).replace('.', ',')))
else:
    print('O valor da alíquota é R${}'.format(str(round(wage * 0.275, 2)).replace('.', ',')))