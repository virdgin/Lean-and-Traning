'''Известно, что фамилии всех участников — различны. Сохраните в массивах список всех участников и выведите его, отсортировав по фамилии в лексикографическом порядке. При выводе указываете фамилию, имя участника и его балл.

Используйте для ввода и вывода файлы input.txt и output.txt с указанием кодировки utf8. Например, для чтения откройте файл с помощью open('input.txt', 'r', encoding='utf8').

Входные данные

Строки вида "Фамилия Имя НомерШколы Балл".

Выходные данные

Строки вида "Фамилия Имя Балл", отсортированные по фамилии.'''

with open('input.txt', 'r', encoding='utf-8') as inFile:
    people = []
    result = []
    for line in inFile:
        people.append((line.split()[0], line.split()[1], line.split()[3]))
        result.append(people)
people.sort()
with open('output.txt', 'w', encoding='utf-8') as outFile:
    for items in people:
        print(*items, file=outFile)
