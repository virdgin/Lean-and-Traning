import random
import sys

def end():
    print("Досвидания!")
    sys.exit()

def valid(a):
    if a.lower() == "нет":
        return False
    else:
        return True


def int_valid(a):
    b = valid(a)
    if b:
        if a.isdigit():
            return int(a)
        else:
            return int_valid(input("Введите число: "))
    else:
        end()


def is_valid(left, right):
    temp = input("Введите загаданное число: ")
    r = valid(temp)
    if r:
        temp = int_valid(temp)
        if left <= temp <= right:
            return temp
        elif temp > right:
            print("Число должно быть меньше", right)
            return is_valid(left, right)
        else:
            print("Число должно быть больше", left)
            return is_valid(left, right)
    else:
        end()


def start():
    print("Сначала давайте определимся диапазон загадываемого числа.")
    while True:
        left = int_valid(input("Введите начальное число: "))
        right = int_valid(input("Введите конечное число: "))
        if left < right:
            break
        else:
            print("Начальное чило должно быть меньше конечного!")
    number = random.randint(left, right)
    counter = 0
    while True:
        num = is_valid(left, right)
        if num > number:
            print("Загаданное число меньше", num)
            right = num
            counter += 1
        elif num < number:
            print("Загаднное число больше", num)
            left = num
            counter += 1
        else:
            print("Вы угадали! Загаданное число", num)
            print("Колличество попыток:", counter+1)
            print("Хотите еще поиграть?")
            if valid(input()):
                start()
            else:
                end()
                break


print("Добро пожаловать в угадайку!")
print("Здесь Вы будете угадывать число которое я загадаю.")
dig = valid(input('Введите "Нет" если хотите выйти: '))
if dig:
    start()
else:
    end()
