def isPalindrome(str):
    if str == str[::-1]:
        return True
    else:
        return False

string = input('Digite uma string: ')
if isPalindrome(string.lower()):
    print('A palavra "{}" é um palíndromo'.format(string))
else:
    print('A palavra "{}" não é um palíndromo'.format(string))
