def fahrenheitConverter(celsius):
    return celsius * 1.8 + 32

def celsiusConverter(fahrenheit):
    return (fahrenheit - 32) / 1.8

print('{} °C = {} °F'.format(5, fahrenheitConverter(5)))
print('{} °F = {} °C'.format(50, celsiusConverter(50)))