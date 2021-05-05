str1 = input('Insira a primeira string: ')
str2 = input('Insira a segunda string: ')

if str2.lower() in str1.lower():
    print('A string "{}" está contida em "{}"'.format(str2, str1))
else:
    print('A string "{}" não está contida em "{}"'.format(str2, str1))