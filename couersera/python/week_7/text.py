'''Дан текст. Выведите слово, которое в этом тексте встречается чаще всего. Если таких слов несколько, 
выведите то, которое меньше в лексикографическом порядке.
Формат ввода
Вводится текст.
Формат вывода
Выведите ответ на задачу.'''
with open('input.txt', 'r', encoding='utf-8') as in_file:
    line = list(in_file.read().strip().split())
result = dict()
for el in line:
    result[el] = result.get(el, 0)+1
result = sorted(result.items(), key=lambda item: [-item[1], item[0]])
print(result[0][0])
