from curses import window
from gettext import textdomain
from tkinter import *
import sys
from tkinter import messagebox
import random
from tkinter import font


def end():
    messagebox.showinfo('Угадайка','Досвидания!')
    sys.exit()

def int_valid(a):
    if a.isdigit():
        return int(a)
    else:
        return int_valid(input("Введите число: "))



def is_valid(left, right):
    temp = input("Введите загаданное число: ")
    temp = int_valid(temp)
    if left <= temp <= right:
        return temp
    elif temp > right:
        print("Число должно быть меньше", right)
        return is_valid(left, right)
    else:
        print("Число должно быть больше", left)
        return is_valid(left, right)

def valid():
    main_lb.delete("1.0","end")
    frame_valid=Frame(window)
    frame_valid.pack(side=TOP)
    valid_lb = Label(
        frame_valid,
        text="Сначала давайте определим \nдиапазон загадываемого числа.",
        font=20
        )
    valid_lb.grid(row=1, column=3)
    btn1.pack_forget()
    btn2.pack_forget()
    left_lb=Label(text='Введите начальное значение:').place(x=1,y=210)
    right_lb=Label(text='Введите конечное значение:').place(x=1,y=260)
   # left_lb.grid(sticky="w")
   # right_lb.grid(sticky="w")
    '''
    while True:
        left = IntVar()#int_valid(input("Введите начальное число: "))
        right = IntVar()#int_valid(input("Введите конечное число: "))
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
'''

window = Tk()
window.title("Угадайка")
window.geometry("500x300")
frame = Frame(window, padx=10, pady=10)
frame.pack(expand=True)
main_lb = Label(
    frame,
    text="Добро пожаловать в угадайку!\nЗдесь Вы будете угадывать число которое я загадаю.\nИграем?",
    font=20,
)
main_lb.grid(row=1, column=3)
btn1 = Button(text="Да", background="#18FF72", width="25", font=15,command=valid)
btn2 = Button(text="Нет", background="#FF5F18", width="25", font=15,command=end)
btn1.pack(side=LEFT)
btn2.pack(side=RIGHT)
window.mainloop()
