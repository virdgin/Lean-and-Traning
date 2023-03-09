from random import randint
from sys import exit
from time import sleep
from tkinter import Button, Entry, Frame, Label, StringVar, Tk, messagebox
import re


def end():
    messagebox.showinfo("Угадайка", "Досвидания!")
    exit()
def int_valid(newval):
    result = re.match(' (^[0-9]{1,5}$)|(^.*$)  ', newval) is not None
    if not result:
        errmsg.set('Должно быть число!')
    else:
        errmsg.set('')
    return result


def is_valid(left, right):
    main_lbl.config(text="Введите загаданное число:")
    check=(window.register(int_valid),'%P')
    num_entry = Entry(font='15', justify='center',validate='key',validatecommand=check)
    num_entry.pack(side='top')
    temp=int(num_entry.get())
    if left <= temp <= right:
        return temp
    elif temp > right:
        messagebox.showinfo(
            "Угадайка", "Число должно быть меньше " + str(right))
        return is_valid(left, right)
    else:
        messagebox.showinfo(
            "Угадайка", "Число должно быть больше " + str(left))
        return is_valid(left, right)
'''def diapason(t):
    btn3 = Button(
        text="Ввести.",
        bg="#18FF72",
    )
    
    btn3.pack(fill='x', side='top')
    return int(num.get())
def l_and_r(event):
    sleep(5)'''
    
def lets_play():
    btn1.pack_forget()
    btn2.pack_forget()
    main_lbl.config(text="Сначала давайте определим \nдиапазон загадываемого числа.")
    while True:
        #num = StringVar()
        main_lbl.config(text='Введите начальное значение:')
        check=(window.register(int_valid),'%P')
        num_entry = Entry(font='15', justify='center',validate='key',validatecommand=check)
        num_entry.pack(side='top')
        num_entry.focus()
        btn3 = Button(
            text="Ввести.",
            bg="#18FF72",
        )
        btn3.pack(fill='x', side='top')
        left = int(num_entry.get())
        main_lbl.config(text="Введите конечное значение:")
        check=(window.register(int_valid),'%P')
        num_entry.pack(side='top')
        right = int(num_entry.get())
        if left < right:
            break
        else:
            messagebox.showinfo(
                "Угадайка", "Конечное число должно быть больше начального!"
            )
    number = randint(left, right)
    counter = 0
    text_1="Угадывай!!!"
    while True:
        num = int(is_valid(left, right))
        if num > number:
            text_1 = "Угадывай!!!\nЗагаданное число меньше" + str(num)
            right = num
            counter += 1
        elif num < number:
            text_1 = "Угадывай!!!\nЗагаднное число больше" + str(num)
            left = num
            counter += 1
        else:
            messagebox.showinfo(
                "Угадайка", f"Вы угадали!\n Загаданное число: {num}\nКолличество попыток: {counter + 1}")
            print("Хотите еще поиграть?")
def event1(event,t):
    main_lbl.config(text=t)
    global btn1
    btn1 = Button(text="Да", background="#18FF72",
              width="25", font='Arial 15', command=lets_play)
    global btn2 
    btn2 = Button(text="Нет", background="#FF5F18",
                width="25", font='Arial 15', command=end)
    btn1.pack(fill='both', side='right', expand=True)
    btn2.pack(fill='both', side='left', expand=True)


window = Tk()
window.title()
window.geometry('500x300')
frame = Frame(window)
frame.pack(expand=True)
text_1='Я хочу сыграть с тобой в игру!'
main_lbl = Label(
    frame,
    text=text_1, 
    font='Arial 15'
)
errmsg = StringVar()
main_lbl.bind('<Button-1>',lambda e,t='Правила просты!\nЯ загадываю число, ты отгадываешь!\nИграем?': event1(e,t))
main_lbl.grid()



window.mainloop()
