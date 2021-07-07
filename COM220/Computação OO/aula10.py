#Definir as exceptions

class DuplicateUsername(Exception):
    pass

class IsMinor(Exception):
    pass

class InvalidAge(Exception):
    pass

class InvalidEmail(Exception):
    pass

class User:
    def __init__(self, username, email, age):
        self.__username = username
        self.__email = email
        self.__age = age

    def getUsername(self):
        return self.__username

    def getEmail(self):
        return self.__email

    def getAge(self):
        return self.__age

if __name__ == '__main__':
    exampleList = [
        ('paulo', 'paulo@gmail.com', 21),
        ('maria', 'maria@gmail.com', 19),
        ('antonio', 'antonio@gmail.com', 25),
        ('pedro', 'pedro@gmail.com', 15),
        ('marisa', 'marisa', 23),
        ('ana', 'ana@gmail.com', -22),
        ('maria', 'maria2@gmail.com', 27)
    ]

    register = {}

    for username, email, age in exampleList:
        try:
            if username in register:
                raise DuplicateUsername()
            if age < 0:
                raise InvalidAge()
            if age < 18:
                raise IsMinor()
            partEmail = email.split('@')
            if len(partEmail) != 2 or not partEmail[0] or not partEmail[1]:
                raise InvalidEmail()
        except DuplicateUsername:
            print('Username {} já está em uso'.format(username))
        except InvalidAge:
            print('A idade {} é inválida'.format(age))
        except IsMinor:
            print('o usuário {} tem idade menor que a permitida'.format(username))
        except InvalidEmail:
            print('O email {} é inválido'.format(email))
        else:
            register[username] = User(username, email, age)