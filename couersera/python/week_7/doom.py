'''Статья 83 закона “О выборах депутатов Государственной Думы Федерального Собрания Российской Федерации” определяет следующий алгоритм пропорционального распределения мест в парламенте.

Необходимо распределить 450 мест между партиями, участвовавших в выборах. Сначала подсчитывается сумма голосов избирателей, поданных за каждую партию и подсчитывается сумма голосов, поданных за все партии. Эта сумма делится на 450, получается величина, называемая “первое избирательное частное” (смысл первого избирательного частного - это количество голосов избирателей, которое необходимо набрать для получения одного места в парламенте). Далее каждая партия получает столько мест в парламенте, чему равна целая часть от деления числа голосов за данную партию на первое избирательное частное.Если после первого раунда распределения мест сумма количества мест, отданных партиям, меньше 450, то оставшиеся места передаются по одному партиям, в порядке убывания дробной части частного от деления числа голосов за данную партию на первое избирательное частное. Если же для двух партий эти дробные части равны, то преимущество отдается той партии, которая получила большее число голосов.

Формат ввода

На вход программе подается список партий, участвовавших в выборах. Каждая строка входного файла содержит название партии (строка, возможно, содержащая пробелы), затем, через пробел, количество голосов, полученных данной партией – число, не превосходящее 10⁸.

Формат вывода

Программа должна вывести названия всех партий и количество голосов в парламенте, полученных данной партией. Названия необходимо выводить в том же порядке, в котором они шли во входных данных.'''
parties = dict()
final = 0
with open('input.txt', 'r', encoding='utf-8') as in_file:
    for line in in_file:
        line = line.split()
        temp = ' '.join(line[:-1])
        parties[temp] = parties.get(temp, 0)+int(line[-1])
        final = final+int(line[-1])
ostatok = parties.copy()
voices = 450
for el in parties:
    ostatok[el] = (parties[el]/final*450) % 1
    parties[el] = (parties[el]/final * 450)//1
    voices -= int(parties[el])
ostatok = (sorted(ostatok, key=lambda x: -ostatok[x]))
while voices >= 1:
    for el in ostatok:
        parties[el] += 1
        voices -= 1
        if voices == 0:
            break
with open('output.txt', 'w', encoding='utf-8') as outFile:
    for el in parties:
        print(el, int(parties[el]), file=outFile)
