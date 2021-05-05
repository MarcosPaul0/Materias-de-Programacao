from random import randint
from time import time

def partition(array, start, end):
    pivot = array[start]
    low = start + 1
    high = end

    while True:
        while low <= high and array[high] >= pivot:
            high = high - 1
        while low <= high and array[low] <= pivot:
            low = low + 1

        if low <= high:
            array[low], array[high] = array[high], array[low]
        else:
            break

    array[start], array[high] = array[high], array[start]

    return high

def quickSort(array, start, end):
    if start >= end:
        return

    p = partition(array, start, end)
    quickSort(array, start, p-1)
    quickSort(array, p+1, end)

def bubbleSort(array):
    for x in range(len(array)):
        for y in range(1, len(array)):
            if array[y] < array[y - 1]:
                aux = array[y]
                array[y] = array[y - 1]
                array[y - 1] = aux

bubbleArray = []
quickArray = []

for x in range(0, 10000):
    number = randint(1, 100000)
    bubbleArray.append(number)
    quickArray.append(number)
#Insere os números aleatórios nos arrays

bubbleStart = time()
bubbleSort(bubbleArray) #Bubblesort do array
bubbleEnd = time()
#Guarda os tempos de antes e depois do bubblesort

quickStart = time()
quickSort(quickArray, 0, len(quickArray) - 1) #Quicksort do array
quickEnd = time()
#Guarda os tempo de antes e depois do quicksort 
print(bubbleArray)
print('O tempo de execução do método Bubblesort é {:.2f} segundos'.format(bubbleEnd - bubbleStart))
print('O tempo de execução do método Quicksort é {:.2f} segundos'.format(quickEnd - quickStart))