''' В олимпиаде по информатике принимало участие несколько человек. 
Определите и выведите средние баллы участников олимпиады в 9 классе, в 10 классе, в 11 классе.
Входные данные 
Информация о результатах олимпиады записана в файле, каждая строка которого имеет вид: 
фамилия имя класс балл.
Фамилия и имя — текстовые строки, не содержащие пробелов. Класс - одно из трех чисел 9, 10, 11. Балл - целое число от 0 до 100.
В этой задаче файл необходимо считывать построчно, не сохраняя содержимое файла в памяти целиком.
Выходные данные
Выведите три числа: средние баллы по 9 классу, по 10 классу, по 11 классу. Входной файл в кодировке utf-8 (используйте open('input.txt', 'r', encoding='utf-8')).'''

with open('Lean-and-Traning\cuersera\python\week 6\input.txt', 'r', encoding='utf-8') as inFiles:
    nine = []
    ten = []
    eleven = []
    for line in inFiles:
        if int(line.split()[2]) == 9:
            nine.append(int(line.split()[3]))
        if int(line.split()[2]) == 10:
            ten.append(int(line.split()[3]))
        if int(line.split()[2]) == 11:
            eleven.append(int(line.split()[3]))
with open('Lean-and-Traning\cuersera\python\week 6\output.txt', 'w', encoding='utf-8') as outFile:
    print(sum(nine)/len(nine), sum(ten)/len(ten),
          sum(eleven)/len(eleven), file=outFile, sep=' ')
