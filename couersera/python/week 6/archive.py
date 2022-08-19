'''Системный администратор вспомнил, что давно не делал архива пользовательских файлов. Однако, объем диска,
куда он может поместить архив, может быть меньше чем суммарный объем архивируемых файлов.
Известно, какой объем занимают файлы каждого пользователя.
Напишите программу, которая по заданной информации о пользователях и свободному объему на архивном 
диске определит максимальное число пользователей, чьи данные можно поместить в архив.
Формат ввода

Программа получает на вход в одной строке число S – размер свободного места на диске 
(натуральное, не превышает 10000), и число N – количество пользователей (натуральное, не превышает 100), 
после этого идет N чисел - объем данных каждого пользователя (натуральное, не превышает 1000), записанных каждое в отдельной строке.
Формат вывода
Выведите наибольшее количество пользователей, чьи данные могут быть помешены в архив.'''
s, n = map(int, input().split())
v = []
for i in range(n):
    v.append(int(input()))
v.sort()
while sum(v) > s:
    v.pop()
print(len(v))