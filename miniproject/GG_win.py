from gettext import textdomain
from tkinter import *
import sys
from tkinter import messagebox
import random
from tkinter import font


def end():
    messagebox.showinfo("Угадайка", "Досвидания!")
    sys.exit()


def diapason(t):
    a = 0
    num_lb = Label(window, text=t, font="Arial 15")
    num_lb.pack(side=TOP, pady="6")
    num_entry = Entry(font=15, justify=CENTER)
    num_entry.pack(side=TOP)
    btn3 = Button(
        text="Ввести.",
        bg="#18FF72",
        font=15,
        command=lambda: int_valid(num_entry.get(), t),
    )
    btn3.pack(fill=X, side=TOP)


def int_valid(a, t):
    if a.isdigit():
        return int(a)
    else:
        messagebox.showinfo("Угадайка", "Введите число!")
        return diapason(t)


def is_valid(left, right):
    temp = diapason("Введите загаданное число:")
    if left <= temp <= right:
        return temp
    elif temp > right:
        messagebox.showinfo("Угадайка", "Число должно быть меньше " + str(right))
        return is_valid(left, right)
    else:
        messagebox.showinfo("Угадайка", "Число должно быть больше " + str(left))
        return is_valid(left, right)


def valid():
    main_text = "Сначала давайте определим \nдиапазон загадываемого числа."
    frame.pack_forget()
    btn1.pack_forget()
    btn2.pack_forget()
    valid_lb = Label(text=main_text, font="Arial 20")
    valid_lb.pack(side=TOP)
    while True:
        text_num = ["Введите начальное значение:", "Введите конечное значение:"]
        left = diapason(text_num[0])
        if left:
            right = diapason(text_num[1])
            if left < right:
                break
            else:
                messagebox.showinfo(
                    "Угадайка", "Конечное число должно быть больше начального!"
                )
    number = random.randint(left, right)
    counter = 0
    main_text = "Угадывай!!!"
    while True:
        num = int(is_valid(left, right))
        if num > number:
            main_text = "Угадывай!!!\nЗагаданное число меньше" + str(num)
            right = num
            counter += 1
        elif num < number:
            main_text = "Угадывай!!!\nЗагаднное число больше" + str(num)
            left = num
            counter += 1
        else:
            print("Вы угадали! Загаданное число", num)
            print("Колличество попыток:", counter + 1)
            print("Хотите еще поиграть?")


main_text = "Добро пожаловать в угадайку!\nЗдесь Вы будете угадывать число которое я загадаю.\nИграем?"
window = Tk()
window.title("Угадайка")
window.geometry()
frame = Frame(window, padx=10, pady=10)
frame.pack(expand=True)
main_lb = Label(
    frame,
    text=main_text,
    font="Arial 15",
)
main_lb.grid(row=0, column=3)
btn1 = Button(text="Да", background="#18FF72", width="25", font=15, command=valid)
btn2 = Button(text="Нет", background="#FF5F18", width="25", font=15, command=end)
btn1.pack(fill=BOTH, side=LEFT, expand=True)
btn2.pack(fill=BOTH, side=RIGHT, expand=True)
window.mainloop()
