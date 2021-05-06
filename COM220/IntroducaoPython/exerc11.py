import math

def hoursForSeconds(hour, minutes, seconds):
    return hour * 3600 + minutes * 60 + seconds

def secondsForHours(seconds):
    hours = seconds // 3600
    seconds -= hours * 3600
    minutes = seconds // 60
    seconds -= minutes * 60
    return '{}:{}:{}'.format(hours, minutes, seconds)

hourIn = input('Digite a hora de entrada (hh:mm:ss): ')
segIn = hoursForSeconds(int(hourIn[0:2]), int(hourIn[3:5]), int(hourIn[6:8]))

hourOut = input('Digite a hora de entrada (hh:mm:ss): ')
segOut = hoursForSeconds(int(hourOut[0:2]), int(hourOut[3:5]), int(hourOut[6:8]))

onSeconds = segOut - segIn
print('O tempo em que o usuário ficou online corresponde a {} horas'.format(secondsForHours(onSeconds)))